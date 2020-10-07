#include<iostream>
#include<ctime>
#include<iomanip>
#include<stdlib.h>
#define n 100000		
using namespace std;
void initarray(int ar[]);
void printArray(int *ar);
int binarySearch(int *ar,int e,int &itr);

int main(){
	//	initializing Array of n size 
	int ar[n];
	initarray(ar);
	clock_t init,fin;
	// e-element ,itr-iteration , st=status	
	int e,itr,st;
	cout<<"Given Array is in *Ascending Order \n";
//	printArray(ar);
	cout<<"\nEnter an integer element to search\t";
	cin>>e;
	cout<<endl;
	init=clock();
	st=binarySearch(ar,e,itr);
	st=binarySearch(ar,e,itr);
	st=binarySearch(ar,e,itr);
	fin=clock();
	cout<<"Total Iteration taken by Binary Search is "<<itr<<endl;
	long double timeTaken=double(fin-init)/double(CLOCKS_PER_SEC);
	cout<<"Total Time taken is "<<fixed<<timeTaken<<setprecision(10)<<endl;
	if(st!=-1){
		cout<<"==>Element Found at index "<<st<<endl;
	}
	else
		cout<<e<<" not found in  first "<<n<<" natural numbers";

	return 0;
}

void initarray(int ar[]){
	for(int i=0;i<n;i++){
		ar[i]=i+1;
	}
}
void printArray(int *ar){
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ar[i]<<" ,";
	
	}
	cout<<"\b."<<endl;
}
int binarySearch(int *ar,int e,int &itr){
	int b,end,m;
	end=n-1,b=0;
	itr=0;
	cout<<endl;
	while(b<=end){
		m=(b+end)/2;
		itr++;
		
		if(ar[m]==e)
			return m;
		else if(ar[m]>e)
			end=m-1;
		else
			b=m+1;
	}
	cout<<endl;
	return -1;
}
