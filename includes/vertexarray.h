#pragma once

#include "glcapabilities.h"
#include "bufferutils.h"

namespace glpp
{
    class VertexArray
    {
		static GLuint sCurrentID_;
		GLuint mID_;
	public:
		VertexArray();
		~VertexArray();
		void Bind() const;
		void Unbind() const;
		void VertexAttributePointer(GLuint Index, GLuint Components, DataType Type, GLsizei Stride, const GLvoid * pData);
		void EnableVertexAttribute(GLuint Index);
		void DisableVertexAttribute(GLuint Index);
	private:
		void CheckBound() const;
		void CheckRebind() const;
    };
}