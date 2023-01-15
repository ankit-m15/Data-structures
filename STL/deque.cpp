#include <iostream>
#include <deque>
using namespace std;

int main()
{

    deque<int> d;

    d.push_back(1);
    d.push_back(1);
    d.push_back(1);
    d.push_back(1); // pushing element from back
    d.push_front(2); // pushing element from front

    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;

    d.pop_back(); // removing element from back
    d.pop_front(); // removing element from front 

    cout << d.empty() << endl; // check for empty return true or false
    cout << d.at(1) << endl; 
    d.erase(d.begin()+1); // deleting element at index 1

    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;

    d.insert(d.begin()+1, 4); // inserting element 4 at index 1

    for (int i = 0; i < d.size(); i++)
        cout << d[i] << " ";
    cout << endl;
}