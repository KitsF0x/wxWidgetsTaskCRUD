add_library(view-main STATIC 
	"MainView.cpp"
)
target_link_libraries(view-main PUBLIC 	
	view-common
	model
)
target_include_directories(view-main PUBLIC .)