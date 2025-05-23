/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:38:23 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/23 13:37:11 by lmatkows         ###   ########.fr       */
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
	int					nb_i;
	float				nb_f;
	double				nb_d;
	char				nb_c;
	
	try
	{
		enType				ttype = FindType(nb);
		std::stringstream	ss(nb);
		if (nb.empty())
			throw ScalarConverter::EmptyInput();
		switch (ttype)
		{
			case T_CHAR:
				nb_c = nb.at(0);
				printFromChar(nb_c);
				break;
			case T_INT:
				ss >> nb_i;
				printFromInt(nb_i);
				break;
			case T_DOUBLE:
				ss >> nb_d;
				printFromDouble(nb_d, nb);
				break;
			case T_FLOAT:
				ss >> nb_f;
				printFromFloat(nb_f, nb);
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
	return ("char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible");
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
	if (nb == "+inff" || nb == "-inff" || nb == "nanf")
		return (true);
	if (nb.find('f') == nb.npos || nb.find('f') != nb.rfind('f'))
		return (false);
	if (nb.find('.') == nb.npos || nb.find('.') != nb.rfind('.'))
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
	char leftover;
	if (nb.empty())
		return (false);
	if (nb == "+inf" || nb == "-inf" || nb == "nan")
		return (true);
	if (nb.find('.') == nb.npos || nb.find('.') != nb.rfind('.'))
		return (false);	
	std::stringstream	ss(nb);
	double				nb_d;
	ss >> nb_d;
	if (ss.fail())
		return (false);
	if (ss >> leftover)
		return false;
	return (true);
}

bool	isChar(std::string nb)
{
	if (nb.empty())
		return (false);
	if ((nb.at(0) >= -128 && nb.at(0) <= 127 && isdigit(nb.at(0)) == false) && nb.length() == 1)
		return (true);
	return (false);
}

bool	isInt(std::string nb)
{
	if (nb.empty())
		return (false);
	char leftover;
	std::stringstream	ss(nb);
	int					nb_i;
	ss >> nb_i;
	if (ss.fail())
		return (false);
	if (ss >> leftover)
		return false;
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

void	printFromFloat(float nb_f, std::string nb)
{
	char	nb_c = static_cast<char>(nb_f);
	int		nb_i = static_cast<int>(nb_f);
	double	nb_d = static_cast<double>(nb_f);
	
	
	if (nb != "+inff" && nb != "-inff" && nb != "nanf")
	{
		std::cout << "char: ";
		if (nb_f < -128 || nb_f > 127)
			std::cout << "impossible" << std::endl;
		else if (nb_c >= 32 && nb_c <= 126)
			std::cout << "'" << nb_c << "'" << std::endl;
		else
			std::cout << "Non displayable" <<std::endl;
		std::cout << "int: " << nb_i << std::endl;
		std::cout << "float: " << nb_f;
		if (static_cast<float>(static_cast<int>(nb_f)) == nb_f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << nb_d;
		if (static_cast<double>(static_cast<int>(nb_f)) == nb_f)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: ";
		std::cout << nb << std::endl;
		nb.erase(nb.size() - 1);
		std::cout << "double: " << nb << std::endl;
	}
}

void	printFromChar(char nb_c)
{
	float	nb_f = static_cast<float>(nb_c);
	int		nb_i = static_cast<int>(nb_c);
	double	nb_d = static_cast<double>(nb_c);
	
	std::cout << "char: ";
	if (nb_c >= 32 && nb_c <= 126)
		std::cout << "'" << nb_c << "'" << std::endl;
	else
		std::cout << "Non displayable" <<std::endl;
	std::cout << "int: " << nb_i << std::endl;
	std::cout << "float: " << nb_f << ".0f" << std::endl;
	std::cout << "double: " << nb_d << ".0" << std::endl;
}

void	printFromDouble(double nb_d, std::string nb)
{
	float	nb_f = static_cast<float>(nb_d);
	int		nb_i = static_cast<int>(nb_d);
	char	nb_c = static_cast<char>(nb_d);
	
	if (nb != "+inf" && nb != "-inf" && nb != "nan")
	{
		std::cout << "char: ";
		if (nb_d < -128 || nb_d > 127)
			std::cout << "impossible" << std::endl;
		else if (nb_c >= 32 && nb_c <= 126)
			std::cout << "'" << nb_c << "'" << std::endl;
		else
			std::cout << "Non displayable" <<std::endl;
		std::cout << "int: " << nb_i << std::endl;
		std::cout << "float: " << nb_f;
		if (static_cast<float>(static_cast<int>(nb_d)) == nb_d)
			std::cout << ".0";
		std::cout << "f" << std::endl;
		std::cout << "double: " << nb_d;
		if (static_cast<double>(static_cast<int>(nb_d)) == nb_d)
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: ";
		std::cout << nb << "f" << std::endl;
		std::cout << "double: " << nb << std::endl;
	}
}

void	printFromInt(int nb_i)
{
	char	nb_c = static_cast<char>(nb_i);
	float	nb_f = static_cast<float>(nb_i);
	double	nb_d = static_cast<double>(nb_i);
	
	std::cout << "char: ";
	if (nb_i < -128 || nb_i > 127)
		std::cout << "impossible" << std::endl;
	else if ((nb_c >= 32 && nb_c <= 126))
		std::cout << "'" << nb_c << "'" << std::endl;
	else
		std::cout << "Non displayable" <<std::endl;
	std::cout << "int: " << nb_i << std::endl;
	std::cout << "float: " << nb_f << ".0f" << std::endl;
	std::cout << "double: " << nb_d << ".0" << std::endl;
}
