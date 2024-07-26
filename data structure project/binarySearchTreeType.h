#pragma once
#include<iostream>
#include<queue>
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
		_size++;
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

	static void Printlevel_order(BstNode* Root)
	{
		queue<BstNode*> temp_q;
		temp_q.push(Root);
		while (!temp_q.empty())
		{
			BstNode* current = temp_q.front();
			cout << current->value << " ";
			if (current->left)
				temp_q.push(current->left);
			if (current->right)
				temp_q.push(current->right);
			temp_q.pop();
		}
		cout << endl;
	}
	void Printlevel_order()
	{
		Printlevel_order(root);
	}

	static void Print_Preorder(BstNode* Root)
	{
		if (!Root) return;
		cout << Root->value << " ";
		Print_Preorder(Root->left);
		Print_Preorder(Root->right);
	}
	void Print_Preorder()
	{
		Print_Preorder(root);
	}

	static void Print_Inorder(BstNode* Root)
	{
		if (!Root) return;
		Print_Inorder(Root->left);
		cout << Root->value << " ";
		Print_Inorder(Root->right);
	}
	void Print_Inorder()
	{
		Print_Inorder(root);
	}
	
	static void Print_Postorder(BstNode* Root)
	{
		if (!Root) return;
		Print_Postorder(Root->left);
		Print_Postorder(Root->right);
		cout << Root->value << " ";
	}
	void Print_Postorder()
	{
		Print_Postorder(root);
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

