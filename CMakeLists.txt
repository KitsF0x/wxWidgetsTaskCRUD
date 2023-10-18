cmake_minimum_required(VERSION 3.0.0)
project(wx-project)

find_package(wxWidgets CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)