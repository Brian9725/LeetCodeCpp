#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		int len = strs.size();
		//将每个string与其字典序建立映射
		map<string, vector<string>> strMap;
		vector<vector<string>> result;
		for (int i = 0; i < len; i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			strMap[temp].push_back(strs[i]);
		}
		for (map<string, vector<string>>::iterator it = strMap.begin(); it != strMap.end(); it++)
			result.push_back(it->second);
		return result;
	}
};