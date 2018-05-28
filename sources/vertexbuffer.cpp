#include <vertexbuffer.h>

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

    void VertexBuffer::SetData(GLsizei Size, const void * pData, BufferUsage Usage) const
    {
        CheckBound();
        glBufferData(GL_ARRAY_BUFFER, Size, pData, Usage);
    }

    void VertexBuffer::SetSubData(GLsizei Size, GLsizei Offset, const void * pData, BufferUsage Usage) const
    {
        CheckBound();
        glBufferSubData(GL_ARRAY_BUFFER, Offset, Size, pData);
    }

    void * VertexBuffer::MapBufferRange(GLsizei Size, GLsizei Offset, GLbitfield Access) const
    {
        CheckBound();
        glMapBufferRange(GL_ARRAY_BUFFER, Offset, Size, Access);
    }

    void * VertexBuffer::MapBuffer(GLbitfield Access) const
    {
        CheckBound();
        glMapBuffer(GL_ARRAY_BUFFER, Access);
    }

    void VertexBuffer::FlushMappedBufferRange(GLsizei Size, GLsizei Offset) const
    {
        CheckBound();
        glFlushMappedBufferRange(GL_ARRAY_BUFFER, Offset, Size);
    }

    void VertexBuffer::Unmap() const
    {
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

    void * VertexBuffer::GetBufferSubData(GLsizei Size, GLsizei Offset) const
    {
        CheckBound();
        void * data = malloc(Size);
        if (!data) return NULL;
        glGetBufferSubdata(GL_ARRAY_BUFFER, Offset, Size, data);
        return data;
    }

    void * VertexBuffer::GetBufferPointer() const
    {
        CheckBound();
        void * ptr = malloc(sizeof(GLsizei));
        glGetBufferPointerv(GL_ARRAY_BUFFER, GL_BUFFER_MAP_POINTER, &ptr);
        return ptr;
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
}