#include "TaskIndexView.hpp"

TaskIndexView::TaskIndexView(wxWindow* parrent, std::vector<Task>& tasks)
	: BaseView(parrent, "List of tasks"), tasks(tasks)
{
	std::string allTasksAsString;

	for (auto&& el : tasks)
	{
		allTasksAsString += fmt::format("[title: \"{}\", description: \"{}\"]", el.title, el.description);
	}

	tasksLabel = new wxStaticText(this, wxID_ANY, allTasksAsString);
	init();
}

void TaskIndexView::initComponents()
{
}

void TaskIndexView::initComponentsLayout()
{
}

void TaskIndexView::assignActionsToComponents()
{
}