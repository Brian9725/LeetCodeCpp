#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	//��str���ո�ֳɵ���
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
			//ch��wd�ֱ��ʾcharMap��wordMap���Ƿ���ƥ���Ԫ��
			bool ch = (charMap.find(pattern[i]) != charMap.end());
			bool wd = (wordMap.find(words[i]) != wordMap.end());
			//���ֻ��һ���У�˵���ǵ���ƥ��
			if (ch != wd) return false;
			//�����������ƥ��Ԫ��
			if (!ch) {
				charMap[pattern[i]] = words[i];
				wordMap[words[i]] = pattern[i];
				continue;
			}
			//�������ƥ��Ԫ�أ��鿴�Ƿ�˫��ƥ��
			if (charMap[pattern[i]] != words[i] || wordMap[words[i]] != pattern[i])
				return false;
		}
		return true;
	}
};