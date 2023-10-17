#include "Application.hpp"

bool Application::OnInit()
{
	MainView* mainView = new MainView();
	mainView->Show(true);
	return true;
}