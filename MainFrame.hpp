#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include <wx/stattext.h>
#endif

#include "Task.hpp"

class MainFrame : public wxFrame
{
private:
	wxStaticText* staticText;
	wxButton* button;
	wxTextCtrl* textCtrl;
	wxStaticBoxSizer* staticBoxSizer;

	Task task;

public:
	MainFrame();
};