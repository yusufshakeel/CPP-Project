#include <iostream>
using namespace std;

class Sample{
	static int count;
public:
	static void showCount(){
		cout<<count<<endl;
	}
	static void update();
};

int Sample::count;

void Sample::update(){
	count++;
}

int main(){
	Sample::showCount();
	Sample::update();
	Sample::showCount();
	return 0;
}