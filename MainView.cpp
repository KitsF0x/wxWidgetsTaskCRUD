#include "MainView.hpp"

MainView::MainView() : wxFrame(nullptr, wxID_ANY, "Task manager")
{
	taskCreateViewButton = new wxButton(this, wxID_ANY, "Create new task");
	taskIndexViewButton = new wxButton(this, wxID_ANY, "Show all tasks");

	staticBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);

	taskCreateViewButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		taskCreateView = new TaskCreateView(this);
		taskCreateView->Show();
		});
	taskIndexViewButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		taskIndexView = new TaskIndexView(this);
		taskIndexView->Show();
		});

	staticBoxSizer->Add(taskCreateViewButton, 0, wxALL, 5);
	staticBoxSizer->Add(taskIndexViewButton, 0, wxALL, 5);
	SetSizerAndFit(staticBoxSizer);
}