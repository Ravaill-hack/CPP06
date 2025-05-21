/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:38:23 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/21 11:05:56 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                              CANONIC FORM                                ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter & toCopy)
{
	(void)toCopy;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& toCopy)
{
	(void)toCopy;
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	ScalarConverter::convert(std::string nb)
{
	int					nb_i = 0;
	float				nb_f = 0.0f;
	double				nb_d = 0.0;
	char				nb_c = 0;
	enType				ttype = FindType(nb);
	std::stringstream	ss(nb);
	
	try
	{
		if (nb.empty())
			throw ScalarConverter::EmptyInput();
		switch (ttype)
		{
			case T_FLOAT:
				ss >> nb_f;
				printFromFloat(nb_f);
				break;
			case T_INT:
				ss >> nb_i;
				printFromInt(nb_i);
				break;
			case T_CHAR:
				nb_c = nb.at(0);
				printFromChar(nb_c);
				break;
			case T_DOUBLE:
				ss >> nb_d;
				printFromDouble(nb_d);
				break;
			default:
				;
		}
	}
	catch(const ScalarConverter::EmptyInput& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(const ScalarConverter::IncorrectSyntax& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               EXCEPTIONS                                 ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

const char * ScalarConverter::IncorrectSyntax::what() const throw()
{
	return ("Error: syntax error");
}

const char * ScalarConverter::EmptyInput::what() const throw()
{
	return ("Error: empty input");
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                               NON MEMBERS                                ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

bool	isFloat(std::string nb)
{
	if (nb.empty())
		return (false);
		
	std::stringstream	ss(nb);
	float				nb_f;
	ss >> nb_f;
	if (ss.fail())
		return (false);
	return (true);
}

bool	isDouble(std::string nb)
{
	if (nb.empty())
		return (false);
		
	std::stringstream	ss(nb);
	double				nb_d;
	ss >> nb_d;
	if (ss.fail())
		return (false);
	return (true);
}

bool	isChar(std::string nb)
{
	if (nb.empty())
		return (false);
	if (nb.at(0) >= -128 && nb.at(0) <= 127 && isdigit(nb.at(0)) == false)
		return (true);
	return (false);
}

bool	isInt(std::string nb)
{
	if (nb.empty())
		return (false);
		
	std::stringstream	ss(nb);
	int					nb_i;
	ss >> nb_i;
	if (ss.fail())
		return (false);
	return (true);
}

enType	FindType(std::string nb)
{
	if (isChar(nb))
		return (T_CHAR);
	else if (isFloat(nb))
		return (T_FLOAT);
	else if (isDouble(nb))
		return (T_DOUBLE);
	else if (isInt(nb))
		return (T_INT);
	else
	{
		throw ScalarConverter::IncorrectSyntax();
		return (T_INVALID);
	}
}

void	printFromFloat(float nb_f)
{
	char	nb_c = static_cast<char>(nb_f);
	int		nb_i = static_cast<int>(nb_f);
	double	nb_d = static_cast<double>(nb_f);
	
	std::cout << "char: '";
	if (nb_c >= 32 && nb_c <= 126)
		std::cout << nb_c << "'" << std::endl;
	else
		std::cout << "Non displayable" <<std::endl;
	std::cout << "int: " << nb_i << std::endl;
	std::cout << "float: " << nb_f << std::endl;
	std::cout << "double: " << nb_d << std::endl;
}

void	printFromChar(char nb_c)
{
	float	nb_f = static_cast<float>(nb_c);
	int		nb_i = static_cast<int>(nb_c);
	double	nb_d = static_cast<double>(nb_c);
	
	std::cout << "char: '";
	if (nb_c >= 32 && nb_c <= 126)
		std::cout << nb_c << "'" << std::endl;
	else
		std::cout << "Non displayable" <<std::endl;
	std::cout << "int: " << nb_i << std::endl;
	std::cout << "float: " << nb_f << std::endl;
	std::cout << "double: " << nb_d << std::endl;
}

void	printFromDouble(double nb_d)
{
	float	nb_f = static_cast<float>(nb_d);
	int		nb_i = static_cast<int>(nb_d);
	char	nb_c = static_cast<char>(nb_d);
	
	std::cout << "char: '";
	if (nb_c >= 32 && nb_c <= 126)
		std::cout << nb_c << "'" << std::endl;
	else
		std::cout << "Non displayable" <<std::endl;
	std::cout << "int: " << nb_i << std::endl;
	std::cout << "float: " << nb_f << std::endl;
	std::cout << "double: " << nb_d << std::endl;
}

void	printFromInt(int nb_i)
{
	char	nb_c = static_cast<char>(nb_i);
	float	nb_f = static_cast<float>(nb_i);
	double	nb_d = static_cast<double>(nb_i);
	
	std::cout << "char: '";
	if (nb_c >= 32 && nb_c <= 126)
		std::cout << nb_c << "'" << std::endl;
	else
		std::cout << "Non displayable" <<std::endl;
	std::cout << "int: " << nb_i << std::endl;
	std::cout << "float: " << nb_f << std::endl;
	std::cout << "double: " << nb_d << std::endl;
}
