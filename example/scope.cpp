#include <iostream>
using namespace std;

int x = 10;					//global variable

int main(){
	cout<<x<<endl;			//print 10

	int x = 20;				//local variable within main()
	cout<<x<<endl;			//print 20
	
	{//<--- Block start here
		int x = 30;			//local variable within this block
		cout<<x<<endl;		//print 30
	}//<--- Block ends here

	cout<<x<<endl;			//print 20

	cout<<::x<<endl;		//print 10
	return 0;
}//main() ends here