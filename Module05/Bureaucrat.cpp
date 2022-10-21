/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:05:52 by ybendavi          #+#    #+#             */
/*   Updated: 2022/10/21 05:07:25 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>

		Bureaucrat::Bureaucrat(void): _name("John Doe")
		{
			std::cout << "Bureaucrat "
					<< getName()
					<< " created."
					<< std::endl;
		}

		Bureaucrat::Bureaucrat(const  Bureaucrat& copy)
		{
			*this = copy;
			std::cout << "Bureaucrat "
					<< getName()
					<< " copied."
					<< std::endl;
		}

		Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
		{
			std::cout << "Bureaucrat "
					<< getName()
					<< " created whith name."
					<< std::endl;
		}

		Bureaucrat::~Bureaucrat(void)
		{
			std::cout << "Bureaucrat "
					<< getName()
					<< " destroyed."
					<< std::endl;
		}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Bureaucrat equal to Bureaucrat." << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

std::ostream  & operator<<(std::ostream & o, Bureaucrat const & i)
{
	return (o);
}
