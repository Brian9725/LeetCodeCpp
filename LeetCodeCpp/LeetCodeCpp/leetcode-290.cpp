#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	//将str按空格分成单词
	vector<string> convert(string str) {
		vector<string> res;
		int len = str.size(), begin = 0, end = begin;
		while (begin < len) {
			while (end + 1 < len && str[end + 1] != ' ') {
				end++;
			}
			res.push_back(str.substr(begin, end - begin + 1));
			begin = end + 2; end = begin;
		}
		return res;
	}

	bool wordPattern(string pattern, string str) {
		vector<string> words = convert(str);
		map<char, string> charMap;
		map<string, char> wordMap;
		int len = pattern.size(), lenW = words.size();
		if (len != lenW) return false;
		for (int i = 0; i < len; ++i) {
			//ch和wd分别表示charMap和wordMap中是否有匹配的元素
			bool ch = (charMap.find(pattern[i]) != charMap.end());
			bool wd = (wordMap.find(words[i]) != wordMap.end());
			//如果只有一方有，说明是单向匹配
			if (ch != wd) return false;
			//如果都不存在匹配元素
			if (!ch) {
				charMap[pattern[i]] = words[i];
				wordMap[words[i]] = pattern[i];
				continue;
			}
			//如果存在匹配元素，查看是否双向匹配
			if (charMap[pattern[i]] != words[i] || wordMap[words[i]] != pattern[i])
				return false;
		}
		return true;
	}
};