#include <iostream>
using namespace std;
const int MAX_SIZE=1000;
struct stack {
 int k; 
stack *next;
 stack(); 
 ~stack(); 
 void push(stack **top, int d){
 	stack *q;//vershina stack
 	q = new stack();//pamyat dlya elementa
	 q->k=d;//zapisali v k
	 if (top==NULL){*top=*q;//esli stack pustoi, to vershina q
	 }
	 else{
	 	q->next = *top; *top=q;//inache
	 }
 }
 // int pop();
 //int back(); 
 //int size(); 
 //void clear();
 };
int main(){
	int m;
	char n;
	do{cin>>n>>m;
	if (n='push'){push(&top,m); cout<<ok<<endl;}
//	if (n='pop'){pop(m);cout<<}
//	if (n='back'){	}
//	if (n='size'){	}
//	if (n='clear'){	}
	}
	while (n!='exit')
	cout<<'bye';
}
