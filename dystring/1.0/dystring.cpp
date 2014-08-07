/**
* Project: dystring
* File: dystring.cpp
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

#include "dystring.h"

//----- DYSTRING CLASS FUNCTIONS ----------------------//

//----- PRIVATE FUNCTIONS -----------------------------//
/* memory allocation */
void dystring::__dymalloc(){
	if(dystr!=0)
		delete dystr;
	dystr = new char[dystrlen+1];
}

/* return length of the string s */
long dystring::__dystrlen(const char *s){
	long l = 0;
	while(*(s+l)!='\0')
		l++;
	return l;
}

/* reallocate memory space and retain previous string */
void dystring::__dyrealloc(){
	char *tmp = new char[dystrlen+1];
	long i;
	for(i=0; *(dystr+i)!='\0'; i++){
		*(tmp+i)=*(dystr+i);
	}
	*(tmp+i)='\0';
	delete dystr;
	dystr = tmp;
}

//----- PUBLIC FUNCTIONS ------------------------------//

//----- CONSTRUCTORS ----------------------------------//

//default constructor
dystring::dystring(void){
	dystrlen = 0;
	dystr = new char('\0');
}

//parameterized constructor
dystring::dystring(const char *s){
	copy(s);
}

//----- MEMBER FUNCTIONS ------------------------------//

/* concatenate source to string */
void dystring::concat(const char *source){
	long slen = __dystrlen(source);
	long i = dystrlen;
	dystrlen += slen;
	__dyrealloc();
	for(long j=0; *(source+j)!='\0'; j++,i++){
		*(dystr+i) = *(source+j);
	}
	*(dystr+i)='\0';
}

/* copy source to string */
void dystring::copy(const char *source){
	dystrlen = __dystrlen(source);
	__dymalloc();
	long i;
	for(i=0;*(source+i) != '\0';i++){
		*(dystr+i) = *(source+i);
	}
	*(dystr+i) = '\0';
}

/* get the content of the string */
char * dystring::get(){
	return dystr;
}

/* return true (1) if string is palindrome. false (0) otherwise */
bool dystring::isPalindrome(){
	for(long i=0, j=dystrlen-1; i<=j; i++,j--){
		if(*(dystr+i)!=*(dystr+j))
			return false;
	}
	return true;
}

/* get the length of the string */
long dystring::length(){
	return dystrlen;
}

/* reverse string */
void dystring::reverse(){
	char ch;
	for(long i=0, j=dystrlen-1; i<j; i++,j--){
		ch = *(dystr+i);
		*(dystr+i) = *(dystr+j);
		*(dystr+j) = ch;
	}
}

/* toggle case. change A to a and vice versa */
void dystring::toggleCase(){
	for(long i=0;i<dystrlen;i++){
		char ch = *(dystr+i);
		if(ch>=65 && ch<=90){
			*(dystr+i) = ch + 32;
		}else if(ch>=97 && ch<=122){
			*(dystr+i) = ch - 32;
		}
	}
}

/* toUpper case change a to A */
void dystring::toUpper(){
	for(long i=0;i<dystrlen;i++){
		char ch = *(dystr+i);
		if(ch>=97 && ch<=122){
			*(dystr+i) = ch - 32;
		}
	}
}
/* toLower case change A to a */
void dystring::toLower(){
	for(long i=0;i<dystrlen;i++){
		char ch = *(dystr+i);
		if(ch>=65 && ch<=90){
			*(dystr+i) = ch + 32;
		}
	}
}