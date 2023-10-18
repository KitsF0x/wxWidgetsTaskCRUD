#include "TaskIndexView.hpp"

TaskIndexView::TaskIndexView(wxWindow* parrent, std::vector<Task>& tasks)
	: BaseView(parrent, "List of tasks"), tasks(tasks)
{
	init();
	for (std::size_t i = 0; i < tasks.size(); i++)
	{
		listOfTasks->InsertItem(i, tasks.at(i).title);
		listOfTasks->SetItem(i, 1, tasks.at(i).description);
	}
	selectFirstElementIfExists();
}

void TaskIndexView::selectFirstElementIfExists()
{
	if (listOfTasks->GetSize().y != 0) {
		selectedTask = 0;
		listOfTasks->SetItemState(0, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
	}
}

void TaskIndexView::initComponents()
{
	listOfTasks = new wxListView(this, wxID_ANY);
	listOfTasks->InsertColumn(0, "Title");
	listOfTasks->SetColumnWidth(0, 120);
	listOfTasks->InsertColumn(1, "Description");
	listOfTasks->SetColumnWidth(1, 420);

	addTaskButton = new wxButton(this, wxID_ANY, "New");
	showTaskButton = new wxButton(this, wxID_ANY, "Show");
	editTaskButton = new wxButton(this, wxID_ANY, "Edit");;
	deleteTaskButton = new wxButton(this, wxID_ANY, "Delete");;

	selectedTaskTitle = new wxStaticText(this, wxID_ANY, "Task title: ");
	selectedTaskDescription = new wxStaticText(this, wxID_ANY, "Task description: ");
}

void TaskIndexView::initComponentsLayout()
{
	// Main
	wxStaticBoxSizer* mainSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "List of tasks");
	mainSizer->Add(listOfTasks, 0, wxEXPAND | wxALL, 5);

	// Details of the task
	wxStaticBoxSizer* detailsSizer = new wxStaticBoxSizer(wxVERTICAL, this);
	detailsSizer->Add(selectedTaskTitle, 1, wxEXPAND | wxALL, 5);
	detailsSizer->Add(selectedTaskDescription, 1, wxEXPAND | wxALL, 5);

	// Buttons
	wxStaticBoxSizer* buttonsSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "Operation buttons");
	buttonsSizer->Add(addTaskButton, 1);
	buttonsSizer->Add(showTaskButton, 1);
	buttonsSizer->Add(editTaskButton, 1);
	buttonsSizer->Add(deleteTaskButton, 1);

	// Add buttons to details
	detailsSizer->Add(buttonsSizer, 1, wxEXPAND | wxALL);
	mainSizer->Add(detailsSizer, 1, wxEXPAND | wxALL);

	SetSizerAndFit(mainSizer);
}

void TaskIndexView::assignActionsToComponents()
{
	addTaskButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		TaskCreateView* view = new TaskCreateView(this, tasks);
		view->Show();
		});
}