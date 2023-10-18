#include "TaskIdDuplicateException.hpp"

TaskIdDuplicateException::TaskIdDuplicateException(std::size_t id) : id(id)
{
}

const char* TaskIdDuplicateException::what() const throw()
{
	std::string msg = "Task with id " + std::to_string(id) + " already exists";
	return msg.c_str();
}