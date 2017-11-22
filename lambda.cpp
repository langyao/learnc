#include <iostream>
#include <fstream>
#include <vector>
#include "Sales_item.h"
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    fstream in(argv[1]);
    vector<Sales_item> vec;
    Sales_item s;
    while(in >> s)
    {
        vec.push_back(s);
    }

    sort(vec.begin(),vec.end(),[](const Sales_item &lhs, const Sales_item &rhs){return lhs.isbn() > rhs.isbn();});

    for(const auto &s : vec)
    {
        cout << s << endl;
    }

    for_each(vec.begin(),vec.end(),[](const Sales_item &s){cout << s << endl;});



}
