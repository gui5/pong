cmake_minimum_required(VERSION 3.16)

project(PONG VERSION 0.0.0.1
                        DESCRIPTION "Another Game of Life Implementation"
                        LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

enable_testing()

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED) 

find_package(SFML COMPONENTS REQUIRED system window graphics network audio)

add_executable(pong src/main.cpp include/player.hpp include/field.hpp include/ball.hpp)
target_include_directories(pong PRIVATE "include")

set_target_properties(pong PROPERTIES
                          CXX_STANDARD 17
                          CXX_STANDARD_REQUIRED YES
                          CXX_EXTENSIONS NO)


target_link_libraries(pong PUBLIC Threads::Threads  X11 FLAC UDev OpenAL
sfml-system sfml-window sfml-network sfml-graphics freetype)

#---------------TESTS--------------------

# add_executable(seedtest test/SeedTest.cpp include/Seed.hpp)
# target_include_directories(seedtest PRIVATE "include")
# set_target_properties(seedtest PROPERTIES
#                           CXX_STANDARD 17
#                           CXX_STANDARD_REQUIRED YES
#                           CXX_EXTENSIONS NO)
# target_link_libraries(seedtest PUBLIC Threads::Threads  X11 FLAC UDev OpenAL
# sfml-system sfml-window sfml-network sfml-graphics freetype)

# add_test(SeedTest ../bin/seedtest)

# add_executable(cellfactorytest test/CellFactoryTest.cpp include/CellFactory.hpp)
# target_include_directories(cellfactorytest PRIVATE "include")
# set_target_properties(cellfactorytest PROPERTIES
#                           CXX_STANDARD 17
#                           CXX_STANDARD_REQUIRED YES
#                           CXX_EXTENSIONS NO)
# target_link_libraries(cellfactorytest PUBLIC Threads::Threads  X11 FLAC UDev OpenAL
# sfml-system sfml-window sfml-network sfml-graphics freetype)

# add_test(CellFactoryTest ../bin/cellfactorytest)% 