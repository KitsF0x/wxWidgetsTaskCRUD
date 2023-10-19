#pragma once

#include "TaskCreateView.hpp"
#include "TaskIndexView.hpp"
#include "BaseView.hpp"
#include "TaskRepository.hpp"

class MainView : public BaseView
{
private:
	wxButton* taskCreateViewButton;
	wxButton* taskIndexViewButton;

	TaskRepository& tasks;
public:
	MainView(wxWindow* parrent, TaskRepository& tasks);
	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
};