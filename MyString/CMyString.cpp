#include "CMyString.h"

// Phương thức nội hỗ trợ việc copy và cắt chuổi

/*
Phương thức copy chuổi source vào chuổi dest
*/
void CMyString::str_cpy(char*& dest, const char* source)
{
	int length = strlen(source);
	dest = new char[16 + length];

	for (int j = 0; j < length; j++)
		dest[j] = source[j];

	dest[length] = '\0';
	
}

/*
Phương thức cắt chuổi substr vào chuổi dest từ vị trí subpos sublen phần tử
*/
void CMyString::str_sub(char*& dest, char* substr, size_t subpos, size_t sublen)
{
	dest = new char[sublen + 1];

	int k = subpos;
	int i = 0;

	while (i < sublen) {
		dest[i] = substr[k];
		k++;
		i++;
	}

	dest[sublen] = '\0';
}


// Phương thức khởi tạo:

CMyString::CMyString()
{
	this->length_ = 0;
	this->capacity_ = 0;
	this->string_ = new char[1];
	this->string_[0] = '\0';
}

CMyString::CMyString(const CMyString& str)
{
	this->length_ = strlen(str.string_);
	this->capacity_ = this->length_ + 16;
	str_cpy(this->string_, str.string_);
}

CMyString::CMyString(const CMyString& str, size_t pos, size_t len)
{
	char* _dummy = NULL;
	char* _dummy2 = NULL;

	str_cpy(_dummy, str.string_);
	str_sub(_dummy2, _dummy, pos, len);

	*this = CMyString();

	*this = _dummy2;

	delete[]_dummy, _dummy2;
}

CMyString::CMyString(const char* s)
{
	if (s != NULL)
	{
		this->length_ = strlen(s);
		this->capacity_ = strlen(s) + 16;
		str_cpy(this->string_, s);
	}
	else
	{
		this->capacity_ = 0;
		this->length_ = 0;
		string_ = new char[0];
	}
}

CMyString::CMyString(const char* s, size_t n)
{
	delete[]this->string_;
	this->string_ = NULL;
	this->length_ = 0;

	this->length_ = n;
	this->capacity_ = this->length_ + 16;

	str_cpy(this->string_, s);
}

CMyString::CMyString(size_t n, char c)
{
	this->length_ = n;
	this->capacity_ = this->length_ + 16;
	this->string_ = new char[this->capacity_];
	
	for (size_t i = 0; i < this->length_; i++) {
		this->string_[i] = c;

	}

	this->string_[this->length_] = '\0';
}

// phương thức hủy
CMyString::~CMyString()
{
	delete[] string_;
}

// Toán tử gán =
CMyString& CMyString::operator=(const CMyString& str)
{
	// TODO: insert return statement here

	if (this != &str) {
		this->clear();

		this->length_ = strlen(str.string_);
		this->capacity_ = this->length_ + 16;
		str_cpy(this->string_, str.string_);
	}

	return *this;
}

CMyString& CMyString::operator=(const char* s)
{
	// TODO: insert return statement here

	this->clear();

	this->length_ = strlen(s);
	this->capacity_ = this->length_ + 16;
	str_cpy(this->string_, s);

	return *this;
}

CMyString& CMyString::operator=(char c)
{
	// TODO: insert return statement here

	this->clear();

	this->length_ = 1;
	this->capacity_ = this->length_ + 16;
	this->string_ = new char[this->capacity_];
	this->string_[0] = c;
	this->string_[1] = '\0';

	return *this;
}

// Iterator
Iterator CMyString::begin()
{
	return Iterator(this->string_);
}

const Iterator CMyString::begin() const
{
	return Iterator(this->string_);
}

Iterator CMyString::end()
{
	return Iterator(this->string_ + this->length_);
}

const Iterator CMyString::end() const
{
	return Iterator(this->string_ + this->length_);
}

Reverse_Iterator CMyString::rbegin()
{
	return Reverse_Iterator(this->string_ + (this->length_ - 1));
}

const Reverse_Iterator CMyString::rbegin() const
{
	return Reverse_Iterator(this->string_ + (this->length_ - 1));
}

Reverse_Iterator CMyString::rend()
{
	return Reverse_Iterator(this->string_ - 1);
}

const Reverse_Iterator CMyString::rend() const
{
	return Reverse_Iterator(this->string_ - 1);
}

const Const_Iterator CMyString::cbegin() const
{
	return Const_Iterator(this->string_);
}

const Const_Iterator CMyString::cend() const
{
	return Const_Iterator(this->string_ + this->length_);
}

