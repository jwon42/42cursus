#ifndef CONTACT_HPP
# define CONTACT_HPP

# include "main.hpp"

class Contact
{
	public:
	Contact();
	int		input_infomation(int idx);
	void	view_contact_list();
	void	view_contact_detail(int	idx);

	private:
	int				_idx;
	std::string		_contact_infomation[11];
	std::string		_contact_fields[11];
};

#endif