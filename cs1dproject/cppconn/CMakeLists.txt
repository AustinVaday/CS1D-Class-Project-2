cmake_minimum_required(VERSION 3.1)

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(boost 1.57.0 COMPONENTS /usr/local/Cellar/boost/1.57.0/include/boost/) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(progname *.cpp *.h) 
    target_link_libraries(progname ${Boost_LIBRARIES})
endif()
