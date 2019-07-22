#include <iostream>
#include <vector>

using namespace std;

int main(void) {

	// vector array
	vector<int> arr;

	// size for the vector
	int n = 5;

	// resize the vector
	arr.resize(n);

	// push input in the vector
	for(int i = 0; i < n; i++) {
		arr[i] = i;
	}

	// print the content of the vector array
	for(int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}