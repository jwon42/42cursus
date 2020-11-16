/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:20:04 by jwon              #+#    #+#             */
/*   Updated: 2020/11/16 14:21:53 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "main.hpp"

class Phonebook
{
	public:
	Phonebook();
	void	ascii_art();
	int		add_contact();
	int		select_contact();
	int		view_phonebook();

	private:
	Contact	_contacts[8];
	int		_number_of_contacts;
};

#endif