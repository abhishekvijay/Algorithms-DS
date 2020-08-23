

#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <iostream>

typedef struct TREENODE
{
	int val;
	TREENODE* left;
	TREENODE* right;
} Node;

Node* getNode(int x)
{
	Node* temp =  NULL;

	temp = (Node *)malloc(sizeof(Node));
	if (temp != NULL) {
		temp->left = NULL;
		temp->right = NULL;
		temp->val = x;
	}
	return temp;
}

void setRight(Node* tree, int x)
{
	if (tree == NULL) {
		std::cout<<"invalid tree"<<std::endl;
		return;
	}

	if (tree->right != NULL) {
		std::cout<<"duplicate node"<<std::endl;
		return;
	}

	tree->right = getNode(x);
	return;
}

void setLeft(Node* tree, int x)
{
	if (tree == NULL) {
		std::cout<<"invalid tree"<<std::endl;
		return;
	}

	if (tree->left != NULL) {
		std::cout<<"duplicate node"<<std::endl;
		return;
	}

	tree->left = getNode(x);
	return;
}

void preOrderTraversal(Node* tree)
{
	if (tree != NULL)
	{
		std::cout<<tree->val<<std::endl;

		preOrderTraversal(tree->left);		

		preOrderTraversal(tree->right);
	}
}

void postOrderTraversal(Node* tree)
{
	if (tree != NULL)
	{
		postOrderTraversal(tree->left);

		postOrderTraversal(tree->right);

		std::cout<<tree->val<<std::endl;
	}
}

void inOrderTraversal(Node* tree)
{
	if (tree != NULL)
	{
		inOrderTraversal(tree->left);

		std::cout<<tree->val<<std::endl;

		inOrderTraversal(tree->right);
	}
}

void insert_binary_tree()
{
	int arr[7] = {105,110,120,80,90,95,100};
	register int i;

	Node* tree = NULL, *p = NULL, *q = NULL;

	for(i=0; i<7; ++i) 
	{
		if (tree == NULL) 
		{
			tree = getNode(arr[i]);
			continue;
		}

		p = q = tree;

		while(arr[i] != p->val && q != NULL)
		{
			p = q;

			if (q->val < arr[i])
				q = q->right;
			else
				q = q->left;
		}

		if (p->val == arr[i])
		{
			std::cout<<"duplicate insertion"<<std::endl;
			break;
		}
		else if (p->val < arr[i])
			setRight(p, arr[i]);
		else if (p->val > arr[i])
			setLeft(p, arr[i]);
	}

	std::cout<<"pre-order elements"<<std::endl;

	preOrderTraversal(tree);

	return;
}