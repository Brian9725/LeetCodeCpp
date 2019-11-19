#include<iostream>
#include<string>
using namespace std;

struct mTreeNode {
	bool end;
	mTreeNode* child[26];
	mTreeNode() : end(false) {
		memset(child, 0, sizeof(child));
	}
};

class Trie {
public:
	mTreeNode *root = NULL;

	/** Initialize your data structure here. */
	Trie() {
		root = new mTreeNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		int len = word.size();
		mTreeNode *cur = root;
		for (int i = 0; i < len; i++) {
			if (cur->child[word[i] - 'a'] == NULL)
				cur->child[word[i] - 'a'] = new mTreeNode();
			cur = cur->child[word[i] - 'a'];
		}
		cur->end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		int len = word.size();
		mTreeNode *cur = root;
		for (int i = 0; i < len; i++) {
			if (cur->child[word[i] - 'a'] == NULL)
				return false;
			cur = cur->child[word[i] - 'a'];
		}
		return cur->end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		int len = prefix.size();
		mTreeNode *cur = root;
		for (int i = 0; i < len; i++) {
			if (cur->child[prefix[i] - 'a'] == NULL)
				return false;
			cur = cur->child[prefix[i] - 'a'];
		}
		return true;
	}
};


/*孩子兄弟法表示树
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

	//初始化前缀树
	Trie() {
		root = new mTreeNode('#');
	}

	//插入单词
	void insert(string word) {
		int len = word.size();
		mTreeNode *cur = root;
		for (int i = 0; i < len; i++) {
			if (cur->child == NULL) {
				cur->child = new mTreeNode(word[i]);
				cur = cur->child;
			}
			else if (cur->child->val == word[i]) {
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
				cur = cur->brother;
			}
		}
		cur->end = true;
	}

	//搜索单词
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

	//搜索前缀
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
*/