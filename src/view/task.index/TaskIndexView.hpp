#pragma once

#include <vector>
#include <fmt/core.h>

#include "Task.hpp"
#include "BaseView.hpp"
#include "TaskCreateView.hpp"
#include "OperationButtonsPanel.hpp"
#include "ListViewOfTasks.hpp"
#include "SelectedTaskDetailsPanel.hpp"

#include <wx/listctrl.h>

class TaskIndexView : public BaseView
{
private:
	TaskRepository& tasks;

	OperationButtonsPanel* operationButtonsPanel;
	ListViewOfTasks* listViewOfTasks;
	SelectedTaskDetailsPanel* selectedTaskDetailsPanel;

	void updateListOfTasks();
public:
	TaskIndexView(wxWindow* parrent, TaskRepository& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};