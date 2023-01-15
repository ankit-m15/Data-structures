#include <iostream>
#include <array> 
using namespace std;

int main()
{
    array<int, 4> A = {1, 2, 3, 4};

    // size() function gives the size of the array
    int size = A.size();

    for (int i = 0; i < size; i++)
    {
        // print element at index i
        cout << A[i] << endl;
    }

    // print the element at index 2
    cout << A.at(2) << endl;

    // print in bool whether array is empty or not
    cout << A.empty() << endl;

    // print the first element of array
    cout << A.front() << endl;

    // print the last element of array
    cout << A.back() << endl;
    
}
