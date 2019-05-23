#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
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
		int i = 0;
		while (str.value[i] != 0) {
			value[stringLength + i] = str.value[i];
			i++;
		}
		value[stringLength + i] = 0;
		stringLength += i;
	}
	void append(char *str) { 
		int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;
		value = new char[stringLength+len(str)];
		for(int i = 0; i<stringLength+len(str);i++)value[i] = temp[i];
		while (str[i] != 0) {
			value[stringLength-1 + i] = str[i];
			i++;
		}
		value[stringLength-1 + i] = 0;
		stringLength += i;

	}
void append(const char *str) { 
		int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;
		value = new char[stringLength+len(str)];
		for(int i = 0; i<stringLength+len(str);i++)value[i] = temp[i];
		while (str[i] != 0) {
			value[stringLength-1 + i] = str[i];
			i++;
		}
		value[stringLength-1 + i] = 0;
		stringLength += i;

	}
	void setValue(char *val) {
		stringLength=0;
		delete[] value;
		value = new char[len(val)+1];
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
			stringLength++;
		}
	}
	void setValue(const char *val) {
		stringLength=0;
		delete[] value;
		value = new char[len(val)+1];
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
			stringLength++;
		}

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
	}
	void setValue(double val, int precision = 10) {
			char* temp = new char[100];
			itoa(precision,temp,10);
			stringLength=0;
			delete[] value;
			_String a("%.");
			a.append(temp);
			a.append("f");
			sprintf(value, a.value, val);
			cout<<value;
	}
	void insert(int position, const char *source) {
	int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;
		
		int l = len(source);
		value = new char[stringLength + l +1];
		
		for (int i = 0; i < position; i++) {
			value[i] = temp[i];
		}
		
		for (int i = 0; i < l; i++) {
			value[position + i] = source[i];
		}
		
		for (int i = position; i< len(temp); i++) {
			value[l + i] = temp[i];
		}
		value[stringLength + l] = 0;
		
		cout<<value;

	} 
	void insert(int position, char *source) {
	int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;
		
		int l = len(source);
		value = new char[stringLength + l +1];
		
		for (int i = 0; i < position; i++) {
			value[i] = temp[i];
		}
		
		for (int i = 0; i < l; i++) {
			value[position + i] = source[i];
		}
		
		for (int i = position; i< len(temp); i++) {
			value[l + i] = temp[i];
		}
		value[stringLength + l] = 0;
		
		cout<<value;

	} 
	void insert(int position, _String source) {
	int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;		
		int l = source.length();
		value = new char[stringLength + l +1];
		
		for (int i = 0; i < position; i++) {
			value[i] = temp[i];
		}
		
		for (int i = 0; i < l; i++) {
			value[position + i] = source[i];
		}
		
		for (int i = position; i< len(temp); i++) {
			value[l + i] = temp[i];
		}
		value[stringLength + l] = 0;
		
		cout<<value;

	} 
	char operator [] (int index) {
		return value[index];
	}
	_String copy(int position, int length) {
		char *d = new char[length+1]; 
		for (int i = 0; i < stringLength; i++) { 
			*(d + i - position) = *(value + i); 
			} 
		*(d+length) = 0; 
		cout<<d;
	} 
	_String operator = (const _String &element) {
	}
	_String operator + (const _String &right) {
	}
	int pos(const char *str) {
	}
	void remove(int position, int length) {
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
	char *a=new char[100];
	cin>>a;
	_String s("abc");
	_String s1("4586");
//	s.setValue(12.213);
	s.copy(0,2);
	
}
