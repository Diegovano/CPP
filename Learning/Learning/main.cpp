#include <iostream>

class dString
{
private:
	char* str;
public:
	dString(const char *ent)
	{
		size_t nCharLoc = 0; // equivalent to the size of the string without the null char
		for (; ent[nCharLoc] != '\0'; ++nCharLoc);
		this->str = new char[nCharLoc + 1];
		for (size_t index = 0; index <= nCharLoc; ++index) this->str[index] = ent[index];
	}

	dString(const size_t sze)
	{
		this->str = new char[sze + 1];
		this->str[sze] = '\0';
	}
	dString() : dString(static_cast<size_t>(0))
	{
	}
	~dString()
	{
	}
	const char* returnStr() const;
	const size_t ssize();
	static const void dString::getlne(std::istream& is, dString &obj);
	const char operator[](const size_t loc);
	void pushBack(const char *ent);
	void pushBack(const char ent);
	const dString& operator+=(dString obj);
	const dString& operator+=(const size_t sze);
	const dString operator+(dString &obj);
	const dString operator+(const size_t sze);
	const bool dString::operator==(dString &obj);
	const bool dString::operator!=(dString &obj);
	friend std::ostream& operator<<(std::ostream &os, const dString &obj);
	friend std::istream& operator>>(std::istream &is, const dString &obj);
	const dString& dString::operator=(const char *ent);
};

const char* dString::returnStr() const
{
	return str;
}

const size_t dString::ssize(void) {
	size_t nCharLoc = 0;
	for (; this->str[nCharLoc] != '\0'; ++nCharLoc);
	return nCharLoc;
}

const void dString::getlne(std::istream& is, dString &obj) {
	dString cont;
	while (std::cin >> cont) {
		obj.pushBack(cont.str);
		if (is.peek() == '\n') return;
		obj.pushBack(' ');
	}

}

const char dString::operator[](const size_t loc) {
	return this->str[loc];
}

void dString::pushBack(const char *ent) {
	dString temp(ent);
	*this += temp;
}

void dString::pushBack(const char ent) {
	dString temp(&ent);
	*this += temp;
}

const dString& dString::operator+=(dString obj) {
	dString temp(this->ssize() + obj.ssize());
	for (size_t index = 0; index < this->ssize(); ++index) temp.str[index] = this->str[index];
	for (size_t index = 0; index <= obj.ssize(); ++index) temp.str[this->ssize() + index] = obj.str[index]; //index<=obj.size to inc '\0'
	this->str = temp.str;
	return *this;
}

const dString& dString::operator+=(const size_t sze) {
	dString temp(sze);
	return *this += temp;
}

const dString dString::operator+(dString &obj) {
	dString temp("");
	temp += *this;
	temp += obj;
	return temp;
}

const dString dString::operator+(const size_t sze) {
	dString temp(this->str);
	temp += sze;
	return temp;
}

const bool dString::operator==(dString &obj) {
	if (this->ssize() != obj.ssize()) return false;
	for (size_t index = 0; index < this->ssize(); ++index) {
		if (this->str[index] != obj.str[index]) return false;
	}
	return true;
}

const bool dString::operator!=(dString &obj) {
	return !(this->operator==(obj));
}

const dString& dString::operator=(const char *ent) {
	this->dString::dString(ent);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const dString &obj) {
	os << obj.returnStr();
	return os;
}

std::istream& operator>>(std::istream& is, const dString &obj) {
	is >> obj.str; //recurive on all paths if use function to return string
	return is;
}

unsigned int retDigits(unsigned int ent)
{
	unsigned int digits = 0;
	if (ent == 0)return 1;
	while (ent)
	{
		ent /= 10;
		++digits;
	}
	return digits;
}

char* castIntToCharInt(int ent)
{
	unsigned int origNumDig = retDigits(ent);
	char *res = new char[origNumDig];
	for (unsigned int iter = 0; iter < origNumDig; ++iter)
	{
		res[iter] = ent / static_cast<int>(pow(10, retDigits(ent) - iter - 1)) + '0';
		ent -= res[iter] * pow(10, retDigits(ent) - iter - 1);
	}
	return res;
}

int main()
{
	std::cout << castIntToCharInt(125) << std::endl;
	system("pause");
}