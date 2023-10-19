#pragma once

#include <wx/wx.h>
#include "Task.hpp"

class SelectedTaskDetailsPanel : public wxPanel
{
private:
	wxStaticText* selectedTaskTitle;
	wxStaticText* selectedTaskDescription;

	const std::string TASK_TITLE_LABEL{ "Task title: " };
	const std::string TASK_DESCRIPTION_LABEL{ "Task description: " };
public:
	SelectedTaskDetailsPanel(wxWindow* parrent);
	void updateDetailsFromTask(Task task);
};