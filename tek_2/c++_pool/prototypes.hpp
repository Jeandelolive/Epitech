/*
** EPITECH PROJECT, 2019
** C++ Pool Rush 3
** File description:
** prototypes.hpp
*/

#ifndef PROTOTYPES_HPP_
	#define PROTOTYPES_HPP_

# define WIN_WIDTH 1100
# define WIN_HEIGHT 800
# define MOD_SIZE 300

# include <iostream>
# include <SFML/Window.hpp>
# include <SFML/System.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>

std::string getKernelVersion();
std::string getHostName();
std::string getUserName();
int manageArgs(int, char **);

/* GRAPHIC */
int graphicMode();
void eventLoop(sf::RenderWindow win, sf::Event event);
void displayLoop(sf::RenderWindow win);
std::string getOsName();
void display_cpu_name(std::string content);
void textMode();

#endif /* !PROTOTYPES_HPP_ */
