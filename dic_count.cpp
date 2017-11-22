#include <map>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
    map<string, size_t> word_count;
    string word;
end:
    while(cin >> word)
    {
        for(auto &w : word)
        {
            if(ispunct(w))
                goto end;
            if(isupper(w))
                w = tolower(w);
        }

        ++word_count[word];
    }

    for(const pair<string, size_t> &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times"  : " time") << endl;;
    }
}
