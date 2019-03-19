#include<fstream>
#include<iostream>
using namespace std;
int main(){
	ofstream fout;
  	fout.open("E:/file.txt");
	char *s=new char(1000);
	cin.get(s,1000);
	while (*s!=0){
		if(*s<90 and *s>=65){
			*s=*s+32;
		}
		else if(*s>=97 and *s<=122){
			*s=*s-32;
		}
		fout<<*s<<endl;
		s++;
		
	}
	fout.close();
}
