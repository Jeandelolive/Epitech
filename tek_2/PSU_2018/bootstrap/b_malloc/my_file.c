/*
** EPITECH PROJECT, 2019
** By Olivier Clement
** File description:
** my_file.c
*/

void malloc()
{
    my_putstr("Jo");
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}

int	my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}