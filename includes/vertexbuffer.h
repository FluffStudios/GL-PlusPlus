#pragma once

#include "glcapabilities.h"
#include "bufferutils.h"

#include <stdio.h>

namespace glpp
{
    class VertexBuffer
    {
        static GLuint sCurrentID_;
        GLuint mID_;
    public:
        VertexBuffer();
        ~VertexBuffer();
        void Bind() const;
        void Unbind() const;
        void SetData(GLsizei Size, const void * pData, BufferUsage Usage) const;
		void SetSubData(GLsizei Size, GLsizei Offset, const void * pData, BufferUsage Usage) const;
		void * MapBufferRange(GLsizei Size, GLsizei Offset, GLbitfield Access) const;
        void * MapBuffer(GLbitfield Access) const;
        void FlushMappedBufferRange(GLsizei Size, GLsizei Offset) const;
        void Unmap() const;
        GLint GetBufferParameter(BufferParameter Parameter) const;
        GLint64 GetBufferParameter64(BufferParameter Parameter) const;
        void * GetBufferSubData(GLsizei Size, GLsizei Offset) const;
        void * GetBufferPointer() const;
    private:
        void CheckBound() const;
        void CheckRebind() const;
    };
}