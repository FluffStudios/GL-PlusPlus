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

#pragma once

#include "glcapabilities.h"
#include "bufferutils.h"

#include <stdio.h>

namespace glpp
{
	/**
     * Representation of Vertex Array and its corresponding functionality
     * in OpenGL
     */
    class VertexArray
    {
		static GLuint sCurrentID_;
		GLuint mID_;
	public:
		/**
		 * Creates a new Vertex Array object
		 */
		VertexArray();

		/**
		 * Disposes of the vertex array object
		 */
		~VertexArray();

		/**
         * Binds the vertex array object
         * 
         * Rebinding a vertex array when it is already bound will
         * potentially cause performance issues on some platforms.
         */
		void Bind() const;

		/**
         * Unbinds the vertex array object
         * 
         * Unbinding a vertex array when none is bound will potentially
         * cause performance issues on some platforms.
         */
		void Unbind() const;

		/**
		 * Specifies the location and data format of an array of vertex
		 * attribute data.
		 * 
		 * @param Index			Index of vertex pointer
		 * @param Components	Number of components per vertex
		 * @param Type			Type of data in vertex attribute array
		 * @param Normalized	Flag for if data has been normalized
		 * @param Stride		Stride of data
		 * @param pData			Offset of data
		 * 
		 * If the array is not bound, it will affect the currently bound 
         * array.  If no array is bound, OpenGL will have an invalid usage
         * error code, as the default array cannot be modified.
		 */
		void VertexAttributePointer(uint32_t Index, uint32_t Components, DataType Type, bool Normalized, sizei Stride, const void * pData);

		/**
		 * Enables a vertex attribute array specified by a vertex buffer and
		 * vertex attribute pointer
		 * 
		 * @param Index			Index of vertex pointer
		 * 
		 * If the array is not bound, it will affect the currently bound 
         * array.  If no array is bound, OpenGL will have an invalid usage
         * error code, as the default array cannot be modified.
		 */
		void EnableVertexAttribute(uint32_t Index);

		/**
		 * Disables a vertex attribute array specified by a vertex buffer and
		 * vertex attribute pointer
		 * 
		 * @param Index			Index of vertex pointer
		 * 
		 * If the array is not bound, it will affect the currently bound 
         * array.  If no array is bound, OpenGL will have an invalid usage
         * error code, as the default array cannot be modified.
		 */
		void DisableVertexAttribute(uint32_t Index);
	private:
		void CheckBound() const;
		void CheckRebind() const;
    };
}