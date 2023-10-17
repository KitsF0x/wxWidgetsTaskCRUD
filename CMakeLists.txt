cmake_minimum_required(VERSION 3.0.0)
project(wx-project)

find_package(wxWidgets CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_executable(${PROJECT_NAME} WIN32
	"main.cpp"
	"Application.cpp"
	"TaskCreateView.cpp"
 "MainView.cpp")
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PRIVATE 
	wx::core 
	wx::base
	fmt::fmt
)
