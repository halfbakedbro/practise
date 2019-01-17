#include "Treenode.h"


void TraversalUtil::PreOrderTraversal(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		else {
			cout << root->data << endl;
			PreOrderTraversal(root->left);
			PreOrderTraversal(root->right);
		}
}

void TraversalUtil::PostOrderTraversal(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		else {
			PostOrderTraversal(root->left);
			PostOrderTraversal(root->right);
			cout << root->data << endl;
		}
}

void TraversalUtil::InOrderTraversal(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		else {
			InOrderTraversal(root->left);
			cout << root->data << endl;
			InOrderTraversal(root->right);
		}
}

void TraversalUtil::LevelOrderTraversal(TreeNode *root) {
	queue <TreeNode *> level;

	if (root == NULL)
		return;
	
	level.push(root);
	
	while (!level.empty()) {
		int count = level.size();

		while (count > 0) {
			TreeNode *temp = level.front();
			level.pop();

			cout << temp->data << endl;
			if (temp->right != NULL)
				level.push(temp->right);

			if (temp->left != NULL)
				level.push(temp->left);
			count--;
		}

		cout << endl;
		
	}
}

void TraversalUtil::postOrderIterative(TreeNode *root) {
	if (root == NULL)
		return;


	
}

void TraversalUtil::preOrderIterative(TreeNode *root) {

}

void TraversalUtil::InorderIterative(TreeNode *root) {
	if (root == NULL)
		return;

	stack <TreeNode*> stac;
	//stac.push(root);

	while (!stac.empty() || root != NULL) {

		while (root != NULL) {
			stac.push(root);
			root = root->left;
		}

		root = stac.top();
		stac.pop();

		cout << root->data << endl;
		
		root = root->right;
	}
}