#include "TaskRepository.hpp"

std::vector<Task>::iterator TaskRepository::findTaskWithId(std::size_t id)
{
	return std::find_if(tasks.begin(), tasks.end(), [=](Task task) {
		return task.id == id;
		});
}

std::vector<Task> TaskRepository::getAll() const noexcept
{
	return tasks;
}

Task TaskRepository::getById(std::size_t id)
{
	auto found = findTaskWithId(id);
	if (found != tasks.end())
	{
		return *found;
	}
	throw TaskNotFoundException(id);
}

void TaskRepository::add(Task newTask)
{
	auto found = findTaskWithId(newTask.id);
	if (found != tasks.end())
	{
		// Task with id already exists
		throw TaskIdDuplicateException(newTask.id);
		return;
	}
	tasks.push_back(newTask);
}

void TaskRepository::updateById(std::size_t id, Task task)
{
	auto found = findTaskWithId(task.id);
	if (found != tasks.end())
	{
		found->title = task.title;
		found->description = task.description;
		return;
	}
	throw TaskNotFoundException(id);
}

void TaskRepository::deleteById(std::size_t id)
{
	auto found = findTaskWithId(id);
	if (found != tasks.end())
	{
		tasks.erase(found);
		return;
	}
	throw TaskNotFoundException(id);
}

std::size_t TaskRepository::size() const
{
	return tasks.size();
}