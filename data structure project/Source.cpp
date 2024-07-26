#include<iostream>
#include<cstdlib>
#include"binarySearchTreeType.h"

using namespace std;
int main()
{
	srand(time(0));
	binarySearchTreeType tree;
	int n;
	for(int i =0;i<10000;i++)
	{
		n = rand();
		tree.Insert(n);
	}
	tree.Printlevel_order();
	
	cout << tree.Search(13) << endl;
	cout << tree.FindMin() << endl;
	cout << tree.FindMax() << endl;

	return 0;
}
