#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <glext.h>

#include "debug.h"

typedef unsigned int bitfield;

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
    class GLCapabilities
    {
        HDC mHDC_;
        HGLRC mHGLRC_;
    public:
        GLCapabilities();
        ~GLCapabilities();
        void MakeContextCurrent();
	private:
		void LoadFunctions();
		void * LoadFunction(const char * FunctionName);
    };
}