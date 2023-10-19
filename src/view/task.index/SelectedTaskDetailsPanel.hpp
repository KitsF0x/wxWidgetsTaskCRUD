#pragma once

#include <wx/wx.h>
#include "Task.hpp"

class SelectedTaskDetailsPanel : public wxPanel
{
private:
	wxStaticText* selectedTaskId;
	wxStaticText* selectedTaskTitle;
	wxStaticText* selectedTaskDescription;

	const std::string TASK_ID_LABEL{ "Task id in repository: " };
	const std::string TASK_TITLE_LABEL{ "Task title: " };
	const std::string TASK_DESCRIPTION_LABEL{ "Task description: " };
public:
	SelectedTaskDetailsPanel(wxWindow* parrent);
	void updateDetailsFromTask(Task task);
};