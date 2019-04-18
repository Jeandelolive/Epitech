/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** lib_ncurses
*/

#include "lib_ncurses.hpp"

lib_ncurses::lib_ncurses()
{

}

void lib_ncurses::create_window()
{
    initscr();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
}

void lib_ncurses::display_box(int y, int x, int size_y, int size_x)
{
    WINDOW *boite;
    boite = subwin(stdscr, size_y, size_x, y, x);
	wborder(boite, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(boite);
}

void lib_ncurses::close_window()
{
    endwin();
}

lib_ncurses::~lib_ncurses()
{
    endwin();
}