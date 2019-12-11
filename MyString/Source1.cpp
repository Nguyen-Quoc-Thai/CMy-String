#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string.h>
using namespace std;

#include"CMyString.h"


int main()
{
	/*
	Phương thức khởi tạo
	*/

	cout << "\n\n------ CONSTRUCTOR----------\n\n";

	char* dummy = new char[100];
	strcpy(dummy, "hello-everybody");

	cout << "\n\nOriginal string: "; 
	puts(dummy);

	CMyString* m1 = new CMyString();				//CMyString();
	CMyString* m2 = new CMyString(dummy);			//CMyString(const char* s);
	CMyString* m3 = new CMyString(*m2);				//CMyString(const CMyString& str);
	CMyString* m4 = new CMyString(dummy,2,4);		//CMyString(const CMyString& str, size_t pos, size_t len = npos);
	CMyString* m5 = new CMyString(dummy, 20);		//CMyString(const char* s, size_t n);
	CMyString* m6 = new CMyString(8, 'a');			//CMyString(size_t n, char c);

	cout << "\nm1 (length): " << m1->length() << "\t\t\tCMyString();";
	cout << "\nm2: " << *m2 << "\t\tCMyString(const char* s);";;
	cout << "\nm3: " << *m3 << "\t\tCMyString(const CMyString& str);";;
	cout << "\nm4: " << *m4 << "\t\t\tCMyString(const CMyString& str, size_t pos, size_t len = npos);";;
	cout << "\nm5: " << *m5 << "\t\tCMyString(const char* s, size_t n);";;
	cout << "\nm6: " << *m6 << "\t\t\tCMyString(size_t n, char c);" << endl << endl;

	/*
	Toán tử gán =
	*/

	cout << "\n\n------ OPERATOR = ----------\n\n";

	const char* dummy2 = "welcome to my project";
	cout << "\n\nOriginal string: ";
	puts(dummy2);

	CMyString m7 = *m6;
	CMyString m8 = dummy2;
	CMyString m9 = "a";

	cout << "\nm7: " << m7 << "\t\t\tCMyString& operator= (const CMyString & str);";;
	cout << "\nm8: " << m8 << "\tCMyString& operator= (const char* s);";;
	cout << "\nm9: " << m9 << "\t\t\t\tCMyString& operator= (char c);" << endl << endl;

	/*
	Iterator
	*/

	cout << "\n\n------ ITERATOR ----------\n\n";

	const char* dummy3 = "testing iterator";
	cout << "\n\nOriginal string: ";
	puts(dummy3);

	CMyString m10 = dummy3;

	cout << "\nFor i using  iterator: ";
	for (auto i = m10.begin(); i != m10.end(); i++) {
		cout << *i;
	}

	cout << endl << endl;


	/*
	Capacity
	*/

	cout << "\n\n------ CAPACITY ----------\n\n";

	const char* dummy4 = "testing capacity";
	cout << "\n\nOriginal string: ";
	puts(dummy4);

	CMyString m11 = dummy4;

	cout << "\nSize: " << m11.size();
	cout << "\nLength: " << m11.length();
	cout << "\nMax size: " << m11.max_size();
	cout << "\nCapacity: " << m11.capacity();
	cout << "\nEmpty: " << m11.empty();

	cout << "\n[Resize (8)]: String: ";
	m11.resize(8);
	cout << m11;

	cout << "\n[Reserve (50)]: Capacity: ";
	m11.reserve(50);
	cout << m11.capacity();

	cout << "\n[Shrink_to_fit()]: Capacity: ";
	m11.shrink_to_fit();
	cout << m11.capacity();

	m11.clear();
	cout << "\n[Clear()]: Length: " << m11.length() << endl << endl;



	/*
	Toán tử trup cập
	*/

	cout << "\n\n------ ELEMENT ACCESS ----------\n\n";

	const char* dummy5 = "testing element access";
	cout << "\n\nOriginal string: ";
	puts(dummy5);

	CMyString m12 = dummy5;

	cout << "\nStr[2]: " << m12[2];
	cout << "\nStr.at(5): " << m12.at(5);
	cout << "\nStr.back(): " << m12.back();
	cout << "\nStr.front(): " << m12.front();

	cout << endl << endl;

	/*
	Thay đổi string
	*/

	cout << "\n\n------ MODIFIERS ----------\n\n";

	const char* dummy6 = "testing";
	cout << "\n\nOriginal string 1: ";
	puts(dummy6);
	const char* dummy7 = "modifiers";
	cout << "\n\nOriginal string 2: ";
	puts(dummy7);

	CMyString m13 = dummy6;
	CMyString m14 = dummy7;

	m13 += m14;
	cout << "\nString 1 += String 2: " << m13;

	m13.append(m14);
	cout << "\nString 1 append String 2: " << m13;

	m14.push_back('z');
	cout << "\nString 2.push_pack('z'): " << m14;


	cout << endl << endl;


	CMyString& operator+= (const CMyString & str);
	CMyString& operator+= (const char* s);
	CMyString& operator+= (char c);

	CMyString& append(const CMyString & str);
	CMyString& append(const CMyString & str, size_t subpos, size_t sublen);
	CMyString& append(const char* s);
	CMyString& append(const char* s, size_t n);
	CMyString& append(size_t n, char c);

	void push_back(char c);

	CMyString& assign(const CMyString & str);
	CMyString& assign(const CMyString & str, size_t subpos, size_t sublen);
	CMyString& assign(const char* s);
	CMyString& assign(const char* s, size_t n);
	CMyString& assign(size_t n, char c);

	CMyString& insert(size_t pos, const CMyString & str);
	CMyString& insert(size_t pos, const CMyString & str, size_t subpos, size_t sublen);
	CMyString& insert(size_t pos, const char* s);
	CMyString& insert(size_t pos, const char* s, size_t n);
	CMyString& insert(size_t pos, size_t n, char c);
	void insert(Iterator p, size_t n, char c);

	CMyString& erase(size_t pos = 0, size_t len = npos);

	CMyString& replace(size_t pos, size_t len, const CMyString & str);
	CMyString& replace(size_t pos, size_t len, const CMyString & str, size_t subpos, size_t sublen);
	CMyString& replace(size_t pos, size_t len, const char* s);
	CMyString& replace(size_t pos, size_t len, const char* s, size_t n);
	CMyString& replace(size_t pos, size_t len, size_t n, char c);

	void swap(CMyString & str);

	void pop_back();



	system("pause");
	return EXIT_SUCCESS;
}