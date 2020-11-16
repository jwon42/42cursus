/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwon <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:50:53 by jwon              #+#    #+#             */
/*   Updated: 2020/11/16 16:38:24 by jwon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#define ERR_ARGC "* LOUD AND UNBEARABLE FEEDBACK NOISE *" 

std::string 	ft_string_upper(char *str)
{
	std::string ret = str;
	
	for (unsigned long i = 0 ; i < ret.length() ; i++)
		ret[i] = toupper(str[i]);
	return (ret);
}

int				main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << ERR_ARGC;
	else
		for (int i = 1 ; i < argc ; i++)
			std::cout << ft_string_upper(argv[i]);
	std::cout << std::endl;
	return (0);
}