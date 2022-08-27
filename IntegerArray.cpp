#include <iostream>
#include "IntegerArray.h"
#include <exception>
using namespace std;

class BadRange : public exception
{
public:
    virtual const char* what() const noexcept override { return "ERROR: Неверно задан индекс элемента массива!"; }
};

class BadLength : public exception
{
public:
    virtual const char* what() const noexcept override { return "ERROR: Неверно задана длина массива!"; }
};

IntegerArray::IntegerArray() :
        m_length(0), m_data(nullptr) {}

IntegerArray::IntegerArray(const IntegerArray &intArr) 
{
    m_length = intArr.m_length;
    if (intArr.m_data)
    {
        m_data = new int[m_length];
        for (int i = 0; i < m_length; ++i)
            m_data[i] = intArr.m_data[i];
    }
    else
        m_data = nullptr;
}

IntegerArray::~IntegerArray() { delete[] m_data; }

void IntegerArray::setLength(int length)
{
    m_length = length;
    if (length < 0)
        throw BadLength();
    else if (length >= 0)
        m_data = new int[length];
}

void IntegerArray::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

int& IntegerArray::operator[](int index)
{
    if ((index < 0) || (index >= m_length))
        throw BadRange();
    return m_data[index];
}

void IntegerArray::reallocate(int newLength)
{
    erase();
    setLength(newLength);
    for (int i = 0; i < newLength; i++)
        m_data[i] = 0;
}

void IntegerArray::resize(int newLength)
{
    if (newLength <= 0)
        throw BadLength();

    int* data = new int[newLength];

    if (newLength == m_length)
        return;
    else if (m_length > newLength)
        for (int index = 0; index < newLength; ++index)
            data[index] = m_data[index];
    else if (m_length < newLength)
    {
        for (int index = 0; index < m_length; ++index)
            data[index] = m_data[index];
        for (int index = m_length; index < newLength; ++index)
            data[index] = 0;
    }

    delete[] m_data;
    m_data = data;
    m_length = newLength;
}

void IntegerArray::setValue(int value, int index)
{
    if ((index < 0) || (index >= m_length))
        throw BadRange();
    m_data[index] = value;
}

void IntegerArray::remove(int index)
{
    if ((index < 0) || (index >= m_length))
        throw BadRange();

    if (m_length == 1)
    {
        erase();
        return;
    }

    int* data = new int[m_length - 1];

    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    for (int after = index + 1; after < m_length; ++after)
        data[after - 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    --m_length;
}

void IntegerArray::insert(int value, int index)
{
    if ((index < 0))
        throw BadLength();

    //setLength(m_length + 1);

    int* data = new int[m_length + 1];
    for (int before = 0; before < index; ++before)
        data[before] = m_data[before];

    data[index] = value;
    for (int after{ index }; after < m_length; ++after)
        data[after + 1] = m_data[after];

    delete[] m_data;
    m_data = data;
    ++m_length;
}


int IntegerArray::getLength() { return m_length; }

void IntegerArray::printValue(int index)
{
    if ((index < 0) || (index >= m_length))
        throw BadRange();
    cout << m_data[index] << endl;
}

void IntegerArray::printArray()
{
    for (int j = 0; j < m_length; j++)
        cout << m_data[j] << " ";
    cout << endl;
}