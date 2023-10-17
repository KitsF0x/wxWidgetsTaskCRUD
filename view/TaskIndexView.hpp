#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <vector>
#include <fmt/core.h>
#include "Task.hpp"

class TaskIndexView : public wxFrame
{
private:
	std::vector<Task>& tasks;
	wxStaticText* tasksLabel;

public:
	TaskIndexView(wxWindow* parrent, std::vector<Task>& tasks);
};