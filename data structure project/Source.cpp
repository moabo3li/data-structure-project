#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;
int main()
{
	clsDblLinkedList<int > MydblLinkedList;
	MydblLinkedList.InsetAtBeginning(5);
	MydblLinkedList.InsetAtBeginning(4);
	MydblLinkedList.InsetAtBeginning(3);
	MydblLinkedList.InsetAtBeginning(2);
	MydblLinkedList.InsetAtBeginning(1);

	MydblLinkedList.InsertAfter(1, 500);


	MydblLinkedList.PrintList();

	clsDblLinkedList<int >::Node* N;
	
	
	return 0;
}