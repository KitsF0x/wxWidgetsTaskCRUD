add_library(model STATIC
	"TaskNotFoundException.cpp"
	"TaskIdDuplicateException.cpp"
	"TaskRepository.cpp"
)
target_include_directories(model PUBLIC .)