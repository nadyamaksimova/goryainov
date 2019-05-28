#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "13 string.cpp"
#include "13 stack.cpp"
int main() {
	char *a=new char[100];
	cin>>a;
	int b;
	cin>>b;
	_String s1("-12.87");
/*	cout << s1.value << endl;
	cout << s2.value << endl;
	s1=s2;
	cout << s1.value << endl;
	cout << s2.value << endl;
	s1.setValue("xcvsdfsd");
	cout << s1.value << endl;
	cout << s2.value << endl;
	s1 = s1+s2;
	cout << s1.value << endl;
	cout << s2.value << endl;
	s1.remove(3,2);
	cout<<s1.pos("12");
	cout<<s1.isEqual(a);*/
	cout<<s1.parseFloat(b);
	return 0;
}
