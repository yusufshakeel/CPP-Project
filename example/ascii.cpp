#include <iostream>
using namespace std;

int main(){
	char ch = 'A';
	int num = ch;	//ASCII value of 'A' i.e. 65
	num = num + 1;	//66 i.e. ASCII value of 'B'
	ch = num;
	cout<<ch;
	return 0;
}