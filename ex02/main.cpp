/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:33:26 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/23 15:14:45 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void)
{
	Base *ptr;
	std::srand(std::time(NULL));
	int i = (rand() % 3) + 1;
	switch (i)
	{
		case 1:
		{
			ptr = new A();
			std::cout << "\nA A-type has been generated" << std::endl;
			return (ptr);
		}
		case 2:
		{
			ptr = new B();
			std::cout << "\nA B-type has been generated" << std::endl;
			return (ptr);
		}
		case 3:
		{
			ptr = new C();
			std::cout << "\nA C-type has been generated" << std::endl;
			return (ptr);
		}
	}
	return (NULL);
}

void identify(Base *p)
{
	std::cout << "\nTrying to interprate with ptr" << std::endl;
	A *isA = dynamic_cast<A *>(p);
	if (isA)
	{
		std::cout << "Is A-type" << std::endl;
		return;
	}
	B *isB = dynamic_cast<B *>(p);
	if (isB)
	{
		std::cout << "Is B-type" << std::endl;
		return;
	}
	C *isC = dynamic_cast<C *>(p);
	if (isC)
	{
		std::cout << "Is C-type" << std::endl;
		return;
	}
	std::cout << "Is none of A, B, C types" << std::endl;
}

void identify(Base &p)
{
	std::cout << "\nTrying to interprate with ref" << std::endl;
	try
	{
		A &isA = dynamic_cast<A&>(p);
		(void)isA;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &isB = dynamic_cast<B&>(p);
			(void)isB;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &isC = dynamic_cast<C&>(p);
				(void)isC;
			}
			catch(const std::exception& e)
			{
				std::cout << "Is none of A, B, C types" << std::endl;
				return;
			}
			std::cout << "Is C-type" << std::endl;
			return;
		}
		std::cout << "Is B-type" << std::endl;
		return;
	}
	std::cout << "Is A-type" << std::endl;
	return;
}

int	main(void)
{
	Base *test1 = generate();
	identify(test1);
	identify(*test1);
}
