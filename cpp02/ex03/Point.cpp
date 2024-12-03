/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 02:00:38 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/03 02:32:19 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : m_x(0), m_y(0) {};

Point::Point(const Point &other) : m_x(other.m_x), m_y(other.m_y) {};

Point::Point(float x, float y): m_x(x), m_y(y) {};

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		(Fixed) this->m_x = other.m_x;
		(Fixed) this->m_y = other.m_y;
	}
	return *this;
}

Point::~Point() {};

Fixed	Point::getX() const
{
	return this->m_x;
}

Fixed	Point::getY() const
{
	return this->m_y;
}
