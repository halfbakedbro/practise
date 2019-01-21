#include "Treenode.h"


int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	
	root->right->right = new TreeNode(7);
	root->right->right->right = new TreeNode(8);
	root->left->right->right = new TreeNode(6);

	//cout << "Number of Nodes :" << OperationUtil::NumberOfNodes(root) << endl;
	//cout << "Depth of the tree:" << OperationUtil::DepthOfBinaryTree(root) << endl;
	int count = 0;
	//OperationUtil::NumberOfLeafNodes(root, count);
	//cout << "Number of leaf Nodes:" << count << endl;

	/*cout << "PreOrder " << endl;
	TraversalUtil::PreOrderTraversal(root);
	cout << "PostOrder " << endl;
	TraversalUtil::PostOrderTraversal(root);*/
	//cout << "InOrder " << endl;
	//TraversalUtil::InOrderTraversal(root);
	/*cout << "levelOrder " << endl;
	TraversalUtil::LevelOrderTraversal(root);
	cout << "inOrderItr " << endl;
	TraversalUtil::InorderIterative(root);

	cout << "preOrderItr" << endl;
	TraversalUtil::preOrderIterative(root);

	cout << "\nPostOrderIt" << endl;
	TraversalUtil::postOrderIterative(root);*/
	//TraversalUtil::MirrorBinaryTree(root);
	cout << endl;
	//TraversalUtil::BoundaryTraverse(root);
	//TraversalUtil::LeftView(root);
	TraversalUtil::VerticalTraverse(root);
	cout << endl;
	//TraversalUtil::RightView(root);
	//TraversalUtil::InOrderTraversal(root);
}