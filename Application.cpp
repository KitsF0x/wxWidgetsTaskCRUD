#include "Application.hpp"

bool Application::OnInit()
{
	TaskCreateView* taskCreateView = new TaskCreateView();
	taskCreateView->Show(true);
	return true;
}