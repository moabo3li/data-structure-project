#include<iostream>
#include"binarySearchTreeType.h"
using namespace std;
int main()
{
	binarySearchTreeType tree;
	tree.Insert(30);
	tree.Insert(20);
	tree.Insert(10);
	tree.Insert(5);
	tree.Insert(8);
	tree.Insert(2);
	tree.Insert(1);
	tree.Insert(65);
	tree.Insert(34);
	tree.Insert(13);
	cout << tree.Search(13) << endl;
	cout << tree.FindMin() << endl;
	cout << tree.FindMax() << endl;

	return 0;
}
