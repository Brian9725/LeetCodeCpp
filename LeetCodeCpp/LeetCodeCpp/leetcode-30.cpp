#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		if (words.empty())
			return result;
		int numWords = words.size(), lenWords = words[0].size(), lenW = numWords * lenWords, lenS = s.size();
		if (lenS == 0 || lenS < lenW || lenWords == 0)
			return result;
		map<string, int> wordsMap, tempMap;
		//统计每个单词出现的个数
		for (int i = 0; i < numWords; i++) {
			if (wordsMap.find(words[i]) != wordsMap.end())
				wordsMap[words[i]]++;
			else
				wordsMap[words[i]] = 1;
		}
		//判断s[start,start+lenW]是否符合要求
		for (int start = 0; start <= lenS - lenW; start++) {
			string tempS = s.substr(start, lenW);
			bool valid = true; tempMap.clear();
			for (int i = 0; i < numWords; i++) {
				string tempWord = tempS.substr(i*lenWords, lenWords);
				if (wordsMap.find(tempWord) == wordsMap.end()) {
					valid = false; break;
				}
				if (tempMap.find(tempWord) == tempMap.end())
					tempMap[tempWord] = 1;
				else {
					tempMap[tempWord]++;
					if (tempMap[tempWord] > wordsMap[tempWord]) {
						valid = false; break;
					}
				}
			}
			if (valid) {
				result.push_back(start);
			}
		}
		return result;
	}
};