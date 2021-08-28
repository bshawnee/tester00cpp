/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 02:23:38 by bshawnee          #+#    #+#             */
/*   Updated: 2021/07/30 21:41:48 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define MAX_PAGE 8

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class Phonebook
{
private:
	int			_index;
	Contact		_person[MAX_PAGE];
	std::string	_getData(std::string data) const;
	void		_printData(Contact &person) const;
public:
	Phonebook();
	void		add(void);
	void		search(void);
};

#endif