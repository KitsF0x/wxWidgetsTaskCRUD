#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <vector>
#include <fmt/core.h>
#include "Task.hpp"
#include "IView.hpp"

class TaskIndexView : public wxFrame, IView
{
private:
	std::vector<Task>& tasks;
	wxStaticText* tasksLabel;

public:
	TaskIndexView(wxWindow* parrent, std::vector<Task>& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};