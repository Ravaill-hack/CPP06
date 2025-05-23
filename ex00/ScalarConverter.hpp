
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

enType			FindType(std::string nb);
void			printFromInt(int nb_i);
void			printFromDouble(double nb_d, std::string nb);
void			printFromChar(char nb_c);
void			printFromFloat(float nb_f, std::string nb);

#endif