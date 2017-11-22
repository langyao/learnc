#include <iostream>
#include <algorithm>
#include <list>
#include <deque>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    list<int> nvec{11};

    vector<int> vec1,vec2;
    list<int>lvec;

    //三种插入迭代器

    //inserter差昂见要给迭代器，接受两个参数，元素插入到所给定的元素之前，返回之前指向的元素
    copy(vec.begin(),vec.end(),inserter(vec1,vec1.begin())); //0 1 2 3 ...9

    //back_inserter元素插入后面
    copy(vec.begin(),vec.end(),back_inserter(vec2)); //0 1 2 3 ...9

    //front_inserter接受一个参数，创建一个使用push_front的迭代器,该插入会将插入元素顺序反过来
    copy(vec.begin(),vec.end(),front_inserter(lvec)); //9 8 7 6...0

    for(auto &s:vec1)
        cout << s << " ";
    cout << endl;
    cout << "size:" << vec1.size() << endl;
    for(auto &i:vec2)
        cout << i << " ";
    cout << endl;

    for(auto &j:lvec)
        cout << j << " ";
    cout << endl;
}
