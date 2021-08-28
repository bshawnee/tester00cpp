/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 02:19:41 by bshawnee          #+#    #+#             */
/*   Updated: 2021/07/30 23:48:47 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>

Phonebook::Phonebook()
{
	this->_index = 0;
}

static bool	correctInput(std::string number, char letter, char greater)
{
	for (size_t i = 0; i < number.length(); i++)
	{
		if (letter == '0' && (number[i] < letter || number[i] > greater))
			return false;
		else if (letter == 'a' && ((number[i] < 'a' || number[i] > 'z') &&
		(number[i] < 'A' || number[i] > 'Z')))
			return false;
	}
	return true;
}

std::string	Phonebook::_getData(std::string data) const
{
	std::string tmp;
	std::cout << "Please enter" << data << ":" << std::endl;
	std::cin >> tmp;
	if (data == " Your phone number" || data == " index")
		while (!correctInput(tmp, '0', '9'))
		{
			std::cout <<"Error: invalid format" << std::endl;
			std::cin >> tmp;
		}
	else if (data == " Your last name" || data == " Your first name")
	{
		while (!correctInput(tmp, 'a', 'z'))
		{
				std::cout <<"Error: invalid format" << std::endl;
				std::cin >> tmp;
		}
	}
	return tmp;
}

void	Phonebook::add(void)
{
	this->_person[this->_index].setFirstName(Phonebook::_getData(" Your first name"));
	this->_person[this->_index].setLastName(Phonebook::_getData(" Your last name"));
	this->_person[this->_index].setNickName(Phonebook::_getData(" Your nickname"));
	this->_person[this->_index].setPhoneNumber(Phonebook::_getData(" Your phone number"));
	this->_person[this->_index].setDarkestSecret(Phonebook::_getData(" Your darkest secret"));
	this->_index += 1;
	if (this->_index == MAX_PAGE)
		this->_index = 0;
}

void	Phonebook::_printData(Contact &person) const
{
		std::cout << std::setw(16) << "First name: " << person.getFirstName() << std::endl;
		std::cout << std::setw(16) << "Last name: " << person.getLastName() << std::endl;
		std::cout << std::setw(16) << "Nick name: " << person.getNickName() << std::endl;
		std::cout << std::setw(16) << "Phone number: " << person.getPhoneNumber() << std::endl;
		std::cout << std::setw(16) << "Darkest Secret: " << person.getDarkestSecret() << std::endl;
}

static std::string	correct_wide(std::string str)
{
	if (str.length() >= 10)
	{
		str.replace(9, 1, 1, '.');
		str.resize(10);
	}
	return (str);
}

void	Phonebook::search(void)
{
	std::string tmp;
	std::cout << "|" << std::setw(10) << "INDEX" << "|";
	std::cout << std::setw(10) << "FIRST_NAME" << "|";
	std::cout << std::setw(10) << "LAST_NAME" << "|";
	std::cout << std::setw(10) << "NICKNAME" << "|" <<std::endl;
	for (int i = 0; i < MAX_PAGE; i++)
	{
		if (this->_person[i].getFirstName().length())
		{
			std::cout << "|" << std::setw(10) << i << "|";
			std::cout << std::setw(10) << correct_wide(_person[i].getFirstName()) << "|";
			std::cout << std::setw(10) << correct_wide(_person[i].getLastName()) << "|";
			std::cout << std::setw(10) << correct_wide(_person[i].getNickName()) << "|" << std::endl;
		}
	}
	if (this->_person[0].getFirstName().length() == 0)
		std::cout << "\nThere are no contacts in the phone book. " << "Use \"ADD\"" << std::endl;
	else if (this->_person[1].getFirstName().length() == 0)
		Phonebook::_printData(this->_person[0]);
	else
	{
		while (true)
		{
			int i = std::atoi(_getData(" index").c_str());
			if (i < 0 || i > MAX_PAGE)
				std::cout << "Error: invalid index" << std::endl;
			else
			{
				if (this->_person[i].getFirstName().length() == 0)
					std::cout << "Error: the person does not exist" << std::endl;
				else
				{
					Phonebook::_printData(this->_person[i]);
					break ;
				}
			}
		}
	}
}