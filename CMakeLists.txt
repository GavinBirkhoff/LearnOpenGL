# 配置 CMake 版本（一般CLion会在创建项目时自动配置此选项，这里可以无需和笔者一致，默认即可）
cmake_minimum_required(VERSION 3.19)
# 生成项目（默认即可）
project(LearnOpenGL)
# 配置C++版本（默认即可）
set(CMAKE_CXX_STANDARD 14)

# 定义源代码文件列表变量
set(COMMON_SOURCE_FILES
        src/glad.c
        # 添加其他共享的源代码文件
    )

# 创建库文件
add_library(CommonLib STATIC ${COMMON_SOURCE_FILES})

# 定义可执行文件源代码文件列表
set(EXECUTABLE_SOURCE_FILES
        src/main.cpp
        # 添加其他可执行文件源代码文件
    )

# 头文件路径配置
include_directories(./includes) # 这里的路径指向项目目录下的 include 文件夹
include_directories(/usr/local/include) # 此处的路径指向的是系统安装GLFW头文件的位置，通常为通过 make install 安装的头文件为此路径

# 设置库文件所在目录
link_directories(./lib)
link_directories(/usr/local/lib) # 安装GLFW时默认安装库文件位置
# 链接编译需要的系统框架
link_libraries("-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")
# 添加源文件（这里的 main.cpp 是你的C++源码文件）
add_executable(LearnOpenGL ${EXECUTABLE_SOURCE_FILES}) # glad.c 一定要填进去！
# 链接 GLFW 库
target_link_libraries(LearnOpenGL CommonLib glfw3)
