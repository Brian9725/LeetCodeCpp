#include<iostream>
#include<string>
using namespace std;

//孩子兄弟法表示树
struct mTreeNode {
	char val;
	bool end;
	mTreeNode *child;
	mTreeNode *brother;
	mTreeNode(char x) : val(x), end(false), child(NULL), brother(NULL) {}
};

class Trie {
public:
	mTreeNode *root;

	/** Initialize your data structure here. */
	Trie() {
		root = new mTreeNode('#');
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (word == "ben") {
			int aaa = 1;
		}
		int len = word.size();
		mTreeNode *cur = root;
		for (int i = 0; i < len; i++) {
			if (cur->child == NULL) {
				mTreeNode *temp = new mTreeNode(word[i]);
				if (i == len - 1)
					temp->end = true;
				cur->child = temp;
				cur = cur->child;
			}
			else if (cur->child->val == word[i]) {
				if (i == len - 1)
					cur->child->end = true;
				cur = cur->child;
			}
			else {
				cur = cur->child;
				while (cur->brother != NULL && cur->brother->val != word[i]) {
					cur = cur->brother;
				}
				if (cur->brother == NULL) {
					mTreeNode *temp = new mTreeNode(word[i]);
					cur->brother = temp;
				}
				if (i == len - 1)
					cur->brother->end = true;
				cur = cur->brother;
			}
		}
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		int len = word.size();
		mTreeNode *cur = root->child;
		for (int i = 0; i < len; i++) {
			while (cur != NULL && cur->val != word[i]) {
				cur = cur->brother;
			}
			if (cur == NULL)
				return false;
			if (i == len - 1 && cur->end)
				return true;
			cur = cur->child;
		}
		return false;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		int len = prefix.size();
		mTreeNode *cur = root->child;
		for (int i = 0; i < len; i++) {
			while (cur != NULL && cur->val != prefix[i]) {
				cur = cur->brother;
			}
			if (cur == NULL)
				return false;
			cur = cur->child;
		}
		return true;
	}
};