/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmatkows <lmatkows@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:48:47 by lmatkows          #+#    #+#             */
/*   Updated: 2025/05/23 14:20:50 by lmatkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer & toCopy){(void)toCopy;}	

Serializer & Serializer::operator=(const Serializer & other){(void)other; return (*this);}

uintptr_t Serializer::serialize(t_Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_Data *>(raw));
}



