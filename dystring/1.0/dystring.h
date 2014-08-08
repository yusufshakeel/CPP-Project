/**
* Project: dystring
* File: dystring.h
* Version: 1.0
* Author: Yusuf Shakeel
* Date: 08 August 2014 Friday
* Language: C++
*
* GitHub repository:
* https://github.com/yusufshakeel/CPP-Project/tree/master/dystring
*
* Author:
* https://www.facebook.com/yusufshakeel
* https://www.youtube.com/yusufshakeel
* https://plus.google.com/+YusufShakeel
* https://www.twitter.com/yusufshakeel
* https://github.com/yusufshakeel
*
* ======================================
* License
* ======================================
*
* The MIT License (MIT)
*
* Copyright (c) 2014 Yusuf Shakeel
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#ifndef __DYSTRING_H_INCLUDED
#define __DYSTRING_H_INCLUDED

class dystring{

private:

	//private data members
	char *dystr;
	long dystrlen;
	
	//private member functions
	void __dymalloc(void);				//free and allocate memory space for string.
	long __dystrlen(const char *);		//find length of the string.
	void __dyrealloc(void);				//reallocated memory space and retain previous string.
	
public:
	
	//constructors
	dystring(void);
	dystring(const char *s);

	//public member functions
	void concat(const char *source);	//concatenate source to string.
	void copy(const char *source);	//copy source to string. overwrite string content.
	char charAt(long index);	//return character at the given index, NULL (\0) for invalid index.
	char * get(void);			//get the content.
	bool isPalindrome(void);	//true (1) if string is Palindrome. false (0) otherwise.
	long indexOf(const char ch);		//return index of first occurance of the character ch in string, -1 otherwise.
	long indexOf(const char *str);		//return index of first occurance of the substring str in string, -1 otherwise.
	void insertAt(const char ch, long index);	//insert character ch at position index in string when index is valid, ignore otherwise.
	long lastIndexOf(const char ch);	//return index of last occurance of the character ch in string, -1 otherwise.
	long lastIndexOf(const char *str);	//return index of last occurance of the substring str in string, -1 otherwise.
	long length(void);			//length of the string.
	void replace(const char ch, const char nch);	//replace all occurance of the character ch with nch in the string.
	void reverse(void);			//reverse string.
	void toggleCase(void);		//toggle case. convert A to a and vice-versa.
	void toUpper(void);			//to upper case. convert a to A.
	void toLower(void);			//to lower case. convert A to a.
	void trim(void);			//remove space from front and end of the string.
	char * substring(long start);	//return a substring from index start till end of the string, for invalid start index return NULL (\0)
	char * substring(long start, long end);	//return a substring from index start to end both inclusive, for invalid index return NULL (\0)
};

#endif /* __DYSTRING_H_INCLUDED ends here*/