cmake_minimum_required(VERSION 3.14)
project(lists-ChristianRojasRojas)

set(CMAKE_CXX_STANDARD 14)

add_executable(lists-ChristianRojasRojas main.cpp mock/mocker.cpp structures/queue.h structures/stack.h structures/lists/circular.h structures/lists/forward.h structures/lists/linked.h structures/lists/list.h structures/lists/node.h)