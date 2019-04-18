/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** lib_ncurses
*/

#ifndef LIB_NCURSES_HPP_
#define LIB_NCURSES_HPP_

#include <ncurses.h>

class lib_ncurses {
	public:
        lib_ncurses();
        void create_window();
        void display_box(int y, int x, int size_y, int size_x);
        void close_window();
        ~lib_ncurses();
	protected:
	private:

};

#endif /* !LIB_NCURSES_HPP_ */
