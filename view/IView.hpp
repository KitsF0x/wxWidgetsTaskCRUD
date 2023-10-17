#pragma once

class IView
{
public:
	virtual void initComponents() = 0;
	virtual void initComponentsLayout() = 0;
	virtual void assignActionsToComponents() = 0;
	void init();
	virtual ~IView() = default;
};