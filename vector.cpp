#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

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

int main(void)
{
 //   vector<string> unique;
 //   string word;
 //   while(cin >> word)
 //       if(find(unique.begin(),unique.end(),word) == unique.end())
 //           unique.push_back(trans(word));
 //
    set<string> sset;
    string word;
    while(cin >> word)
        sset.insert(trans(word));
    for(auto &c: sset)
        cout << c << " ";
    cout << endl;

}
