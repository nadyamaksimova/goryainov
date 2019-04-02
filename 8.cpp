#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE=3;
struct stack {
 int m_size=0; 
 int m_elems[MAX_SIZE]={0}; 
 stack(){
 };
 ~stack(){
 };
 void push(int n){
     if(m_size == MAX_SIZE){cout<<"error"<<endl;}
     else{
 	m_elems[m_size]=n;
 	m_size++;
 	cout<<"ok"<<endl;}
 };
 int pop(){
    if (m_size==0){cout<<"error"<<endl; return 0;}
    else{
 	int q;
 	m_size--;
 	q=m_elems[m_size];
 	m_elems[m_size]=0;
 	cout<<q<<endl;
 	return q;}
 };
 int back(){
     if (m_size==0){cout<<"error"<<endl; return 0;}
     else{
 	 int q=m_elems[m_size-1];
 	 cout<<q<<endl;
 	 return q;}
 };
 int size(){
 	return m_size;
 };
 void clear(){
 	m_size=0;
 	cout<<"ok"<<endl;
 };
};

int main(){
	int n; string b; stack g;
	do{
		cin>>b;
		if(b=="push"){
			cin>>n;
			g.push(n);
		}
		if(b=="pop")   g.pop();
		if(b=="back")  g.back();
		if(b=="size")  cout<<g.size();
		if(b=="clear") g.clear();
	} while(b!="exit");
	cout<<"bye"<<endl;
	}
