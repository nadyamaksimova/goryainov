#include <iostream>
#include "_String.h"
using namespace std;
	int _String::len(char *c) {
		int a = 0;
		for (int i = 0; *(c + i) != 0; i++)a++;
		return a;
	}
	int _String::len(const char *c) {
		int a = 0;
		for (int i = 0; *(c + i) != 0; i++)a++;
		return a;
	}
	_String::_String() {
		stringLength = 0;
		value = new char[1];
		value[0] = 0;
	}
	_String::_String(char *val) {
		stringLength = 0;
		int a = len(val);
		value = new char[a + 1];
		for (int i = 0; i < a + 1; i++) {
			value[i] = val[i];
			stringLength++;
		}
		value[a + 1] = 0;
	}
	_String::_String(const char *val) {
		int a = len(val);
		stringLength = a;
		value = new char[a + 1];
		for (int i = 0; i < a; i++) {
			value[i] = val[i];
		}
		value[a] = 0;
	}
	
	_String::~_String() {
		delete[] value;
	}
	_String::_String(const _String &element) {
		int lenVal = 0;
		stringLength = 0;
		for (int i = 0; (element.value[i]) != 0; ++i) lenVal++;
		char * str = new char[lenVal + 1];
		for (int i = 0; element.value[i] != 0; i++) {
			*(str + i) = element.value[i];
			stringLength++;
		}
		*(str + lenVal) = 0;
		value = str;
	}
	
	int _String::length() {
		return stringLength;
	}
	void _String::append(_String str) { 
		int i = 0;
		while (str.value[i] != 0) {
			value[stringLength + i] = str.value[i];
			i++;
		}
		value[stringLength + i] = 0;
		stringLength += i;
	}
	void _String::append(char *str) { 
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
	void _String::append(const char *str) { 
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
	void _String::setValue(char *val) {
		stringLength = len(val);
		delete[] value;
		value = new char[stringLength + 1];
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
		}
		value[stringLength] = 0;
	}
	void _String::setValue(const char *val) {
		stringLength = len(val);
		delete[] value;
		value = new char[stringLength + 1];
		for (int i=0; i < len(val); i++){
			value[i]=val[i];
		}
		value[stringLength] = 0;
	}
	void _String::setValue(int val) {
		stringLength=0;
		delete[] value;
		char* b = new char[val+48];
		value = new char[len(b)+1];
		for (int i=0; i < len(b-1); i++){
			value[i]=val;
			stringLength++;
		}
	}
	void _String::setValue(double val, int precision = 10) {
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
	void _String::insert(int position, const char *source) {
	int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;
		int l = len(source);
		value = new char[stringLength + l +1];
		for (int i = 0; i < position; i++) value[i] = temp[i];
		for (int i = 0; i < l; i++) value[position + i] = source[i];
		for (int i = position; i< len(temp); i++) value[l + i] = temp[i];
		value[stringLength + l] = 0;
		cout<<value;
	}
	void _String::insert(int position, char *source) {
	int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;
		int l = len(source);
		value = new char[stringLength + l +1];
		for (int i = 0; i < position; i++) value[i] = temp[i];
		for (int i = 0; i < l; i++) value[position + i] = source[i];
		for (int i = position; i< len(temp); i++) value[l + i] = temp[i];
		value[stringLength + l] = 0;
		cout<<value;
	} 
	void _String::insert(int position, _String source) {
	int i = 0;
		char *temp = new char[stringLength];
		for(int i = 0; i<stringLength;i++)temp[i] = value[i];
		delete[] value;		
		int l = source.length();
		value = new char[stringLength + l +1];
		for (int i = 0; i < position; i++) value[i] = temp[i];
		for (int i = 0; i < l; i++)	value[position + i] = source[i];
		for (int i = position; i< len(temp); i++) value[l + i] = temp[i];
		value[stringLength + l] = 0;
		cout<<value;
	} 
	char _String::operator [] (int index) {
		return value[index];
	}
	_String _String::copy(int position, int length) {
		char *d = new char[length+1]; 
		for (int i = 0; i < stringLength; i++) { 
			*(d + i - position) = *(value + i); 
			} 
		*(d+length) = 0; 
		cout<<d;
	} 
	_String _String::operator = (const _String &element) {
		setValue(element.value);
		return *this;
	}
	_String _String::operator + (const _String &right) {
		_String s3(value);
		s3.append(right.value);
		return s3;
	}
	
	void _String::remove(int position, int length) {
		int i = 0 , k = position + length;
		char *temp = new char[stringLength];
		char *temp2 = new char[stringLength];		
		for(i = 0; i< position; i++)temp[i]=value[i];
		temp[position] = 0;
		for( i = k; i<=len(value); i++)temp2[i-k] = value[i];
		_String a(temp); a.append(temp2);
		cout<<a.value;
	}
	int _String::pos(const char *str){
 		int i, j, n = 0;
 		int lenS = len(str), lenV = len(value);
 		for (i = 0; i <= lenV - lenS; i++){
 			for (j = 0; j<lenV && value[i + j] == str[j]; j++);
 				if (j == lenS) return i;
 				else if (j-1 == lenS) return i;
 				}
 		return -1;
 }

	bool _String::isEqual(char *str) {
		int lenS = len(str), lenV = len(value), j=0, i = 0;
		if(lenS!=lenV) return 0;
		else{
			for (i = 0; i <= lenV; i++){if(value[i]==str[i])j++; else break;}
			if (j-1==lenS) return 1;
			else return 0;}
		}
	bool _String::isEqual(const char *str) {
		int lenS = len(str), lenV = len(value), j=0, i = 0;
		if(lenS!=lenV) return 0;
		else{
			for (i = 0; i <= lenV; i++){if(value[i]==str[i])j++; else break;}
			if (j-1==lenS) return 1;
			else return 0;}
		}
	int _String::parseInt(int &error) {
			int i = 0, j = 0, b = 0;
			if(value[0]=='-'){
				for(i = 1; i <= stringLength; i++)if(value[i]<'9' && value[i]>'0')j++;
				if(j+1==stringLength)  b = atoi(value);
				return b;
			}
			if(value[0]=='+'){
				for(i = 1; i <= stringLength; i++)if(value[i]<'9' && value[i]>'0')j++;
				if(j+1==stringLength) b = atoi(value);
				return b;
			}
			for(i = 0; i <= stringLength; i++)if(value[i]<'9' && value[i]>'0')j++;
			if(j==stringLength) b = atoi(value); 
			return b;
			}
	float _String::parseFloat(int &error) {
			int i = 0, j = 0, t = 0;
			float b = 0;
			if(value[0]=='-'){
				for(i = 1; i <= stringLength; i++)
					if(value[i]<'9' && value[i]>'0' || value[i]=='.'){
						j++;if(value[i]=='.')t++;if(t>1)break;}
				if(j+1==stringLength)  b = atof(value);
				return b;
			}
			if(value[0]=='+'){
				for(i = 1; i <= stringLength; i++)if(value[i]<'9' && value[i]>'0' || value[i]=='.'){
						j++;if(value[i]=='.')t++;if(t>1)break;}
				if(j+1==stringLength) b = atof(value);
				return b;
			}
			if(value[0]!='.'){
			for(i = 0; i <= stringLength; i++)if(value[i]<'9' && value[i]>'0' || value[i]=='.'){
						j++;cout<<j<<' '<<stringLength<<endl;if(value[i]=='.')t++;if(t>1)break;}
			if(j==stringLength) b = atof(value);
			return b;}


