#include <iostream>
#include <stdlib.h>
#include<ctime>
using namespace std;
int main(){
	srand(time(NULL));
	int i=0, max=0, c=0; 
	int *s = new int(101);
	for(i=0;i<100;++i){
		*s=10+rand()%89;
		cout<<*s<<endl;
		if (*s>max)	max=*s;
		else if(*s==max){
			c++;}
	}
	cout<<"4islo: "<< c<<endl<<"max: "<< max<<endl;	
return 0;
}
