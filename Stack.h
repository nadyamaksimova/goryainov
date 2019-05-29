#ifndef STACK_H
#include <iostream> 
using namespace std;
struct stack {
 int m_size=0; 
 int *m_elems= new int[0]; 
 stack(){
 };
 ~stack(){
 };
public:
	void push(int n);

	int pop();

	int back();
	
	int size();
	
	void clear();

	void showList();
};

#endif 
