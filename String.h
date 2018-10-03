#ifndef _STRING_H_
#define _STRING_H_
#include <string.h>
#include <assert.h>

class String {
private:
	unsigned int allocated_memory;
	char* string;

	void Allocate(unsigned int size) {
		allocated_memory = size;
		string = new char[allocated_memory];
	}
public:
	String() {
		Allocate(1);
	}
	String(const char* str) {
		assert(str != nullptr);
		if (str != nullptr) {
			Allocate(strlen(str)+1);
			strcpy(string,str);
		}
		else {
			Allocate(1);
		}
	}
	String(const String& str) {
		assert(str.GetString() != nullptr);
		if (str.GetString() != nullptr) {
			Allocate(str.allocated_memory + 1);
			strcpy(string, str.GetString());
		}
		else {
			Allocate(1);
		}

	}

	char* GetString() const {
		return string;
	}	

	String& operator= (const char* str)
	{
		assert(str != nullptr);
		if (str != nullptr) {
			Allocate(strlen(str) + 1);
			strcpy(string, str);
		}
		return *this;
	}
	String& operator= (const String& str)
	{
		assert(str.GetString() != nullptr);
		if (str.GetString() != nullptr) {
			Allocate(str.allocated_memory + 1);
			strcpy(string, str.GetString());
		}
		return *this;
	}
};

#endif
