#include<bits/stdc++.h>
#define n 8
#define deno 25
#define ele 9
using namespace std;
struct Btree{
	int data;
	int color;/*o for black*/
	Btree *parent;
	Btree *left;
	Btree *right;
} *root=NULL;


void rotateLeft(Btree *&pt) 
{ 
    Btree *pt_right = pt->right; 
    pt->right = pt_right->left; 
  
    if (pt->right != NULL) 
        pt->right->parent = pt; 
    pt_right->parent = pt->parent; 
    if (pt->parent == NULL) 
        root = pt_right; 
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_right; 
    else
        pt->parent->right = pt_right; 
  
    pt_right->left = pt; 
    pt->parent = pt_right; 
} 
  
void rotateRight(Btree *&root, Btree *&pt) 
{ 
    Btree *pt_left = pt->left; 
  
    pt->left = pt_left->right; 
  
    if (pt->left != NULL) 
        pt->left->parent = pt; 
  
    pt_left->parent = pt->parent; 
  
    if (pt->parent == NULL) 
        root = pt_left; 
  
    else if (pt == pt->parent->left) 
        pt->parent->left = pt_left; 
  
    else
        pt->parent->right = pt_left; 
  
    pt_left->right = pt; 
    pt->parent = pt_left; 
} 
void balanceColor(Btree *pt) 
{ 
    Btree *parent_pt = NULL; 
    Btree *grand_parent_pt = NULL; 
  
    while ((pt != root) && (pt->color != 0) && 
           (pt->parent->color == 1)) 
    { 
  
        parent_pt = pt->parent; 
        grand_parent_pt = pt->parent->parent; 
  
        /*  Case : A 
            Parent of pt is left child of Grand-parent of pt */
        if (parent_pt == grand_parent_pt->left) 
        { 
  
            Btree *uncle_pt = grand_parent_pt->right; 
  
            /* Case : 1 
               The uncle of pt is also red 
               Only Recoloring required */
            if (uncle_pt != NULL && uncle_pt->color == 1) 
            { 
                grand_parent_pt->color = 1; 
                parent_pt->color = 0; 
                uncle_pt->color = 0; 
                pt = grand_parent_pt; 
            } 
  
            else
            { 
                /* Case : 2 
                   pt is right child of its parent 
                   Left-rotation required */
                if (pt == parent_pt->right) 
                { 
                    rotateLeft(parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is left child of its parent 
                   Right-rotation required */
                rotateRight(root, grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
  
        /* Case : B 
           Parent of pt is right child of Grand-parent of pt */
        else
        { 
            Btree *uncle_pt = grand_parent_pt->left; 
  
            /*  Case : 1 
                The uncle of pt is also red 
                Only Recoloring required */
            if ((uncle_pt != NULL) && (uncle_pt->color == 1)) 
            { 
                grand_parent_pt->color = 1; 
                parent_pt->color = 0; 
                uncle_pt->color = 0; 
                pt = grand_parent_pt; 
            } 
            else
            { 
                /* Case : 2 
                   pt is left child of its parent 
                   Right-rotation required */
                if (pt == parent_pt->left) 
                { 
                    rotateRight(root, parent_pt); 
                    pt = parent_pt; 
                    parent_pt = pt->parent; 
                } 
  
                /* Case : 3 
                   pt is right child of its parent 
                   Left-rotation required */
                rotateLeft(grand_parent_pt); 
                swap(parent_pt->color, grand_parent_pt->color); 
                pt = parent_pt; 
            } 
        } 
    } 
  
    root->color = 0; 
} 
  
void insertRBST(int d){
	
	Btree *tmp,*node,*tmp2;
	node=new Btree;
	node->data=d;
	node->color=1;/*red*/
	node->parent=node->left=node->right=NULL;
	
	if(root==NULL){
		node->color=0;
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
	balanceColor(node);
}


void displayBtree(Btree *root){
	cout<<endl;
	cout<<setw(50)<<setfill('=');
	cout<<" Btree  : "<<root->data<<endl;
	cout<<" Node Color : ";
	root->color?cout<<"Red":cout<<"Black";
	cout<<endl;
	if(root->parent!=NULL)
		cout<<"Parent: "<<root->parent->data<<endl;
	else
		cout<<" *****Root RBtree***** "<<endl;
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
void inshow(Btree *root){
	if(root==NULL){
		return;
	}
	inshow(root->left);
	displayBtree(root);
	inshow(root->right);	
}
int main(){
	system("cls");
	cout<<"Program on RBTree\n";
	Btree *tmp;	//searching
	int e;
	cout<<"Insertion in RBTree ";
	for(int i=0;i<n;i++){
		e=rand()%deno;
		insertRBST(e);
	}

	cout<<"\b\b."<<endl;
	e=rand()%deno;
	
	cout<<setw(80)<<setfill('>');	
	cout<<setw(70)<<"Inorder Traversal \n";
	inshow(root);
		
	cout<<endl;
	return 0;
}
