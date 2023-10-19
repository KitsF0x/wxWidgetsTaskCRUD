#include "BaseView.hpp"

BaseView::BaseView(wxWindow* parrent, const std::string& title)
	: wxFrame(parrent, wxID_ANY, title)
{
}
void BaseView::init()
{
	initComponents();
	initComponentsLayout();
	assignActionsToComponents();
}