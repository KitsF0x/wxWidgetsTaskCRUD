#include "MainView.hpp"

MainView::MainView(wxWindow* parrent, TaskRepository& tasks)
	: BaseView(parrent, "wxWidgets task CRUD"), tasks(tasks)
{
	init();
}

void MainView::initComponents()
{
	taskCreateViewButton = new wxButton(this, wxID_ANY, "Create new task");
	taskIndexViewButton = new wxButton(this, wxID_ANY, "Show all tasks");
}

void MainView::initComponentsLayout()
{
	wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);

	staticBoxSizer->Add(taskCreateViewButton, 0, wxALL, 5);
	staticBoxSizer->Add(taskIndexViewButton, 0, wxALL, 5);
	SetSizerAndFit(staticBoxSizer);
}

void MainView::assignActionsToComponents()
{
	taskCreateViewButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		TaskCreateView* taskCreateView = new TaskCreateView(this, this->tasks);
		taskCreateView->Show();
		});
	taskIndexViewButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		TaskIndexView* taskIndexView = new TaskIndexView(this, this->tasks);
		taskIndexView->Show();
		});
}