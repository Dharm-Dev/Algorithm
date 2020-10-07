/*
	Author: Dharm Vashisth
	Description: Implementation of Bubble Sorting using smart flag as well. 
*/
#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define n 200
using namespace std;
void bubbleSort(int ar[]);
void arprint(int ar[]);
void result(long itr,long sitr);
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
	
	
	cout<<setw(60)<<"Sorted Array using Bubble Sort\n\n";
	bubbleSort(ar);
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
void bubbleSort(int ar[]){
	bool swapf,f=1;
	long iswap,tmp,itr=0;
// iswap is for smart iteration count.	

	for(int i=0;i<n-1;i++){
		swapf=0;
		for(int j=0;j<n-1-i;j++){
			if(ar[j]>ar[j+1]){
				tmp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=tmp;
			
				swapf=1;	
			}
			itr++;	
		}
		if(!swapf&& f){
			iswap=itr;
			f=0;	
		}
	}
	result(itr,iswap);
}
void result(long itr,long sitr){	
	cout<<setw(60)<<"Total Iteration taken in Bubble Sorting\n";
	cout<<setw(40)<<"Simple Scan : "<<itr<<endl;
	cout<<setw(40)<<"Smart Scan : "<<sitr<<endl;
}
