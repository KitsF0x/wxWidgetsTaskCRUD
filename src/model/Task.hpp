#pragma once

#include <string>

struct Task
{
	std::size_t id{ 0 };
	std::string title;
	std::string description;
};