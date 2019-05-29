#ifndef _STRING_H
#define _STRING_H
#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

	class _String {
	int stringLength = 1;
	public:
		_String();
		
		_String(char *val);
		
		_String(const char *val);

		~_String();

		_String(const _String &element);

		int length();

		void append(_String str);

		void append(char *str);

		void append(const char *str);

		void setValue(char *val);

		void setValue(const char *val);

		void setValue(int val);

		void setValue(double val, int precision = 10);

		_String operator = (const _String &element);

		_String operator + (const _String &right);

		int pos(const char *str);

		void remove(int position, int length);

		void insert(int position, const char *source);

		void insert(int position, char *source);

		void insert(int position, _String source);

		_String copy(int position, int length);

		char operator [] (int index);

		int parseInt(int &error);

		float parseFloat(int &error);

		bool isEqual(char *str);

		bool isEqual(const char *str);
	}; 
#endif
