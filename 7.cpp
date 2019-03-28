#include <iostream>
#include <string>
using namespace std;
const int MAX_SIZE=101;
struct stack {
 int m_size=0; 
 int m_elems[MAX_SIZE]={0}; 
 stack(){
 };
 ~stack(){
 };
 void push(int n){
 	m_elems[m_size]=n;
 	m_size++;
 	cout<<"ok"<<endl;
 };
 int pop(){
 	int q;
 	m_size--;
 	q=m_elems[m_size];
 	m_elems[m_size]=0;
 	return q;
 };
 int back(){
 	m_size--;
 	int q=m_elems[m_size];
 	return q;
 };
 int size(){
 	return m_size;
 };
 void clear(){
 	for(int i=0;i<=m_size;i++){m_elems[i]=0;}
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
		if(b=="pop")   cout<<g.pop();
		if(b=="back")  cout<<g.back();
		if(b=="size")  cout<<g.size();
		if(b=="clear") g.clear();
	} while(b!="exit");
	cout<<"bye"<<endl;
}
