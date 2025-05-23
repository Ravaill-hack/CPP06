/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:06:38 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/23 14:22:09 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	t_Data		test = {2, 10, 'c'};
	t_Data		*ptr_before = &test;
	t_Data		*ptr_after;
	uintptr_t	intptr;
	
	std::cout << "Before serialization" << std::endl;
	std::cout << "x = " << ptr_before->x << ", y = " << ptr_before->y << ", char = " << ptr_before->a << std::endl;
	intptr = Serializer::serialize(ptr_before);
	ptr_after = Serializer::deserialize(intptr);
	std::cout << "After serialization and deserialization" << std::endl;
	std::cout << "x = " << ptr_after->x << ", y = " << ptr_after->y << ", char = " << ptr_after->a << std::endl;
}
