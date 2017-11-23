#include <memory>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdlib.h>
#include "StrBlob.h"

using namespace std;


int main(int argc,char **argv)
{
    if(argc < 2)
    {
        cout << "Usage:./a.out filename" << endl;
        exit(-1);
    }

    ifstream input(argv[1]);
    StrBlob s;
    string line;

    string word;
    while(getline(input,line))
    {
        istringstream is(line);
        while(is >> word)
        {
            s.push_back(word);
        }
    }

    for(auto it = s.begin(); neq(it,s.end()); it.incr())
    {
        cout << it.deref() << " ";
    }
    cout << endl;







    //	StrBlob s = {"an", "apple", "in the tree"};
    //
    //	cout << "s.size()" << s.size() << endl;
    //	cout << "s.front" << s.front() << endl;
    //	cout << "s.back()" << s.back() << endl;
    //
    //	string t("haha");
    //	cout << "s.push_back(t)" << endl;
    //	s.push_back("haha");
    //	cout << "s.front" << s.front() << endl;
    //	cout << "s.back()" << s.back() << endl;
    //
    //
    //
    //	cout << "s.pop_back()" << endl;
    //	s.pop_back();
    //	cout << "s.front" << s.front() << endl;
    //	cout << "s.back()" << s.back() << endl;
    //
    //	cout << "s.empty()" << s.empty() << endl;




    return 0;

}
