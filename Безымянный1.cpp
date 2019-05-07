#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class _String {
	char *value;
	int stringLength = -1;
	int len(char *c) {
		int a = 0;
		for (int i = 0; *(c + i) != 0; i++)a++;
		return a;
	}
	int len(const char *c) {
		int a = 0;
		for (int i = 0; *(c + i) != 0; i++)a++;
		return a;
	}
public:
	_String() {
		stringLength = 0;
		value = new char[1];
		value[0] = 0;
	}
	_String(char *val) {
		stringLength = 0;
		int a = len(val);
		value = new char[a + 1];
		for (int i = 0; i < a + 1; i++) {
			value[i] = val[i];
			stringLength++;
		}
		value[a + 1] = 0;
		//cout << "char " << value << endl;
	}
	_String(const char *val) {
		stringLength = 0;
		int a = len(val);
		value = new char[a + 1];
		for (int i = 0; i < a + 1; i++) {
			value[i] = val[i];
			stringLength++;
		}
		value[a + 1] = 0;
		//cout << "const char " << value << endl;
	}
	
	~_String() {
		delete[] value;
	}
	_String(const _String &element) {
		int lenVal = 0;
		stringLength = 0;
		for (int i = 0; (element.value[i]) != 0; ++i)
			lenVal++;
		char * str = new char[lenVal + 1];
		for (int i = 0; element.value[i] != 0; i++) {
			*(str + i) = element.value[i];
			stringLength++;
		}
		*(str + lenVal) = 0;
		value = str;
	}
	
	int length() {
		
		return stringLength;
	}
	void append(_String str) {
		char *str1 = new char[stringLength + str.length() + 1];
		for (int i = 0; i < (stringLength + str.length()); i++) {
			if (i < stringLength) { *(str1 + i) = *(value + i); }
			if (i >= stringLength) { *(str1 + i) = str[i - stringLength]; }
			*(str1 + stringLength + str.length()) = 0;
			stringLength = (stringLength + length());
			delete[] value;
			value = str1;
		}
	}
	void append(char *str) {
		int len = 0;
		for (int i = 0; *(str + i) != 0; i++) {
			len++;
		}
		char *str1 = new char[stringLength + len + 1];
		for (int i = 0; i < (stringLength + len); i++) {
			if (i < stringLength) { *(str1 + i) = *(value + i); }
			if (i >= stringLength) { *(str1 + i) = *(str + i - stringLength); }
			*(str1 + stringLength + len) = 0;
			stringLength = stringLength + len;
			delete[] value;
			value = str1;
		}
	}
	void append(const char *str) {
		int len = 0;
		for (int i = 0; *(str + i) != 0; i++) {
			len++;
		}
		char *str1 = new char[stringLength + len+ 1];
		for (int i = 0; i < (stringLength + len); i++) {
			if (i < stringLength) { *(str1 + i) = *(value + i); }
			if (i >= stringLength) { *(str1 + i) = *(str + i - stringLength); }
			*(str1 + stringLength + len) = 0;
			stringLength = stringLength + len;
			delete[] value;
			value = str1;
		}
	}
	void setValue(char *val) {
		stringLength=0;
		delete[] value;
		value = new char[len(val)+1];
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
			stringLength++;
		}
		cout<<value;
	}
	void setValue(const char *val) {
		stringLength=0;
		delete[] value;
		value = new char[len(val)+1];
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
			stringLength++;
		}
		cout<<value;
	}
	void setValue(int val) {
		stringLength=0;
		delete[] value;
		char* b = new char[val+48];
		value = new char[len(b)+1];
		for (int i=0; i < len(b-1); i++){
			value[i]=val;
			stringLength++;
		}
		cout<<value;
	}
/*	void setValue(double val, int precision = 10) {
		stringLength=0;
		delete[] value;
		value = new char(len(val)+1);
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
			stringLength++;
		}
		cout<<value;
	}*/
	_String operator = (const _String &element) {
	}
	_String operator + (const _String &right) {
	}
	int pos(const char *str) {
	}
	void remove(int position, int length) {
	}
	void insert(int position, int length, const char *source) {
	}
	void insert(int position, int length, char *source) {
	}
	void insert(int position, int length, _String source) {
	}
	_String copy(int position, int length) {
	}
	char operator [] (int index) {
		return value[index];
	}
	int parseInt(int &error) {
	}
	float parseFloat(int &error) {
	}
	bool isEqual(char *str) {
	}
	bool isEqual(const char *str) {
	}
};

int main() {
	int a;
	cin>>a;
	_String s("a");
	_String s1("b");
	s.setValue(a);
}
