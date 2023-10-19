#pragma once

#include <vector>
#include <fmt/core.h>

#include "Task.hpp"
#include "BaseView.hpp"
#include "TaskCreateView.hpp"

#include <wx/listctrl.h>

class TaskIndexView : public BaseView
{
private:
	TaskRepository& tasks;
	wxListView* listOfTasks;

	wxStaticText* selectedTaskTitle;
	wxStaticText* selectedTaskDescription;

	wxButton* addTaskButton;
	wxButton* showTaskButton;
	wxButton* editTaskButton;
	wxButton* deleteTaskButton;

	std::size_t selectedTask{ 0 };

	void updateListOfTasks();
public:
	TaskIndexView(wxWindow* parrent, TaskRepository& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};