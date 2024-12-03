/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:52:10 by rpandipe          #+#    #+#             */
/*   Updated: 2024/12/03 02:19:13 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
# define __POINT_HPP__

#include <iostream>
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Point &other);
		Point(float x, float y);
		Point& operator=(const Point &other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;
		
	private:
		Fixed const m_x;
		Fixed const m_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif