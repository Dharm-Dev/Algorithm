/*
	Date: 26/08/2020
	Author: Dharm Vashisth
	Description: Implementation of Insertion Sort. 

*/
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define n 320
using namespace std;
void insertionSort(int ar[]);
void swap(int &a,int &b);
void arprint(int ar[]);
void result(long itr);
int main(){
	system("cls");
	
	int ar[n];
	int i;
//	initializing array
	for(i=0;i<n;i++)
		ar[i]=rand();
	cout<<setw(60)<<"Array Elements before Sorting\n\n";
	cout<<"Total Elements in an array : "<<n<<endl;
	arprint(ar);
	
	cout<<setw(60)<<"Sorted Array using Insertion Sort\n\n";
	insertionSort(ar);
	arprint(ar);

	system("pause");
	return 0;
}
void arprint(int ar[]){
	cout<<endl;
	cout<<"Array : => ";
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" , ";
	cout<<"\b\b."<<endl<<endl;
}
void insertionSort(int ar[]){
	int i,j;
	long itr=0;
	for(i=1;i<n;i++){
		j=i;
		while(j>0 && ar[j]<ar[j-1]){
			swap(ar[j],ar[j-1]);
			j--;
			itr++;
		}
	}
	result(itr);
}
void result(long itr){	
	cout<<setw(60)<<"Total Iteration taken in Selection Sorting :"<<itr<<endl;
}
void swap(int &a,int &b){
	int c;
	c=a;
	a=b;
	b=c;	
}
