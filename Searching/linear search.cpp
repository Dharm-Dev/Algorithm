#include<iostream>
#include<ctime>
#include<stdio.h>
#include<iomanip>
#define n 100000		
using namespace std;
void initarray(int ar[]);
void printArray(int *ar);
int linearSearch(int *ar,int e,int &itr);

int main(){
	//	initializing Array of n size 
	int ar[n];
	initarray(ar);
	// e-element ,itr-iteration , st=status	
	int e,itr,st;
	clock_t strt,end;
	cout<<"Given Array is in *Ascending Order of first"<<n<<" Natural Numbers \n";
//	printArray(ar);
	cout<<"\nEnter an integer element to search\t";
	cin>>e;
	cout<<endl;
	strt=clock();
	st=linearSearch(ar,e,itr);	
	end=clock();
	double time_taken=double(end-strt)/double(CLOCKS_PER_SEC);
	cout<<"Total Iteration taken in Linear Search is "<<itr<<endl;
	cout<<"Time taken : "<<fixed<<time_taken<<setprecision(10)<<endl;
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
int linearSearch(int *ar,int e,int &itr){
	itr=0;
	for(int i=0;i<n;i++){
		itr++;
		if(ar[i]==e)
			return i;
	}
	return -1;
}

