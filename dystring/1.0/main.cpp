#include <iostream>
#include "dystring.h"
using namespace std;

int main(){
	dystring str = "hello";
	dystring s = "hello" + str;
	cout<<s.countVowel()<<endl;
	cout<<s.length();
	return 0;
}