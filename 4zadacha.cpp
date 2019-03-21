#include <iostream> 
#include <cstdlib>
#include<stdio.h>
using namespace std; 
int find(char *c, const char *search) { 
for (int i = 0; *(c + i) != 0; i++) { 
	if(*(c+i)==*search) return i; 
} 
return -1; 
} 
char *copy(char *c, int index, int count){ 
char *d = new char[count+1]; 
for (int i = index; i < index + count; i++) { 
*(d + i - index) = *(c + i); 
} 
*(d+count) = 0; 
return d; 
} 
int len(char *c){ 
int a = 0; 
for( int i=0;*(c+i)!=0;i++){ 
a++;} 
return a; 
} 
char *del(char *c, int index, int count){ 
int b=len(c); 
char *d = new char[b-count+1]; 

//io 0 ai index - 1 
for (int i = 0; i < index; i++) *(d + i) = *(c + i); 

//io index + count ai eiioa no?iee abcde 
for (int i = index + count; i < b; i++) *(d + i - count) = *(c + i); 

*(d+b-count)=0; 
delete[] c; 
return d; 
} 
char *insert(char *c, char *subs, int index){ 
int o=len(c); 
int l=len(subs); 
char *d = new char(o+l); 
	for(int i = 0; i<index+1;++i){ 
		*(d+i) = *(c+i); 
	} 
	for(int i = index, j = 0; j<l;++i, ++j){ 
		*(d+i)= *(subs+j); 
	} 
	for(int i= index + l, j = index;j<o;++i, ++j){ 
		*(d+i)= *(c+j); 
	} 
return d; 
} 
int levoe(char *c, int index){
	int sl;
		for(int i = index - 1;i>=0;--i){
			if(c[i]>='0' && c[i]<='9' || c[i]=='.'){sl=i;
		}
		else break;
		} 
	return sl;
}
int pravoe(char *c, int index){
	int sp;
	for(int i = index + 1;i<len(c);++i){
		if(c[i]>='0' && c[i]<='9' || c[i]=='.'){
		sp=i;}
	else break;
	} 
	return sp;
}
int main() {
int sl,sp; 
int a = 101; 
char *c = new char[a]; 
cin.get(c,100);
int znak=find(c,"*");
sl=levoe(c,znak);
sp=pravoe(c,znak);
char *h=copy(c,sl,find(c,"*"));
char *h1=copy(c,sp,find(c,"*"));
c=del(c,sl,len(c)-sl);
float d=atoi(h)*atoi(h1);
char *numb = new char[20];
sprintf(numb, "%f", d);
//cout<<insert(c,numb,sl); не работает строка
}
