# LCRSTree(Left Children Right Sibling Tree)

Left-Children Right-Sibling(LCRS) Representation of Tree
(MIT License)

Example in the code

![LCRS Tree](./img/LCRSTree.png)

**features**
* Sibling cannot have same value

**usage(example)**

~~~
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
~~~



made by skyiwalker
