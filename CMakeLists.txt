set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")
cmake_minimum_required(VERSION 3.14)
project(2048_Oyunu) # Proje adını güncelledik

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(SFML)

add_executable(2048 main.cpp oyun.cpp tahta.cpp)

target_link_libraries(2048 sfml-graphics sfml-window sfml-system)

if(WIN32)
    add_custom_command(TARGET 2048 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:2048> #  2048 yaptık
        $<TARGET_FILE_DIR:2048>      # 2048 yaptık
        COMMAND_EXPAND_LISTS
    )
endif()