#pragma once

#include <stdexcept>
#include <string>

class TaskNotFoundException : public std::exception
{
private:
	std::size_t id{ 0 };
public:
	TaskNotFoundException(std::size_t id);
	const char* what() const throw() override;
};