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