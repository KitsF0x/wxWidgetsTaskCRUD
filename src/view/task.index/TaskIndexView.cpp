#include "TaskIndexView.hpp"

TaskIndexView::TaskIndexView(wxWindow* parrent, TaskRepository& tasks)
	: BaseView(parrent, "List of tasks"), tasks(tasks)
{
	init();
}

void TaskIndexView::initComponents()
{
	selectedTaskDetailsPanel = new SelectedTaskDetailsPanel(this);
	listViewOfTasks = new ListViewOfTasks(this, tasks, selectedTaskDetailsPanel);
	operationButtonsPanel = new OperationButtonsPanel(this, tasks, listViewOfTasks);
}

void TaskIndexView::initComponentsLayout()
{
	wxStaticBoxSizer* mainSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "List of tasks");
	mainSizer->Add(listViewOfTasks, 0, wxEXPAND | wxALL, 5);

	wxBoxSizer* detailsAndButtonsSizer = new wxBoxSizer(wxVERTICAL);

	detailsAndButtonsSizer->Add(selectedTaskDetailsPanel, 1, wxEXPAND | wxALL);
	detailsAndButtonsSizer->Add(operationButtonsPanel, 1, wxEXPAND | wxALL);
	mainSizer->Add(detailsAndButtonsSizer, 0, wxEXPAND | wxALL);

	SetSizerAndFit(mainSizer);
}

void TaskIndexView::assignActionsToComponents()
{
}