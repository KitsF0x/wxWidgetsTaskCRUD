add_executable(${PROJECT_NAME} WIN32
	"Application.cpp"
	"main.cpp"
)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_link_libraries(${PROJECT_NAME} PRIVATE 
	wx::core 
	wx::base
	model
	view
)