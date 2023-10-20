#include "SelectedTaskDetailsPanel.hpp"

SelectedTaskDetailsPanel::SelectedTaskDetailsPanel(wxWindow* parrent)
	: wxPanel(parrent, wxID_ANY)
{
	selectedTaskId = new wxStaticText(this, wxID_ANY, TASK_ID_LABEL);
	selectedTaskTitle = new wxStaticText(this, wxID_ANY, TASK_TITLE_LABEL);
	selectedTaskDescription = new wxStaticText(this, wxID_ANY, TASK_DESCRIPTION_LABEL);

	wxStaticBoxSizer* sizer = new wxStaticBoxSizer(wxVERTICAL, this);
	sizer->Add(selectedTaskId);
	sizer->Add(selectedTaskTitle);
	sizer->Add(selectedTaskDescription);
	SetSizer(sizer);
}

void SelectedTaskDetailsPanel::updateDetailsFromTask(Task task)
{
	selectedTaskId->SetLabelText(TASK_ID_LABEL + std::to_string(task.id));
	selectedTaskTitle->SetLabelText(TASK_TITLE_LABEL + task.title);
	selectedTaskDescription->SetLabelText(TASK_DESCRIPTION_LABEL + task.description);
}