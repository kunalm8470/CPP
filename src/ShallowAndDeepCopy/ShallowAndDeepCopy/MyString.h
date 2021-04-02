#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
private:
	char* m_data{};
	int m_length;
public:
	MyString(const char* src);
	MyString(const MyString&);
	~MyString();

	MyString& operator=(const MyString&);

	void deep_copy(const MyString&);
	char* get_data() const;
	int get_length() const;
};
#endif
