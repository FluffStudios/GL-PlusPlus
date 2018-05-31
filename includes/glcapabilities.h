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
    Nick Clark      30-MAY-18       Creation of GLCapabilities class
 */

#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <glext.h>

#include "debug.h"

typedef unsigned char uint8_t;
typedef char uint8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned long long uint64_t;
typedef long long uint64_t;
typedef int sizei;

#pragma region buffers

PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
PFNGLBINDBUFFERBASEPROC glBindBufferBase;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLBUFFERSUBDATAPROC glBufferSubData;
PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
PFNGLMAPBUFFERPROC glMapBuffer;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
PFNGLUNMAPBUFFERPROC glUnmapBuffer;
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
PFNGLISBUFFERPROC glIsBuffer;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParamateriv;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubdata;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;

#pragma endregion

#pragma region arrays

PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLISVERTEXARRAYPROC glIsVertexArray;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;

#pragma endregion

namespace glpp
{
    /**
     * Loads and manages the OpenGL capabilities on Windows platforms
     */
    class GLCapabilities
    {
        HDC mHDC_;
        HGLRC mHGLRC_;
    public:
        /**
         * Loads the functions for OpenGL and makes this context current
         */
        GLCapabilities();

        /**
         * Dispose of the current GL context
         */
        ~GLCapabilities();

        /**
         * Makes the GL context current
         */
        void MakeContextCurrent();
	private:
        /**
         * Loads all OpenGL functions
         */
		void LoadFunctions();

        /**
         * Loads OpenGL function by name from libraries
         */
		void * LoadFunction(const char * FunctionName);
    };
}