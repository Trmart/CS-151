// test.cpp
// Description: Implement my own version of the vector that uses
//  dynamic memory allocation and pointers
// Name(s): Taylor Martin, Dan Blanchette, Stephen Haldi
// Date:1/23/2020
#include "myVector.h"

Vector::Vector()
{
        m_elements = new int[1];
        m_capacity = 1;
        m_size = 0;
}

void Vector::push_back(int data)
{
    if (m_size == m_capacity)
    {  
        m_capacity *= 2;
        int* temp = new int [m_capacity];
        m_elements [0] = data;
        for (int index =0; index < m_size; index++)
        {
            temp[index] = m_elements[index]; 
        }
        delete [] m_elements; 
        m_elements = temp; 
    }
    m_elements[m_size] = data;
    ++m_size;
}

void Vector::set(int index, int data)
{
    if (index >= m_size || index < 0)
    {
        cout << "index = " << index << " out of bounds, exiting\n";
        exit(0);
    }
    m_elements[index] = data;
}

int Vector::at(int index)
{
    if (index >= m_size || index < 0)
    {
        cout << "index = " << index << " out of bounds, exiting\n";
        exit(0);
    }
    return m_elements[index];
}

void Vector::pop_back()
{
    --m_size;
}

int Vector::size() const
{
    return m_size;
}

int Vector::capacity() const
{
    return m_capacity;
}