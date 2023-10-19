#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "TaskRepository.hpp"

class ListViewOfTasks : public wxPanel
{
private:
	wxListView* listOfTasks;

	TaskRepository& tasks;

	wxStaticText* selectedTaskTitle;
	wxStaticText* selectedTaskDescription;

	const std::string TASK_TITLE_LABEL{ "Task title: " };
	const std::string TASK_DESCRIPTION_LABEL{ "Task description: " };

public:
	ListViewOfTasks(
		wxWindow* parrent,
		TaskRepository& tasks,
		wxStaticText* selectedTaskTitle,
		wxStaticText* selectedTaskDescription
	);
	void recreateList();
	wxListView* getListView();
};