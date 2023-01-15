#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int,string>m; // it stores key value pair
    m[2]="ankit";
    m[2]="ankit";
    m[8]="aryan";
    m[5]="harsh";

    for(auto i:m) // iteration in map
    cout<<i.first<<" "<<i.second<<endl;

    cout<<"finding "<<m.count(8)<<endl; // check key 8 is present or not
    m.erase(8); // erase that key value pair

    for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;
//          key           value

    for (auto itr = m.find(5); itr != m.end(); itr++){ // iteration in map
        cout << itr->first << " " << itr->second << '\n';
    }
    return 0;
}