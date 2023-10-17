#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "TaskCreateView.hpp"
#include "TaskIndexView.hpp"
#include "IView.hpp"

class MainView : public wxFrame, IView
{
private:
	wxButton* taskCreateViewButton;
	wxButton* taskIndexViewButton;
	wxStaticBoxSizer* staticBoxSizer;

	std::vector<Task>& tasks;
public:
	MainView(std::vector<Task>& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};