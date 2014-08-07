#include <iostream>
using namespace std;

//class declaration
class AddNum{
	private:
		int a,b;
	public:
		void getint();	//to get integer
		void display();	//to display result
};

void AddNum::getint(){
	cout<<"Enter two integer value: ";
	cin>>a>>b;
}

void AddNum::display(){
	cout<<"Sum = "<<a+b<<endl;
}

int main(){
	AddNum obj;		//create object of AddNum class
	obj.getint();	//get input from user
	obj.display();	//display result
	return 0;
}