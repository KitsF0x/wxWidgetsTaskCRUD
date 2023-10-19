add_library(view-task.index STATIC 
	"TaskIndexView.cpp"
)
target_link_libraries(view-task.index PUBLIC 	
	view-task.create
)
target_include_directories(view-task.index PUBLIC .)