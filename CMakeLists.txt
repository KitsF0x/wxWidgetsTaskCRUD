cmake_minimum_required(VERSION 3.0.0)
project(wx-project)

find_package(wxWidgets CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(app)
add_subdirectory(model)
add_subdirectory(view)