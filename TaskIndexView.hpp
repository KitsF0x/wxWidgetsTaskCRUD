#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <vector>
#include "Task.hpp"

class TaskIndexView : public wxFrame
{
private:
	std::vector<Task> tasks;

public:
	TaskIndexView(wxWindow* parrent);
};