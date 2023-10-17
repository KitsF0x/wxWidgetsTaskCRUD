#include "MainView.hpp"

MainView::MainView() : wxFrame(nullptr, wxID_ANY, "Task manager")
{
	taskCreateViewButton = new wxButton(this, wxID_ANY, "Create new task");
	taskCreateViewButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		taskCreateView = new TaskCreateView(this);
		taskCreateView->Show();
		});
}