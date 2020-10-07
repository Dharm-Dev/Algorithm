/*
	Date: 27/08/2020
	Author: Dharm Vashisth
	Description: Implementation of Heap Sort.
*/
#include<iostream>
#include<stdlib.h>
#define len 10
using namespace std;
void swap(int &a,int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
class Heap{
	int *ar;
	int n,curSize;
	public:
		
		Heap(int sz){
			n=sz;
			curSize=1;
			ar=new int[n];
		}
		void insert(int key){
			int i;
			i=curSize;
			while(i>1&&(ar[i/2])<key)
			{
				ar[i]=ar[i/2];
				i=i/2;
			}
			ar[i]=key;
			curSize++;			
		}
		void adjust(){
			int tmp;
			swap(ar[1],ar[curSize-1]);
//			tmp=ar[curSize-1];
//			ar[curSize-1]=ar[1];
//			ar[1]=tmp;			
			curSize--;
			int j=2;
			while(j<curSize-1){
				if(ar[j]<ar[j+1])
					j=j+1;
				if(ar[j]>ar[j/2]){
					swap(ar[j/2],ar[j]);
//					tmp=ar[j/2];
//					ar[j/2]=ar[j];
//					ar[j]=tmp;
				}
				j*=2;
			}
		}
		void print(){
			for(int i=1;i<=n;i++)
				cout<<ar[i]<<" ";
			cout<<endl;
		}
};
int main(){
	system("cls");
	
	Heap H(len);
	int e;
	cout<<"Insertion in an array\n";
	for(int i=1;i<=len;i++){
		e=rand();
		cout<<i<<" ";
		H.insert(i);
	}
		
	cout<<endl;
	cout<<"\nSorting using Max Heap Sort"<<endl;
	for(int i=0;i<len;i++){
		cout<<"\nStep "<<i+1<<endl;
		H.print();
		H.adjust();
	}
	cout<<"\nFinal Sorted Array\n";
	H.print();
	system("pause");
	return 0;
}
