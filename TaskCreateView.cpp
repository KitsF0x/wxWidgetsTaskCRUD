#include "TaskCreateView.hpp"

TaskCreateView::TaskCreateView() : wxFrame(NULL, wxID_ANY, "Application")
{
	initComponents();
	initComponentsLayout();
	assignActionsToComponents();

	Centre();
}

void TaskCreateView::initComponents()
{
	titleTextInput = new wxTextCtrl(this, wxID_ANY, "");
	descriptionTextInput = new wxTextCtrl(this, wxID_ANY, "");
	titleLabel = new wxStaticText(this, wxID_ANY, "Task title: ");
	descriptionLabel = new wxStaticText(this, wxID_ANY, "Task description: ");
	addButton = new wxButton(this, wxID_ANY, "Create task", wxDefaultPosition);

	staticBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this, "Create new task");
	titleBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);
	descriptionBoxSizer = new wxStaticBoxSizer(wxVERTICAL, this);
}

void TaskCreateView::initComponentsLayout()
{
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
		task.title = titleTextInput->GetValue().ToStdString();
		});
	// Set description of the task model
	descriptionTextInput->Bind(wxEVT_TEXT, [=](wxCommandEvent&) {
		task.description = descriptionTextInput->GetValue().ToStdString();
		});
	// Show task model details
	addButton->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		std::string msg = fmt::format("Task title: {}\nTask description: {}",
		task.title, task.description);
	wxMessageBox(msg);
		});
}