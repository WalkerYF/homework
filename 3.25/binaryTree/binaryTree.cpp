#include "binaryTree.h"
#include <iostream>
using std::cout;

void BinaryTree::MemoryDelete(node* p){
	if (p == nullptr)
		return ;
	if (p->left == nullptr && p->right == nullptr){
		return;
	}

	MemoryDelete(p->left);
	delete p->left;
	p->left = nullptr;

	MemoryDelete(p->right);
	delete p->right;
	p->right = nullptr;


}

void BinaryTree::BuildTree(const node* Source_Root, node* &Target_Root)
{
	if (Source_Root == nullptr)
		return ;

	Target_Root = new node(Source_Root->ele);
	Target_Root->left = nullptr;
	Target_Root->right = nullptr;

	if (Source_Root->left != nullptr){
		BuildTree(Source_Root->left, Target_Root->left);
	}
	if (Source_Root->right != nullptr){
		BuildTree(Source_Root->right, Target_Root->right);
	}
}
void BinaryTree::BuildTree(const int* arr,int len, node* &root)
{
	root = new node(arr[0]);

	for (int i = 1; i < len; i++){
		node * p = root;
			while (1){
				if (arr[i] == p->ele)
					break;
				if (arr[i] > p->ele){
					if (p->right == nullptr){
						node * pRight = new node(arr[i]);
						p->right = pRight;
						break;
					}
					else {// p->right != nullptr
						p = p->right;
						continue;
					}
				}
				else{//arr[i] < p->ele
					if (p->left == nullptr){
						node * pLeft = new node(arr[i]);
						p->left = pLeft;
						break;
					}
					else {// p->left != left
						p = p->left;
						continue;
					}
				}
			}
	}


	// if (len == 0)
	// 	return ;
	// if (root == nullptr){
	// 	root = new node(arr[0]);
	// 	root->left = nullptr;
	// 	root->right = nullptr;
	// }

	// if (arr[1] < root->ele)
	// 	BuildTree(arr+1, len-1, root->left);
	// if (arr[1] > root->ele)
	// 	BuildTree(arr+1, len-1, root->right);




}
void BinaryTree::preorder(const node* p)
{
	if (p == nullptr){
		return ;
	}
	cout << p->ele << " ";
	preorder(p->left);

	preorder(p->right);
}

BinaryTree::BinaryTree()
{
	root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree& old){
	this->root = nullptr;
	BuildTree(old.root, this->root);
}

BinaryTree::BinaryTree(const int* arr, int len){
	this->root = nullptr;
	BuildTree(arr,len,this->root);
}

void BinaryTree::ResetTree(const int* arr, int len){
	clear();
	BuildTree(arr, len, this->root);
}

BinaryTree::~BinaryTree(){
	clear();
}

void BinaryTree::clear(){
	if (root == nullptr)
		return ;
	MemoryDelete(root);
	delete root;
	root = nullptr;
}

void BinaryTree::insert(int ele)
{
	node * p = root;
	if (root == nullptr){
		root = new  node(ele);
		return ;
	}
		while (1){
			if (ele == p->ele)
				break;
			if (ele > p->ele){
				if (p->right == nullptr){
					node * pRight = new node(ele);
					p->right = pRight;
					break;
				}
				else {// p->right != nullptr
					p = p->right;
					continue;
				}
			}
			else{//arr[i] < p->ele
				if (p->left == nullptr){
					node * pLeft = new node(ele);
					p->left = pLeft;
					break;
				}
				else {// p->left != left
					p = p->left;
					continue;
				}
			}
		}
}

void BinaryTree::Delete(int ele){
	if (root == nullptr)
		return ;
	node * p = root;
	node * pp = root;
	while (p != nullptr && p->ele != ele){
		if (ele < p->ele){
			pp = p;
			p = p->left;
		}
		else{
			pp = p;
			p = p->right;
		}
	}
	//can not find the element
	if (p == nullptr)
		return ;
	//
	if (p->left == nullptr && p->right == nullptr){

		if (p == root){
			delete p;
			root = nullptr;
			return ;
		}

		if (p->ele < pp->ele)
			pp->left = nullptr;
		else
			pp->right = nullptr;
		delete p;
		return ;
	}

	if (p->left == nullptr ){
		node * temp = p->right;
		p->ele = temp->ele;
		p->left = temp->left;
		p->right = temp->right;
		// bug  ,enter left by mistake;
		delete temp;
		return ;
	}

	// The follows is the condition that
	// left child exists
	if (p->left->right == nullptr){
		node * temp = p->left;
		p->ele = temp->ele;
		p->left = temp->left;
		delete temp;
		return ;
	}

	if (p->left->right != nullptr){
		node * mostRnode = p->left;
		node * mostRnode2 = p->left;
		while(mostRnode->right != nullptr){
			mostRnode2 = mostRnode;
			mostRnode = mostRnode->right;
		}
		node * left_mostRnode = mostRnode->left;
		p->ele = mostRnode->ele;
		mostRnode2->right = left_mostRnode;
		delete mostRnode;
		return ;
	}
}

void BinaryTree::print(){
	preorder(root);
	cout << endl;
}
