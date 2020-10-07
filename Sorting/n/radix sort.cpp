/*
	Date: 04/09/2020.
	Author: Dharm Vashisth.
	Description: Implement Radix Sort.
*/
#include<iostream>
#include<stdlib.h>
#define n 30
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
void countSort(int ar[],int exp){
	int sz=10;
	int c[sz]={0};
	int b[n];
	int k;
	static int z=1;
	for(int i=0;i<n;i++){
		c[(ar[i]/exp)%10]++;
	}
	for(int i=1;i<sz;i++){
		c[i]+=c[i-1];
	}	
	for(int i=n-1;i>=0;i--){
		k=c[(ar[i]/exp)%10];
		c[(ar[i]/exp)%10]--;
		b[k-1]=ar[i];
	}
	for(int i=0;i<n;i++){
		ar[i]=b[i];
	}
	cout<<"\nIteration : "<<z<<endl;
	z++;
	print(ar,n);
	
}
void radixSort(int ar[]){
	int i,j,k;
	i=max(ar);
	for(j=1;i/j>0;j*=10){
		countSort(ar,j);
	}
}
int main(){
	int ar[n];
	
	for(int i=0;i<n;i++){
		ar[i]=rand()%30000;
	}
	
	cout<<"Given Array : ";
	print(ar,n);
	
	radixSort(ar);
	cout<<endl;
	cout<<"Sorted Array using Radix sort : \n";
	print(ar,n);
	cout<<endl;
}
