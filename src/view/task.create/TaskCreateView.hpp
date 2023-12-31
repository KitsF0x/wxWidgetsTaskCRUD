#pragma once

#include <fmt/core.h>

#include "BaseView.hpp"
#include "Task.hpp"
#include "TaskRepository.hpp"

class TaskCreateView : public BaseView
{
private:
	wxStaticText* titleLabel;
	wxStaticText* descriptionLabel;
	wxTextCtrl* titleTextInput;
	wxTextCtrl* descriptionTextInput;
	wxButton* addButton;

	TaskRepository& tasks;
	Task taskToAdd;

	void initComponents() override;
	void initComponentsLayout() override;
	void assignActionsToComponents() override;
public:
	TaskCreateView(wxWindow* parrent, TaskRepository& tasks);
};