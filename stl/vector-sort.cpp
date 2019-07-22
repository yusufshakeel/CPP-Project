/**
 * author: yusuf shakeel
 * date: 19-jun-2016
 *
 * description:
 * sort content of vector array in ascending and descending order
 *
 * input:
 * the first line of the input contains integer t denoting the number of test cases
 * then t lines follows
 * each line starts with number n denoting the size of the array and then n integer numbers following.
 * 
 * output:
 * print the odd number test code in ascending order
 * print even number of test code in descending order
 *
 * example #1
 * 
 * input:
 * 2
 * 5 1 3 5 2 4
 * 3 3 9 1
 *
 * output:
 * 1 2 3 4 5
 * 9 3 1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortAsc(vector<int>);
vector<int> sortDesc(vector<int>);

int main(void) {

	// get number of test cases
	int t;
	cin >> t;

	// vector
	vector<int> arr;

	while(t--) {

		// get the number of numbers
		int n;
		cin >> n;
		arr.resize(n);
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		if (t % 2 == 0) {
			// sort desc
			arr = sortDesc(arr);
		} else {
			// sort asc
			arr = sortAsc(arr);
		}

		// output
		for(int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

	}

	return 0;
}

vector<int> sortAsc(vector<int> arr) {
	sort(arr.begin(), arr.end());
	return arr;
}

vector<int> sortDesc(vector<int> arr) {
	sort(arr.begin(), arr.end(), greater<int>());
	return arr;
}