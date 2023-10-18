#pragma once

#include <vector>
#include <algorithm>
#include "Task.hpp"
#include "TaskNotFoundException.hpp"
#include "TaskIdDuplicateException.hpp"

class TaskRepository
{
private:
	std::vector<Task> tasks;

	std::vector<Task>::iterator findTaskWithId(std::size_t id);
public:
	std::vector<Task> getAll() const noexcept;
	Task getById(std::size_t id);
	void add(Task newTask);
	void updateById(std::size_t id, Task task);
	void deleteById(std::size_t id);
	std::size_t size() const;
};