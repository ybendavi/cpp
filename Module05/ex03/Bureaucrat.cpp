/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 05:05:52 by ybendavi          #+#    #+#             */
/*   Updated: 2022/10/22 19:52:27 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

		Bureaucrat::Bureaucrat(void): _name("John Doe"), _grade(150)
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
			if (grade < 1)
				throw GradeTooHighException();
			else if (grade > 150)
				throw GradeTooLowException();
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

std::string	Bureaucrat::getName(void) const
		{
			return (this->_name);
		}

int		Bureaucrat::getGrade(void) const
		{
			return (this->_grade);
		}

void		Bureaucrat::setName(std::string name)
		{
			this->_name = name;
		}

void		Bureaucrat::setGrade(int grade)
		{
			if (grade < 1)
				throw GradeTooHighException();
			if (grade > 150)
				throw GradeTooLowException();
			this->_grade = grade;
		}

void		Bureaucrat::inc(void)
		{
			setGrade(getGrade() - 1);
		}

void		Bureaucrat::dec(void)
		{
			setGrade(getGrade() + 1);
		}

void		Bureaucrat::signForm(Form& i)
		{
			try
			{
				i.beSigned(*this);
				std::cout << this->getName()
						<< " signed "
						<< i.getName()
						<< " ."
						<< std::endl;

			}
			catch (std::exception &e)
			{
				std::cout << this->getName()
						<< " couldn't sign "
						<< i.getName()
						<< " because "
						<< e.what()
						<< std::endl;
			}
		}

void		Bureaucrat::executeForm(Form const & form)
{
		try
		{
			form.execute(*this);
			std::cout << this->getName()
					<< " executed "
					<< form.getName()
					<< std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << this->getName()
					<< " couldn't execute "
					<< form.getName()
					<< " because "
					<< e.what()
					<< std::endl;
		}
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
		{
			return ("Grade is too high.");
		}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
		{
			return ("Grade is too low.");
		}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &src)
		{
			std::cout << "Bureaucrat equal to Bureaucrat." << std::endl;
			if (this == &src)
				return (*this);
			setName(src.getName());
			setGrade(src.getGrade());
			return (*this);
		}

std::ostream  & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}
