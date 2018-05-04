/*
Author: Aaron Jaeger
*/

#ifndef BINARYSEARCHTREEDEMO_H
#define BINARYSEARCHTREEDEMO_H

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "BinarySearchTree.h"

using std::cout;
using std::endl;
using std::setw;
using std::vector;

const int MAX_SIZE = 20;
const int WIDTH = 5;
const int ROW_SIZE = 5;

int rowCount = 0;

template <class T>
void printNode(T data) {

	cout << setw(WIDTH) << data;

	rowCount++;

	if (rowCount == ROW_SIZE) {

		cout << endl;

		rowCount = 0;
	}
}

template <class T>
void printHeightAndSize(BinarySearchTree<T> bst) {

	cout << endl << "Integer Binary Search Tree Height: " << bst.height()
		<< endl << "Integer Binary Search Tree Size: " << bst.size();
}

template <class T>
void printInorder(BinarySearchTree<T> bst) {

	cout << endl << endl << "In-order traversal:" << endl;

	rowCount = 0;

	bst.inorder(printNode);
}

template <class T>
void printPreorder(BinarySearchTree<T> bst) {

	cout << endl << endl << "Pre-order traversal:" << endl;

	rowCount = 0;

	bst.preorder(printNode);
}

template <class T>
void printPostorder(BinarySearchTree<T> bst) {

	cout << endl << endl << "Post-order traversal:" << endl;

	rowCount = 0;

	bst.postorder(printNode);
}

template <class T>
void printSearch(BinarySearchTree<T> bst, T sData) {

	cout << endl << "Searching for " << sData << ": ";

	if (bst.search(sData)) {

		cout << "found!";
	}
	else {

		cout << "not found!";
	}

	cout << endl;
}

template <class T>
void printRemove(BinarySearchTree<T> bst, T rData) {

	cout << endl << "Removing " << rData << ": ";

	if (bst.remove(rData)) {

		cout << "removed!";
	}
	else {

		cout << "not removed!";
	}

	cout << endl;
}
#endif /*BINARYSEARCHTREEDEMO_H*/
