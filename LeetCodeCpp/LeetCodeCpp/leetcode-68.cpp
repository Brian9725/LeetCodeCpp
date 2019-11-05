#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int len = words.size(), idx = 0, numWords = 0, numChars = 0, allBlank = 0, moreBlank = 0, lessBlank = 0, cntMoreBlank = 0;
		string tempRes = "", lessBlankStr = "";
		while (idx < len) {
			numWords = 0, numChars = 0;
			while (idx < len && numChars + numWords + words[idx].size() <= maxWidth) {
				numChars += words[idx].size();
				numWords++; idx++;
			}
			tempRes = ""; lessBlankStr = ""; allBlank = maxWidth - numChars;
			//如果是最后一行
			if (idx == len) {
				for (int i = idx - numWords; i < idx; i++) {
					tempRes += words[i];
					if (i == idx - 1)
						break;
					tempRes += " ";
				}
				for (int i = 0; i < maxWidth - numChars - numWords + 1; i++)
					tempRes += " ";
				result.push_back(tempRes);
				break;
			}
			//如果这一行只有一个单词
			if (numWords == 1) {
				tempRes += words[idx - 1];
				for (int i = 0; i < allBlank; i++)
					lessBlankStr += " ";
				tempRes += lessBlankStr;
				result.push_back(tempRes);
				continue;
			}
			lessBlank = allBlank / (numWords - 1);
			cntMoreBlank = allBlank % (numWords - 1);
			for (int i = 0; i < lessBlank; i++)
				lessBlankStr += " ";
			for (int i = idx - numWords; i < idx; i++) {
				tempRes += words[i];
				if (i == idx - 1)
					break;
				if (cntMoreBlank) {
					tempRes += " "; cntMoreBlank--;
				}
				tempRes += lessBlankStr;
			}
			result.push_back(tempRes);
		}
		return result;
	}
};