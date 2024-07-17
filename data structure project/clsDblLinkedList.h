#pragma once
#include<iostream>
using namespace std;
 
template <class T>
class clsDblLinkedList
{
protected:
	int _Size = 0;
public:
	class Node
	{
	public:
		T value;
		Node* next;
		Node* prev;
	};
	Node* head = NULL;
	void InsetAtBeginning(T value)
	{
		Node* newnode = new Node;
		newnode->value = value;
		newnode->next = head;
		newnode->prev = NULL;
		if (head)
			head->prev = newnode;
		head = newnode;
		_Size++;
	}

	void PrintList()
	{
		Node* Current = head;
		while (Current)
		{
			cout << Current->value << " ";
			Current = Current->next;
		}
		cout << "\n";
	}

	Node* Find(T value)
	{
		Node* Current = head;
		while (Current)
		{
			if (Current->value == value)
				return Current;
			Current = Current->next;
		}
		return NULL;
	}

	void InsertAfter(Node* current, T value)
	{
		Node* newnode = new Node;
		newnode->value = value;
		newnode->next = current->next;
		newnode->prev = current;
		if (current->next)
			current->next->prev = newnode;
		current->next = newnode;
		_Size++;
	}

	void InsertAtEnd(T value)
	{
		Node* newnode = new Node;
		newnode->value = value;
		newnode->next = NULL;
		if (head == NULL)
		{
			newnode->prev = NULL;
			head = newnode;
		}
		else
		{
			Node* current = head;
			while (current->next)
			{
				current = current->next;
			}
			current->next = newnode;
			newnode->prev = current;
		}
		_Size++;

	}

	void DeleteNode(Node*& nodetodelete)
	{
		if (head == NULL || nodetodelete == NULL)
			return;
		if (head == nodetodelete)
			head = nodetodelete->next;
		if (nodetodelete->next)
			nodetodelete->next->prev = nodetodelete->prev;
		if (nodetodelete->prev)
			nodetodelete->prev->next = nodetodelete->next;
		delete nodetodelete; 
		_Size--;

	}

	void DeleteFirstNode()
	{
		if (head == NULL)
			return;
		Node* temp = head;
		head = head->next;
		if (head)
			head->prev = NULL;
		delete temp;
		_Size--;

	}

	void DeleteLastNode()
	{
		if (head == NULL)
			return;
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}
		Node* current = head;
		while (current->next->next)
			current = current->next;
		Node* temp = current->next;
		current->next = NULL;
		delete temp;
		_Size--;

	}
	
	int Size()
	{
		return _Size;
	 }

	bool IsEmpty()
	{
		return _Size;
	}

	void Clear()
	{
		while (_Size)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* current = head;
		Node* temp = nullptr;
		while (current)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}
		if (temp)
			head = temp->prev;
	}

	Node* GetNode(int index)
	{
		int counter = 0;
		if (index<0 || index>_Size - 1)
			return NULL;
		Node* current = head;
		while (current&&current->next)
		{
			if (counter == index)
				break;

			current = current->next;
			counter++;
		}
		return current;
	}

	T GetItem(int index)
	{
		Node* temp = GetNode(index);
	    return temp ? temp->value :NULL;
	}

	bool UpdaateItem(int index, T newvalue)
	{
		Node* Itemnode = GetNode(index);
			if (Itemnode)
			{
				Itemnode->value = newvalue;
				return true;
			}
			else
				return false;

	}

	bool InsertAfter(int index, T value)
	{
		Node* itemnode = GetNode(index);
		if (itemnode)
		{
			InsertAfter(itemnode, value);
			return true;
		}
		return false;

	}


};

