#pragma once

#include <fmt/core.h>

#include "Task.hpp"
#include "BaseView.hpp"

class TaskCreateView : public BaseView
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