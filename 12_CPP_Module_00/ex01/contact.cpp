/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:56:58 by jwon              #+#    #+#             */
/*   Updated: 2020/11/16 14:31:43 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

Contact::Contact()
{
	for (int i = 1 ; i < 8 ; i++)
		_contact_infomation[i] = std::string();
	_contact_fields[0] = "First name";
	_contact_fields[1] = "Last name";
	_contact_fields[2] = "Nickname";
	_contact_fields[3] = "Login";
	_contact_fields[4] = "Postal address";
	_contact_fields[5] = "Email address";
	_contact_fields[6] = "Phone number";
	_contact_fields[7] = "Birthday date";
	_contact_fields[8] = "Favorite meal";
	_contact_fields[9] = "Underwear color";
	_contact_fields[10] = "Darkest secret";
}

int		Contact::input_infomation(int idx)
{
	_idx = idx;
	std::cout << "─────────────────────────────────────────────" << std::endl;
	std::cout << "* Please enter a infomations. *" << std::endl;
	for (int i = 0 ; i < 11 ; i++)
	{
		while (_contact_infomation[i].size() == 0)
		{
			std::cout << _contact_fields[i] << " : ";
			std::getline(std::cin, _contact_infomation[i]);
			if (std::cin.eof())
				return (-1);
			if (_contact_infomation[i].size() == 0)
				std::cout << "Error: Invalid value." << std::endl;
		}
	}
	std::cout << "* Successfully registered. *" << std::endl;
	std::cout << "─────────────────────────────────────────────" << std::endl;
	return (0);
}

void	Contact::view_contact_list()
{
	std::cout << "│" << std::setw(10) << _idx;
	for (int i = 0 ; i < 3 ; i++)
	{
		if (_contact_infomation[i].size() < 10)
			std::cout << "│" << std::setw(10) << _contact_infomation[i];
		else
			std::cout << "│" << _contact_infomation[i].substr(0, 9) << ".";
	}
	std::cout << "│" << std::endl;
}

void	Contact::view_contact_detail(int idx)
{
	std::cout << "─────────────────────────────────────────────" << std::endl;
	std::cout << "This is the contact infomation for index [" << idx << "]" << std::endl;
	for (int i = 0 ; i < 11 ; i++)
		std::cout << _contact_fields[i] << " : " << _contact_infomation[i] << std::endl;
	std::cout << "─────────────────────────────────────────────" << std::endl;
}