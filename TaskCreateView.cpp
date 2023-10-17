#include "TaskCreateView.hpp"

TaskCreateView::TaskCreateView() : wxFrame(NULL, wxID_ANY, "Application")
{
	initComponents();
	initSizer();
	assignActionsToComponents();

	Centre();
}

void TaskCreateView::initComponents()
{
	addTaskButton = new wxButton(this, wxID_ANY, "Click Me!", wxDefaultPosition);
	taskDetailsStaticText = new wxStaticText(this, wxID_ANY, "Hello", wxDefaultPosition);
	taskTitleTextCtrl = new wxTextCtrl(this, wxID_ANY, "");
	staticBoxSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "Create new task");

}

void TaskCreateView::initSizer()
{
	staticBoxSizer->Add(addTaskButton, 0, wxALL, 5);
	staticBoxSizer->Add(taskDetailsStaticText, 0, wxALL, 5);
	staticBoxSizer->Add(taskTitleTextCtrl, 0, wxALL, 5);
	SetSizerAndFit(staticBoxSizer);
}

void TaskCreateView::assignActionsToComponents()
{
	taskTitleTextCtrl->Bind(wxEVT_TEXT, [=](wxCommandEvent&) {
		taskDetailsStaticText->SetLabel(taskTitleTextCtrl->GetValue());
		task.title = taskTitleTextCtrl->GetValue().ToStdString();
		});
	addTaskButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		wxMessageBox(task.title);
		});
}
