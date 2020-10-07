/*
	Date: 04/09/2020.
	Author: Dharm Vashisth.
	Description: Implement Bucket Sort.
*/
#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#define n 20
using namespace std;
void print(float ar[],int size){
	for(int i=0;i<size;i++){
		cout<<ar[i]<<"\t";
	}
	cout<<endl;
}
void bucketSort(float ar[]){
	
	list<float> b[10];
	list<float>::iterator itr;
	int i,j,k;
	
	for(i=0;i<n;i++){
		j=ar[i]*10;
		b[j].push_back(ar[i]);	
	}
	cout<<"\nBucket without internal Sorting:\n";
	for(k=0;k<10;k++){
		cout<<k<<"  = > ";
		for(itr=b[k].begin();itr!=b[k].end();itr++){
			cout<<*itr<<" , ";
		}
		cout<<endl<<endl;
	}
	j=0;
	for(k=0;k<10;k++){
		
		if(b[k].size()>0)
		{
			b[k].sort();	//internal sorting	
			for(itr=b[k].begin();itr!=b[k].end();itr++)
				ar[j++]=*itr;
		}
	}
	cout<<"\nBucket after internal Sorting:\n";
	for(k=0;k<10;k++){
		cout<<k<<"  = > ";
		for(itr=b[k].begin();itr!=b[k].end();itr++){
			cout<<*itr<<" , ";
		}
		cout<<endl<<endl;
	}
}
int main(){
	float ar[n];
	
	for(int i=0;i<n;i++){
		ar[i]=(float)(rand()%1000)/1000;
	}
	
	cout<<"Given Array :\n";
	print(ar,n);
	
	bucketSort(ar);
	
	cout<<"Array after internal sorting using Bucket sort :\n";
	print(ar,n);
	cout<<endl;
}
