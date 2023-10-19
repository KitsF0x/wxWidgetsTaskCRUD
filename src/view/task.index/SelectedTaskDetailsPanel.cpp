#include "SelectedTaskDetailsPanel.hpp"

SelectedTaskDetailsPanel::SelectedTaskDetailsPanel(wxWindow* parrent)
	: wxPanel(parrent, wxID_ANY)
{
	selectedTaskTitle = new wxStaticText(this, wxID_ANY, TASK_TITLE_LABEL);
	selectedTaskDescription = new wxStaticText(this, wxID_ANY, TASK_DESCRIPTION_LABEL);

	wxStaticBoxSizer* sizer = new wxStaticBoxSizer(wxVERTICAL, this);
	sizer->Add(selectedTaskTitle);
	sizer->Add(selectedTaskDescription);
	SetSizer(sizer);
}

void SelectedTaskDetailsPanel::updateDetailsFromTask(Task task)
{
	selectedTaskTitle->SetLabelText(TASK_TITLE_LABEL + task.title);
	selectedTaskDescription->SetLabelText(TASK_DESCRIPTION_LABEL + task.description);
}