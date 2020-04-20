cmake_minimum_required(VERSION 3.14)
project(lists-ChristianRojasRojas)

set(CMAKE_CXX_STANDARD 14)

include_directories(structures)
include_directories(structures/lists)
include_directories(structures/lists/iterators)
include_directories(mock)
include_directories(test)

add_executable(lists-ChristianRojasRojas main.cpp mock/mocker.cpp mock/mocker.h structures/queue.h structures/stack.h structures/lists/circular.h structures/lists/forward.h structures/lists/linked.h structures/lists/list.h structures/lists/node.h structures/lists/iterators/bidirectional_iterator.h structures/lists/iterators/forward_iterator.h)