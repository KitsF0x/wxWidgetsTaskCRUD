#pragma once

#include <wx/wx.h>
#include <wx/listctrl.h>
#include "TaskRepository.hpp"
#include "SelectedTaskDetailsPanel.hpp"

class ListViewOfTasks : public wxPanel
{
private:
	wxListView* listOfTasks;
	TaskRepository& tasks;
	SelectedTaskDetailsPanel* selectedTaskDetailsPanel;

public:
	ListViewOfTasks(
		wxWindow* parrent,
		TaskRepository& tasks,
		SelectedTaskDetailsPanel* selectedTaskDetailsPanel
	);
	void recreateList();
	wxListView* getListView();
};