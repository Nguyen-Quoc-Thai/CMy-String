#include<iterator>

using namespace std;

class  Const_Reverse_Iterator : public iterator<input_iterator_tag, char>
{
public:
	typedef const char* Pointer;
public:
	const char* p;
	Pointer ptr;

	Const_Reverse_Iterator() { this->p = NULL; this->ptr = NULL; }
	Const_Reverse_Iterator(const char* s) : p(s) {}
	Const_Reverse_Iterator(const Const_Reverse_Iterator& m) : p(m.p) {}

	Const_Reverse_Iterator& operator++() {--p; return *this;}
	Const_Reverse_Iterator operator++(int) {Const_Reverse_Iterator tmp(*this);operator--();return tmp;}

	Const_Reverse_Iterator& operator--() {++p; return *this;}
	Const_Reverse_Iterator operator--(int) {Const_Reverse_Iterator tmp(*this);operator++();return tmp;}

	bool operator==(const Const_Reverse_Iterator& rhs) const {return p == rhs.p;}

	bool operator!=(const Const_Reverse_Iterator& rhs) const {return p != rhs.p;}

	const char& operator*() {return *p;}

	const Pointer operator->() {return ptr;}
};