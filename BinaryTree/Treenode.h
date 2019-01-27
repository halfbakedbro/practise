
#pragma once
#ifndef Treenode_h
#define Treenode_h
#endif // !Treenode_h
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
private:
	int data;
	
public:
	TreeNode * left;
	TreeNode *right;
	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	friend class TraversalUtil;
	friend class OperationUtil;

};

class TraversalUtil
{
public:
	//Traversal
	static void PreOrderTraversal(TreeNode *root);
	static void PostOrderTraversal(TreeNode *root);
	static void InOrderTraversal(TreeNode *root);
	static void LevelOrderTraversal(TreeNode *root);
	static void LevelOrderSpiral(TreeNode *root);
	static void preOrderIterative(TreeNode *root);
	static void postOrderIterative(TreeNode *root);
	static void InorderIterative(TreeNode *root);

	static void VerticalTraverse(TreeNode *root);
	static void DiagnolTraverse(TreeNode *root);
	static void BoundaryTraverse(TreeNode *root);
	static void TraverseLeftnotLeaf(TreeNode *root);
	static void PrintLeafNodes(TreeNode *root);
	static void TraverseRightRevnotLeaf(TreeNode *root);

	static void LeftView(TreeNode *root);
	static void RightView(TreeNode *root);

};

class OperationUtil {
public:
	static void MirrorBinaryTree(TreeNode *root);
	static int NumberOfNodes(TreeNode *root);
	static int DepthOfBinaryTree(TreeNode *root);
	static int NumberOfLeafNodes(TreeNode *root, int &count);

};