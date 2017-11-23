#ifndef STDBLOB_H
#define STRBLOB_H


#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <initializer_list>

class StrBlobPtr;



class StrBlob
{
	public:
        friend class StrBlobPtr;

        StrBlobPtr begin();
        StrBlobPtr end();
		typedef std::vector<std::string>::size_type size_type;
		StrBlob();
		StrBlob(std::initializer_list<std::string>il );
		size_type size() const {return data->size();}

		void push_back(const std::string &t){data->push_back(t);}
		void pop_back();

		std::string& front();
		std::string& back();


		const std::string& front() const;
		const std::string& back() const;
		bool empty() const {return data->empty();}

	private:
		std::shared_ptr<std::vector<std::string>> data;
		void check(size_type i,const std::string &msg) const ;
};


StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>())
{
}

StrBlob::StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il))
{
}

void StrBlob::check(size_type i,const std::string &msg)const
{
	if(i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}


void StrBlob::pop_back()
{
	check(0,"pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front()
{
	check(0,"front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::back()
{
	check(0,"back on empty StrBlob");
	return data->back();
}


const std::string& StrBlob::front() const
{
	check(0,"front on empty StrBlob");
	return data->front();
}
const std::string& StrBlob::back() const
{
	check(0,"back on empty StrBlob");
	return data->back();
}



class StrBlobPtr
{
    public:
    std::weak_ptr<std::vector<std::string>> wpt;
    std::size_t curr;
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a,std::size_t sz = 0):wpt(a.data),curr(sz){}

    std::string& deref() const;
    StrBlobPtr& incr(); //前缀递增

    private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t,const std::string&) const;
};


std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t sz, const std::string &msg) const
{
    auto p = wpt.lock();
    if(!p)
        throw std::runtime_error("unbound StrBlobPtr");
    if(sz > p->size())
        throw std::out_of_range(msg);
    return p;
}


std::string& StrBlobPtr::deref() const
{
   auto p =  check(curr,"curr is not valid");
   return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
   check(curr,"increment past end of StrBlobPtr");
   ++curr;
   return *this;
}


inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this,data->size());
}

inline bool eq(StrBlobPtr a,StrBlobPtr b)
{
    auto l = a.wpt.lock(), r = b.wpt.lock();
    if(l == r)
        return (!r || a.curr == b.curr); //为空或者都指向同一元素
    else
        return false;
}
inline bool neq(StrBlobPtr a, StrBlobPtr b)
{
    return !eq(a,b);
}

#endif
