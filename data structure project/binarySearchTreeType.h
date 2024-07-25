#pragma once
#include<iostream>
using namespace std;

class binarySearchTreeType
{

protected :
	int _size = 0;
	
public:

	~binarySearchTreeType()
	{
		destroy(root);
	}
	class BstNode
	{
	public:
		int value;
		BstNode* left;
		BstNode* right;
	};
	
	BstNode* root = NULL;
	
	static BstNode* Insert(BstNode *&Root,int value)
	{
		if (!Root)
		{
			Root = new BstNode;
			Root->value = value;
			Root->left = Root->right = NULL;
			return Root;
		}
		else if(value <= Root->value)
		{
			Root->left = Insert(Root->left, value);

		}
		else 
		{
			Root->right = Insert(Root->right, value);
		}
		return Root;
	}

	void Insert(int value)
	{
		Insert(root, value);
	}

	static bool Search(BstNode* Root, int value)
	{
		if (!Root)
			return false;
		else if (Root->value == value)
			return true;
		else if (value <= Root->value)
			return Search(Root->left, value);
		else  
			return Search(Root->right, value);
	}
	bool Search(int value)
	{
		return Search(root, value);
	}

	static int  FindMin(BstNode* Root)
	{
		if (!Root) {
			cout << "Error:Tree is empty\n";
			return -1;
		}
		while (Root->left)
		{
			Root = Root->left;
		}
		return Root->value;
	}
	int FindMin()
	{
		return FindMin(root);

	}

	static int  FindMax(BstNode* Root)
	{
		if (!Root) {
			cout << "Error:Tree is empty\n";
			return -1;
		}
		while (Root->right)
		{
			Root = Root->right;
		}
		return Root->value;
	}
	int FindMax()
	{
		return FindMax(root);

	}

	static int  height(BstNode* Root)
	{
		if (!Root)
			return -1;
		int leftheight = height(Root->left);
		int rightheight = height(Root->right);
		return max(leftheight, rightheight)+1;
	}
	int height()
	{
		return height(root);
	}




private:
	void destroy(BstNode* node)
	{
		if (node)
		{
			destroy(node->left);
			destroy(node->right);
			delete node;
		}
	}


};

