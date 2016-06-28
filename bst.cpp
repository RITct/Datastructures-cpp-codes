/*
 * This is a free program to show working and implementation of a simple
 * Binary Search Tree  in CPP
 *
 * You are free to use it however as you want.
 *
 * Author doesnt hold responsibility to this code
 *
 * Author : Sidhin S Thomas
 * email: sidhin.thomas@gmail.com
 */


#include <iostream>

using namespace std;

class node{
public:
	int data;
	node* right;
	node* left;
	node(int n){
		data = n ;
		left=right=NULL;
	}
};

class BST {
private:
	node *root;
	void inOrder(node*);
	node* insert(node*,int);
	node* findMin(node*);
	node* remove(node*,int);
public:
	BST(){
		root = NULL;
	}
	void print();
	void insert(int);
	void remove(int);
};

void BST::remove(int n){
	if(root==NULL){
		cout << "Can't delete, empty tree\n";
		return;
	}
	root = remove(root,n);
}
node* BST::findMin(node *ptr){
	if(ptr->left==NULL) return ptr;
	findMin(ptr->left);
}
node* BST::remove(node* ptr,int n){
	if(ptr==NULL){
		cout<< "Element not present\n";
		return NULL;
	}
	//DEBUG : cout << "Node:" << ptr->data << endl ;
	if(ptr->data<n)
		ptr->right = remove(ptr->right,n);
	else if(ptr->data>n)
		ptr->left = remove(ptr->left,n);
	else if (ptr->data == n){
		if(ptr->left){
			if(ptr->right){
				node *min = findMin(ptr->right);
				ptr->data = min->data;
				cout << "case 2\n";
				ptr->right = remove(ptr->right,min->data);
			}
			else{
				node *temp = ptr->left ;
				delete ptr ;
				return temp;
			}
		}
		else if(ptr->right){
			node *temp = ptr->right;
			delete ptr; 
			return temp ;
		}
		else{
			delete ptr;
			return NULL;
		}
	}
	return ptr ;
}
void BST::print(){
	if(root==NULL){
		cout << " Empty tree\n";
		return;
	}
	inOrder(root);
	cout << endl ;
}

void BST::inOrder(node* ptr){
	if(ptr==NULL) return ;
	cout << "(" ;
	inOrder(ptr->left);
	cout << ptr->data  ;
	inOrder(ptr->right);
	cout << ")";
}

void BST::insert(int n){
	if(root!=NULL){
		root=insert(root,n);
	}
	else root = new node(n);
}

node* BST::insert(node* ptr,int n){
	if(ptr == NULL){
		ptr = new node(n);
	}
	else if(ptr->data > n) 
		ptr->left = insert(ptr->left,n);
	else if(ptr->data < n)
		ptr->right = insert(ptr->right,n);
	return ptr ;
}
int main(){
	BST tree ;
	int n = 1;
	while(1){
		cout << "\n1-insert\n2-delete\n";
		cin >> n ;
		switch (n){
			case 1 :
				cin >> n ;
				cout<<"Insert\n";
				tree.insert(n);
				break;
			case 2:
				cin >> n ;
				tree.remove(n);
				break;
		}
		/*
		if(1==n){
			cin >> n ;
			cout<<"Insert\n";
			tree.insert(n);
		}
		else if(n==2){
			cin >> n ;
			tree.remove(n);
		}*/
		tree.print();
	}
}