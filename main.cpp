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

#include "Tree.hpp"

int main()
{
	// Example is below.
	/*   Let's create below tree
	*           1
	     /   /    \    \
	    2  3      4     5
	              |   /  | \
	              6   7  8  9   */
	// Left child right sibling representation
	/*  1
	    |
	    2 -> 3 -> 4 -> 5
	              |    |
	              6    7 -> 8 -> 9  */

	int num_root = 1;
	Tree<int>* tree = new Tree<int>(num_root);		
	tree->Root()->AddChild(2);
	/**************** alternative usage for above **************/
	/*
	int num_root = 1;
	Tree<int>* tree = new Tree<int>();
	tree->SetRoot(num_root)->AddChild(2); 
	*/
	/***********************************************************/
	tree->Root()->AddChild(3);
	Node<int>* node4 = tree->Root()->AddChild(4)->GetThisNode();
	tree->Root()->AddChild(5)->AddChild(7)->AddSibling(8)->AddSibling(9);
	tree->AddChild(node4, 6);
	if (!tree->AddChild(node4, 6))
	{
		std::cout << "Cannot add child which has same value as that's sibling." << std::endl;
	}
	if (tree->FindChild(node4, 6))
	{
		std::cout << "Found value 6 at Node4." << std::endl;
	}
	if (tree->Root()->FindChild(4))
	{
		std::cout << "Found value 4 at Root Node" << std::endl;
	}
	if (tree->Root()->FindChild(6))
	{
		// Cannot enter here because children of root doesn't have value 6
		std::cout << "Found value 6 at Root Node" << std::endl;
	}
	std::cout << tree->Root()->GetNumChildren() << std::endl;

	tree->traverseTree(tree->GetRoot());
	
	delete tree;
	return 0;
}