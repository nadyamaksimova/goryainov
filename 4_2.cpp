#include <iostream> 
#include <cstdlib>
#include <stdio.h>
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
	for(int i = 0; i<o+l;++i){ 
	if(i<index) {
	*(d+i)=(*(c+i));
	}
	if((i>=index) and (i<(index + l))){
		*(d+i)=(*(subs+i-index));
	}
	if(i>=(index+l)){
		*(d+i)=(*(c+i-l));
	}
	*(d+o+l)=0;
	
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
float math(char z, float sl, float sp){
	float d;
	if(z=='/')d=sl/sp;
	if(z=='*')d=sl*sp;
	if(z=='+')d=sl+sp;
	if(z=='-')d=sl-sp;
	return d;
}
int main() {
int a = 101, sl, sp; 
char *c = new char[a]; 
cin.get(c,101);
while(find(c,"/")!=-1 || find(c,"*")!=-1){
	cout << c << endl;
	int p1 = find(c,"/");
	int p2 = find(c,"*");
	int p = 0;
	if (p1 == -1) {
		p = p2;
	} else if (p2 == -1){
		p = p1;
	} else {
		p = (p1 < p2) ? p1 : p2;
	}
	char z = c[p];
	sl=levoe(c, p);
	sp=pravoe(c, p);
	
	float h=atof(copy(c, sl, p-sl));
	float h1=atof(copy(c, p+1, sp-p));
	c=del(c, sl, sp-sl+1);
	
	char *numb = new char[20];
	sprintf(numb, "%f", math(z,h,h1));
	cout << numb << endl;
	c = insert(c, numb, sl);
}
cout << c << endl;
while(find(c,"+")!=-1 || find(c,"-")!=-1){
	int p1 = find(c,"+");
	int p2 = find(c,"-");
	int p = 0;
	if (p1 == -1) {
		p = p2;
	} else if (p2 == -1){
		p = p1;
	} else {
		p = (p1 < p2) ? p1 : p2;
	}
	char z = c[p];
	sl=levoe(c, p);
	sp=pravoe(c, p);
	
	float h=atof(copy(c, sl, p-sl));
	float h1=atof(copy(c, p+1, sp-p));
	cout << c << endl;
	c=del(c, sl, sp-sl+1);
	cout << c << endl;
	
	char *numb = new char[20];
	sprintf(numb, "%f", math(z,h,h1));
	cout << numb << endl;
	c = insert(c, numb, sl);
}
cout << c << endl; 
return 0;
}
