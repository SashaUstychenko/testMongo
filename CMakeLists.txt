cmake_minimum_required(VERSION 3.10)
project(testMongo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



find_package(PkgConfig REQUIRED)
find_package(Boost REQUIRED COMPONENTS system filesystem)


pkg_search_module(MONGOCXX REQUIRED libmongocxx)
pkg_search_module(BSONCXX REQUIRED libbsoncxx)


include_directories(${MONGOCXX_INCLUDE_DIRS})
include_directories(${BSONCXX_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

include_directories(${workspaceFolder}/**)
include_directories(/usr/local/include/mongocxx/v_noabi)
include_directories(/usr/local/include/bsoncxx/v_noabi)
include_directories(/usr/local/include/bsoncxx/v_noabi/bsoncxx/third_party/mnmlstc)

find_library(BCRYPT_LIBRARY bcrypt)

add_executable(testMongo main.cpp timer.cpp)
target_link_libraries(testMongo ${MONGOCXX_LIBRARIES} 
                                ${BCRYPT_LIBRARY}
                                ${BSONCXX_LIBRARIES} 
                                ${Boost_LIBRARIES})



