#include<iostream>
#include<ctime>
#include<stdio.h>
#define n 100000		
using namespace std;
void initarray(int ar[]);
void printArray(int *ar);
int linearSearch(int *ar,int e,int &itr);
int binarySearch(int *ar,int e,int &itr);

int main(){
	//	initializing Array of n size 
	int ar[n];
	initarray(ar);
	int st,e,itr;
	//	printArray(ar);
	time_t s,end;
	clock_t c1,tim;
	c1=clock();
	s=time(NULL);
	cout<<"Enter an integer element to search\t";
	cin>>e;
	
	cout<<endl;
	
	time_t a,b,c,d;
	time(&a);
	
	st=linearSearch(ar,e,itr);
	time(&b);
	//	cout<<"Starting time Linear Search "<<a<<" and Ending time "<<b<<endl;
	cout<<"Total Iteration taken is "<<itr<<endl;
	if(st!=-1){
		cout<<"==>Element Found at index "<<st<<endl;
	}
	else
		cout<<e<<" not found in  first "<<n<<" natural numbers";
	
	cout<<endl<<endl;	
	c=time(NULL);
	st=binarySearch(ar,e,itr);
	d=time(NULL);
	//	cout<<"Starting time Binary Search "<<c<<" and Ending time "<<d<<endl;
	cout<<"Total Iteration taken is "<<itr<<endl;
	if(st!=-1){
		cout<<"==>Element Found at index "<<st<<endl;
	}
	else
		cout<<e<<" not found in  first "<<n<<" natural numbers";
	end=time(NULL);
	cout<<s<<" and "<<end<<".Final time "<<(difftime(end,s))<<endl;
	tim=clock();
	printf("%6.3f\n",c1);
	printf("%6.3f",tim);
	
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
