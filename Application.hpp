#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainView.hpp"

class Application : public wxApp
{
private:
	std::vector<Task> tasks;
public:
	virtual bool OnInit() override;
};