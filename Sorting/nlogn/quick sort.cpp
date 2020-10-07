/*
	Date: 03/09/2020
	Author: Dharm Vashisth
	Description: Implementation of quick Sort.
*/
#include<iostream>
#include<stdlib.h>
#define n 100
using namespace std;
void swap(int &a,int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
int partition (int arr[], int low, int high) 
{ 
	int i,j;
	int p=arr[low];
	i=low+1;
	j=high;
	do{
 		while(arr[i]<p){
 			i++;
		 }
		while(arr[j]>p){
			j--;
		}
		if(i<j){
			swap(arr[i],arr[j]);
		}
	}while(i<j);
	swap(arr[j],arr[low]);
	return j;
} 
void quickSort(int ar[], int low, int high) 
{ 
	int p;
    if (low < high) 
    { 
        p = partition(ar, low, high); 

        quickSort(ar, low, p - 1); 
        quickSort(ar, p + 1, high); 
    } 
}
void print(int ar[]){
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ";
	}
	cout<<endl;
}
int main(){
	system("cls");
	
	int ar[n];
	int e;
	cout<<"Insertion in an array\n";
	for(int i=0;i<n;i++){
		e=rand()%621;
		ar[i]=e;
	}
	print(ar);
	cout<<endl;
	cout<<"\nSorting using Quick Sort"<<endl;
	quickSort(ar,0,n-1);
	cout<<"\nFinal Sorted Array\n";
	print(ar);
	system("pause");
	return 0;
}
 
