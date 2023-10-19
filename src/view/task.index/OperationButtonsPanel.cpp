#include "OperationButtonsPanel.hpp"

void OperationButtonsPanel::updateListOfTasks()
{
	listOfTasks->getListView()->ClearAll();
	listOfTasks->getListView()->InsertColumn(0, "Id");
	listOfTasks->getListView()->InsertColumn(1, "Title");
	listOfTasks->getListView()->SetColumnWidth(1, 120);
	listOfTasks->getListView()->InsertColumn(2, "Description");
	listOfTasks->getListView()->SetColumnWidth(2, 420);

	auto tasksVec = tasks.getAll();
	for (std::size_t i = 0; i < tasks.size(); i++)
	{
		listOfTasks->getListView()->InsertItem(i, std::to_string(tasksVec.at(i).id));
		listOfTasks->getListView()->SetItem(i, 1, tasksVec.at(i).title);
		listOfTasks->getListView()->SetItem(i, 2, tasksVec.at(i).description);
	}
}

OperationButtonsPanel::OperationButtonsPanel(wxWindow* parrent, TaskRepository& tasks, ListViewOfTasks* listOfTasks)
	: wxPanel(parrent, wxID_ANY), parrent(parrent), tasks(tasks), listOfTasks(listOfTasks)
{
	addTaskButton = new wxButton(this, wxID_ANY, "New");
	showTaskButton = new wxButton(this, wxID_ANY, "Show");
	editTaskButton = new wxButton(this, wxID_ANY, "Edit");
	deleteTaskButton = new wxButton(this, wxID_ANY, "Delete");

	// Buttons
	wxStaticBoxSizer* buttonsSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "Operation buttons");
	buttonsSizer->Add(addTaskButton);
	buttonsSizer->Add(showTaskButton);
	buttonsSizer->Add(editTaskButton);
	buttonsSizer->Add(deleteTaskButton);
	SetSizerAndFit(buttonsSizer);

	addTaskButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		TaskCreateView* view = new TaskCreateView(parrent, this->tasks);
		view->Show();

		view->Bind(wxEVT_CLOSE_WINDOW, [=](wxCloseEvent& event) {
			updateListOfTasks();
			event.Skip();
			});
		});
}