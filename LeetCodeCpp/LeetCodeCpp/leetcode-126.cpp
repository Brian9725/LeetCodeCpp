#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//wordMap存放了每个通用状态对应的单词，如h*t->hit，hot
	map<string, vector<string>> wordMap;

	int visitNode(queue<pair<string, int>>& q, map<string, int>& visit, map<string, int>& othervisit) {
		pair<string, int> node = q.front(); q.pop();
		string word = node.first;
		int lv = node.second, len = word.size();
		for (int i = 0; i < len; ++i) {
			string temp = word.substr(0, i) + "*" + word.substr(i + 1);
			if (wordMap.find(temp) == wordMap.end()) continue;
			vector<string> tempList = wordMap[temp];
			int lenList = tempList.size();
			for (int j = 0; j < lenList; ++j) {
				//如果当前单词已经从另一头被访问，说明已找到匹配路线
				if (othervisit.find(tempList[j]) != othervisit.end())
					return lv + othervisit[tempList[j]];
				//如果当前单词已经从本边被访问，说明是一个环路
				if (visit.find(tempList[j]) == visit.end()) {
					q.push(make_pair(tempList[j], lv + 1));
					visit[tempList[j]] = lv + 1;
				}
			}
		}
		return -1;
	}

	//先求出最小的转换序列长度
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
			return 0;
		int len = wordList.size(), lenW = wordList[0].size(), res = 0;
		//初始化wordMap
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < lenW; ++j) {
				string temp = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1);
				vector<string> tempList;
				if (wordMap.find(temp) != wordMap.end())
					tempList = wordMap[temp];
				tempList.push_back(wordList[i]);
				wordMap[temp] = tempList;
			}
		}
		queue<pair<string, int>> beginQ, endQ;
		beginQ.push(make_pair(beginWord, 1));
		endQ.push(make_pair(endWord, 1));
		map<string, int> visitB, visitE;
		visitB[beginWord] = 1; visitE[endWord] = 1;
		//从两端向中间BDS
		while (!beginQ.empty() && !endQ.empty()) {
			res = visitNode(beginQ, visitB, visitE);
			if (res > -1) return res;
			res = visitNode(endQ, visitE, visitB);
			if (res > -1) return res;
		}
		return 0;
	}

	void dfs(vector<vector<string>>& res, vector<string>& tempRes, map<string, int>& visit, map<string, int>& firstV, 
		string beginWord, string endWord, vector<string>& wordList, int cur, int minLen) {
		if (cur == minLen) {
			if (tempRes[cur - 1] == endWord)
				res.push_back(tempRes);
			return;
		}
		string word = tempRes[cur - 1];
		for (int i = 0; i < (int)word.size(); ++i) {
			string temp = word.substr(0, i) + "*" + word.substr(i + 1);
			if (wordMap.find(temp) == wordMap.end()) continue;
			vector<string> tempList = wordMap[temp];
			for (int j = 0; j < (int)tempList.size(); ++j) {
				//firstV中不会存第minLen层的字符串，因为这一层只有endWord才有效
				if (cur + 1 == minLen && tempList[j] == endWord) {
					tempRes.push_back(tempList[j]);
					res.push_back(tempRes);
					tempRes.pop_back();
					break;
				}
				//如果tempList[j]已经被访问过或者第一次能访问到tempList[j]的层数比当前要低
				if (visit.find(tempList[j]) != visit.end() || firstV[tempList[j]] < cur + 1) continue;
				tempRes.push_back(tempList[j]); visit[tempList[j]] = 1;
				dfs(res, tempRes, visit, firstV, beginWord, endWord, wordList, cur + 1, minLen);
				tempRes.pop_back(); visit.erase(tempList[j]);
			}
		}
	}

	//first中存储第一次能访问到该单词需要几步
	void buildFirst(map<string, int>& firstV, queue<pair<string, int>>& q, vector<string>& wordList, int minLen) {
		while (!q.empty()) {
			pair<string, int> node = q.front(); q.pop();
			string word = node.first;
			int lv = node.second, len = word.size();
			if (lv + 1 == minLen) break;
			for (int i = 0; i < len; ++i) {
				string temp = word.substr(0, i) + "*" + word.substr(i + 1);
				if (wordMap.find(temp) == wordMap.end()) continue;
				vector<string> tempList = wordMap[temp];
				int lenList = tempList.size();
				for (int j = 0; j < lenList; ++j) {
					if (firstV.find(tempList[j]) == firstV.end()) {
						firstV[tempList[j]] = lv + 1;
						q.push(make_pair(tempList[j], lv + 1));
					}
				}
			}
		}
	}

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> res;
		int minLen = ladderLength(beginWord, endWord, wordList);
		if (minLen == 0) return res;
		vector<string> tempRes;
		tempRes.push_back(beginWord);
		map<string, int> visit, firstV;
		visit[beginWord] = 1; firstV[beginWord] = 1;
		queue<pair<string, int>> q;
		q.push(make_pair(beginWord, 1));
		buildFirst(firstV, q, wordList, minLen);
		dfs(res, tempRes, visit, firstV, beginWord, endWord, wordList, 1, minLen);
		return res;
	}
};