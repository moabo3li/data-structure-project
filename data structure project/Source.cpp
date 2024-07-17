#include <iostream>
#include "clsDblLinkedList.h"
#include <chrono>
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
	auto start = std::chrono::high_resolution_clock::now();
	
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> duration = end - start;
	std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
	
	return 0;
}