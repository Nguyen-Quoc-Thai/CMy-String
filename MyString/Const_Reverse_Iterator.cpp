#include<iterator>

using namespace std;

class  Const_Reverse_Iterator : public iterator<input_iterator_tag, char>
{
public:
	typedef const char* pointer;
public:
	const char* p;
	pointer ptr;

	Const_Reverse_Iterator() {
		this->p = NULL;
		this->ptr = NULL;
	}
	Const_Reverse_Iterator(const char* x) :p(x) {}
	Const_Reverse_Iterator(const Const_Reverse_Iterator& mit) : p(mit.p) {}
	Const_Reverse_Iterator& operator++() {
		--p;
		return *this;
	}
	Const_Reverse_Iterator operator++(int) {
		Const_Reverse_Iterator tmp(*this);
		operator--();
		return tmp;
	}
	Const_Reverse_Iterator& operator--() {
		++p; return *this;
	}
	Const_Reverse_Iterator operator--(int) {
		Const_Reverse_Iterator tmp(*this);
		operator++();
		return tmp;
	}
	bool operator==(const Const_Reverse_Iterator& rhs) const {
		return p == rhs.p;
	}
	bool operator!=(const Const_Reverse_Iterator& rhs) const {
		return p != rhs.p;
	}
	const char& operator*() {
		return *p;
	}
	const pointer operator->() {
		return ptr;
	}
};