#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	//wordMap�����ÿ��ͨ��״̬��Ӧ�ĵ��ʣ���h*t->hit��hot
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
				//�����ǰ�����Ѿ�����һͷ�����ʣ�˵�����ҵ�ƥ��·��
				if (othervisit.find(tempList[j]) != othervisit.end())
					return lv + othervisit[tempList[j]];
				//�����ǰ�����Ѿ��ӱ��߱����ʣ�˵����һ����·
				if (visit.find(tempList[j]) == visit.end()) {
					q.push(make_pair(tempList[j], lv + 1));
					visit[tempList[j]] = lv + 1;
				}
			}
		}
		return -1;
	}

	//�������С��ת�����г���
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
			return 0;
		int len = wordList.size(), lenW = wordList[0].size(), res = 0;
		//��ʼ��wordMap
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
		//���������м�BDS
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
				//firstV�в�����minLen����ַ�������Ϊ��һ��ֻ��endWord����Ч
				if (cur + 1 == minLen && tempList[j] == endWord) {
					tempRes.push_back(tempList[j]);
					res.push_back(tempRes);
					tempRes.pop_back();
					break;
				}
				//���tempList[j]�Ѿ������ʹ����ߵ�һ���ܷ��ʵ�tempList[j]�Ĳ����ȵ�ǰҪ��
				if (visit.find(tempList[j]) != visit.end() || firstV[tempList[j]] < cur + 1) continue;
				tempRes.push_back(tempList[j]); visit[tempList[j]] = 1;
				dfs(res, tempRes, visit, firstV, beginWord, endWord, wordList, cur + 1, minLen);
				tempRes.pop_back(); visit.erase(tempList[j]);
			}
		}
	}

	//first�д洢��һ���ܷ��ʵ��õ�����Ҫ����
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