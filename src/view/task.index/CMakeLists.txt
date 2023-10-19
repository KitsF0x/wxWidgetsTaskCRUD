add_library(view-task.index STATIC 
	"TaskIndexView.cpp"
	"OperationButtonsPanel.cpp"
	"ListViewOfTasks.cpp"
	"SelectedTaskDetailsPanel.cpp"
)
target_link_libraries(view-task.index PUBLIC 	
	view-task.create
	view-common
)
target_include_directories(view-task.index PUBLIC .)