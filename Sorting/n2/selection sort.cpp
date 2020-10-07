/*
	Date: 26/08/2020
	Author: Dharm Vashisth
	Description: Implementation of Selection Sort. 

*/
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define n 120
using namespace std;
void selectionSort(int ar[]);
int min(int ar[],int i);
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
	
	cout<<setw(60)<<"Sorted Array using Selection Sort\n\n";
	selectionSort(ar);
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
void selectionSort(int ar[]){
	int tmp,key;
	long itr=0;
	for(int i=0;i<n-1;i++){
		key=min(ar,i);
		
		tmp=ar[i];
		ar[i]=ar[key];
		ar[key]=tmp;
		itr++;
	}
	result(itr);
}
void result(long itr){	
	cout<<setw(60)<<"Total Iteration taken in Selection Sorting :"<<itr<<endl;
}
int min(int ar[],int i){
	int minele;
	minele=i;
	for(int j=i+1;j<n;j++){
		if(ar[j]<ar[minele]){
			minele=j;	
		}
	}
	return minele;
}
