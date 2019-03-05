cmake_minimum_required(VERSION 2.6)
project(LGen)

set(CMAKE_CXX_FLAGS "-std=c++14")

add_definitions(-D_GLFW_X11=1 -D_GLFW_GLX=1 -D_GLFW_USE_OPENGL=1)

include_directories(
	${CMAKE_SOURCE_DIR}/glfw/include
	${CMAKE_SOURCE_DIR}/LParse/include
	${CMAKE_SOURCE_DIR}/LParse/src
	${CMAKE_SOURCE_DIR}/LRender/include
	${CMAKE_SOURCE_DIR}/LRender/src
	${CMAKE_SOURCE_DIR}/src
)

file(GLOB_RECURSE all_SRCS
	"${PROJECT_SOURCE_DIR}/glfw/src/x11_init.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/x11_monitor.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/x11_window.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/xkb_unicode.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/linux_joystick.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/posix_time.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/posix_thread.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/glx_context.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/egl_context.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/osmesa_context.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/context.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/init.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/input.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/monitor.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/vulkan.c"
	"${PROJECT_SOURCE_DIR}/glfw/src/window.c"

	"${PROJECT_SOURCE_DIR}/src/*.cpp"
	"${PROJECT_SOURCE_DIR}/LParse/src/*.cpp"
	"${PROJECT_SOURCE_DIR}/LRender/src/*.cpp"
	"${PROJECT_SOURCE_DIR}/LRender/src/*.c"
)

add_executable(LGen ${all_SRCS})

target_link_libraries(LGen GL X11 dl pthread)