#ifndef _STRING_H_
#define _STRING_H_
#include <string.h>
#include <assert.h>

class String {
private:
	unsigned int allocated_memory = 0u;
	char* string = nullptr;

	void Allocate(unsigned int size) {
		allocated_memory = size;
		string = new char[allocated_memory];
	}
public:
	String() {}
	String(const char* str) {
		assert(str != nullptr);
		if (str != nullptr) {
			Allocate(strlen(str)+1);
			strcpy(string,str);
		}
	}
	String(const String& str) {
		assert(str.string != nullptr);
		if (str.string != nullptr) {
			Allocate(str.allocated_memory + 1);
			strcpy(string, str.string);
		}

	}
	~String() {
		if (string != nullptr)
		{
			delete[] string;
			string = nullptr;
		}
	}

	char* GetString() const {
		return string;
	}	

	char* operator= (const char* str)
	{
		assert(str != nullptr);
		if (str != nullptr) {
			if (string != nullptr) delete[] string;
			Allocate(strlen(str) + 1);
			strcpy(string, str);
		}
		return string;
	}
	String operator= (const String& str)
	{
		assert(str.string != nullptr);
		if (str.string != nullptr) {
			if (string != nullptr) delete[] string;
			Allocate(str.allocated_memory + 1);
			strcpy(string, str.string);
		}
		return *this;
	}
};

#endif
