#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<string>
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
	cout << "\nOriginal string 2: ";
	puts(dummy7);

	CMyString m13 = dummy6;
	CMyString m14 = dummy7;

	m13 += m14;
	cout << "\n[String 1 += String 2]: String 1: " << m13;

	m13.append(m14);
	cout << "\n[String 1 append String 2]: String 1: " << m13;

	m14.push_back('z');
	cout << "\n[String 2.push_pack('z')]: String 2: " << m14;

	m14.pop_back();
	cout << "\n[String 2.pop_pack()]: String 2: " << m14;

	m14.assign(m13, 2, 6);
	cout << "\n[String 2.assign(m13, 2, 6)]: String 2: " << m14;

	m14.replace(3, 3, "aaa");
	cout << "\n[String 2.replace(3, 3, aaa)]: String 2: " << m14;

	m14.insert(3, "aaa");
	cout << "\n[String 2.insert(3, aaa)]: String 2: " << m14;

	m14.swap(m13);
	cout << "\n[String 2.swap(String 1)]: String 2: " << m14;


	cout << endl << endl;


	/*
	Tìm kiếm só sánh trên chuổi
	*/

	cout << "\n\n------ STRING OPERATIONS ----------\n\n";

	const char* dummy8 = "testing string";
	cout << "\n\nOriginal string 1: ";
	puts(dummy8);
	const char* dummy9 = "operations";
	cout << "\nOriginal string 2: ";
	puts(dummy9);

	CMyString m15 = dummy8;
	CMyString m16 = dummy9;

	cout << "\n[String 1 to char*]: String 1: " << m15.c_str();
	
	char* test = new char[100];
	int l = m15.copy(test, 2, 6);
	cout << "\n[String 1.copy(test, 2, 6)]: Test: " << *test;

	cout << "\n[String 1.find(String 2, 0)]: Index: " << m15.find(m16, 0);
	cout << "\n[String 1.rfind(String 2, 10)]: Index: " << m15.rfind(m16, 10);
	cout << "\n[String 1.find_first_of(String 2, 10)]: Index: " << m15.find_first_of(m16, 10);
	cout << "\n[String 1.find_last_of(String 2, 10)]: Index: " << m15.find_last_of(m16, 10);
	cout << "\n[String 1.find_first_not_of(String 2, 10)]: Index: " << m15.find_first_not_of(m16, 10);
	cout << "\n[String 1.find_last_not_of(String 2, 10)]: Index: " << m15.find_last_not_of(m16, 10);

	m16 = m15.substr(0, 5);
	cout << "\n[String 2 = String 1.substr(0, 5)]: String 2:  " << m16;
	cout << "\n[String 2.compare(String 1)]: Result:  " << m16.compare(m15);

	
	cout << endl << endl;


	/*
	Các toán tử và các phương thức khác
	*/

	cout << "\n\n------ NON-MEMBER FUNCTION OVERLOADS ----------\n\n";

	const char* dummy10 = "testing non-member";
	cout << "\n\nOriginal string 1: ";
	puts(dummy10);
	const char* dummy11 = "function overloads";
	cout << "\nOriginal string 2: ";
	puts(dummy11);

	CMyString m17 = dummy10;
	CMyString m18 = dummy11;

	CMyString tem;
	string tem1;

	cout << "\n[String = String 1 + String 2]: String: " << m17 + " " + m18;
	cout << "\n[String 1 == String 2]: Result: " << (m17 == m18);
	cout << "\n[String 1 != String 2]: Result: " << (m17 != m18);
	cout << "\n[String 1 < String 2]: Result: " << (m17 < m18);
	cout << "\n[String 1 <= String 2]: Result: " << (m17 <= m18);
	cout << "\n[String 1 > String 2]: Result: " << (m17 > m18);
	cout << "\n[String 1 >= String 2]: Result: " << (m17 >= m18);

	cout << "\n[Operator >>]: ENTER string: ";
	cin >> tem;
	cin.ignore(0);
	cout << "[Operator <<]: OUTPUT string: ";
	cout << tem;

	cin >> noskipws;

	cout << "\n[Method getline]: ENTER string: ";
	getline(cin, tem1);
	get_line(cin, tem);
	cin.ignore(0);
	cout << "[Operator <<]: OUTPUT string: ";
	cout << tem;
	
	cout << endl << endl;

	system("pause");
	return EXIT_SUCCESS;
}