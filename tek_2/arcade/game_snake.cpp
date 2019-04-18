/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** game_snake
*/

#include "game_snake.hpp"

game_snake::game_snake()
{
    this->_apple = new apple();
    this->_map = new map();
    this->_snake = new snake();
}

game_snake::~game_snake()
{

}