#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int>vect;
    cout<<vect.capacity()<<endl;
    vect.push_back(1);
    vect.push_back(2);

    cout<<vect.capacity()<<endl;
    vect.push_back(3);

    cout<<vect.capacity()<<endl;
    vect.push_back(4);
    vect.push_back(5);
    vect.pop_back();
    cout<<vect.capacity()<<endl;

    vector<int> v1(vect); //copied a vector into another vector
    for(int i=1; i<v1.size(); i++)
    cout<<v1[i]<<" ";
    cout<<endl;

    cout<<vect.capacity()<<endl; // it tells how much element can fit 

//  for this, refer the file  DSA -> STL -> array.cpp
    cout<<vect.size()<<endl;  // it tells how much element present in vector
    cout<<vect.front()<<endl;
    cout<<vect.back()<<endl;
    cout<<vect.at(2)<<endl;

    vect.erase(vect.begin()+1); // deleting element at index 1
    vect.insert(vect.begin()+1,4); // insetting element 4 at index 1
    
    vect.push_back(5); // adds the element at the end into the vector
    vect.pop_back(); // removes the last element from the vector
    vect.clear(); // clear the elements into the vector


    cout<<vect.size();
}
