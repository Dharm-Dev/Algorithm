#include<iostream>
#include<stdlib.h>
#include<iomanip>
#define n 12
#define deno 25
#define ele 9
using namespace std;
struct Btree{
	int data;
	Btree *parent;
	Btree *left;
	Btree *right;
} *root=NULL;
void insertBST(int d){
	Btree *tmp,*node,*tmp2;
	
	node=new Btree;
	node->data=d;
	node->parent=node->left=node->right=NULL;
	
	if(root==NULL){
		root=node;	
	}
	else{
		tmp=tmp2=root;
		
		while(tmp!=NULL){
			tmp2=tmp;
			if(tmp->data < d){
				tmp=tmp->right;
			}
			else
				tmp=tmp->left;
		}
		tmp=tmp2;
		if(tmp->data<d)
			tmp->right=node;
			
		else
			tmp->left=node;
			
		node->parent=tmp;
	}
	cout<<d<<", ";
}
void displayNode(Btree *root){
	cout<<endl;
	cout<<setw(50)<<setfill('=');
	cout<<" Node  : "<<root->data<<endl;
	if(root->parent!=NULL)
		cout<<"Parent: "<<root->parent->data<<endl;
	else
		cout<<" *****Root Node***** "<<endl;
	if(root->left!=NULL)
		cout<<"Left  : "<<root->left->data<<endl;
	else
		cout<<"Left  : NULL"<<endl;
	if(root->right!=NULL)
		cout<<"Right : "<<root->right->data<<endl;
	else
		cout<<"Right : NULL"<<endl;
	

	cout<<endl;
}
Btree* search(int d){
	Btree *tmp,*tmp2;
	tmp=root;
	while(tmp!=NULL){
			tmp2=tmp;
			if(tmp->data < d){
				tmp=tmp->right;
			}
			else if(tmp->data==d){
				return tmp;
			}
			else
				tmp=tmp->left;
	}
	return NULL;	
}
void inshow(Btree *root){
	if(root==NULL){
		return;
	}
	inshow(root->left);
	displayNode(root);
	inshow(root->right);	
}
void preshow(Btree *root){
	if(root==NULL){
		return;
	}
	displayNode(root);
	preshow(root->left);
	preshow(root->right);	
}
void postshow(Btree *root){
	if(root==NULL){
		return;
	}
	postshow(root->left);
	postshow(root->right);
	displayNode(root);
}
void deleteBST(int d){
	Btree *tmp;
	tmp=search(d);
	if(tmp==NULL)
		cout<<"!!Element Doesn't Exists\n";
	else{
		
		cout<<"Deleting node "<<d<<" from BST ...\n";
		Btree *point,*tmp2;
		tmp=tmp2=root;
//		getting the node to be deleted.
		while(tmp!=NULL){
				tmp2=tmp;
				if(tmp->data < d){
					tmp=tmp->right;
				}
				else if(tmp->data==d)	
					break;
				else
					tmp=tmp->left;
		}
		tmp=tmp2;
		displayNode(tmp);
//	3 cases arise.	
		if(tmp->left==NULL && tmp->right==NULL){
			/*deletion with no child
			identifying deleted node is parent left or right*/
			if(tmp->parent->left==tmp)
				tmp->parent->left=NULL;
			else
				tmp->parent->right=NULL;
			/*Delete the node*/	
			tmp->parent=tmp->left=tmp->right=NULL;
			delete(tmp);
		}
		
		
		else if(tmp->left!=NULL&&tmp->right!=NULL){
			/*
			deletion with two children Successor
			our task is to find it's successor.
			*/
			point=tmp;
			tmp=tmp->right;
			
			if(tmp->left==NULL){  /*no left child exists for successor.*/
				tmp->parent=point->parent;
				
				if(point->parent->left==point)
					point->parent->left=tmp;
				else
					point->parent->right=tmp;
				point->right=NULL;
				tmp->left=point->left;
				tmp->left->parent=tmp;
				tmp=point;
			}
			else{
				while(tmp->left!=NULL){
				tmp=tmp->left;
				}
				/*tmp needs to be deleted. and deallocate it from it's parent.*/
				/*identifying successor is parent left or right*/
				if(tmp->parent->left==tmp)
					tmp->parent->left=NULL;
				else
					tmp->parent->right=NULL;
	
				displayNode(point);
				displayNode(tmp);
				/*copy data to point*/
				point->data=tmp->data;	
			}
						
			/*delete the node*/		
			tmp->left=tmp->right=tmp->parent=NULL;
			delete(tmp);
		}
		
		else {
			/*
			deletion with one child.
			swap child and parent.
			*/
			if(tmp->left==NULL){
				tmp2=tmp->right;
				tmp2->parent=tmp->parent;
			}
			else{
				tmp2=tmp->left;
				tmp2->parent=tmp->parent;	
			}
 			/*identifying deleted node is parent left or right*/
			if(tmp->parent->left==tmp)
				tmp->parent->left=tmp2;
			else
				tmp->parent->right=tmp2;
			/*Delete the node*/
			tmp->parent=tmp->left=tmp->right=NULL;
			delete(tmp);
		}
	}
}

int main(){
	system("cls");
	cout<<"Program started on BST\n";
	Btree *tmp;	//searching
	int e;
	cout<<"Insertion in BST ";
	for(int i=0;i<n;i++){
		e=rand()%deno;
		insertBST(e);
	}
	cout<<"\b\b."<<endl;
	e=rand()%deno;
	
	cout<<"\nSearching "<<ele<<" in the BST...\n";
	tmp=search(ele);
	if(!tmp){
		cout<<"\nResult : Element does not Exists\n";
	}	
	else
	{
		cout<<"\nElement Found at node given below:\n";
		displayNode(tmp);		
	}
	
	cout<<setw(80)<<setfill('>');	
	cout<<setw(70)<<"Preorder Traversal \n";
	preshow(root);
	
	deleteBST(ele);	
	
	cout<<setw(80)<<setfill('>');	
	cout<<setw(70)<<"Inorder Traversal \n";
	inshow(root);
	
	cout<<setw(80)<<setfill('>');	
	cout<<setw(70)<<"Postorder Traversal \n";
	postshow(root);
		
	cout<<endl;

	return 0;
}
