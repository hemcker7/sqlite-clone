cmake_minimum_required(VERSION 3.16)

project(SQLiteClone)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(sqlite_clone
    src/main.cpp
    src/InputBuffer.cpp
    src/MetaCommand.cpp
    src/Statement.cpp
    src/Table.cpp
    src/Executor.cpp
)