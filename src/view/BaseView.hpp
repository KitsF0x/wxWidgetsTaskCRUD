#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class BaseView : public wxFrame
{
public:
	BaseView(wxWindow* parrent, const std::string& title);

	virtual void initComponents() = 0;
	virtual void initComponentsLayout() = 0;
	virtual void assignActionsToComponents() = 0;
	void init();
	virtual ~BaseView() = default;
};