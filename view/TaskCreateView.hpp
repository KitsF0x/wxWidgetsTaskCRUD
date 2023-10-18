#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/stattext.h>
#endif

#include <fmt/core.h>

#include "Task.hpp"
#include "IView.hpp"

class TaskCreateView : public wxFrame, IView
{
private:
	wxStaticText* titleLabel;
	wxStaticText* descriptionLabel;
	wxTextCtrl* titleTextInput;
	wxTextCtrl* descriptionTextInput;
	wxButton* addButton;

	std::vector<Task>& tasks;
	Task taskToAdd;

	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
public:
	TaskCreateView(wxWindow* parrent, std::vector<Task>& tasks);
};