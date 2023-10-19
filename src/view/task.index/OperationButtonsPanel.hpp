#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/listctrl.h>
#endif

#include "TaskCreateView.hpp"
#include "ListViewOfTasks.hpp"

class OperationButtonsPanel : public wxPanel
{
private:
	wxButton* addTaskButton;
	wxButton* showTaskButton;
	wxButton* editTaskButton;
	wxButton* deleteTaskButton;

	TaskRepository& tasks;
	wxWindow* parrent;
	ListViewOfTasks* listOfTasks;

	void updateListOfTasks();
public:
	OperationButtonsPanel(wxWindow* parrent, TaskRepository& tasks, ListViewOfTasks* listOfTasks);
};