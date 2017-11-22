#include <iostream>
#include <list>

using namespace std;

void printListContent(list<int>& listInput);

int main(void)
{
    list<int> a;

    a.push_front(4);
    a.push_front(3);
    a.push_front(2);
    a.push_back(5);
    printListContent(a);
    cout << endl;

    list<int> b;
    b.push_back(100);
    b.push_front(200);
    list<int>::iterator iter = b.begin();
    b.insert(iter,1);
    //插入三种方式
    iter++;
    b.insert(iter,4,2);
    //将list a整个插入数组中
    b.insert(b.begin(),a.begin(),a.end());
    printListContent(b);

    return 0;

}

void printListContent(list<int>& listInput)
{
    list<int>::iterator iter;
    for(iter = listInput.begin(); iter != listInput.end(); iter++)
    {
        cout << *iter << endl;
    }
}
