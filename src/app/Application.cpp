#include "Application.hpp"

bool Application::OnInit()
{
	//MainView* mainView = new MainView(nullptr, tasks);
	//mainView->Show(true);

	TaskIndexView* taskIndexView = new TaskIndexView(nullptr, tasks);
	taskIndexView->Show();
	return true;
}