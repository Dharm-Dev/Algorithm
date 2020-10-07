
#include<iostream>
#include<stdlib.h>
#include<list>
#include<iterator>
#define n 30		
using namespace std;
void initarray(list<int> ar[]);
void printArray(list<int> ar[]);
int hashk(int);
int directSearch(list<int> ar[],int e);

int main(){
	// e-element ,st=status	
	int e,st;
	list<int> ar[2*n];
	
	cout<<"Given Array : ";
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
		cout<<e<<" is not found in the given Array"<<endl;
	return 0;
}
int hashk(int k){
	return k%n;
}
void initarray(list<int> ar[]){
	int k,key,total=0;;
	for(int i=0;i<n;i++){
		k=rand()%1000;
		key=hashk(k);
// 		cout<<key<<" => "<<k<<endl;
		ar[key].push_back(k);
		total++;
	}
	cout<<"\n\nTotal Elements in an Array is "<<total<<endl;
}
void printArray(list<int> ar[]){
	int total=0;
	list<int>::iterator itr;
	cout<<"Key => value "<<endl;
	for(int i=0;i<2*n;i++){
		for(itr=ar[i].begin();itr!=ar[i].end();++itr){
			cout<<i<<" => "<<*itr<<" , ";
			total++;
		}
	}
	cout<<"\b\b."<<endl;
}
int directSearch(list<int> ar[],int e){
	int k=hashk(e);
	list<int>::iterator itr;
	for(itr=ar[k].begin();itr!=ar[k].end();++itr){
		if(*itr==e)
			return k;
	}
	return -1;
}

