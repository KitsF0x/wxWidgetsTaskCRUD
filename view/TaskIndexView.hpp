#pragma once

#include <vector>
#include <fmt/core.h>

#include "Task.hpp"
#include "BaseView.hpp"

class TaskIndexView : public BaseView
{
private:
	std::vector<Task>& tasks;
	wxStaticText* tasksLabel;

public:
	TaskIndexView(wxWindow* parrent, std::vector<Task>& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};