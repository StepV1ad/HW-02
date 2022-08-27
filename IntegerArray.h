#pragma once

class IntegerArray
{
public:
    IntegerArray();
    IntegerArray(const IntegerArray& intArr);
    ~IntegerArray();

    void setLength(int length);
    void erase();
    int& operator[](int index);
    void reallocate(int newLength);
    void resize(int newLength);
    void setValue(int value, int index);
    void remove(int index);
    int getLength();
    void printValue(int index);
    void printArray();
    void insert(int value, int index);
    void insertAtBeginning(int value) { insert(value, 0); }
    void insertAtEnd(int value) { insert(value, m_length); }

private:
    int m_length;
    int* m_data;
};