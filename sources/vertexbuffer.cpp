/*

	Copyright (c) 2018 Fluff Studios
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

*/

/*
    REVISION HISTORY

    AUTHOR          DATE            CHANGES
    Nick Clark      30-MAY-18       Creation of Vertex Buffer abstraction
 */

#include "vertexbuffer.h"

namespace glpp
{
    GLuint VertexBuffer::sCurrentID_;

    VertexBuffer::VertexBuffer()
    {
        glGenBuffers(1, &mID_);
    }

    VertexBuffer::~VertexBuffer()
    {
        glDeleteBuffers(1, &mID_);
        mID_ = 0;
    }

    void VertexBuffer::Bind() const
    {
        CheckRebind();
        glBindBuffer(GL_ARRAY_BUFFER, mID_);
    }

    void VertexBuffer::Unbind() const
    {
        CheckRebind();
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::SetData(sizei Size, const void * pData, BufferUsage Usage)
    {
        CheckBound();
        CheckMapped(0, Size);
#ifdef _DEBUG
        this->mSize_ = Size;
        printf("Setting Vertex Buffer (%d) data with size (%d) and usage (%d)", mID_, mSize_, Usage);
#endif
        glBufferData(GL_ARRAY_BUFFER, Size, pData, Usage);
    }

    void VertexBuffer::SetSubData(sizei Size, sizei Offset, const void * pData, BufferUsage Usage)
    {
        CheckBound();
        CheckMapped(Offset, Size);
#ifdef _DEBUG
        this->mSize_ = Size;
        printf("Setting Vertex Buffer (%d) data with offset (%d), size (%d) and usage (%d)", mID_, Offset, mSize_, Usage);
#endif
        glBufferSubData(GL_ARRAY_BUFFER, Offset, Size, pData);
    }

    void * VertexBuffer::MapBufferRange(sizei Size, sizei Offset, MapAccess Access)
    {
        CheckBound();
#ifdef _DEBUG
        if (mMapped_)
        {
            if ((mMappedRange_.Offset >= begin && (mMappedRange_.Offset + mMappedRange_.Size) <= begin)
                || (mMappedRange_.Offset <= end && (mMappedRange_.Offset + mMappedRange_.Size) >= end))
            {
                Debug::Write("Buffer already mapped.", HIGH, INVALID_FUNCTION);
            }
        }

        mMappedRange_.Offset = Offset;
        mMappedRange_.Size = Size;
        mMapped_ = true;
#endif
        glMapBufferRange(GL_ARRAY_BUFFER, Offset, Size, Access);
#ifdef _DEBUG
        if (glGetError() == GL_OUT_OF_MEMORY)
        {
            Debug::Write("Out of memory.", HIGH, INVALID_FUNCTION);
        }
#endif
    }

    void * VertexBuffer::MapBuffer(MapAccess Access)
    {
        CheckBound();
#ifdef _DEBUG
        if (mMapped_)
        {
            if ((mMappedRange_.Offset >= begin && (mMappedRange_.Offset + mMappedRange_.Size) <= begin)
                || (mMappedRange_.Offset <= end && (mMappedRange_.Offset + mMappedRange_.Size) >= end))
            {
                Debug::Write("Buffer already mapped.", HIGH, INVALID_FUNCTION);
            }
        }

        mMappedRange_.Offset = 0;
        mMappedRange_.Size = mSize_;
        mMapped_ = true;
#endif
        glMapBuffer(GL_ARRAY_BUFFER, Access);
#ifdef _DEBUG
        if (glGetError() == GL_OUT_OF_MEMORY)
        {
            Debug::Write("Out of memory.", HIGH, INVALID_FUNCTION);
        }
#endif
    }

    void VertexBuffer::FlushMappedBufferRange(sizei Size, sizei Offset)
    {
        CheckBound();
#ifdef _DEBUG
        
#endif
        glFlushMappedBufferRange(GL_ARRAY_BUFFER, Offset, Size);
    }

    void VertexBuffer::Unmap()
    {
#ifdef _DEBUG
        if (!mMapped_)
        {
            Debug::Write("Buffer already unmapped.", LOW, INVALID_FUNCTION);
        }
        mMapped_ = false;
#endif
        CheckBound();
        glUnmapBuffer(GL_ARRAY_BUFFER);
    }

    GLint VertexBuffer::GetBufferParameter(BufferParameter Parameter) const
    {
		CheckBound();
        GLint value;
        glGetBufferParamateriv(GL_ARRAY_BUFFER, Parameter, &value);
        return value;
    }

    GLint64 VertexBuffer::GetBufferParameter64(BufferParameter Parameter) const
    {
        CheckBound();
        GLint64 value;
        glGetBufferParameteri64v(GL_ARRAY_BUFFER, Parameter, &value);
        return value;
    }

    void * VertexBuffer::GetBufferSubData(sizei Size, GLsizei Offset) const
    {
        CheckBound();
        void * data = malloc(Size);
        if (!data) return NULL;
        glGetBufferSubdata(GL_ARRAY_BUFFER, Offset, Size, data);
        return data;
    }

    void VertexBuffer::CheckBound() const
    {
#ifdef _DEBUG
        if (sCurrentID_ != mID_ || sCurrentID_ == 0) 
        {
            char buffer[1024];
            memset(buffer, 0, 1024 * sizeof(char));
            sprintf(buffer, "VertexBuffer not bound.  Active Buffer: %d", mID_);
            Debug::Write(buffer, HIGH, BAD_DATA);
        }
#endif
    }

    void VertexBuffer::CheckRebind() const
    {
#ifdef _DEBUG
		if (sCurrentID_ == mID_) Debug::Write("VertexBuffer already bound.", MEDIUM, PERFORMANCE);
		sCurrentID_ = mID_;
#endif
    }

    void VertexBuffer::CheckMapped(uint32_t Offset, uint32_t Size) const
    {
#ifdef _DEBUG
        uint32_t begin = Offset;
        uint32_t end = Offset + Size;

        if (mMapped_)
        {
            if ((mMappedRange_.Offset >= begin && (mMappedRange_.Offset + mMappedRange_.Size) <= begin)
                || (mMappedRange_.Offset <= end && (mMappedRange_.Offset + mMappedRange_.Size) >= end))
            {
                Debug::Write("Trying to access mapped data from invalid function!", HIGH, INVALID_FUNCTION);
            }
        }
#endif
    }
}