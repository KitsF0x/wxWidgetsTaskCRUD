add_library(view-task.create STATIC 
	"TaskCreateView.cpp"
)
target_link_libraries(view-task.create PUBLIC 	
	view-common
	model
)
target_include_directories(view-task.create PUBLIC .)