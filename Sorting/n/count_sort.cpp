/*
	Date: 3/09/2020.
	Author: Dharm Vashisth.
	Description: Implement Count Sort.
*/
#include<iostream>
#include<stdlib.h>
#define n 100
using namespace std;
void print(int ar[],int size){
	for(int i=0;i<size;i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
int max(int ar[]){
	int max=ar[0];
	for(int i=1;i<n;i++){
		if(max<ar[i])
			max=ar[i];
	}
	return max;
}
void countSort(int ar[]){
	int sz=max(ar)+1;
	int c[sz];
	int b[n];
	int k;
	cout<<"\n Intermediate Steps : "<<endl;
	for(int i=0;i<sz;i++){
		c[i]=0;
	}
	
	for(int i=0;i<n;i++){
		c[ar[i]]++;
	}
	cout<<"Count Array : ";
	print(c,sz);
	
	for(int i=1;i<sz;i++){
		c[i]+=c[i-1];
	}
	
	cout<<"Commulative Count Array : ";
	print(c,sz);
		
//	reverse starting of an array as it is Stable sort.
	for(int i=n-1;i>=0;i--){
		k=c[ar[i]];
		c[ar[i]]--;
		b[k-1]=ar[i];
	}
	
	for(int i=0;i<n;i++){
		ar[i]=b[i];
	}
	cout<<"\nCount Sort Completed.\n";
}
int main(){
	int ar[n];
	
	for(int i=0;i<n;i++){
		ar[i]=rand()%15;
	}
	
	cout<<"Given Array : ";
	print(ar,n);
	
	countSort(ar);
	
	cout<<"Sorted Array using count sort : ";
	print(ar,n);
	cout<<endl;
}
