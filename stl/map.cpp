/**
 * author: yusuf shakeel
 * date: 19-jun-2016
 *
 * description:
 * find frequency of the letters
 *
 * input:
 * the first line of the input contains integer t denoting the number of test cases
 * then t lines follows
 * each line contains a character and a string
 * print 
 * 
 * output:
 * on each line print the frequency of the mentioned character in the given string and the frequency of all the characters.
 *
 * constraint:
 * 1 <= t <= 10
 * 1 <= |s| <= 100
 *
 * example #1
 * 
 * input:
 * 2
 * a asdfa
 * x zxc
 *
 * output:
 * 2 a:2 d:1 f:1 s:1 
 * 1 c:1 x:1 z:1
 */


#include <iostream>
#include <map>

using namespace std;

int main(void) {

	// take the test case
	int t;
	cin >> t;

	// frequency map
	map<char, int> freqMap;

	// map iterator
	map<char, int>::iterator itr;

	while(t--) {

		// clear the map
		freqMap.clear();

		// take the character and string
		char ch;
		string str;

		cin >> ch >> str;

		// length of the string
		int len = str.length();

		// frequency of the character in the string
		int freq = 0;

		for(int i = 0; i < len; i++) {
			if (str[i] == ch) {
				freq++;
			}

			if (freqMap.find(str[i]) == freqMap.end()) {
				freqMap[str[i]] = 1;
			} else {
				freqMap[str[i]] = freqMap[str[i]] + 1;
			}
		}

		cout << freq << " ";

		for(itr = freqMap.begin(); itr != freqMap.end(); ++itr) {
			cout << itr->first << ":" << itr->second << " ";
		}

		cout << endl;

	}

	return 0;
}
