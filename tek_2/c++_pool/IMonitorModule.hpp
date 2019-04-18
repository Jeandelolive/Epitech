/*
** EPITECH PROJECT, 2019
** C++ Pool Rush 3
** File description:
** IMonitorModule.hpp
*/

#ifndef IMONITORMODULE_HPP_
#define IMONITORMODULE_HPP_

#include <iostream>
#include <ncurses.h>

class IMonitorModule {
	public:
		virtual ~IMonitorModule() {};
        virtual std::string getName() const = 0;
        virtual void setName(const std::string &name) = 0;
        virtual bool getDisplay() const = 0;
        virtual void setDisplay(bool display) = 0;
        virtual void displayText() = 0;
        virtual void displayGraphic() = 0;
};

#endif /* !IMONITORMODULE_HPP_ */
