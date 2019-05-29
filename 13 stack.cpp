#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;
 void Stack::push(int n){
     if(m_size == *m_elems){
         int *b_elems = new int[m_size+1];
         for(int i=0;i<m_size;i++)
             b_elems[i]=m_elems[i];
             delete[] m_elems;
        m_elems = new int[m_size+1];
        for(int i=0;i<m_size;i++)
             m_elems[i]=b_elems[i];
        delete[] b_elems;}
 	m_elems[m_size]=n;
 	m_size++;}

 int Stack::pop(){
 	int q;
 	m_size--;
 	q=m_elems[m_size];
 	m_elems[m_size]=0;
 	cout<<q<<endl;
 	return q;
 };
 int Stack::back(){
 	 int q=m_elems[m_size-1];
 	 cout<<q<<endl;
 	 return q;
 };
 int Stack::size(){
 	return m_size;
 };
 void Stack::clear(){
 	m_size=0;
 	cout<<"ok"<<endl;
 };
