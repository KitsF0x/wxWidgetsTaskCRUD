#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/stattext.h>
#endif

#include <fmt/core.h>

#include "Task.hpp"

class TaskCreateView : public wxFrame
{
private:
	wxStaticText* titleLabel;
	wxStaticText* descriptionLabel;
	wxTextCtrl* titleTextInput;
	wxTextCtrl* descriptionTextInput;
	wxButton* addButton;

	wxStaticBoxSizer* titleBoxSizer;
	wxStaticBoxSizer* descriptionBoxSizer;
	wxStaticBoxSizer* staticBoxSizer;

	std::vector<Task>& tasks;
	Task taskToAdd;

	void initComponents();
	void initComponentsLayout();
	void assignActionsToComponents();
public:
	TaskCreateView(wxWindow* parrent, std::vector<Task>& tasks);
};