#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
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

class Solution {
public:
	vector<string> result;
	Trie *root;
	vector<vector<int>> visit;
	map<string, int> wordMap;

	//参见leetcode-79
	void dfs(vector<vector<char>>& board, string word, int row, int col) {
		//如果在字典中没有以word开头的单词
		if (!root->startsWith(word)) 
			return;
		//如果字典中存在word并且还没有加入result
		if (root->search(word) && wordMap[word] == 1) {
			wordMap[word] = 0;
			result.push_back(word);
		}
		//检查当前位置上方一个字符
		if (row > 0 && visit[row - 1][col] == 0) {
			visit[row - 1][col] = 1;
			dfs(board,word + board[row - 1][col], row - 1, col);
			visit[row - 1][col] = 0;
		}
		//检查当前位置下方一个字符
		if (row < (int)board.size() - 1 && visit[row + 1][col] == 0) {
			visit[row + 1][col] = 1;
			dfs(board, word + board[row + 1][col], row + 1, col);
			visit[row + 1][col] = 0;
		}
		//检查当前位置左方一个字符
		if (col > 0 && visit[row][col - 1] == 0) {
			visit[row][col - 1] = 1;
			dfs(board, word + board[row][col - 1], row, col - 1);
			visit[row][col - 1] = 0;
		}
		//检查当前位置右方一个字符
		if (col < (int)board[0].size() - 1 && visit[row][col + 1] == 0) {
			visit[row][col + 1] = 1;
			dfs(board, word + board[row][col + 1], row, col + 1);
			visit[row][col + 1] = 0;
		}
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int rLen = board.size();
		if (rLen == 0) return result;
		int cLen = board[0].size();
		if (cLen == 0) return result;
		visit = vector<vector<int>>(rLen, vector<int>(cLen, 0));
		int len = words.size();
		//创建words的字典树，参考leetcode-208
		root = new Trie();
		for (int i = 0; i < len; i++) {
			root->insert(words[i]);
			if (wordMap.find(words[i]) == wordMap.end()) 
				wordMap[words[i]] = 1;
		}
		for (int i = 0; i < rLen; i++) {
			for (int j = 0; j < cLen; j++) {
				if (i == 1 && j == 3) {
					int aa = 1;
				}
				string word = "#"; word[0] = board[i][j];
				visit[i][j] = 1;
				dfs(board, word, i, j);
				visit[i][j] = 0;
			}
		}
		return result;
	}
};