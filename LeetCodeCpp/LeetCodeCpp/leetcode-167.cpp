#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size(), head = 0, tail = len - 1;
		vector<int> result;
		for (int i = 0; i < len - 1; i++) {
			if (numbers[head] + numbers[tail] == target) {
				result.push_back(head + 1);
				result.push_back(tail + 1);
				break;
			}
			else if (numbers[head] + numbers[tail] > target)
				tail--;
			else
				head++;
		}
		return result;
	}

	/*
	vector<int> twoSum(vector<int>& numbers, int target) {
		int len = numbers.size();
		vector<int> result;
		for (int i = 0; i < len - 1; i++) {
			int low = i + 1, high = len - 1, mid = 0;
			int temp = target - numbers[i];
			//在numbers[i+1..len-1]中二分查找temp
			while (low <= high) {
				mid = low + (high - low) / 2;
				if (numbers[mid] == temp) {
					result.push_back(i + 1);
					result.push_back(mid + 1);
					break;
				}
				else if (numbers[mid] > temp)
					high = mid - 1;
				else
					low = mid + 1;
			}
		}
		return result;
	}
	*/
};