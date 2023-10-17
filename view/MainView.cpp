#include "MainView.hpp"

MainView::MainView(std::vector<Task>& tasks) 
	: wxFrame(nullptr, wxID_ANY, "Task manager"), tasks(tasks)
{
	init();
}

void MainView::initComponents()
{
	taskCreateViewButton = new wxButton(this, wxID_ANY, "Create new task");
	taskIndexViewButton = new wxButton(this, wxID_ANY, "Show all tasks");
	staticBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);
}

void MainView::initComponentsLayout()
{
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
