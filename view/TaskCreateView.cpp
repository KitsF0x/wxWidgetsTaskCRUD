#include "TaskCreateView.hpp"

TaskCreateView::TaskCreateView(wxWindow* parrent, std::vector<Task>& tasks)
	: wxFrame(parrent, wxID_ANY, "Application"), tasks(tasks)
{
	init();
	Centre();
}

void TaskCreateView::initComponents()
{
	titleTextInput = new wxTextCtrl(this, wxID_ANY, "");
	descriptionTextInput = new wxTextCtrl(this, wxID_ANY, "");
	titleLabel = new wxStaticText(this, wxID_ANY, "Task title: ");
	descriptionLabel = new wxStaticText(this, wxID_ANY, "Task description: ");
	addButton = new wxButton(this, wxID_ANY, "Create task", wxDefaultPosition);
}

void TaskCreateView::initComponentsLayout()
{
	wxStaticBoxSizer* titleBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this, "Create new task");
	wxStaticBoxSizer* descriptionBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);
	wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);

	titleBoxSizer->Add(titleLabel, 0, wxALL, 5);
	titleBoxSizer->Add(titleTextInput, 0, wxALL, 5);
	staticBoxSizer->Add(titleBoxSizer, wxEXPAND, 0);

	descriptionBoxSizer->Add(descriptionLabel, 0, wxALL, 5);
	descriptionBoxSizer->Add(descriptionTextInput, 0, wxALL, 5);
	staticBoxSizer->Add(descriptionBoxSizer, wxEXPAND | wxALL, 0);

	staticBoxSizer->Add(addButton, 0, wxALL, 5);
	SetSizerAndFit(staticBoxSizer);
}

void TaskCreateView::assignActionsToComponents()
{
	// Set title of the task model
	titleTextInput->Bind(wxEVT_TEXT, [=](wxCommandEvent&) {
		taskToAdd.title = titleTextInput->GetValue().ToStdString();
		});
	// Set description of the task model
	descriptionTextInput->Bind(wxEVT_TEXT, [=](wxCommandEvent&) {
		taskToAdd.description = descriptionTextInput->GetValue().ToStdString();
		});
	// Show task model details
	addButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		tasks.push_back(taskToAdd);
		wxMessageBox("Added new task");
		});
}