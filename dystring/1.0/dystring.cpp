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
void dystring::__dymalloc(void){
	if(dystr != 0)
		delete dystr;
	dystr = new char[dystrlen + 1];
}

/* return length of the string s */
long dystring::__dystrlen(const char *s){
	long l = 0;
	while(*(s + l) != '\0')
		l++;
	return l;
}

/* reallocate memory space and retain previous string */
void dystring::__dyrealloc(void){
	char *tmp = new char[dystrlen + 1];
	long i;
	for(i = 0; *(dystr + i) != '\0'; i++){
		*(tmp + i) = *(dystr + i);
	}
	*(tmp + i) = '\0';
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
	for(long j = 0; *(source + j) != '\0'; j++, i++){
		*(dystr + i) = *(source + j);
	}
	*(dystr + i)='\0';
}

/* copy source to string */
void dystring::copy(const char *source){
	dystrlen = __dystrlen(source);
	__dymalloc();
	long i;
	for(i = 0; *(source + i) != '\0'; i++){
		*(dystr + i) = *(source + i);
	}
	*(dystr + i) = '\0';
}

/* return character at the given index, NULL (\0) for invalid index. */
char dystring::charAt(long index){
	if(index < 0 || index >= dystrlen)
		return '\0';
	return *(dystr+index);
}

/* get the content of the string dystr */
char * dystring::get(void){
	return dystr;
}

/* return true (1) if string is palindrome. false (0) otherwise */
bool dystring::isPalindrome(void){
	for(long i = 0, j = dystrlen - 1; i <= j; i++, j--){
		if(*(dystr + i) != *(dystr + j))
			return false;
	}
	return true;
}

/* return index of first occurance of the character ch in string, -1 otherwise. */
long dystring::indexOf(const char ch){
	for(long i = 0; *(dystr + i) != '\0'; i++){
		if(*(dystr + i) == ch)
			return i;
	}
	return -1;
}

/* return index of first occurance of the substring str in string, -1 otherwise. */
long dystring::indexOf(const char *str){
	long slen = __dystrlen(str);
	for(long i = 0, c = 0; *(dystr + i) != '\0'; i++, c = 0){
		for(long j = 0; j < slen; j++){
			if(*(dystr + i + j) == *(str + j))
				c++;
		}
		if(c == slen)
			return i;
	}
	return -1;
}

/* insert character ch at position index in string when index is valid, ignore otherwise. */
void dystring::insertAt(const char ch, long index){
	if(index >= 0 && index < dystrlen){
		dystrlen++;
		__dyrealloc();
		for(long i = dystrlen - 1; i > index; i--){
			*(dystr + i) = *(dystr + i - 1);
		}
		*(dystr + index) = ch;
	}
}

/* return index of last occurance of the character ch in string, -1 otherwise. */
long dystring::lastIndexOf(const char ch){
	for(long i = dystrlen - 1; i >= 0; i--){
		if(*(dystr + i) == ch)
			return i;
	}
	return -1;
}

/* return index of last occurance of the substring str in string, -1 otherwise. */
long dystring::lastIndexOf(const char *str){
	long slen = __dystrlen(str);
	for(long i = dystrlen - slen, c = 0; i >= 0; i--, c = 0){
		for(long j = 0; j < slen; j++){
			if(*(dystr + i + j) == *(str + j))
				c++;
		}
		if(c == slen)
			return i;
	}
	return -1;
}

/* get the length of the string */
long dystring::length(void){
	return dystrlen;
}

/* replace all occurance of the character ch with nch in the string.*/
void dystring::replace(const char ch, const char nch){
	for(long i = 0; i < dystrlen; i++){
		if(*(dystr + i) == ch)
			*(dystr + i) = nch;
	}
}

/* reverse string */
void dystring::reverse(void){
	char ch;
	for(long i = 0, j = dystrlen - 1; i < j; i++, j--){
		ch = *(dystr + i);
		*(dystr + i) = *(dystr + j);
		*(dystr + j) = ch;
	}
}

/* toggle case. change A to a and vice versa */
void dystring::toggleCase(void){
	for(long i = 0; i < dystrlen; i++){
		char ch = *(dystr + i);
		if(ch >= 65 && ch <= 90){
			*(dystr + i) = ch + 32;
		}else if(ch >= 97 && ch <= 122){
			*(dystr + i) = ch - 32;
		}
	}
}

/* toLower case change A to a */
void dystring::toLower(void){
	for(long i = 0; i < dystrlen; i++){
		char ch = *(dystr + i);
		if(ch >= 65 && ch <= 90){
			*(dystr + i) = ch + 32;
		}
	}
}

/* toUpper case change a to A */
void dystring::toUpper(void){
	for(long i = 0; i < dystrlen; i++){
		char ch = *(dystr + i);
		if(ch >= 97 && ch <= 122){
			*(dystr + i) = ch - 32;
		}
	}
}

/* remove space from front and end of the string. */
void dystring::trim(void){
	long beg = 0, end = dystrlen - 1;
	while(*(dystr + beg) < 33)
		beg++;
	while(*(dystr + end) < 33)
		end--;
	dystrlen = end - beg + 1;
	char *tmp = new char[dystrlen + 1];
	long i;
	for(i = 0; i < dystrlen; i++){
		*(tmp + i) = *(dystr + beg + i);
	}
	*(tmp + i) = '\0';
	delete dystr;
	dystr = tmp;
}

/* return a substring from index start till the end of the string, for invalid start index return NULL (\0) */
char * dystring::substring(long start){
	if(start < 0 || start >= dystrlen)
		return '\0';
		
	long substrlen = dystrlen - start;
	char *str = new char[substrlen + 1];
	long i;
	for(i = 0; i < substrlen; i++){
		*(str + i) = *(dystr + start + i);
	}
	*(str + i) = '\0';
	return str;
}

/* return a substring from index start to end, for invalid index return NULL (\0) */
char * dystring::substring(long start, long end){
	if(start < 0 || start >= dystrlen || end < 0 || end >= dystrlen)
		return '\0';
		
	long substrlen = end - start + 1;
	char *str = new char[substrlen + 1];
	long i;
	for(i = 0; i < substrlen; i++){
		*(str + i) = *(dystr + start + i);
	}
	*(str + i) = '\0';
	return str;
}