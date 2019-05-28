#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "14 string.cpp"
#include "14 stack.cpp"
int main(){
	int a = 101, sl,sp;
	stack g; 
	char *c = new char[a]; 
	cin.get(c,101);
	while(find(c," ")!=-1){
	if(c[0]>='0' && c[0]<='9'){
		int h=atoi(copy(c,0,find(c," ")));
		g.push(h);
		c = del(c,0,find(c," ")+1);
	} else if(c[0]=='+' || c[0]=='-' || c[0]=='*' || c[0]=='/') {
			sl=g.pop();
			sp=g.pop();
			int h1=math(c[0],sp,sl);
			g.push(h1);
			c = del(c, 0, find(c," ") + 1);
		}
	}
	cout<<g.pop();
	}
