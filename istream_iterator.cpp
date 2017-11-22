#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
    istream_iterator<int> in(cin),eof;

   //cout <<  accumulate(in,eof,0) << endl;

    vector<int> vec;
    while(in != eof)
    {
        vec.push_back(*in++);
    }


   ostream_iterator<int> out(cout," ");
   copy(vec.begin(),vec.end(),out);
   cout << endl;

   for(auto e : vec)
   {
   //    out = e;
       *out++ = e;
   }

   cout << endl;

}
