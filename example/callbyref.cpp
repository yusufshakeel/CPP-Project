//call by reference

#include <iostream>
using namespace std;

void swap(int &, int &);	//function declaration

int main(){
	int x = 10, y = 20;
	cout<<"Before:\tx="<<x<<"\ty="<<y<<endl;
	swap(x, y);
	cout<<"After:\tx="<<x<<"\ty="<<y<<endl;
	return 0;
}

void swap(int &x, int &y){
	int t = x;
	x = y;
	y = t;
	cout<<"swap():\tx="<<x<<"\ty="<<y<<endl;
}