
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /*
    ���� ū ������ ���� ���� ������ �� 
    1 2 3 5 4 -> 3 ���� 5�� ��
    1 2 4 3 5 -> 3 �������� ū ���� ��
    
    1 3 5 1 1 -> 1 5 1 1 3
    1 2 7 5 2 -> 1 5 2 2 7
    */
    void nextPermutation(vector<int>& nums) {
        int maxNum = 0, length = nums.size() - 1;
        for (int i = length; i >= 0; --i) {
            if (nums[i] >= maxNum) {
                maxNum = nums[i];
            }
            else {
                int index;
                for (int j = length; j > i; --j) {
                    if (nums[i] < nums[j]) {
                        index = j;
                        break;
                    }
                }
                int temp = nums[index];
                nums[index] = nums[i];
                nums[i] = temp;
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> d = { 1, 5, 1 }; 
    Solution* s = new Solution();
    s->nextPermutation(d);
    delete s;
}