const Const_Reverse_Iterator CMyString::crbegin() const
{
	return Const_Reverse_Iterator(this->string_ + (this->length_ - 1));
}

const Const_Reverse_Iterator CMyString::crend() const
{
	return Const_Reverse_Iterator(this->string_ - 1);
}

void CMyString::swap(CMyString& x, CMyString& y)
{
	CMyString _dummy = x;
	x = y;
	y = _dummy;
}

// delim là kí tự kết thúc
istream& CMyString::getline(istream& is, CMyString& str, char delim)
{
	// TODO: insert return statement here

	char* _dummy = new char[1001];

	gets_s(_dummy, 1000);

	CMyString _dummy2;

	int len = 0;

	for (int i = 0; i < strlen(_dummy); i++) {
		if (_dummy[i] == delim) {
			len = i;
			break;
		}
	}

	_dummy2.length_ = len;
	_dummy2.capacity_ = _dummy2.length_ + 16;
	_dummy2.string_ = new char[_dummy2.capacity_];

	for (int i = 0; i < _dummy2.length_; i++) {
		_dummy2.string_[i] = _dummy[i];
	}

	_dummy2.string_[_dummy2.length_] = '\0';

	str = _dummy2;

	delete[] _dummy;
	_dummy2.~CMyString();

	return is;
}

istream& CMyString::getline(istream& is, CMyString& str)
{
	// TODO: insert return statement here

	char* _dummy = new char[1001];
	is >> _dummy;

	str = _dummy;
	int len = strlen(_dummy);

	str.string_[len] = '\0';

	delete[] _dummy;

	return is;
}

size_t CMyString::size() const
{
	return size_t(this->length_);
}

size_t CMyString::length() const
{
	return size_t(this->length_);
}

size_t CMyString::max_size() const
{
	return size_t(pow(2, 32) - 1);
}

void CMyString::resize(size_t n)
{
	if (n > 0) {
		char* _dummy = NULL;
		str_cpy(_dummy, this->string_);

		if (n > this->length_) {
			this->length_ = n;
			this->capacity_ = length_ + 16;
			this->string_ = new char[this->capacity_];

			for (size_t j = 0; j < strlen(_dummy); j++) {
				this->string_[j] = _dummy[j];
			}
			this->string_[strlen(_dummy)] = '\0';
		}
		else {
			this->length_ = n;
			this->string_ = new char[this->length_ + 1];

			size_t i = 0;

			while (i < n) {
				this->string_[i] = _dummy[i];
				i++;
			}

			this->string_[i] = '\0';
		}
		delete[]_dummy;
	}
}

void CMyString::resize(size_t n, char c)
{
	if (n > 0) {
		char* _dummy = NULL;
		str_cpy(_dummy, this->string_);

		if (n > this->length_) {
			this->length_ = n;
			this->capacity_ = length_ + 16;
			this->string_ = new char[this->capacity_];

			for (size_t j = 0; j < strlen(_dummy); j++) {
				this->string_[j] = _dummy[j];
			}

			size_t count = 0;
			size_t k = strlen(_dummy);
			while (count < n - k) {
				this->string_[k] = c;
				k++;
				count++;
			}

			this->string_[this->length_] = '\0';
		}
		else {
			this->length_ = n;
			this->string_ = new char[this->length_ + 1];

			size_t i = 0;

			while (i < n) {
				this->string_[i] = _dummy[i];
				i++;
			}

			this->string_[i] = '\0';
		}

		delete[]_dummy;
	}
}

size_t CMyString::capacity()
{
	return size_t(this->capacity_);
}

void CMyString::reserve(size_t n)
{
	if (n > this->capacity_) {
		char* _dummy = NULL;
		str_cpy(_dummy, this->string_);

		*this = CMyString();

		this->length_ = n;
		this->capacity_ = n + 16;

		this->string_ = new char[this->capacity_];

		for (int i = 0; i < strlen(_dummy); i++) {
			this->string_[i] = _dummy[i];
		}

		this->string_[strlen(_dummy)] = '\0';

		delete[]_dummy;
	}
}

void CMyString::clear()
{
	this->length_ = 0;
	this->capacity_ = 0;
	delete[]this->string_;
	this->string_ = NULL;
}

bool CMyString::empty() const
{
	if (this->length_ == 0 && this->string_ == NULL) {
		return true;
	}

	return false;
}

void CMyString::shrink_to_fit()
{
	char* _dummy = NULL;
	str_cpy(_dummy, this -> string_);

	this->clear();

	this->length_ = strlen(_dummy);
	this->capacity_ = this->length_ + 1;

	this->string_ = new char[this->capacity_];

	for (int i = 0; i < this->length_; i++) {
		this->string_[i] = _dummy[i];
	}

	this->string_[this->length_] = '\0';

}

