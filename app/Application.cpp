#include "Application.hpp"

bool Application::OnInit()
{
	MainView* mainView = new MainView(tasks);
	mainView->Show(true);
	return true;
}