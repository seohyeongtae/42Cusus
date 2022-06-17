/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyseo <hyseo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:52:22 by hyseo             #+#    #+#             */
/*   Updated: 2022/06/17 18:23:57 by hyseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdlib.h>

template<typename T>
class  Array
{
private:
    T* array;
    size_t arr_size;
public:
    Array(void) : array(new T[0]), arr_size(0){};
    Array(size_t arr_size) : array(new T[arr_size]), arr_size(arr_size){};
    Array(const Array& a) : array(new T[a.size()]) , arr_size(a.size())
    {
        for (int i = 0; i < arr_size; i++)
            array[i] = a.array[i];
    }
    ~Array(){ delete[] array; };
    size_t size() const
    {
        return (this->arr_size);
    };

    Array& operator=(const Array& a)
    {

        if (this != &a)
        {
            if (arr_size)
            {
                delete[] array;
                this->arr_size = 0;
                this->array = NULL;
            }
                
            this->arr_size = a.arr_size;
            this->array = new T(arr_size);
            for (int i = 0; i < this->arr_size; i++)
                this->array[i] = a.array[i];
        }    
        return (*this);
    };

    T& operator[] (size_t num) 
    {
        if (num >= arr_size)
        {
            throw Array::NumException();
        }
        return (array[num]);
    };

    const T& operator[] (size_t num) const
    {
        if (num >= arr_size)
        {
            throw Array::NumException();
        }
        return (array[num]);
    };
    
    class NumException : public std::exception 
    {
        public:
        const char* what() const throw()
        {
            return "NumException size error";
        }
    };
};

#endif