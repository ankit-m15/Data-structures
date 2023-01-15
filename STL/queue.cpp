#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<string> q;

    q.push("ab"); // push element from back
    q.push("cd");
    q.push("ef");
    cout<<q.empty()<<endl;// check whether queue is empty or not

    cout << q.front() << endl; // first element of queue
    q.pop(); // pop element from front
    cout << q.front() << endl;
    cout << q.back() << endl; // last element of queue

}