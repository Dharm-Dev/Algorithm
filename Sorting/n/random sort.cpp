/*
	Date: 04/09/2020
	Author: Dharm Vashisth
	Description: Implementation of randomized select.
*/
#include<iostream>
#include<stdlib.h>
#define n 20
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
int randomSort(int ar[], int low, int high,int k) 
{ 
	int p;
	if(low==high)
		return ar[low];
	
    p = partition(ar, low, high); 
    p=p-low+1;
		if(k==p){
			cout<<ar[k]<<endl;
			return ar[k];
		}
		else if(k<p)
        	randomSort(ar, low, p-1 ,k); 
        else
			randomSort(ar, p + 1, high,k-p+low-1); 
		cout<<"2."<<ar[k]<<endl;
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
	cout<<"\nSorting using Random Sort"<<endl;
	int k=0;
	k=randomSort(ar,0,n-1,5);
	cout<<k<<endl;
	cout<<"\nFinal Sorted Array\n";
	print(ar);
	system("pause");
	return 0;
}
 
