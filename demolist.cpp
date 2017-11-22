#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>

using namespace std;


string trans(string &s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] -= ('A' - 'a');
        }
        else if(ispunct(s[i]))
        {
            s.erase(i,1);
        }
    }
    return s;
}

int main(int argc, char **argv)
{
    map<string,list<int>> lineno_word;
    fstream in(argv[1]);
    string word;
    int patno = 0;
    string line;
    while(getline(cin,line))
    {
        patno++;
        istringstream l_in(line);
        while(l_in >> word)
        {
            lineno_word[trans(word)].push_back(patno);
        }
    }

    for(auto &w : lineno_word)
    {
         cout << w.first << " " << endl;
         for(auto iter = w.second.begin(); iter != w.second.end(); ++iter)
             cout << *iter << " ";
         cout << endl;
    }
}
