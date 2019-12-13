#include<iterator>

using namespace std;

class Const_Iterator : public iterator<input_iterator_tag, char>
{
public:
	typedef const char* Pointer;
public:
	const char* p;
	Pointer ptr;

	Const_Iterator(const char* s) :p(s) {}
	Const_Iterator(const Const_Iterator& m) : p(m.p) {}

	Const_Iterator& operator++() {++p; return *this;}
	Const_Iterator operator++(int) { Const_Iterator tmp(*this); operator++(); return tmp; }

	Const_Iterator& operator--() {--p; return *this; }
	Const_Iterator operator--(int) { Const_Iterator tmp(*this); operator--(); return tmp; }

	bool operator==(const Const_Iterator& rhs) const { return p == rhs.p; }
	bool operator!=(const Const_Iterator& rhs) const { return p != rhs.p; }

	const char& operator* () { return *p; }
	const Pointer operator->() { return ptr; }
};
