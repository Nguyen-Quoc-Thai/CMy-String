#include<iterator>

using namespace std;

class Iterator : public iterator<input_iterator_tag, char>
{
public:
	typedef char* pointer;
public:
	char* p;
	pointer ptr;

	Iterator() {
		this->p = NULL;
		this->ptr = NULL;
	}
	Iterator(char* x) :p(x) {}
	Iterator(const Iterator& mit) : p(mit.p) {}
	Iterator& operator++() {
		++p;
		return *this;
	}
	Iterator operator+(int n) {
		Iterator tmp(*this);
		tmp.p += n;
		return tmp;
	}
	Iterator operator++(int) {
		Iterator tmp(*this);
		operator++();
		return tmp;
	}
	Iterator& operator--() {
		--p; return *this;
	}
	Iterator operator--(int) {
		Iterator tmp(*this);
		operator--();
		return tmp;
	}
	bool operator==(const Iterator& rhs) const {
		return p == rhs.p;
	}
	bool operator!=(const Iterator& rhs) const {
		return p != rhs.p;
	}
	char& operator*() {
		return *p;
	}
	pointer operator->() {
		return ptr;
	}
};