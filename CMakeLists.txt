cmake_minimum_required(VERSION 4.0)
project(Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test
        Main.cpp
        appicon.rc)

# Set the produced executable file name to "PyTha++"
set_target_properties(Test PROPERTIES OUTPUT_NAME "PyTha++")

if (MINGW)
    target_link_options(Test PRIVATE -static -static-libgcc -static-libstdc++)
endif()
