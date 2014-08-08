#include <iostream>
#include "dystring.h"
using namespace std;

int main(){
	dystring str = "hello";
	cout<<str.get()<<endl;
	cout<<str.length()<<endl;
	dystring sub = str.substring(2);
	cout<<sub.get()<<endl;
	cout<<sub.length();
	return 0;
}