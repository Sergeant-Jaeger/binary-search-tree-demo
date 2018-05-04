/*
Author: Aaron Jaeger
*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "BinaryTree.h"

template <class T>
class BinarySearchTree : public BinaryTree<T> {

	void insert(Node<T>* &node, T nData) {

		if (node == nullptr) {

			node = new Node<T>(nData);
		}
		else {
			
			if (node->data > nData) {

				insert(node->childLeft, nData);
			}	
			else {

				insert(node->childRight, nData);
			}	
		}
	}

	bool search(Node<T>* &node, T sData) {

		bool searchBool;

		if (node != nullptr) {
			
			if (node->data == sData) {

				searchBool = true;
			}
			else if (node->data > sData) {

				searchBool = search(node->childLeft, sData);
			}
			else {

				searchBool = search(node->childRight, sData);
			}
		}
		else {

			searchBool = false;
		}
		
		return searchBool;
	}

	bool remove(Node<T>* &node, T rData) {

		bool removeBool;

		if (node == nullptr) {

			removeBool = false;
		}
		else if (node->data > rData) {
			
			removeBool = remove(node->childLeft, rData);
		}
		else if (node->data < rData) {
			
			removeBool = remove(node->childRight, rData);
		}
		else if (node->childLeft != nullptr && node->childRight != nullptr) {
			
			Node<T> *pred = node->childLeft;

			while (pred->childRight != nullptr) {

				pred = pred->childRight;
			}

			node->data = pred->data;

			removeBool = remove(node->childLeft, pred->data);
		}
		else if (node->childLeft == nullptr && node->childRight == nullptr) {
			
			delete node;

			node = nullptr;

			removeBool = true;
		}
		else {

			Node<T>* temp = node;

			if (node->childLeft != nullptr) {

				node = node->childLeft;
			}	
			else {

				node = node->childRight;
			}
				
			delete temp;

			removeBool = true;
		}

		return removeBool;
	}

public:
	
	BinarySearchTree<T>() : BinaryTree<T>() {

	}

	void insert(T nData) {

		insert(BinaryTree<T>::root, nData);
	}

	bool search(T sData) {

		return search(BinaryTree<T>::root, sData);
	}

	bool remove(T rData) {

		return remove(BinaryTree<T>::root, rData);
	}
};
#endif /*BINARYSEARCHTREE_H*/
