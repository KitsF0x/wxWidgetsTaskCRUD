#pragma once

#include "TaskCreateView.hpp"
#include "TaskIndexView.hpp"
#include "BaseView.hpp"

class MainView : public BaseView
{
private:
	wxButton* taskCreateViewButton;
	wxButton* taskIndexViewButton;

	std::vector<Task>& tasks;
public:
	MainView(wxWindow* parrent, std::vector<Task>& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};