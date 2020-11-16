/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:16:14 by jwon              #+#    #+#             */
/*   Updated: 2020/11/16 14:32:30 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int		main(void)
{
	bool			working;
	Phonebook		phonebook;
	std::string		command;

	phonebook.ascii_art();
	working = true;
	while (working)
	{
		std::cout << "Please enter a command. (ADD, SEARCH OR EXIT) : ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			return (-1);
		if (!command.compare("ADD") && (phonebook.add_contact()) < 0)
			break ;
		else if (!command.compare("SEARCH") && (phonebook.view_phonebook() < 0))
			break ;
		else if (!command.compare("EXIT"))
			working = false;
	}
	return (0);
}