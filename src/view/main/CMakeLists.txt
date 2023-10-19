add_library(view-main STATIC 
	"MainView.cpp"
)
target_link_libraries(view-main PUBLIC 	
	view-common
	model
	view-task.create
	view-task.index
)
target_include_directories(view-main PUBLIC .)