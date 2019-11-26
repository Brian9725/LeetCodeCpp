#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<queue>
#include<vector>
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
			if (wordMap.find(temp) == wordMap.end())
				continue;
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
};