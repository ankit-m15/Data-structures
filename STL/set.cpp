#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s; // set stores the unique element
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    s.insert(5);


    for (int i : s)
        cout << i << " ";
        cout<<endl;

     s.erase(s.begin());
    for (int i : s)
        cout << i << " ";
        cout<<endl;

    cout << "5 is present or not " << s.count(5) << endl; //return true or false

    auto itr = s.find(2); // points to position where 2 is present

    for (auto i = itr; i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout<<endl;

    return 0;
}