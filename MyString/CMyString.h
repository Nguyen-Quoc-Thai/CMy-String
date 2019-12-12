#pragma once

#include"Iterator.cpp"
#include"Const_Iterator.cpp"
#include"Reverse_Iterator.cpp"
#include"Const_Reverse_Iterator.cpp"

#include<iostream>
#include<fstream>
#include<string.h>
#include<time.h>

using namespace std;

// Member constance
static const size_t npos = -1;

class CMyString
{
private:
	char* string_;    // Chuổi các kí tự
	size_t capacity_; // kích thức bộ nhớ lưu chuổi string
	size_t length_;   // Chiều dài của chuổi

	void str_cpy(char*& dest, const char* source);
	void str_sub(char*& dest, char* substr, size_t subpos, size_t sublen);

public:

	// Constructor:
	CMyString();
	CMyString(const CMyString& str);
	CMyString(const CMyString& str, size_t pos, size_t len = npos);
	CMyString(const char* s);
	CMyString(const char* s, size_t n);
	CMyString(size_t n, char c);


	// Destructor
	~CMyString();

	// Operator =
	CMyString& operator= (const CMyString& str);
	CMyString& operator= (const char* s);
	CMyString& operator= (char c);

	// Iterator
	Iterator begin();
	const Iterator begin() const;

	Iterator end();
	const Iterator end() const;

	Reverse_Iterator rbegin();
	const Reverse_Iterator rbegin() const;

	Reverse_Iterator rend();
	const Reverse_Iterator rend() const;

	const Const_Iterator cbegin() const;
	const Const_Iterator cend() const;
	const Const_Reverse_Iterator crbegin() const;
	const Const_Reverse_Iterator crend() const;

	// Capacity
	size_t size() const;
	size_t length() const;
	size_t max_size() const;

	void resize(size_t n);
	void resize(size_t n, char c);

	size_t capacity();
	void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();

	// Element access----------------------------------------------------------------------------------------
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;

	char& at(size_t pos);
	const char& at(size_t pos) const;

	char& back();
	const char& back() const;

	char& front();
	const char& front() const;

	// Modifiers ----------------------------------------------------------------------------------------
	CMyString& operator+= (const CMyString& str);
	CMyString& operator+= (const char* s);
	CMyString& operator+= (char c);

	CMyString& append(const CMyString& str);
	CMyString& append(const CMyString& str, size_t subpos, size_t sublen);
	CMyString& append(const char* s);
	CMyString& append(const char* s, size_t n);
	CMyString& append(size_t n, char c);

	void push_back(char c);

	CMyString& assign(const CMyString& str);
	CMyString& assign(const CMyString& str, size_t subpos, size_t sublen);
	CMyString& assign(const char* s);
	CMyString& assign(const char* s, size_t n);
	CMyString& assign(size_t n, char c);

	CMyString& insert(size_t pos, const CMyString& str);
	CMyString& insert(size_t pos, const CMyString& str, size_t subpos, size_t sublen);
	CMyString& insert(size_t pos, const char* s);
	CMyString& insert(size_t pos, const char* s, size_t n);
	CMyString& insert(size_t pos, size_t n, char c);
	void insert(Iterator p, size_t n, char c);

	CMyString& erase(size_t pos = 0, size_t len = npos);

	CMyString& replace(size_t pos, size_t len, const CMyString& str);
	CMyString& replace(size_t pos, size_t len, const CMyString& str, size_t subpos, size_t sublen);
	CMyString& replace(size_t pos, size_t len, const char* s);
	CMyString& replace(size_t pos, size_t len, const char* s, size_t n);
	CMyString& replace(size_t pos, size_t len, size_t n, char c);

	void swap(CMyString& str);

	void pop_back();

	// String operations ----------------------------------------------------------------------------------------
	const char* c_str() const;

	const char* data() const;

	allocator<char> get_allocator() const;

	size_t copy(char* s, size_t len, size_t pos = 0) const;

	size_t find(const CMyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;

	size_t rfind(const CMyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;

	size_t find_first_of(const CMyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;

	size_t find_last_of(const CMyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;

	size_t find_first_not_of(const CMyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;

	size_t find_last_not_of(const CMyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;

	CMyString substr(size_t pos = 0, size_t len = npos) const;

	int compare(const CMyString& str) const;
	int compare(size_t pos, size_t len, const CMyString& str) const;
	int compare(size_t pos, size_t len, const CMyString& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;

	// Non-member function overloads ----------------------------------------------------------------------------------------
	friend CMyString operator+ (const CMyString& lhs, const CMyString& rhs);
	friend CMyString operator+ (const CMyString& lhs, const char* rhs);
	friend CMyString operator+ (const char* lhs, const CMyString& rhs);
	friend CMyString operator+ (const CMyString& lhs, char rhs);
	friend CMyString operator+ (char lhs, const CMyString& rhs);

	friend bool operator== (const CMyString& lhs, const CMyString& rhs);
	friend bool operator== (const char* lhs, const CMyString& rhs);
	friend bool operator== (const CMyString& lhs, const char* rhs);

	friend bool operator!= (const CMyString& lhs, const CMyString& rhs);
	friend bool operator!= (const char* lhs, const CMyString& rhs);
	friend bool operator!= (const CMyString& lhs, const char* rhs);

	friend bool operator<  (const CMyString& lhs, const CMyString& rhs);
	friend bool operator<  (const char* lhs, const CMyString& rhs);
	friend bool operator<  (const CMyString& lhs, const char* rhs);

	friend bool operator<= (const CMyString& lhs, const CMyString& rhs);
	friend bool operator<= (const char* lhs, const CMyString& rhs);
	friend bool operator<= (const CMyString& lhs, const char* rhs);

	friend bool operator>  (const CMyString& lhs, const CMyString& rhs);
	friend bool operator>  (const char* lhs, const CMyString& rhs);
	friend bool operator>  (const CMyString& lhs, const char* rhs);

	friend bool operator>= (const CMyString& lhs, const CMyString& rhs);
	friend bool operator>= (const char* lhs, const CMyString& rhs);
	friend bool operator>= (const CMyString& lhs, const char* rhs);

	void swap(CMyString& x, CMyString& y);

	friend istream& operator>> (istream& is, CMyString& str);
	friend ostream& operator<< (ostream& os, const CMyString& str);

	friend istream& get_line(istream& is, CMyString& str, char delim);
	friend istream& get_line(istream& is, CMyString& str);
};

