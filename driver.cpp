#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

int main() {
    LinkedList<int> intList;

    cout << "Test 1: Append 10,20,30\n";
    intList.append(10); intList.append(20); intList.append(30);
    cout << intList;

    cout << "Test 2: Insert 15 at pos 1\n";
    intList.insert(1, 15);
    cout << intList;

    cout << "Test 3: Insert 5 at pos 0\n";
    intList.insert(0, 5);
    cout << intList;

    cout << "Test 4: Insert 40 at end\n";
    intList.insert(intList.getLength(), 40);
    cout << intList;

    cout << "Test 5: Replace pos 2 with 99\n";
    intList.replace(2, 99);
    cout << intList;

    cout << "Test 6: Get element at pos 3\n";
    cout << intList.getElement(3) << "\n";

    cout << "Test 7: Remove pos 0\n";
    intList.remove(0);
    cout << intList;

    cout << "Test 8: Remove last element\n";
    intList.remove(intList.getLength() - 1);
    cout << intList;

    cout << "Test 9: Clear list\n";
    intList.clear();
    cout << intList;

    cout << "Test 10: Exception getElement from empty list\n";
    try { intList.getElement(0); }
    catch (string& e) { cout << e << endl; }

    cout << "Test 11: Exception remove from empty list\n";
    try { intList.remove(0); }
    catch (string& e) { cout << e << endl; }

    LinkedList<string> strList;

    cout << "\nTest 12: Append A,B,C\n";
    strList.append("A"); strList.append("B"); strList.append("C");
    cout << strList;

    cout << "Test 13: Insert X at pos 1\n";
    strList.insert(1, "X");
    cout << strList;

    cout << "Test 14: Replace pos 2 with Y\n";
    strList.replace(2, "Y");
    cout << strList;

    cout << "Test 15: Remove pos 0\n";
    strList.remove(0);
    cout << strList;

    cout << "Test 16: Clear string list\n";
    strList.clear();
    cout << strList;

    return 0;
}