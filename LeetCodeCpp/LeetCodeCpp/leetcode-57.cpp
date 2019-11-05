#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		if (newInterval.size() == 0)
			return intervals;
		vector<vector<int>> result;
		if (intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		//startIdx��ʾ���һ���յ�С��newInterval[0]�������±꣬endIdx��ʾ��һ��������newInterval[1]�������±�
		int len = intervals.size(), low = 0, high = len - 1, startIdx = 0, endIdx = 0;
		//���ֲ���startIdx
		while (low <= high) {
			startIdx = low + (high - low) / 2;
			if (intervals[startIdx][1] < newInterval[0])
				low = startIdx + 1;
			else
				high = startIdx - 1;
		}
		if (intervals[startIdx][1] >= newInterval[0])
			startIdx--;
		//���ֲ���endIdx
		low = 0; high = len - 1;
		while (low <= high) {
			endIdx = low + (high - low) / 2;
			if (intervals[endIdx][0] > newInterval[1])
				high = endIdx - 1;
			else
				low = endIdx + 1;
		}
		if (intervals[endIdx][0] <= newInterval[1])
			endIdx++;
		//�������յ�С��newInterval[0]���������result
		for (int i = 0; i <= startIdx; i++)
			result.push_back(intervals[i]);
		//���м������ϲ�����
		vector<int> tempRes;
		if (startIdx < len - 1)
			tempRes.push_back(min(intervals[startIdx + 1][0], newInterval[0]));
		else
			tempRes.push_back(newInterval[0]);
		if (endIdx > 0)
			tempRes.push_back(max(intervals[endIdx - 1][1], newInterval[1]));
		else
			tempRes.push_back(newInterval[1]);
		result.push_back(tempRes);
		//������������newInterval[1]���������result
		for (int i = endIdx; i < len; i++)
			result.push_back(intervals[i]);
		return result;
	}
};