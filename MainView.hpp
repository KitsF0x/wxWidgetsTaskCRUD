#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "TaskCreateView.hpp"

class MainView : public wxFrame
{
private:
	wxButton* taskCreateViewButton;
	TaskCreateView* taskCreateView;
public:
	MainView();
};