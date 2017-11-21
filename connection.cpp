#include <iostream>
#include <memory>

using namespace std;

struct connection
{

};

struct destination
{

};


struct connection connect(struct destnation *d)
{
	struct connection d;
	cout << "connected!!!" << endl;
	return d;
}

void disconnec(struct connection *d)
{
	cout << "disconnect" <<　endl;
}

void end_connection(struct connection *d)
{
	disconnect(d);
}

void f(destination &d)
{
	struct connection c = connect(&d);
	shared_ptr<struct connection> p(&d,end_connect); 
	
}

int main(void)
{
	struct destination d;
	f(d);

}
