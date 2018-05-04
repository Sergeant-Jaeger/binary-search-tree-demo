/*
Author: Aaron Jaeger
*/

#include "BinarySearchTreeDemo.h"

int main() {

	vector<int> vINT(MAX_SIZE);

	for (int i = 0; i < MAX_SIZE; i++) {

		vINT[i] = i;
	}

	random_shuffle(vINT.begin(), vINT.end());

	BinarySearchTree<int> bstINT;

	vector<int>::iterator it;

	for (it = vINT.begin(); it != vINT.end(); it++) {

		bstINT.insert(*it);
	}

	cout << "Beginning Binary Search Tree Demo with Integers." << endl;

	printHeightAndSize(bstINT);

	printInorder(bstINT);

	printPreorder(bstINT);

	printPostorder(bstINT);

	printSearch(bstINT, 7);

	printRemove(bstINT, 7);

	for (int i = 0; i <= 20; i++) {

		if (i % 2 != 0) {

			printRemove(bstINT, i);
		}
	}

	for (int i = 0; i <= 20; i++) {

		printSearch(bstINT, i);
	}

	printHeightAndSize(bstINT);

	printInorder(bstINT);

	cout << endl << endl;

	return 0;
}