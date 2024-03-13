## vscode + MinGW64 + cmake

从官网上下载glew, glfw，注意要是x64的版本。glut官网没有64位的，google搜一个即可。

```
opengl
├── <build>
|
├── <External>
|		├─glew-2.2.0-win32//里面有x64的dll
|		|
|		├─glfw-3.3.8.bin.WIN64
|		|
|		├─glut-3.7
|
├── main.cpp
|
├── CMakeLists.txt
```

官网下载cmake，下载后可在terminal使用cmake -verson查看是否完成安装。

下面给出本人的cmake代码

```cmake
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
include_directories(${PROJECT_SOURCE_DIR}/External/glut-3.7/include)

# 生成可执行文件
add_executable(${PROJECT_NAME} 
    ./main.cpp
)
    
# 链接操作
target_link_libraries(${PROJECT_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/External/glfw-3.3.8.bin.WIN64/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3.a
    ${PROJECT_SOURCE_DIR}/External/glew-2.2.0-win32/glew-2.2.0/bin/Release/x64/glew32.dll
    ${PROJECT_SOURCE_DIR}/External/glut-3.7/glut64.dll
    OpenGL::GL
)
```

准备好CMakeLists.txt和main.cpp的代码后，就可以进行链接运行了。

```
cd build
cmake ..
make
.\OpenGLPrograming.exe
```

然后就g了，非常好，搞了两天，玉玉了。

报错是找不到glew32.dll，找不到glut64.dll。

红温了，直接把这几个dll扔system32，然后就可以了，不知道为啥，可能是windows的问题。
