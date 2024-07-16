#pragma once
#include<iostream>
using namespace std;
 
template <class T>
class clsDblLinkedList
{
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
		newnode->next = head->next;
		newnode->prev = NULL;
		if (head)
			head->prev = newnode;
		head = newnode;
	}

	void PrintList()
	{
		Node* Current = head;
		while (cur)
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
	}


};

