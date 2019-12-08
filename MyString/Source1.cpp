#include<iostream>
using namespace std;

#include"CMyString.h"


int main()
{

	CMyString ck("1223345");

	cout << ck.size() << endl;
	cout << ck.length() << endl;
	cout << ck.max_size() << endl;
	cout << ck.capacity() << endl;

	ck.resize(50);
	cout << ck.size() << endl;
	ck.shrink_to_fit();
	cout << ck.size() << endl;
	ck.clear();
	cout << ck.size() << endl;

	
	system("pause");
	return EXIT_SUCCESS;
}