#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

int main(void)
{
    vector<int> ivec{
    0,1,2,3,4,5,6,7,8,9
    };

    ostream_iterator<int> out_iter(cout," ");
    //vector<int>::reverse_iterator,
    copy(ivec.crbegin(),ivec.crend(),out_iter);
    cout << endl;


    for(auto it = ivec.crbegin(); it != ivec.crend(); ++it)
        cout << *it << " ";
    cout << endl;


    list<int> ilist;
    copy(ivec.cbegin()+3,ivec.cend()-2,front_inserter(ilist));

    copy(ilist.begin(),ilist.end(),out_iter);
    cout << endl;

    auto rcomma = find(ivec.crbegin(),ivec.crend(),0);
    cout << *++rcomma << endl;
}
