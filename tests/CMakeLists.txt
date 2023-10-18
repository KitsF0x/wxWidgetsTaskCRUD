add_executable(${PROJECT_NAME}-tests 
	"TaskRepositoryTest.cpp"
)
target_link_libraries(${PROJECT_NAME}-tests PRIVATE 
	GTest::gtest 
	GTest::gtest_main
	model
)