/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:40:42 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 15:56:40 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T &cnt, int n)
{
	typename T::iterator it;

	it = std::find(cnt.begin(), cnt.end(), n);
	if (it == cnt.end())
		throw ElementNotFoundException();
	return it;
}

const char* ElementNotFoundException::what() const throw()
{
	return("Element not found in container");
}