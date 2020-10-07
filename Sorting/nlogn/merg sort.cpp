/*
	Date: 04/09/2020
	Author: Dharm Vashisth
	Description: Implementation of Merge Sort.
*/
#include<iostream>
#include<stdlib.h>
#define n 100
using namespace std;
void merge(int ar[], int low, int m, int high) 
{ 
    int i, j, k;
	 
    int n1 = m - low + 1; // size of first array
    int n2 = high - m; 	// size of second array
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = ar[low + i];
		 
    for (j = 0; j < n2; j++) 
        R[j] = ar[m + 1 + j];
		 
    i = 0;
    j = 0;
    k = low;
    
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            ar[k] = L[i]; 
            i++; 
        } 
        else { 
            ar[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
//  if first array is not empty
    while (i < n1) { 
        ar[k] = L[i]; 
        i++; 
        k++; 
    } 
//  if second array is not empty
   while (j < n2) { 
        ar[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
// High will start from n-1 index.
void mergeSort(int ar[], int low, int high) 
{ 
    if (low < high) { 
        int m =(low + high)/ 2; 
  
        mergeSort(ar, low, m); 
        mergeSort(ar, m + 1, high); 
  
        merge(ar, low, m, high); //divide array in two halfs and merg in ascending order.
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
	cout<<"\nSorting using Merg Sort"<<endl;
	mergeSort(ar,0,n-1);
	cout<<"\nFinal Sorted Array\n";
	print(ar);
	system("pause");
	return 0;
}
 
