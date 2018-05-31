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

#pragma once

#include "glcapabilities.h"
#include "bufferutils.h"

#include <stdio.h>

namespace glpp
{
    /**
     * Representation of Vertex Buffer and its corresponding functionality
     * in OpenGL
     */
    class VertexBuffer
    {
        static GLuint sCurrentID_;
        GLuint mID_;
    public:
        /**
         * Creates a new Vertex Buffer object
         */
        VertexBuffer();
        
        /**
         * Disposes of the vertex buffer object
         */
        ~VertexBuffer();

        /**
         * Binds the vertex buffer object
         * 
         * Rebinding a vertex buffer when it is already bound will
         * potentially cause performance issues on some platforms.
         */
        void Bind() const;

        /**
         * Unbinds the vertex buffer object
         * 
         * Unbinding a vertex buffer when none is bound will potentially
         * cause performance issues on some platforms.
         */
        void Unbind() const;

        /**
         * Sets the data in the vertex buffer
         * 
         * @param Size      Size of buffer
         * @param pData     Pointer to the data
         * @param Usage     Usage type of the data
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        void SetData(sizei Size, const void * pData, BufferUsage Usage) const;

        /**
         * Sets the data in the vertex buffer
         * 
         * @param Size      Size of data loaded into buffer
         * @param Offset    Offset to load to in buffer
         * @param pData     Pointer to the data
         * @param Usage     Usage type of the data
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
		void SetSubData(sizei Size, sizei Offset, const void * pData, BufferUsage Usage) const;

        /**
         * Maps a range of the buffer to a pointer in memory
         * 
         * @param Size      Size of chunk to map to memory
         * @param Offset    Offset of buffer to map to memory
         * @param Access    Logical OR of access flags for buffer
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
		void * MapBufferRange(sizei Size, sizei Offset, MapAccess Access) const;

        /**
         * Maps a buffer to a pointer in memory
         * 
         * @param Access    Logical OR of access flags for buffer
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        void * MapBuffer(MapAccess Access) const;

        /**
         * Notifies OpenGL that modifications have been made the mapping
         * of the VertexBuffer
         * 
         * @param Size      Size of range to flush
         * @param Offset    Offset of range to flush
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        void FlushMappedBufferRange(sizei Size, GLsizei Offset) const;

        /**
         * Unmaps the currently bound buffer. After unmapping, the pointer
         * originally returned may or may not continue to contain the data 
         * of the buffer depending on the underlying OpenGL implementation.
         * It is not recommended that code uses this memory address after
         * unmapping, as it may cause a read or write error.
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        void Unmap() const;

        /**
         * Gets the parameter of a buffer
         * 
         * @param Parameter     Parameter to query value of
         * @return              Value of parameter
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        GLint GetBufferParameter(BufferParameter Parameter) const;

        /**
         * Gets the parameter of a buffer as a 64 bit integer
         * 
         * @param Parameter     Parameter to query value of
         * @return              Value of parameter
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        GLint64 GetBufferParameter64(BufferParameter Parameter) const;

        /**
         * Returns a pointer to the buffer subdata
         * 
         * @param Size      Size of range to get data of
         * @param Offset    Offset of range to get data of
         * @return          Pointer to data.  Data must be free'd when done, as it
         *                  is heap allocated.
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        void * GetBufferSubData(sizei Size, GLsizei Offset) const;

        /**
         * Returns a pointer to the buffer
         * 
         * @return          Pointer to data.  Data must be free'd when done, as it
         *                  is heap allocated.
         * 
         * If the buffer is not bound, it will affect the currently bound 
         * buffer.  If no buffer is bound, OpenGL will have an invalid usage
         * error code, as the default buffer cannot be modified.
         */
        void * GetBufferPointer() const;
    private:
        void CheckBound() const;
        void CheckRebind() const;
    };
}