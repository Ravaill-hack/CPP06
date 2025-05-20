/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:38:23 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/20 16:43:27 by lmatkows         ###   ########.fr       */
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

ScalarConverter::ScalarConverter(const ScalarConverter & toCopy){}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& toCopy)
{
	return (*this);
}

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                 OTHERS                                   ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

void	ScalarConverter::convert(std::string nb)
{
	int			nb_int = 0;
	float		nb_float = 0.0f;
	double		nb_double = 0.0;
	char		nb_char = 0;
	
	try
	{
		enType	ttype = FindType(nb);
	
		switch (ttype)
		{
			case T_FLOAT:
				nb_float = toFloat(nb);
				nb_int = static_cast<int>(nb_float);
				nb_double = static_cast<double>(nb_float);
				nb_char = static_cast<char>(nb_float);
				break;
			case T_INT:
				nb_int = toInt(nb);
				nb_float = static_cast<float>(nb_int);
				nb_double = static_cast<double>(nb_int);
				nb_char = static_cast<char>(nb_int);
				break;
			case T_CHAR:
				nb_char = toChar(nb);
				nb_float = static_cast<float>(nb_char);
				nb_int = static_cast<int>(nb_char);
				nb_double = static_cast<double>(nb_char);
				break;
			case T_DOUBLE:
				nb_double = toDouble(nb);
				nb_int = static_cast<int>(nb_double);
				nb_float = static_cast<float>(nb_double);
				nb_char = static_cast<char>(nb_double);
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
	
	std::cout << "char: " << std::endl;
	std::cout << "int: " << std::endl;
	std::cout << "float: " << std::endl;
	std::cout << "double: " << std::endl;
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
	
}

bool	isDouble(std::string nb)
{
	
}

bool	isChar(std::string nb)
{
	if (nb.length() != 1)
		return (false);
	if (nb[0] >= )
}

bool	isInt(std::string nb)
{
	
}


static enType	FindType(std::string nb)
{
	int	f = 1;

	if (isChar())
	if (nb[nb.length() - 1] == 'f')
	{
		if (nb.find('.') != nb.npos && nb.rfind('.') == nb.find('.'))
		{
			for (int i = 0; nb.length() - 1; i++)
			{
				if ((nb[i] < '0' || nb[i] > '9') && nb[i] != '.')
					f = 0;
			}
			if (f == 1)
				return (T_FLOAT);
		}
	}
}

int				toInt(std::string nb)
{
	
}

char			toChar(std::string nb)
{
	
}

float			toFloat(std::string nb)
{
	
}

double			toDouble(std::string nb)
{
	
}
