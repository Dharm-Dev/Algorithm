#include<iostream>
#include<stdlib.h>
#define n 30		
using namespace std;
void initarray(int ar[]);
void printArray(int *ar);
int hash(int);
int directSearch(int *ar,int e);

int main(){
	system("cls");
	// e-element ,st=status	
	int e,st;
	int ar[n];
	
	cout<<"Given Array : \n";
	initarray(ar);
	
	printArray(ar);
	cout<<"\nEnter an integer element to search in an Array\t";
	cin>>e;
	
	st=directSearch(ar,e);
	cout<<endl;
	
	if(st!=-1){
		cout<<"==>Element Found at index "<<st<<endl;
	}
	else
		cout<<e<<" is not found in the given Array (may be because of collision) "<<endl;
	system("pause");
	return 0;
}
int hash(int k){
	return k%n;
}
void initarray(int ar[]){
	int k,key,total=0;;
	for(int i=0;i<n;i++)
		ar[i]=0;
	for(int i=0;i<n/2;i++){
		k=rand();
		key=hash(k);
		cout<<key<<" => "<<k<<" , ";
		ar[key]=k;
		total++;
	}
	cout<<"\b\b."<<endl;
	cout<<"\n\nTotal Elements in an Array is "<<total<<endl;
}
void printArray(int *ar){
	int total=0;
	cout<<endl;
	for(int i=0;i<n;i++){
		if(ar[i]!=0){
			cout<<ar[i]<<" ,";
			total++;
		}
			
		else
			cout<<" _ , ";
	}
	
	cout<<"\b."<<endl;
	cout<<"\n\nTotal Elements available "<<total;
}
int directSearch(int *ar,int e){
	int k=hash(e);
	if(ar[k]==e)
			return k;
	return -1;
}

