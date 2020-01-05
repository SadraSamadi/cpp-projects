#include <iostream>
#include "BST.h"

using namespace std;

int main(void)
{
	BST<int> bst;
	bst.add(13);
	bst.add(14);
	bst.add(6);
	bst.add(9);
	bst.add(8);
	bst.add(22);
	bst.add(1);
	bst.add(10);
	bst.add(5);
	bst.add(-1);
	bst.add(15);
	bst.remove(-1);
	cout << (bst.exist(15) ? "true" : "false") << endl;
	cout << (bst.exist(14) ? "true" : "false") << endl;
	cout << (bst.exist(22) ? "true" : "false") << endl;
	cout << (bst.exist(-1) ? "true" : "false") << endl;
	return 0;
}