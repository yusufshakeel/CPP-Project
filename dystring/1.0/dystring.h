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
	void __dymalloc();					//free and allocate memory space for string.
	long __dystrlen(const char *);		//find length of the string.
	void __dyrealloc();					//reallocated memory space and retain previous string.
	
public:
	
	//constructors
	dystring(void);
	dystring(const char *s);

	//public member functions
	void concat(const char *source);	//concatenate source to string
	void copy(const char *source);	//copy source to string. overwrite string content.
	char * get();			//get the content.
	bool isPalindrome();	//true (1) if string is Palindrome. false (0) otherwise.
	long length();			//length of the string.
	void reverse();			//reverse string.
	void toggleCase();		//toggle case. convert A to a and vice-versa.
	void toUpper();			//to upper case. convert a to A.
	void toLower();			//to lower case. convert A to a.
};

#endif /* Not __DYSTRING_H_INCLUDED */