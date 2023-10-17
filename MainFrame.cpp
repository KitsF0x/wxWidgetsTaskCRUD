#include "MainFrame.hpp"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Application")
{
	// Init components
	button = new wxButton(this, wxID_ANY, "Click Me!", wxDefaultPosition);
	staticText = new wxStaticText(this, wxID_ANY, "Hello", wxDefaultPosition);
	textCtrl = new wxTextCtrl(this, wxID_ANY, "");

	// Init sizer
	staticBoxSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, "Create new task");

	// Add compontents to sizer
	staticBoxSizer->Add(button, 0, wxALL, 5);
	staticBoxSizer->Add(staticText, 0, wxALL, 5);
	staticBoxSizer->Add(textCtrl, 0, wxALL, 5);
	SetSizerAndFit(staticBoxSizer);

	// Assign actions
	textCtrl->Bind(wxEVT_TEXT, [=](wxCommandEvent&) {
		staticText->SetLabel(textCtrl->GetValue());
		task.title = textCtrl->GetValue().ToStdString();
		});
	button->Bind(wxEVT_BUTTON, [=](wxCommandEvent&) {
		wxMessageBox(task.title);
		});
	// Center window
	Centre();
}