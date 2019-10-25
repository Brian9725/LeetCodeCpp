#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int strsSize = strs.size();
		if (strsSize == 0) 
			return "";
		string result = "";
		for (int i = 0; i < strsSize; i++) {
			if (strs[i].size() == 0 || strs[i][0] != strs[0][0])
				return "";
		}
		result += strs[0][0];
		int len = strs[0].size();
		for (int i = 1; i <= len - 1; i++) {
			for (int j = 1; j < strsSize; j++)
				if (strs[j].size() == i || strs[j][i] != strs[0][i])
					return result;
			result += strs[0][i];
		}
		return result;
	}
};