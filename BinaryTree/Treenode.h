
#pragma once
#ifndef Treenode_h
#define Treenode_h
#endif // !Treenode_h
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	int countNodes();

};

class TraversalUtil
{
public:
	//TraversalUtil() {}
	static void PreOrderTraversal(TreeNode *root);
	static void PostOrderTraversal(TreeNode *root);
	static void InOrderTraversal(TreeNode *root);
	static void LevelOrderTraversal(TreeNode *root);
	static void preOrderIterative(TreeNode *root);
	static void postOrderIterative(TreeNode *root);
	static void InorderIterative(TreeNode *root);
};
