/*
** EPITECH PROJECT, 2019
** tek_2
** File description:
** manager
*/

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include <vector>

class manager {
    public:
        manager();
        void create_kitchen();
        ~manager();
    protected:
    private:
        std::vector<int> list_pid;
};

#endif /* !MANAGER_HPP_ */
