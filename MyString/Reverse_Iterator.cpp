#include<iterator>

using namespace std;

class  Reverse_Iterator : public iterator<input_iterator_tag, char>
{
public:
	typedef char* pointer;
public:
	char* p;
	pointer ptr;

	Reverse_Iterator() {
		this->p = NULL;
		this->ptr = NULL;
	}
	Reverse_Iterator(char* x) :p(x) {}
	Reverse_Iterator(const Reverse_Iterator& mit) : p(mit.p) {}
	Reverse_Iterator& operator++() {
		--p;
		return *this;
	}
	Reverse_Iterator operator++(int) {
		Reverse_Iterator tmp(*this);
		operator--();
		return tmp;
	}
	Reverse_Iterator& operator--() {
		++p; return *this;
	}
	Reverse_Iterator operator--(int) {
		Reverse_Iterator tmp(*this);
		operator++();
		return tmp;
	}
	bool operator==(const Reverse_Iterator& rhs) const {
		return p == rhs.p;
	}
	bool operator!=(const Reverse_Iterator& rhs) const {
		return p != rhs.p;
	}
	char& operator*() {
		return *p;
	}
	pointer operator->() {
		return ptr;
	}
};