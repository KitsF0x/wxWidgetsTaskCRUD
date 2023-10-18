#include "Application.hpp"

bool Application::OnInit()
{
	MainView* mainView = new MainView(nullptr, tasks);
	mainView->Show(true);
	return true;
}