/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:30:37 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/23 11:16:21 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: An input is needed" << std::endl;
		return (1);
	}
	if (argc > 2)
	{
		std::cerr << "Error: There must be only one input" << std::endl;
		return (1);	
	}
	ScalarConverter::convert(argv[1]);
	return (0);	
}
