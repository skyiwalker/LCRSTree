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

template<typename T>
class Node {
private:
	T data;
	Node* child;
	Node* sibling;

public:
	Node(T data) {
		this->data = data;
		child = NULL;
		sibling = NULL;
	}

	~Node() {
		DeleteNode(child);
		DeleteNode(sibling);
	}

	void DeleteNode(Node* n) {
		if (n == NULL) return;
		delete n;
	}

	void SetData(T data) {
		this->data = data;
	}

	void SetChild(Node* child) {
		this->child = child;
	}

	void SetSibling(Node* sibling) {
		this->sibling = sibling;
	}

	T& GetData() {
		return data;
	}

	Node* GetChild() {
		return child;
	}

	Node* GetSibling() {
		return sibling;
	}

	Node* Next() {
		return sibling;
	}

};