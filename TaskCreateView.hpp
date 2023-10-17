#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/stattext.h>
#endif

#include "Task.hpp"

class TaskCreateView : public wxFrame
{
private:
	wxStaticText* taskDetailsStaticText;
	wxButton* addTaskButton;
	wxTextCtrl* taskTitleTextCtrl;
	wxStaticBoxSizer* staticBoxSizer;

	Task task;

	void initComponents();
	void initSizer();
	void assignActionsToComponents();
public:
	TaskCreateView();
};