Project: dystring
Author: Yusuf Shakeel
Date: 08 August 2014 Friday
Language: C++

GitHub repository:
https://github.com/yusufshakeel/CPP-Project/tree/master/dystring

Author:
https://www.facebook.com/yusufshakeel
https://www.youtube.com/yusufshakeel
https://plus.google.com/+YusufShakeel
https://www.twitter.com/yusufshakeel
https://github.com/yusufshakeel

======================================
License
======================================

The MIT License (MIT)

Copyright (c) 2014 Yusuf Shakeel

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================
FAQ
===========================================

Q. What is dystring?
A. It is an Open Source Project created by me [Yusuf Shakeel].
It is a C++ class which is used to create string object and comes with some functions to manipulate the string.

dystring consists of the following files:
1. dystring.h    - header file which contains the dystring class.
2. dystring.cpp  - this file contains the implementation code.

Since it is an open-source project so feel free to modify the code as per your need and imagination.



Q. How to use dystring in your project?
A. To use dystring you have to copy the dystring.h and dystring.cpp file in the source directory of your project and then include dystring.h header file in your project file.
Note! I am using CodeLite version 6.0 to create dystring header file and I have kept the files in the src directory.
So, my workspace in CodeLite looks as follows:

dystring
 |
 +-src
    |
	+-dystring.cpp
	+-dystring.h
	+-main.cpp



Q. How to create dystring object?
A. Say you want to create dystring object inside main.cpp file, then first you have to include the dystring.h header file inside your main.cpp file.

//inside main.cpp file
#include <iostream>
#include "dystring.h"		//<---- header file included

using namespace std;

int main(){
	return 0;
}

Now create an object of dystring class inside say main() function by writing the following line:

dystring str;

If you want to create and initialize the object with some string then write the following line:

dystring str = "Hello World!";



Q. How to print the content of str?
A. If you have created an object say,

dystring str = "Hello World!";

And want to print the content of str, then write the following line:

cout<<str.get();

And you will get the following output:
Hello World!