char& CMyString::operator[](size_t pos)
{
	// TODO: insert return statement here

	return this->string_[pos];
}

const char& CMyString::operator[](size_t pos) const
{
	// TODO: insert return statement here

	return this->string_[pos];
}

char& CMyString::at(size_t pos)
{
	// TODO: insert return statement here

	return this->string_[pos];
}

const char& CMyString::at(size_t pos) const
{
	// TODO: insert return statement here

	return this->string_[pos];
}

char& CMyString::back()
{
	// TODO: insert return statement here

	return this->string_[this->length_ - 1];
}

const char& CMyString::back() const
{
	// TODO: insert return statement here

	return this->string_[this->length_ - 1];
}

char& CMyString::front()
{
	// TODO: insert return statement here

	return this->string_[0];
}

const char& CMyString::front() const
{
	// TODO: insert return statement here

	return this->string_[0];
}

CMyString& CMyString::operator+=(const CMyString& str)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	str_cpy(_dummy,this->string_);

	this->length_ += str.length_;
	this->capacity_ = this->length_ + 16;

	this->string_ = new char[this->capacity_];

	int i = 0;
	while (_dummy[i] != '\0')
	{
		this->string_[i] = _dummy[i];
		i++;
	}

	int j = i, k = 0;
	while (str.string_[k] != '\0')
	{
		this->string_[j] = str.string_[k];
		k++;
		j++;
	}

	this->string_[j] = '\0';

	delete[] _dummy;

	return *this;
}

CMyString& CMyString::operator+=(const char* s)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	str_cpy(_dummy, this->string_);

	this->length_ += strlen(s);
	this->capacity_ = this->length_ + 16;

	this->string_ = new char[this->capacity_];

	int i = 0;
	while (_dummy[i] != '\0')
	{
		this->string_[i] = _dummy[i];
		i++;
	}

	int j = i, k = 0;
	while (s[k] != '\0')
	{
		this->string_[j] = s[k];
		k++;
		j++;
	}

	this->string_[j] = '\0';

	delete[] _dummy;

	return *this;
}

CMyString& CMyString::operator+=(char c)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	str_cpy(_dummy, this->string_);

	this->length_ = strlen(_dummy) + 1;
	this->capacity_ = this->length_ + 16;

	this->string_ = new char[this->capacity_];

	int i = 0;
	while (_dummy[i] != '\0') {
		this->string_[i] = _dummy[i];
		i++;
	}

	this->string_[i] = c;
	this->string_[i + 1] = '\0';

	delete[]_dummy;
	return *this;
}

CMyString& CMyString::append(const CMyString& str)
{
	// TODO: insert return statement here

	*this += str;
	return *this;
}

CMyString& CMyString::append(const CMyString& str, size_t subpos, size_t sublen)
{
	// TODO: insert return statement here

	char* _dummy = NULL;

	str_sub(_dummy, str.string_, subpos, sublen);

	*this += _dummy;

	delete[] _dummy;

	return *this;
}

CMyString& CMyString::append(const char* s)
{
	// TODO: insert return statement here

	*this += s;
	return *this;
}

CMyString& CMyString::append(const char* s, size_t n)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	_dummy = new char[n + 1];

	for (int i = 0; i < n; i++) {
		_dummy[i] = s[i];
	}

	_dummy[n] = '\0';

	*this += _dummy;

	delete[]_dummy;

	return *this;
}

CMyString& CMyString::append(size_t n, char c)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	_dummy = new char[n + 1];

	for (int i = 0; i < n; i++) {
		_dummy[i] = c;
	}

	_dummy[n] = '\0';

	*this += _dummy;

	delete[]_dummy;

	return *this;
}

void CMyString::push_back(char c)
{
	*this += c;
}

CMyString& CMyString::assign(const CMyString& str)
{
	// TODO: insert return statement here

	return *this = CMyString(str);
}

CMyString& CMyString::assign(const CMyString& str, size_t subpos, size_t sublen)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	str_sub(_dummy, str.string_, subpos, sublen);

	*this = CMyString(_dummy);

	delete[] _dummy;
	return *this;
}

CMyString& CMyString::assign(const char* s)
{
	// TODO: insert return statement here

	return *this = CMyString(s);
}

CMyString& CMyString::assign(const char* s, size_t n)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;

	str_cpy(_dummy2, s);
	str_sub(_dummy, _dummy2, 0, n);

	*this = CMyString(_dummy);

	delete[] _dummy;
	delete[] _dummy2;

	return *this;
}

