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

#include "glcapabilities.h"

namespace glpp
{
    enum BufferUsage : GLuint
	{
		STREAM_DRAW = GL_STREAM_DRAW,
		STREAM_READ = GL_STREAM_READ,
		STREAM_COPY = GL_STREAM_COPY,
		STATIC_DRAW = GL_STATIC_DRAW,
		STATIC_READ = GL_STATIC_READ,
		STATIC_COPY = GL_STATIC_COPY,
		DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
		DYNAMIC_READ = GL_DYNAMIC_READ,
		DYNAMIC_COPY = GL_DYNAMIC_COPY
	};

    enum MapAccess : GLuint
    {
        MAP_READ = GL_MAP_READ_BIT,
        MAP_WRITE = GL_MAP_WRITE_BIT,
        MAP_INVALIDATE_BUFFER = GL_MAP_INVALIDATE_BUFFER_BIT,
        MAP_INVALIDATE_RANGE = GL_MAP_INVALIDATE_RANGE_BIT,
        MAP_FLUSH_EXPLICIT = GL_MAP_FLUSH_EXPLICIT_BIT,
        MAP_UNSYNCHRONIZED = GL_MAP_UNSYNCHRONIZED_BIT
    };

	enum BufferParameter : GLuint
	{
		BUFFER_SIZE = GL_BUFFER_SIZE,
		BUFFER_USAGE = GL_BUFFER_USAGE,
		BUFFER_ACCESS = GL_BUFFER_ACCESS,
		BUFFER_ACCESS_FLAGS = GL_BUFFER_ACCESS_FLAGS,
		BUFFER_MAPPED = GL_BUFFER_MAPPED,
		BUFFER_MAP_OFFSET = GL_BUFFER_MAP_OFFSET,
		BUFFER_MAP_LENGTH = GL_BUFFER_MAP_LENGTH
	};

	enum DataType : GLuint
	{
		BYTE = GL_BYTE,
		UBYTE = GL_UNSIGNED_BYTE,
		SHORT = GL_SHORT,
		USHORT = GL_UNSIGNED_SHORT,
		INT = GL_INT,
		UINT = GL_UNSIGNED_INT
	};

	static MapAccess operator | (const MapAccess LHS, const MapAccess RHS);
}