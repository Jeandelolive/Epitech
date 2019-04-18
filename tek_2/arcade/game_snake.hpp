/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** game_snake
*/

#ifndef GAME_SNAKE_HPP_
#define GAME_SNAKE_HPP_

#include "map.hpp"
#include "snake.hpp"
#include "apple.hpp"

class game_snake {
	public:
        game_snake();
        ~game_snake();
	protected:
	private:
        map *_map;
        snake *_snake;
        apple *_apple;

};

#endif /* !GAME_SNAKE_HPP_ */
