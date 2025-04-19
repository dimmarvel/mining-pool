cmake_minimum_required(VERSION 3.26)
project(mining-pool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(BOOST_ROOT /usr/local)

find_package(Boost 1.81.0 REQUIRED COMPONENTS system)

# Подключаем подпроекты
add_subdirectory(libs/server)
add_subdirectory(app/server)