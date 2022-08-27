#include <iostream>
#include "IntegerArray.h"
#include <exception>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    
    IntegerArray array;
    int length = 10;
    try { array.setLength(length); }
    catch (exception& e)
    {
        array.erase();
        cout << e.what() << endl;
    }
    for (int i = 0; i < length; i++)
        array[i] = i + 1;
    array.printArray();

    length = -10;
    try { array.setLength(length); }
    catch (exception& e)
    {
        array.erase();
        cout << e.what() << endl;
    }
    array.printArray();

    int newLength = -8;
    try { array.reallocate(newLength); }
    catch (exception& e) { cout << e.what() << endl; }
    array.printArray();
    newLength = 8;
    try { array.reallocate(newLength); }
    catch (exception& e) { cout << e.what() << endl; }
    array.printArray();

    newLength = 6;
    for (int i = 0; i < newLength; i++)
        array[i] = i + 1;
    try { array.resize(newLength); }
    catch (exception& e) { cout << e.what() << endl; }
    array.printArray();

    int index = 2;
    try { array.remove(index); }
    catch (exception& e) { cout << e.what() << endl; }
    array.printArray();
    index = -2;
    try { array.remove(index); }
    catch (exception& e) { cout << e.what() << endl; }

    int number = 45;
    try { array.setValue(number, index); }
    catch (exception& e) { cout << e.what() << endl; }
    array.printArray();

    index = 4;
    try { array.printValue(index); }
    catch (exception& e) { cout << e.what() << endl; }
    

    IntegerArray array2(array);
    array2.printArray();
    cout << array2.getLength() << endl;
    array2.insertAtBeginning(45);
    array2.insertAtEnd(97);
    array2.printArray();
    return 0;
}