add_library(view-common STATIC "BaseView.cpp")
target_link_libraries(view-common PUBLIC 	
	wx::core 
	wx::base
)
target_include_directories(view-common PUBLIC .)