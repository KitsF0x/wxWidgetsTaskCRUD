#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "TaskCreateView.hpp"

class Application : public wxApp
{
public:
	virtual bool OnInit() override;
};