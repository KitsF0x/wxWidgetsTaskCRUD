add_library(view STATIC 
	"MainView.cpp"
	"TaskCreateView.cpp"
	"TaskIndexView.cpp"
	"BaseView.cpp"
)
target_include_directories(view PUBLIC .)
target_link_libraries(view PRIVATE 	
	wx::core 
	wx::base
	fmt::fmt
	model
)