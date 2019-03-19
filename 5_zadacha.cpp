#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int k=1,max=0;
	int *p=new int[n];
	for(int i=0;i<n;i++){
		cin>>*p;
		p++;}
	p-=n;
	for (int i=0; i<n-1; i++) {
 		if(*p==*(p+1)) {
	 	k++;}
		else {
			if(k>max){
				max=k;}
		k=1;}
	p++;}
	if(k>max){
				max=k;}
cout<<max<<endl;}
