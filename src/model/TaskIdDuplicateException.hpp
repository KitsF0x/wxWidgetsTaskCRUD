#pragma once

#include <stdexcept>
#include <string>

class TaskIdDuplicateException : public std::exception
{
private:
	std::size_t id{ 0 };
public:
	TaskIdDuplicateException(std::size_t id);
	const char* what() const throw() override;
};