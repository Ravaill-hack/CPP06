
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iomanip>
# include <iostream>
# include <string>

class ScalarInverter
{
	public:
		char	convert(std::string str_char) const;
		int		convert(std::string str_int) const;
		float	convert(std::string str_float) const;
		double	convert(std::string str_double) const;

};

#endif