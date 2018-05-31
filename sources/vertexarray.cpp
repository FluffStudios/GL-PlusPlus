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
    Nick Clark      30-MAY-18       Creation of Vertex Array abstraction
 */

#include "vertexarray.h"

namespace glpp
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &mID_);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &mID_);
        mID_ = 0;
    }

    void VertexArray::Bind() const
    {
        CheckRebind();
        glBindVertexArray(mID_);
    }

    void VertexArray::Unbind() const
    {
        CheckRebind();
        glBindVertexArray(0);
    }

    void VertexArray::VertexAttributePointer(uint32_t Index, uint32_t Components, DataType Type, bool Normalized, sizei Stride, const void * pData)
    {
        CheckBound();
        glVertexAttribPointer(Index, Components, Type, Normalized, Stride, pData);
    }

    void VertexArray::EnableVertexAttribute(uint32_t Index)
    {
        CheckBound();
        glEnableVertexAttribArray(Index);
    }

    void VertexArray::DisableVertexAttribute(uint32_t Index)
    {
        CheckBound();
        glDisableVertexAttribArray(Index);
    }

    void VertexArray::CheckBound() const
    {
#ifdef _DEBUG
        if (sCurrentID_ != mID_ || sCurrentID_ == 0) 
        {
            char buffer[1024];
            memset(buffer, 0, 1024 * sizeof(char));
            sprintf(buffer, "VertexArray not bound.  Active Array: %d", mID_);
            Debug::Write(buffer, HIGH, BAD_DATA);
        }
#endif
    }

    void VertexArray::CheckRebind() const
    {
#ifdef _DEBUG
		if (sCurrentID_ == mID_) Debug::Write("VertexArray already bound.", MEDIUM, PERFORMANCE);
		sCurrentID_ = mID_;
#endif
    }
}