//calling a member function from inside of another function
//is call member function nesting.

#include <iostream>
using namespace std;

class FindMax{
	private:
		int a,b;
		int max();
	public:
		void getint();
		void disp();
};

int FindMax::max(){
	if(a>b) return a;
	return b;
}

void FindMax::getint(){
	cout<<"Enter two integer: ";
	cin>>a>>b;
}

void FindMax::disp(){
	cout<<"Max = "<<max();
}

int main(){
	FindMax obj;
	obj.getint();
	obj.disp();
	return 0;
}