CMyString& CMyString::assign(size_t n, char c)
{
	// TODO: insert return statement here

	CMyString _dummy;

	_dummy.append(n, c);

	*this = CMyString(_dummy);

	return *this;
}

CMyString& CMyString::insert(size_t pos, const CMyString& str)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;

	str_cpy(_dummy, this->string_);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy, pos, strlen(_dummy) - pos);

	*this = CMyString();

	*this += _dummy2;
	*this += str.string_;
	*this += _dummy3;

	delete[] _dummy, _dummy2, _dummy3;

	return *this;

}

CMyString& CMyString::insert(size_t pos, const CMyString& str, size_t subpos, size_t sublen)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;
	char* _dummy4 = NULL;

	str_cpy(_dummy, this->string_);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy, pos, strlen(_dummy) - pos);
	str_sub(_dummy4, str.string_, subpos, sublen);

	*this = CMyString();

	*this += _dummy2;
	*this += _dummy4;
	*this += _dummy3;

	delete[] _dummy, _dummy2, _dummy3, _dummy4;

	return *this;
}

CMyString& CMyString::insert(size_t pos, const char* s)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;

	str_cpy(_dummy, this->string_);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy, pos, strlen(_dummy) - pos);

	*this = CMyString();

	*this += _dummy2;
	*this += s;
	*this += _dummy3;

	delete[] _dummy, _dummy2, _dummy3;

	return *this;
}

CMyString& CMyString::insert(size_t pos, const char* s, size_t n)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;
	char* _dummy4 = NULL;
	char* _dummy5 = NULL;

	str_cpy(_dummy, this->string_);
	str_cpy(_dummy5, s);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy, pos, strlen(_dummy) - pos);
	str_sub(_dummy4, _dummy5, 0, n);

	*this = CMyString();

	*this += _dummy2;
	*this += _dummy4;
	*this += _dummy3;

	delete[] _dummy, _dummy2, _dummy3, _dummy4, _dummy5;

	return *this;
}

CMyString& CMyString::insert(size_t pos, size_t n, char c)
{
	// TODO: insert return statement here

	CMyString _dummy;

	_dummy.append(n, c);

	this->insert(pos, _dummy);

	_dummy.~CMyString();

	return *this;
}

void CMyString::insert(Iterator p, size_t n, char c)
{
	CMyString _dummy;

	_dummy.append(n, c);

	this->insert(*p, _dummy);

	_dummy.~CMyString();

}

CMyString& CMyString::erase(size_t pos, size_t len)
{
	// TODO: insert return statement here

	if (pos < 0 || pos > this->length_ - 1) {
		cout << "Pos error !" << endl;
		return *this;
	}

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;

	str_cpy(_dummy, this->string_);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy, pos + len, strlen(_dummy) -  (pos + len));
}

CMyString& CMyString::replace(size_t pos, size_t len, const CMyString& str)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;
	char* _dummy4 = NULL;

	str_cpy(_dummy, this->string_);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, str.string_, 0, len);
	str_sub(_dummy4, _dummy, pos + len, strlen(_dummy) - (pos + len));
	
	*this = CMyString();

	*this += _dummy2;
	*this += _dummy3;
	*this += _dummy4;

	delete[] _dummy, _dummy2, _dummy3, _dummy4;

	return *this;
}

CMyString& CMyString::replace(size_t pos, size_t len, const CMyString& str, size_t subpos, size_t sublen)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;
	char* _dummy4 = NULL;
	char* _dummy5 = NULL;

	str_cpy(_dummy, this->string_);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, str.string_, subpos, sublen);
	str_sub(_dummy5, _dummy3, 0, len);
	str_sub(_dummy4, _dummy, pos + len, strlen(_dummy) - (pos + len));

	*this = CMyString();

	*this += _dummy2;
	*this += _dummy5;
	*this += _dummy4;

	delete[] _dummy, _dummy2, _dummy3, _dummy4, _dummy5;

	return *this;
}

CMyString& CMyString::replace(size_t pos, size_t len, const char* s)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;
	char* _dummy4 = NULL;
	char* _dummy5 = NULL;

	str_cpy(_dummy, this->string_);
	str_cpy(_dummy5, s);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy5, 0, len);
	str_sub(_dummy4, _dummy, pos + len, strlen(_dummy) - (pos + len));

	*this = CMyString();

	*this += _dummy2;
	*this += _dummy3;
	*this += _dummy4;

	delete[] _dummy, _dummy2, _dummy3, _dummy4, _dummy5;

	return *this;

}


