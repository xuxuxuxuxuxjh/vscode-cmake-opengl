cmake_minimum_required(VERSION 3.0)
project(OpenGLPrograming)

find_package(OpenGL REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-finput-charset=UTF-8")  
set(CMAKE_C_FLAGS "-finput-charset=UTF-8")  

# 添加头文件目录
include_directories(include)
include_directories(${PROJECT_SOURCE_DIR}/External/glfw-3.3.8.bin.WIN64/glfw-3.3.8.bin.WIN64/include/GLFW)
include_directories(${PROJECT_SOURCE_DIR}/External/glew-2.2.0-win32/glew-2.2.0/include/GL)
include_directories(${PROJECT_SOURCE_DIR}/External/config/glut-3.7/include)

# 生成可执行文件
add_executable(${PROJECT_NAME} 
    ./main.cpp
)
    
# 链接操作
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/External/glfw-3.3.8.bin.WIN64/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3.a
    ${PROJECT_SOURCE_DIR}/External/glew-2.2.0-win32/glew-2.2.0/bin/Release/x64/glew32.dll
    # ${PROJECT_SOURCE_DIR}/External/freeglut-3.4.0/freeglut-3.4.0/glut32.dll
    ${PROJECT_SOURCE_DIR}/External/config/glut-3.7/glut64.dll
    OpenGL::GL
)