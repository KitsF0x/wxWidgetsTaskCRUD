#include "IView.hpp"

void IView::init()
{
	initComponents();
	initComponentsLayout();
	assignActionsToComponents();
}