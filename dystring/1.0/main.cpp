#include <iostream>
#include "dystring.h"
using namespace std;

int main(){
	dystring str = "aBCd";
	str.reverse();
	cout<<str.get()<<endl;
	cout<<str.length()<<endl;
	return 0;
}