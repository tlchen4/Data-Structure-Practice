#include <iostream>

struct TreeNode {
	TreeNode* left;
	int data;
	TreeNode* right;
};


TreeNode* CreateTreeNode(int data) {
	TreeNode* newNode = new TreeNode;

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;


	return newNode;
}

void TreeInsert(TreeNode** rootNode, int data) {
	// rootNode is pointer to pointer. dereferencing gives you the pointer to the root node. We do this so we can modify where root points to if necessary (vs just modifying what root already points to)
	//dereferencing pointer to pointer lets us edit the address the pointer points to
	if (*rootNode == NULL) {
		//case of empty tree
		*rootNode = CreateTreeNode(data);
	}

	else if (data <= (*rootNode)->data) {



	}


	return;
}

void BinaryTreeMain() {

	TreeNode* root_pointer;

	root_pointer = NULL;

	TreeInsert(&root_pointer, 15);



	return;
}