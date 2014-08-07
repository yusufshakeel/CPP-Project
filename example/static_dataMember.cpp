#include <iostream>
using namespace std;

class Sample{
private:
	static int count;
public:
	void dispCount(){
		count++;
		cout<<count<<'\n';
	}
};

int Sample::count;

int main(){
	Sample obj1;
	obj1.dispCount();

	Sample obj2;
	obj2.dispCount();
	return 0;
}