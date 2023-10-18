#include "TaskNotFoundException.hpp"

TaskNotFoundException::TaskNotFoundException(std::size_t id) : id(id)
{
}

const char* TaskNotFoundException::what() const throw()
{
	std::string msg = "Not found task with id " + std::to_string(id);
	return msg.c_str();
}