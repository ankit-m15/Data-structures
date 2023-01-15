#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();

    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;

}
