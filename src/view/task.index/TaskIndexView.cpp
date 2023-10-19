#include "TaskIndexView.hpp"

TaskIndexView::TaskIndexView(wxWindow* parrent, TaskRepository& tasks)
	: BaseView(parrent, "List of tasks"), tasks(tasks)
{
	init();
}

void TaskIndexView::updateListOfTasks()
{
}

void TaskIndexView::initComponents()
{
	updateListOfTasks();

	selectedTaskTitle = new wxStaticText(this, wxID_ANY, "");
	selectedTaskDescription = new wxStaticText(this, wxID_ANY, "");

	listViewOfTasks = new ListViewOfTasks(this, tasks, selectedTaskTitle, selectedTaskDescription);
	operationButtonsPanel = new OperationButtonsPanel(this, tasks, listViewOfTasks);
}

void TaskIndexView::initComponentsLayout()
{
	// Main
	wxStaticBoxSizer* mainSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "List of tasks");
	mainSizer->Add(listViewOfTasks, 0, wxEXPAND | wxALL, 5);

	// Details of the task
	wxStaticBoxSizer* detailsSizer = new wxStaticBoxSizer(wxVERTICAL, this);
	detailsSizer->Add(selectedTaskTitle, 1, wxEXPAND | wxALL, 5);
	detailsSizer->Add(selectedTaskDescription, 1, wxEXPAND | wxALL, 5);

	// Add buttons to details
	detailsSizer->Add(operationButtonsPanel, 1, wxEXPAND | wxALL);
	mainSizer->Add(detailsSizer, 1, wxEXPAND | wxALL);

	SetSizerAndFit(mainSizer);
}

void TaskIndexView::assignActionsToComponents()
{
}