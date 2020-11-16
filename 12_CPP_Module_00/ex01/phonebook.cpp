/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:28:12 by jwon              #+#    #+#             */
/*   Updated: 2020/11/16 14:31:16 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Phonebook::Phonebook()
{
	_number_of_contacts = 0;
}

void	Phonebook::ascii_art()
{
std::cout << " _____ _____ _____ _____ _____ _____ _____ _____ _____ " << std::endl;
std::cout << "|  _  |  |  |     |   | |   __| __  |     |     |  |  |" << std::endl;
std::cout << "|   __|     |  |  | | | |   __| __ -|  |  |  |  |    -|" << std::endl;
std::cout << "|__|  |__|__|_____|_|___|_____|_____|_____|_____|__|__| by jwon" << std::endl;
std::cout << std::endl;
}

int		Phonebook::add_contact()
{
	if (_number_of_contacts < 8)
	{
		if (_contacts[_number_of_contacts].input_infomation(_number_of_contacts + 1) < 0)
			return (-1);
		_number_of_contacts++;
	}
	else
		std::cout << "Error: Phonebook memory is full." << std::endl;
	return (0);
}


int		Phonebook::select_contact()
{
	int		flag_isdigit;
	char	*idx = new char[2];

	flag_isdigit = 1;
	std::cout << "Please select an index : ";
	std::cin >> idx;
	if (std::cin.eof())
	{
		delete []idx;
		return (-1); 
	}
	for (size_t i = 0 ; i < strlen(idx) ; i++)
	{
		if (isdigit(idx[i]) == 0)
			flag_isdigit = 0;
	}
	if (!flag_isdigit || std::cin.fail() || atoi(idx) > _number_of_contacts || atoi(idx) <= 0)
	{
		std::cout << "Error: Invalid index value." << std::endl;
		std::cout << "─────────────────────────────────────────────" << std::endl;
		delete []idx;
		return (1);
	}
	_contacts[atoi(idx) - 1].view_contact_detail(atoi(idx));
	delete []idx;
	return (0);
}

int		Phonebook::view_phonebook()
{
	if (_number_of_contacts == 0)
		std::cout << "Error: Phonebook is empty." << std::endl;
	else
	{
		std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
		std::cout << "│     INDEX│FIRST NAME│ LAST NAME│  NICKNAME│" << std::endl;
		std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
		for (int i = 0 ; i < _number_of_contacts ; i++)
			_contacts[i].view_contact_list();	
		std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
		if (select_contact() < 0)
			return (-1);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return (0);
}
