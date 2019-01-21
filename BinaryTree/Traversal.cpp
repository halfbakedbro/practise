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

void TraversalUtil::LeftView(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else {
		queue <TreeNode *> qt;
		qt.push(root);

		while (!qt.empty()) {
			int count = qt.size();
			int queueCount = qt.size();

			while (count > 0) {
				TreeNode *temp = qt.front();
				qt.pop();

				if (count == queueCount) {
					cout << temp->data << ",";
				}

				if (temp->left != NULL)
					qt.push(temp->left);

				if (temp->right != NULL)
					qt.push(temp->right);

				count--;
			}
		}
		
	}
}

void TraversalUtil::RightView(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else {
		queue <TreeNode *> qt;
		qt.push(root);

		while (!qt.empty()) {
			int count = qt.size();
			int queueCount = qt.size();

			while (count > 0) {
				TreeNode *temp = qt.front();
				qt.pop();

				if (count == 1) {
					cout << temp->data << ",";
				}

				if (temp->left)
					qt.push(temp->left);

				if (temp->right)
					qt.push(temp->right);

				count--;
			}
		}
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

void TraversalUtil::TraverseLeftnotLeaf(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else if(root->left == NULL && root->right == NULL) {
		return;
	}
	else {
		cout << root->data << ",";
		TraverseLeftnotLeaf(root->left);
	}
}

void TraversalUtil::PrintLeafNodes(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else if (root->left == NULL && root->right == NULL) {
		cout << root->data << ",";
	}
	else {
		PrintLeafNodes(root->left);
		PrintLeafNodes(root->right);
	}
}

void TraversalUtil::TraverseRightRevnotLeaf(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else if (root->left == NULL && root->right == NULL) {
		return;
	}
	else {
		TraverseRightRevnotLeaf(root->right);
		cout << root->data << ",";
	}
}

void TraversalUtil::BoundaryTraverse(TreeNode *root) {
	cout << endl;
	TraverseLeftnotLeaf(root);
	PrintLeafNodes(root);
	TraverseRightRevnotLeaf(root->right);
}

void TraversalUtil::DiagnolTraverse(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else {
		multimap <int, TreeNode*> maps;
		queue <TreeNode *> que;
		//que.push()
	}
}

void TraversalUtil::VerticalTraverse(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else {
		map<int, vector<int>> hash;

		int hd = 0;
		queue<pair<TreeNode*, int>>queue;
		queue.push(make_pair(root, hd));

		while (!queue.empty()) {
			pair<TreeNode*, int> pr = queue.front();
			queue.pop();
			hd = pr.second;
			root = pr.first;

			hash[hd].push_back(root->data);

			if (root->left != NULL)
				queue.push(make_pair(root->left, hd - 1));
			if (root->right != NULL)
				queue.push(make_pair(root->right, hd + 1));
		}

		map < int, vector<int>> ::iterator itr;
		for (itr = hash.begin(); itr != hash.end(); itr++) {
			for (int i = 0; i < itr->second.size(); i++)
				cout << itr->second[i] << " ";
			cout << endl;
		}
	}
}

void OperationUtil::MirrorBinaryTree(TreeNode *root) {
	if (root == NULL) {
		return;
	}
	else {
		MirrorBinaryTree(root->left);
		MirrorBinaryTree(root->right);
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int OperationUtil::DepthOfBinaryTree(TreeNode *root) {
	if (root == NULL)
		return 0;

	int lheight = DepthOfBinaryTree(root->left);
	int rheight = DepthOfBinaryTree(root->right);

	if (lheight > rheight)
		return lheight + 1;
	else
		return rheight + 1;
}

int OperationUtil::NumberOfNodes(TreeNode *root) {
	if (root == NULL)
		return 0;

	return (1 + NumberOfNodes(root->left) + NumberOfNodes(root->right));
}

int OperationUtil::NumberOfLeafNodes(TreeNode *root, int &count) {
	if (root == NULL) {
		return 0;
	}
	else if(root->left == NULL && root->right == NULL){
		count++;
	}
	else {
		NumberOfLeafNodes(root->left, count);
		NumberOfLeafNodes(root->right, count);
	}
}