#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(void)
{
    deque<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    a.push_front(1);
    a.push_front(0);

    for(size_t ncount = 0; ncount < a.size(); ncount++)
    {
        cout << "a[" << ncount << "] = " << a[ncount] << endl;
    }
    cout << endl << endl;

    a.pop_back();
    a.pop_front();

    deque<int>::iterator iElementLocater ;
    for(iElementLocater = a.begin();
        iElementLocater!=a.end();iElementLocater++)
    {
        size_t nOffset  = distance(a.begin(),iElementLocater);
        cout << "a[" << nOffset << "] = " << *iElementLocater << endl;

    }

    return 0;
}
