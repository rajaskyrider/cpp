/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:24:21 by rpandipe          #+#    #+#             */
/*   Updated: 2025/02/12 13:54:39 by rpandipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array () : m_n(0), m_ptr(NULL)
{}

template <typename T>
Array<T>::Array (unsigned int n) : m_n(n)
{
	m_ptr = new T[m_n]();
}

template <typename T>
Array<T>::Array(Array<T> const &other): m_n(other.m_n)
{
	if (this->m_n == 0)
	{
		this->m_ptr = NULL;
		return ;
	}
	this->m_ptr = new T[this->m_n];
	for(int i = 0; i < m_n; i++)
		this->m_ptr[i] = other->m_ptr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T> const &other)
{
	if (this != &other)
	{
		delete[] this->m_ptr;
		this->m_n = other->m_n;
		if (this->m_n == 0)
		{
			this->m_ptr = NULL;
			return *this;
		}
		this->m_ptr = new T[m_n];
		for(int i = 0; i < m_n; i++)
			this->m_ptr[i] = other->m_ptr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_ptr;
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
	if (i >= m_n)
		throw Array<T>::IndexOutOfBoundsException();
	return (m_ptr[i]);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= m_n)
		throw Array<T>::IndexOutOfBoundsException();
	return (m_ptr[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->m_n);
}

template <typename T>
T* Array<T>::getArray() const
{
	return (this->m_ptr);
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds");
}