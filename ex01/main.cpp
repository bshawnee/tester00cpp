/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 02:24:40 by bshawnee          #+#    #+#             */
/*   Updated: 2021/07/30 23:39:57 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int		main(void)
{
	Phonebook	book;
	std::string	command;

	std::cout << "Please enter: \"EXIT\", \"ADD\" or \"SEARCH\"" << std::endl;
	while (std::cin >> command)
	{
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
			book.add();
		else if (command == "SEARCH")
			book.search();
		else
			std::cout << "Error: Unknown command" << std::endl;
		std::cout << "Please enter: \"EXIT\", \"ADD\" or \"SEARCH\"" << std::endl;
	}
	return 0;
}