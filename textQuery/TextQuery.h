#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <set>
class QueryResult;
class TextQuery
{
    public:
        //typedef std::vector<std::string>::size_type line_no;
        using line_no = std::vector<std::string>::size_type;
        TextQuery(std::ifstream &f):svec(new std::vector<std::string>)
    {
        //  svec = std::make_shared<new std::vector<std::string>>;
        line_no lineno = 0;
        std::string line;
        while(getline(f,line))
        {
            svec->push_back(line);
            std::istringstream is(line);
            std::string word;
            while(is >> word)
            {
                auto &lines = wordMap[word];
                if(!lines)
                    lines.reset(new std::set<line_no>);
                lines->insert(lineno);
            }
            lineno++;
        }
    }

        QueryResult query(const std::string &s) const;
    private:
        std::shared_ptr<std::vector<std::string>> svec;
        std::map<std::string,std::shared_ptr<std::set<line_no>>> wordMap;
};


//class QueryResult;
class QueryResult
{
    public:
        friend std::ostream& print(std::ostream &s,const QueryResult& qr);
        QueryResult(const std::string &s,
                std::shared_ptr<std::vector<std::string>> f,
                std::shared_ptr<std::set<TextQuery::line_no>> l):sought(s),file(f),lines(l){}
    private:
        std::string sought;
        std::shared_ptr<std::vector<std::string>> file;
        std::shared_ptr<std::set<TextQuery::line_no>> lines;
};


QueryResult TextQuery::query(const std::string &s) const
{
    std::shared_ptr<std::set<line_no>> p(new std::set<line_no>);
    auto iter  = wordMap.find(s);

    if(iter  == wordMap.end())
    {
        return QueryResult(s,svec,p);
    }
    else
        return QueryResult(s,svec,iter->second);

}

const std::string make_plural(TextQuery::line_no lineno,const std::string &a,const std::string &b)
{
    return lineno > 1 ? a+b : a;
}

std::ostream &print(std::ostream &os,const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(),"time","s") << std::endl;

    for(auto w : *qr.lines)
    {
        os << "line ( "  << w+1 << " ) " << *(qr.file->begin() + w ) ;

    }
    return os;

}
