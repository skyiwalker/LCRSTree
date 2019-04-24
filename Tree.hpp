/*
MIT License

Copyright (c) [2019] [Seokkeun Yi] (Github: skyiwalker)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <iostream>
#include "Node.hpp"

template<typename T>
class Tree {
private:
	Node<T>* root;
	Node<T>* pn; // Working Node
public:
	Tree() {
		root = NULL;
		pn = NULL;
	}

	Tree(T data) {
		root = new Node<T>(data);
		pn = root;
	}

	~Tree() {
		delete root;
	}

	Tree *SetRoot(T data) {
		// If root exists, delete tree
		if(root) delete root;
		root = new Node<T>(data);
		pn = root; // Point root node
		return this;
	}

	Tree *Root() {
		pn = root;
		return this;
	}

	Node<T> *GetRoot() {
		return root;
	}

	bool IsRoot() {
		if (pn == root) return true;
		else return false;
	}

	bool IsRoot(Node<T> *node) {
		if (node == root) return true;
		else return false;
	}

	Tree *Child() {
		if (pn->GetChild()) {
			pn = pn->GetChild(); // Point this node
			return this;
		}
		else {
			return NULL;
		}
	}

	Node<T> *GetChild() {
		if (pn->GetChild()) {
			return pn->GetChild(); // Point this node
		}
		else {
			return NULL;
		}
	}

	Node<T> *GetThisNode() {
		return pn;
	}

	void NodeChangeData(T data) {
		pn->SetData(data);
	}

	Tree *AddChild(T data) {
		if (FindChild(data) == NULL) { // Cannot add a value same as sibling
			Node<T>* tmp;
			tmp = pn->GetChild();
			if (tmp == NULL) { // If this node doesn't have a child
				pn->SetChild(new Node<T>(data));
				pn = pn->GetChild(); // Point this node
				return this;
			}
			while (true) { // If this node has a child
				if (tmp->GetSibling() == NULL) { // If this Node is end of siblings
					tmp->SetSibling(new Node<T>(data));
					pn = tmp->GetSibling(); // Point this node
					return this;
				}
				tmp = tmp->GetSibling(); // Move to Next Sibling
			}
		}
		return NULL; // Failed to add child
	}

	Tree *AddChild(Node<T> *node, T data) {
		if (FindChild(node, data) == NULL) {
			Node<T>* tmp;
			tmp = node->GetChild();
			if (tmp == NULL) { // If this node doesn't have a child
				node->SetChild(new Node<T>(data));
				pn = node->GetChild(); // Point this node
				return this;
			}
			while (true) { // If this node has a child
				if (tmp->GetSibling() == NULL) { // If this Node is end of siblings
					tmp->SetSibling(new Node<T>(data));
					pn = tmp->GetSibling(); // Point this node
					return this;
				}
				tmp = tmp->GetSibling(); // Move to Next Sibling
			}
		}
		return NULL; // Failed to add child
	}

	Tree *AddSibling(T data) {
		while (true) {
			if (pn->GetSibling() == NULL) { // If this Node is end of siblings
				pn->SetSibling(new Node<T>(data));
				pn = pn->GetSibling(); // Point this node
				return this;
			}
			pn = pn->GetSibling(); // Move to Next Sibling
		}
	}

	Node<T>* FindChild(T data) {
		Node<T>* tmp;
		tmp = pn->GetChild();
		if (tmp == NULL) { // If this node doesn't have a child			
			return NULL;
		}
		while (true) { // If this node has a child		
			if (tmp->GetData() == data) {
				pn = tmp; // Point this node
				return tmp;
			}
			else if (tmp->GetSibling() == NULL) { // If this Node is end of siblings(Matches Not Found)
				return NULL;
			}
			tmp = tmp->GetSibling(); // Move to Next Sibling
		}
	}

	Node<T>* FindChild(Node<T> *node, T data) {
		Node<T>* tmp;
		tmp = node->GetChild();
		if (tmp == NULL) { // If this node doesn't have a child			
			return NULL;
		}
		while (true) { // If this node has a child		
			if (tmp->GetData() == data) {
				pn = tmp; // Point this node
				return tmp;
			}
			else if (tmp->GetSibling() == NULL) { // If this Node is end of siblings(Matches Not Found)
				return NULL;
			}
			tmp = tmp->GetSibling(); // Move to Next Sibling
		}
	}

	int GetNumChildren(Node<T> *node) {
		int count = 0;
		Node<T>* tmp;
		tmp = node->GetChild();
		if (tmp == NULL) { // If this node doesn't have a child			
			return 0;
		}
		while (true) { // If this node has a child
			count++;
			if (tmp->GetSibling() == NULL) { // If this Node is end of siblings(Matches Not Found)
				return count;
			}
			tmp = tmp->GetSibling(); // Move to Next Sibling
		}
	}

	int GetNumChildren() {
		int count = 0;
		Node<T>* tmp;
		tmp = pn->GetChild();
		if (tmp == NULL) { // If this node doesn't have a child			
			return 0;
		}
		while (true) { // If this node has a child
			count++;
			if (tmp->GetSibling() == NULL) { // If this Node is end of siblings(Matches Not Found)
				return count;
			}
			tmp = tmp->GetSibling(); // Move to Next Sibling
		}
	}

	void RemoveChild(Node<T> *node) {
		delete node;
	}

	void traverseTree(Node<T> *rootNode)
	{
		if (rootNode == NULL)
			return;

		while (rootNode)
		{
			std::cout << " " << rootNode->GetData();
			if (rootNode->GetChild())
				traverseTree(rootNode->GetChild());
			rootNode = rootNode->Next();
		}
	}

	void SetPN(Node<T>* n) {
		pn = n;
	}

};