
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iomanip>
# include <iostream>
# include <sstream> 
# include <string>
# include <cctype>
# include <limits>

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(std::string nb);
		operator float();
		operator int();
		operator char();
		operator double();

		class EmptyInput : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class IncorrectSyntax : public std::exception
		{
			public:
				const char *what() const throw();
		};

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter & toCopy);
		ScalarConverter & operator=(const ScalarConverter & other);

};

enum enType {T_FLOAT, T_INT, T_CHAR, T_DOUBLE, T_INVALID};

static enType	FindType(std::string nb);

int				toInt(std::string nb);
char			toChar(std::string nb);
float			toFloat(std::string nb);
double			toDouble(std::string nb);

#endif