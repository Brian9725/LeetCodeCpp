#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		//resultNum��ʾ�Ѿ����ظ����������±�
		int resultNum = 0, tempNum = 1, numsSize = nums.size();
		//isSecond��ʾ��ǰ�����Ƿ��Ѿ���������
		bool isSecond = false;
		if (numsSize == 0)
			return 0;
		while (tempNum < numsSize) {
			//�����ǰ���ֺ�ǰһ����ȣ�������ж��Ƿ��Ѿ�����������
			if (nums[tempNum] == nums[tempNum - 1]) {
				if (!isSecond) {
					isSecond = true;
					nums[++resultNum] = nums[tempNum];
				}
			}
			else {
				isSecond = false;
				nums[++resultNum] = nums[tempNum];
			}
			tempNum++;
		}
		return resultNum + 1;
	}
};