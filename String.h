#ifndef _STRING_H_
#define _STRING_H_

class String {
private:
	unsigned int length;
	char* string;

	void Allocate(unsigned int size) {
		length = size;
		string = new char[length];
	}

	void Copy(const char* str) {
		for (int i = 0; i < length; i++) string[i] = str[i];
	}
public:
	String() {
		Allocate(1);
	}
	String(const char* str) {
		if (str != nullptr) {
			Allocate(CalculateLength(str));
			Copy(str);
		}
		else {
			Allocate(1);
		}
	}
	String(const String& str) {
		if (str.GetString() != nullptr) {
			Allocate(str.length);
			Copy(str.string);
		}
		else {
			Allocate(1);
		}

	}

	char* GetString() const {
		return string;
	}	
	unsigned int CalculateLength(const char* str) const {
		unsigned int str_length;
		for (str_length = 0; str[str_length] != '\0'; str_length++);
		str_length++; //space for \0 char
		return str_length;
	}
	String& operator= (const char* str)
	{
		Allocate(CalculateLength(str) + 1);
		Copy(str);
		return *this;
	}
	String& operator= (const String& str)
	{
		Allocate(CalculateLength(str.GetString()));
		Copy(str.GetString());
		return *this;
	}
};

#endif
