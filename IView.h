#pragma once
#ifndef IVIEW_H
#define IVIEW_H
#include <string>

class IView
{
protected:
	virtual ~IView() = default;

	virtual void showText(const std::string& text) = 0;
	virtual void showTextWithSection(const std::string& text) = 0;
	virtual void showTextWithConfirmation(const std::string& text) = 0;
	virtual std::string parseNum(double value) = 0;
};

#endif // IVIEW_H
