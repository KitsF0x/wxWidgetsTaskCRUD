#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainView.hpp"
#include "TaskRepository.hpp"

class Application : public wxApp
{
private:
	TaskRepository tasks;

public:
	virtual bool OnInit() override;
};