CMyString& CMyString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	// TODO: insert return statement here

	char* _dummy = NULL;
	char* _dummy2 = NULL;
	char* _dummy3 = NULL;
	char* _dummy4 = NULL;
	char* _dummy5 = NULL;
	char* _dummy6 = NULL;

	str_cpy(_dummy, this->string_);
	str_cpy(_dummy6, s);
	str_sub(_dummy2, _dummy, 0, pos);
	str_sub(_dummy3, _dummy6, 0, n);
	str_sub(_dummy5, _dummy3, 0, len);
	str_sub(_dummy4, _dummy, pos + len, strlen(_dummy) - (pos + len));

	*this = CMyString();

	*this += _dummy2;
	*this += _dummy5;
	*this += _dummy4;

	delete[] _dummy, _dummy2, _dummy3, _dummy4, _dummy5, _dummy6;

	return *this;
}


CMyString& CMyString::replace(size_t pos, size_t len, size_t n, char c)
{
	// TODO: insert return statement here

	CMyString _dummy;
	_dummy.append(n, c);

	return this->replace(pos, len, _dummy.string_);

	_dummy.~CMyString();
}

void CMyString::swap(CMyString& str)
{
	CMyString _dummy = *this;

	*this = str;

	str = _dummy;
}

void CMyString::pop_back()
{
	char* _dummy = NULL;
	str_cpy(_dummy, this->string_);

	this->clear();

	this->length_ = strlen(_dummy) - 1;
	this->capacity_ = this->length_ + 16;

	this->string_ = new char[this->capacity_];

	for (int i = 0; i < this->length_; i++) {
		this->string_[i] = _dummy[i];
	}

	this->string_[this->length_] = '\0';
}

const char* CMyString::c_str() const
{
	return this->string_;
}

const char* CMyString::data() const
{
	return nullptr;
}

allocator<char> CMyString::get_allocator() const
{
	return allocator<char>();
}

size_t CMyString::copy(char* s, size_t len, size_t pos) const
{
	if (pos < 0 || pos >= this->length_)
		return -1;

	int k = 0;
	for (int i = pos; i < (pos) + len; i++) {
		s[k] = this->string_[i];
		k++;
	}

	s[pos + len] = '\0';

	return len;
}

size_t CMyString::find(const CMyString& str, size_t pos) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = 0; i < this->length_; i++) {
		if (str.string_[i] == this->string_[i] && this->length_ - i >= str.length_) {
			int k = i;

			for (int j = 0; j < strlen(str.string_); j++) {
				if (str.string_[j] != this->string_[k]) {
					break;
				}

				if (j == strlen(str.string_) - 1) {
					return i;
				}
				k++;
			}
		}
	}

	return this->length_;
}

size_t CMyString::find(const char* s, size_t pos) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = 0; i < this->length_; i++) {
		if (s[i] == this->string_[i] && this->length_ - i >= strlen(s)) {
			int k = i;

			for (int j = 0; j < strlen(s); j++) {
				if (s[j] != this->string_[k]) {
					break;
				}

				if (j == strlen(s) - 1) {
					return i;
				}
				k++;
			}
		}
	}

	return this->length_;
}

size_t CMyString::find(const char* s, size_t pos, size_t n) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = pos; i < pos + n; i++) {
		if (s[i] == this->string_[i] && this->length_ - i >= strlen(s)) {
			int k = i;

			for (int j = 0; j < strlen(s); j++) {
				if (s[j] != this->string_[k]) {
					break;
				}

				if (j == strlen(s) - 1) {
					return i;
				}

				k++;
			}
		}
	}

	return this->length_;
}

size_t CMyString::find(char c, size_t pos) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = pos; i < this->length_; i++) {
		if (this->string_[i] == c) {
			return i;
		}
	}

	return this->length_;
}

size_t CMyString::rfind(const CMyString& str, size_t pos) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = length_ - pos; i >= 0; i--) {
		if (str.string_[i] == this->string_[i] && this->length_ - i >= str.length_) {
			int k = i;

			for (int j = 0; j < strlen(str.string_); j++) {
				if (str.string_[j] != this->string_[k]) {
					break;
				}

				if (j == strlen(str.string_) - 1) {
					return i;
				}
				k++;
			}
		}
	}

	return this->length_;
}

size_t CMyString::rfind(const char* s, size_t pos) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = length_ - pos; i >= 0; i--) {
		if (s[i] == this->string_[i] && this->length_ - i >= strlen(s)) {
			int k = i;

			for (int j = 0; j < strlen(s); j++) {
				if (s[j] != this->string_[k]) {
					break;
				}

				if (j == strlen(s) - 1) {
					return i;
				}
				k++;
			}
		}
	}

	return this->length_;
}

