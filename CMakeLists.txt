cmake_minimum_required(VERSION 3.10)
project(testMongo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)

pkg_search_module(BCRYPT REQUIRED libcrypt)
pkg_search_module(MONGOCXX REQUIRED libmongocxx)
pkg_search_module(BSONCXX REQUIRED libbsoncxx)

include_directories(${MONGOCXX_INCLUDE_DIRS})
include_directories(${BSONCXX_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${BCRYPT_INCLUDE_DIRS})

add_executable(testMongo main.cpp)
target_link_libraries(testMongo ${MONGOCXX_LIBRARIES} ${BSONCXX_LIBRARIES} ${BCRYPT_LIBRARIES} ${Boost_LIBRARIES})

