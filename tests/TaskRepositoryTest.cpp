#include <gtest/gtest.h>

#include "Task.hpp"
#include "TaskRepository.hpp"

class TaskRepositoryTest : public ::testing::Test {
protected:
	TaskRepository repository;
};

TEST_F(TaskRepositoryTest, AddingNewTaskShouldIncreaseTaskCount) {
	Task task1{ 1, "Task 1", "Description 1" };
	Task task2{ 2, "Task 2", "Description 2" };

	repository.add(task1);
	repository.add(task2);

	auto tasks = repository.getAll();
	ASSERT_EQ(tasks.size(), 2);
}

TEST_F(TaskRepositoryTest, AddingDuplicateIdShouldThrowException) {
	Task task{ 1, "Task 1", "Description 1" };
	repository.add(task);

	Task duplicateTask{ 1, "Task 2", "Description 2" };

	ASSERT_THROW(repository.add(duplicateTask), TaskIdDuplicateException);
}

TEST_F(TaskRepositoryTest, GettingNonexistentTaskShouldThrowException) {
	ASSERT_THROW(repository.getById(1), TaskNotFoundException);
}

TEST_F(TaskRepositoryTest, UpdatingExistingTaskShouldModifyTask) {
	Task task{ 1, "Task 1", "Description 1" };
	repository.add(task);

	Task updatedTask{ 1, "Updated Task 1", "Updated Description 1" };
	repository.updateById(1, updatedTask);

	auto retrievedTask = repository.getById(1);
	ASSERT_EQ(retrievedTask.title, "Updated Task 1");
	ASSERT_EQ(retrievedTask.description, "Updated Description 1");
}

TEST_F(TaskRepositoryTest, DeletingExistingTaskShouldReduceTaskCount) {
	Task task{ 1, "Task 1", "Description 1" };
	repository.add(task);

	repository.deleteById(1);

	auto tasks = repository.getAll();
	ASSERT_TRUE(tasks.empty());
}

TEST_F(TaskRepositoryTest, DeletingNonexistentTaskShouldThrowException) {
	ASSERT_THROW(repository.deleteById(1), TaskNotFoundException);
}