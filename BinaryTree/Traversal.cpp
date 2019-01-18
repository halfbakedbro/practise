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

	stack <TreeNode *> st;
	do {

		while (root) {
			if (root->right)
				st.push(root->right);
			st.push(root);

			root = root->left;
		}

		root = st.top();
		st.pop();

		if (root->right && !st.empty() && st.top() == root->right) {
			st.pop();
			st.push(root);
			root = root->right;
		}
		else {
			cout << root->data << " ";
			root = NULL;
		}

	} while (!st.empty());

}

void TraversalUtil::preOrderIterative(TreeNode *root) {
	if (root == NULL)
		return;
	stack <TreeNode *> st;

	while (!st.empty() || root != NULL) {
		while (root != NULL) {
			cout << root->data << " ";
			st.push(root);
			root = root->left;
		}

		root = st.top();
		st.pop();
		root = root->right;
	}
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