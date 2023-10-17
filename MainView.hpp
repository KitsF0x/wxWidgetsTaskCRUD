#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "TaskCreateView.hpp"
#include "TaskIndexView.hpp"

class MainView : public wxFrame
{
private:
	wxButton* taskCreateViewButton;
	wxButton* taskIndexViewButton;
	wxStaticBoxSizer* staticBoxSizer;

	TaskCreateView* taskCreateView;
	TaskIndexView* taskIndexView;
public:
	MainView();
};