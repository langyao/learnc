#include <iostream>
#include <string>
#include "TextQuery.h"

using namespace std;

int main(int argc,char **argv)
{
    ifstream infile(argv[1]);
    TextQuery tq(infile);

    while(true)
    {
        cout << "enter word to look for,or q to quit:";
        string s;
        if(!(cin >> s) || s == "q")
            break;
        print(cout,tq.query(s)) << endl;
    }

}