size_t CMyString::rfind(const char* s, size_t pos, size_t n) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = length_ - pos; i >= pos - n; i--) {
		if (s[i] == this->string_[i] && this->length_ - i >= strlen(s)) {
			int k = i;

			for (int j = 0; j < strlen(s); j++) {
				if (s[j] != this->string_[k]) {
					break;
				}

				if (j == strlen(s) - 1) {
					return i;
				}
				k++;
			}
		}
	}

	return this->length_;
}

size_t CMyString::rfind(char c, size_t pos) const
{
	if (pos < 0 || pos > length_)
		return -1;

	for (int i = length_ - pos; i >= 0; i++) {
		if (this->string_[i] == c) {
			return i;
		}
	}

	return this->length_;
}

size_t CMyString::find_first_of(const CMyString& str, size_t pos) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	int i;
	for (i = pos; i < this->length_; i++) {
		for (int j = 0; j < strlen(str.string_); j++) {
			if (this->string_[i] == str.string_[j])
				return i;
		}
	}

	return -1;
}

size_t CMyString::find_first_of(const char* s, size_t pos) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	int i;
	for (i = pos; i < this->length_; i++) {
		for (int j = 0; j < strlen(s); j++) {
			if (this->string_[i] == s[j])
				return i;
		}
	}

	return -1;
}

size_t CMyString::find_first_of(const char* s, size_t pos, size_t n) const
{
	if (pos < 0 || pos > this->length_ || pos + n > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	int i;
	for (i = pos; i < n; i++) {
		for (int j = 0; j < strlen(s); j++) {
			if (this->string_[i] == s[j])
				return i;
		}
	}

	return -1;
}

size_t CMyString::find_first_of(char c, size_t pos) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	int i;
	for (i = pos; i < this->length_; i++) {
		if (this->string_[i] == c)
			return i;
	}

	return -1;
}

size_t CMyString::find_last_of(const CMyString& str, size_t pos) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	for (int i = pos; i >= 0; i--) {
		for (int j = 0; j < strlen(str.string_); j++) {
			if (this->string_[i] == str.string_[j])
				return i;
		}
	}

	return -1;
}

size_t CMyString::find_last_of(const char* s, size_t pos) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	for (int i = pos; i >= 0; i--) {
		for (int j = 0; j < strlen(s); j++) {
			if (this->string_[i] == s[j])
				return i;
		}
	}

	return -1;
}

size_t CMyString::find_last_of(const char* s, size_t pos, size_t n) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	for (int i = pos; i >= pos - n; i--) {
		for (int j = 0; j < strlen(s); j++) {
			if (this->string_[i] == s[j])
				return i;
		}
	}

	return -1;
}

size_t CMyString::find_last_of(char c, size_t pos) const
{
	if (pos < 0 || pos > this->length_) {
		cout << "Pos error !" << endl;
		return -1;
	}

	for (int i = pos; i >= 0; i--) {
		if (this->string_[i] == c)
			return i;
	}

	return -1;
}

