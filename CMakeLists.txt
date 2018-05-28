cmake_minimum_required( VERSION 3.0 )

project( gl-plusplus )

FILE ( GLOB_RECURSE SRC sources/* )

add_library( gl-plusplus ${SRC} )

find_package( OpenGL )

target_link_libraries( gl-plusplus PUBLIC ${OPENGL_gl_LIBRARY})
target_include_directories( gl-plusplus PUBLIC includes/ )
