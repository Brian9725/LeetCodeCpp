#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	static bool cmp(vector<int>&a, vector<int>&b) {
		if (a[0] == b[0])
			return a[1] > b[1];
		return a[0] < b[0];
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		int len = intervals.size();
		if (len < 2)
			return intervals;
		//��intervals�����������յ�ݼ�����VS2015�ᱨ��
		sort(intervals.begin(), intervals.end(), cmp);
		vector<vector<int>> result;
		vector<int> tempRes;
		//tempMΪ�ϲ�����յ�
		int i = 0, tempM = 0;
		while (i < len) {
			tempRes.clear();
			tempRes.push_back(intervals[i][0]);
			tempM = intervals[i][1];
			while (i < len) {
				//���tempMС�ڵ�i���������㣬��˵��֮��������޷���֮�ϲ�
				if (tempM < intervals[i][0])
					break;
				//���tempM�ڵ�i�����������յ�֮�䣬�����tempM��ֵ
				if (tempM < intervals[i][1])
					tempM = intervals[i][1];
				i++;
			}
			tempRes.push_back(tempM);
			result.push_back(tempRes);
		}
		return result;
	}
};