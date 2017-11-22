#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

//#define PRINT(type) for_each()
void print(vector<string>::iterator beg, vector<string>::iterator end)
{
    for_each(beg,end, [](const string &s){cout << s << endl;});
}

void elimDups(vector<string> &words)
{
    //按字典序排列
    sort(words.begin(),words.end());

    //返回指向不重复区域之后一个位置的迭代器
    auto iter = unique(words.begin(),words.end());


    words.erase(iter, words.end());


}


void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);

    //按长度重新排序 长度相同的元素维持字典序
    //stable_sort(words.begin(),words.end(),[](const string &s1,const string &s2){return s1.size() > s2.size();});


    print(words.begin(),words.end());


    cout << endl;
    //返回一个迭代器，指向第一个大于sz大小的元素迭代器
  //  auto wc = find_if(words.begin(),words.end(),[sz](const string &s){return s.size() >= sz;});

    //partition 对元素进行划分，谓词为true的排在前半部分，返回一个迭代器，指向最后一个使谓词为true元素之后的位置,stable维持原有字典序
    auto wc = stable_partition(words.begin(),words.end(),[sz](const string &s){
            return s.size() >= sz;
            });
    cout << words.end() - wc << endl;

    print(words.begin(),wc);
}

int main(int argc, char **argv)
{
    fstream in(argv[1]);
    vector<string> words;
    string s;
    while(in >> s)
    {
        words.push_back(s);
    }

    biggies(words,5);




}
