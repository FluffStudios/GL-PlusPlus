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

#include <GLCapabilities.h>

namespace glpp
{
    GLCapabilities::GLCapabilities()
    {    
        mHGLRC_ = wglCreateContext(mHDC_);
        wglMakeCurrent(mHDC_, mHGLRC_);
		LoadFunctions();
    }

    GLCapabilities::~GLCapabilities()
    {
        wglMakeCurrent(NULL, NULL);
        wglDeleteContext(mHGLRC_);
    }

    void GLCapabilities::MakeContextCurrent()
    {
        wglMakeCurrent(mHDC_, mHGLRC_);
    }

	void GLCapabilities::LoadFunctions()
	{
		glGenBuffers = (PFNGLGENBUFFERSPROC)LoadFunction("wglGenBuffers");
		glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)LoadFunction("wglDeleteBuffers");
		glBindBuffer = (PFNGLBINDBUFFERPROC)LoadFunction("wglBindBuffer");
		glBindBufferRange = (PFNGLBINDBUFFERRANGEPROC)LoadFunction("wglBindBufferRange");
		glBindBufferBase = (PFNGLBINDBUFFERBASEPROC)LoadFunction("wglBindBufferBase");
		glBufferData = (PFNGLBUFFERDATAPROC)LoadFunction("wglBufferData");
		glBufferSubData = (PFNGLBUFFERSUBDATAPROC)LoadFunction("wglBufferSubdata");
		glMapBufferRange = (PFNGLMAPBUFFERRANGEPROC)LoadFunction("wglMapBufferRange");
		glMapBuffer = (PFNGLMAPBUFFERPROC)LoadFunction("wglMapBuffer");
		glFlushMappedBufferRange = (PFNGLFLUSHMAPPEDBUFFERRANGEPROC)LoadFunction("wglFlushMappedBufferRange");
		glUnmapBuffer = (PFNGLUNMAPBUFFERPROC)LoadFunction("wglUnmapBuffer");
		glCopyBufferSubData = (PFNGLCOPYBUFFERSUBDATAPROC)LoadFunction("wglCopyBufferSubdata");
		glIsBuffer = (PFNGLISBUFFERPROC)LoadFunction("wglIsBuffer");
		glGetBufferParamateriv = (PFNGLGETBUFFERPARAMETERIVPROC)LoadFunction("wglGetBufferParamateriv");
		glGetBufferParameteri64v = (PFNGLGETBUFFERPARAMETERI64VPROC)LoadFunction("wglGetBufferParameteri64v");
		glGetBufferSubdata = (PFNGLGETBUFFERSUBDATAPROC)LoadFunction("wglGetBufferSubdata");
		glGetBufferPointerv = (PFNGLGETBUFFERPOINTERVPROC)LoadFunction("wglGetBufferPointerv");

		glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)LoadFunction("wglGenVertexArrays");
		glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)LoadFunction("wglDeleteVertexArrays");
		glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)LoadFunction("wglBindVertexArray");
		glIsVertexArray = (PFNGLISVERTEXARRAYPROC)LoadFunction("wglIsVertexArray");
		glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)LoadFunction("wglVertexAttribPointer");
		glEnableVertexAttribArray = (PFNGLENABLEVERTEXATTRIBARRAYPROC)LoadFunction("wglEnableVertexAttribArray");
		glDisableVertexAttribArray = (PFNGLDISABLEVERTEXATTRIBARRAYPROC)LoadFunction("wglDisableVertexAttribArray");
		glDrawArraysInstanced = (PFNGLDRAWARRAYSINSTANCEDPROC)LoadFunction("wglDrawArraysInstanced");
		glDrawArraysIndirect = (PFNGLDRAWARRAYSINDIRECTPROC)LoadFunction("wglDrawArraysIndirect");
		glMultiDrawArrays = (PFNGLMULTIDRAWARRAYSPROC)LoadFunction("wglMultiDrawArrays");
		glDrawElementsInstanced = (PFNGLDRAWELEMENTSINSTANCEDPROC)LoadFunction("wglDrawElementsInstancedProc");
		glMultiDrawElements = (PFNGLMULTIDRAWELEMENTSPROC)LoadFunction("wglMultiDrawElements");
		glDrawRangeElements = (PFNGLDRAWRANGEELEMENTSPROC)LoadFunction("wglDrawRangeElements");
		glDrawElementsBaseVertex = (PFNGLDRAWELEMENTSBASEVERTEXPROC)LoadFunction("wglDrawElementsBaseVertex");
		glDrawRangeElementsBaseVertex = (PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC)LoadFunction("wglDrawRangeElementsBaseVertex");
		glDrawElementsInstancedBaseVertex = (PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)LoadFunction("wglDrawElementsInstancedBaseVertex");
		glDrawElementsIndirect = (PFNGLDRAWELEMENTSINDIRECTPROC)LoadFunction("wglDrawElementsIndirect");
		glMultiDrawElementsBaseVertex = (PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC)LoadFunction("wglMultiDrawElementsBaseVertex");
	}

	void * GLCapabilities::LoadFunction(const char * FunctionName)
	{
		void * addr = (void *) wglGetProcAddress(FunctionName);
		if (addr == (void*)0x0 || addr == (void *)0x1 || addr == (void *)0x2 || addr == (void *)0x3 || addr == (void *)-1)
		{
			HMODULE module = LoadLibraryA("opengl32.dll");
			addr = (void *)GetProcAddress(module, FunctionName);
		}
		return addr;
	}
}