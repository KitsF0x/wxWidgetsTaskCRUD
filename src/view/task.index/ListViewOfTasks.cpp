#include "ListViewOfTasks.hpp"

ListViewOfTasks::ListViewOfTasks(
	wxWindow* parrent,
	TaskRepository& tasks,
	wxStaticText* selectedTaskTitle,
	wxStaticText* selectedTaskDescription)
	:
	wxPanel(parrent, wxID_ANY),
	tasks(tasks),
	selectedTaskTitle(selectedTaskTitle),
	selectedTaskDescription(selectedTaskDescription)
{
	listOfTasks = new wxListView(this, wxID_ANY);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(listOfTasks, 1, wxEXPAND | wxALL, 5);
	SetSizer(sizer);

	listOfTasks->Bind(wxEVT_COMMAND_LIST_ITEM_SELECTED, [=](wxListEvent& event) {
		selectedTaskTitle->SetLabelText(TASK_TITLE_LABEL + listOfTasks->GetItemText(event.GetIndex(), 1));
		selectedTaskDescription->SetLabelText(TASK_DESCRIPTION_LABEL + listOfTasks->GetItemText(event.GetIndex(), 2));
		});
	recreateList();
}

void ListViewOfTasks::recreateList()
{
	listOfTasks->ClearAll();
	listOfTasks->InsertColumn(0, "Id");
	listOfTasks->InsertColumn(1, "Title");
	listOfTasks->SetColumnWidth(1, 120);
	listOfTasks->InsertColumn(2, "Description");
	listOfTasks->SetColumnWidth(2, 420);

	auto tasksVec = tasks.getAll();
	for (std::size_t i = 0; i < tasks.size(); i++)
	{
		listOfTasks->InsertItem(i, std::to_string(tasksVec.at(i).id));
		listOfTasks->SetItem(i, 1, tasksVec.at(i).title);
		listOfTasks->SetItem(i, 2, tasksVec.at(i).description);
	}
}

wxListView* ListViewOfTasks::getListView()
{
	return listOfTasks;
}