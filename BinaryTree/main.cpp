#include "Treenode.h"


int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	cout << "PreOrder " << endl;
	TraversalUtil::PreOrderTraversal(root);
	cout << "PostOrder " << endl;
	TraversalUtil::PostOrderTraversal(root);
	cout << "InOrder " << endl;
	TraversalUtil::InOrderTraversal(root);
	cout << "levelOrder " << endl;
	TraversalUtil::LevelOrderTraversal(root);

	cout << "inOrderItr " << endl;
	TraversalUtil::InorderIterative(root);
}