size_t CMyString::find_first_not_of(const CMyString& str, size_t pos) const
{
	int flag;
	if (pos < 0 || pos > this->length_) 
		return -1;

	for (int i = pos; i < this->length_; i++) {
		flag = 1;

		for (int j = 0; j < strlen(str.string_); j++) {
			if (this->string_[i] == str.string_[j]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) 
			return i;

	}
	return -1;
}

size_t CMyString::find_first_not_of(const char* s, size_t pos) const
{
	int flag;
	if (pos < 0 || pos > this->length_)
		return -1;

	for (int i = pos; i < this->length_; i++) {
		flag = 1;

		for (int j = 0; j < strlen(s); j++) {
			if (this->string_[i] == s[j]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			return i;

	}
	return -1;
}

size_t CMyString::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	int flag;
	if (pos < 0 || pos > this->length_ || pos + n > length_ )
		return -1;

	for (int i = pos; i < n; i++) {
		flag = 1;

		for (int j = 0; j < strlen(s); j++) {
			if (this->string_[i] == s[j]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			return i;

	}
	return -1;
}

size_t CMyString::find_first_not_of(char c, size_t pos) const
{
	if (pos < 0 || pos > this->length_)
		return -1;

	for (int i = pos; i < this->length_; i++) {
		if (this->string_[i] != c) {
			return i;
		}
	}

	return -1;
}

size_t CMyString::find_last_not_of(const CMyString& str, size_t pos) const
{
	int flag;

	if (pos < 0 || pos > this->length_) 
		return -1;

	for (int i = pos; i >= 0; i--) {
		flag = 1;

		for (int j = strlen(str.string_); j >= 0; j--) {
			if (this->string_[i] == str.string_[j]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1) 
			return i;
	}

	return -1;
}

size_t CMyString::find_last_not_of(const char* s, size_t pos) const
{
	int flag;

	if (pos < 0 || pos > this->length_)
		return -1;

	for (int i = pos; i >= 0; i--) {
		flag = 1;

		for (int j = strlen(s); j >= 0; j--) {
			if (this->string_[i] == s[j]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			return i;
	}

	return -1;
}

size_t CMyString::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	int flag;

	if (pos < 0 || pos > this->length_ || pos - n < 0)
		return -1;

	for (int i = pos; i >= pos - n; i--) {
		flag = 1;

		for (int j = strlen(s); j >= 0; j--) {
			if (this->string_[i] == s[j]) {
				flag = 0;
				break;
			}
		}

		if (flag == 1)
			return i;
	}

	return -1;
}

size_t CMyString::find_last_not_of(char c, size_t pos) const
{
	if (pos < 0 || pos > this->length_)
		return -1;

	for (int i = pos; i >= 0; i--) {
		if (this->string_[i] != c) {
			return i;
		}
	}

	return -1;
}

CMyString CMyString::substr(size_t pos, size_t len) const
{
	if (pos<0 || pos>length_ || pos + len > length_) {
		cout << "Pos error !" << endl;
		return nullptr;
	}

	CMyString _dummy;
	_dummy.length_ = len;
	_dummy.capacity_ = length_ + 16;
	_dummy.string_ = new char[capacity_];

	for (int i = pos; i < len + pos; i++) {
		_dummy[i] = this->string_[i];
	}
	_dummy[_dummy.length_] = '\0';
	
	return _dummy;
}

int CMyString::compare(const CMyString& str) const
{
	if (this->length_ > str.length_)
		return 1;
	else {
		if (this->length_ < str.length_)
			return -1;
		else {
			for (int i = 0; i < this->length_; i++) {
				if (this->string_[i] != str.string_[i]) 
					return 1;
			}
			return 0;
		}
	}	
}

int CMyString::compare(size_t pos, size_t len, const CMyString& str) const
{
	CMyString _dummy;

	_dummy.assign(*this, pos, len);

	if (_dummy == str) 
		return 0;
	else {
		if (str.length_ < _dummy.length_ || str < _dummy)
			return -1;
		else
			return 1;
	}
}

int CMyString::compare(size_t pos, size_t len, const CMyString& str, size_t subpos, size_t sublen) const
{
	CMyString _dummy;
	CMyString _dummy2;

	_dummy.assign(*this, pos, len);
	_dummy2.assign(str, subpos, sublen);

	if (_dummy == _dummy2) 
		return 0;
	else {
		if (_dummy2.length_ < _dummy.length_ || _dummy2 < _dummy) 
			return -1;
		else 
			return 1;
	}
}

int CMyString::compare(const char* s) const
{
	if (this->length_ > strlen(s))
		return 1;
	else {
		if (this->length_ < strlen(s))
			return -1;
		else {
			for (int i = 0; i < this->length_; i++) {
				if (this->string_[i] != s[i])
					return 1;
			}
			return 0;
		}
	}
}

int CMyString::compare(size_t pos, size_t len, const char* s) const
{
	CMyString _dummy;

	_dummy.assign(*this, pos, len);

	if (_dummy.string_ == s)
		return 0;
	else {
		if (strlen(s) < _dummy.length_ || s < _dummy.string_)
			return -1;
		else
			return 1;
	}
}

CMyString operator+(const CMyString& lhs, const CMyString& rhs)
{
	return (CMyString)lhs += rhs;
}

CMyString operator+(const CMyString& lhs, const char* rhs)
{
	return (CMyString)lhs += rhs;
}

CMyString operator+(const char* lhs, const CMyString& rhs)
{
	return (CMyString)lhs += rhs;
}

CMyString operator+(const CMyString& lhs, char rhs)
{
	CMyString _dummy;

	_dummy.length_ = lhs.length_ + 1;
	_dummy.capacity_ = _dummy.length_ + 16;
	_dummy.string_ = new char[_dummy.capacity_];

	int i = 0;

	while (lhs.string_ != '\0') {
		_dummy.string_[i] = lhs.string_[i];
		i++;
	}
	_dummy.string_[i] = rhs;
	_dummy.string_[i + 1] = '\0';

	return _dummy;
}

CMyString operator+(char rhs, const CMyString& lhs)
{
	CMyString _dummy;

	_dummy.length_ = lhs.length_ + 1;
	_dummy.capacity_ = _dummy.length_ + 16;
	_dummy.string_ = new char[_dummy.capacity_];

	int i = 0;

	while (lhs.string_ != '\0') {
		_dummy.string_[i] = lhs.string_[i];
		i++;
	}
	_dummy.string_[i] = rhs;
	_dummy.string_[i + 1] = '\0';

	return _dummy;
}

bool operator==(const CMyString& lhs, const CMyString& rhs)
{
	if (lhs.length_ != rhs.length_) 
		return false;

	int capa = lhs.length_;
	int i = 0;

	while ((i < capa) && (lhs.string_[i] == rhs.string_[i])) 
		i++;

	return (i == capa);
}

bool operator==(const char* lhs, const CMyString& rhs)
{
	if (strlen(lhs) != rhs.length_)
		return false;

	int capa = strlen(lhs);
	int i = 0;

	while ((i < capa) && (lhs[i] == rhs.string_[i]))
		i++;

	return (i == capa);
}

bool operator==(const CMyString& lhs, const char* rhs)
{
	if (lhs.length_ != strlen(rhs))
		return false;

	int capa = lhs.length_;
	int i = 0;

	while ((i < capa) && (lhs.string_[i] == rhs[i]))
		i++;

	return (i == capa);
}

bool operator!=(const CMyString& lhs, const CMyString& rhs)
{
	if (lhs.length_ != rhs.length_)
		return true;

	int capa = lhs.length_;
	int i = 0;

	while ((i < capa) && (lhs.string_[i] != rhs.string_[i]))
		i++;

	return (i != capa);
}

bool operator!=(const char* lhs, const CMyString& rhs)
{
	if (strlen(lhs) != rhs.length_)
		return true;

	int capa = strlen(lhs);
	int i = 0;

	while ((i < capa) && (lhs[i] != rhs.string_[i]))
		i++;

	return (i != capa);
}

bool operator!=(const CMyString& lhs, const char* rhs)
{
	if (lhs.length_ != strlen(rhs))
		return true;

	int capa = lhs.length_;
	int i = 0;

	while ((i < capa) && (lhs.string_[i] != rhs[i]))
		i++;

	return (i != capa);
}

bool operator<(const CMyString& lhs, const CMyString& rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const char* lhs, const CMyString& rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const CMyString& lhs, const char* rhs)
{
	return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<=(const CMyString& lhs, const CMyString& rhs)
{
	return !(lhs > rhs);
}

bool operator<=(const char* lhs, const CMyString& rhs)
{
	return !(lhs > rhs);
}

bool operator<=(const CMyString& lhs, const char* rhs)
{
	return !(lhs > rhs);
}

bool operator>(const CMyString& lhs, const CMyString& rhs)
{
	int sum_dummy = 0;
	int sum_dummy2 = 0;

	for (int i = 0; i < lhs.length_; i++) {
		sum_dummy += (int)lhs[i];
	}

	for (int i = 0; i < rhs.length_; i++) {
		sum_dummy += (int)rhs[i];
	}
	return sum_dummy > sum_dummy2;
}

bool operator>(const char* lhs, const CMyString& rhs)
{
	return (CMyString(lhs) > rhs);
}

bool operator>(const CMyString& lhs, const char* rhs)
{
	return (lhs > CMyString(rhs));
}

bool operator>=(const CMyString& lhs, const CMyString& rhs)
{
	return !(lhs < rhs);
}

bool operator>=(const char* lhs, const CMyString& rhs)
{
	return !(lhs < rhs);
}

bool operator>=(const CMyString& lhs, const char* rhs)
{
	return !(lhs < rhs);
}

istream& operator>>(istream& is, CMyString& str)
{
	// TODO: insert return statement here

	char* _dummy = new char[1000];
	is >> _dummy;

	str = _dummy;
	int len = strlen(_dummy);

	str.string_[len] = '\0';

	delete[] _dummy;

	return is;
}

ostream& operator<<(ostream& os, const CMyString& str)
{
	// TODO: insert return statement here

	if (str.string_ == NULL || str.length_ == 0) {
		return os;
	}
	else {
		int j = 0;
		if (strlen(str.string_) > 0)
		{
			while (str.string_[j] != '\0') {
				os << str.string_[j];
				j++;
			}
		}
	}

	return os;
}
