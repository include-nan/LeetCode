/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /**
         * 二分查找最重要的就是不对元素重复查找
         * 注意开闭区间
         */
        vector<int> ans;
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left >= nums.size() || nums[left] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(left);
        }

        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right >= nums.size() || nums[right] != target) {
            ans.push_back(-1);
        } else {
            ans.push_back(right);
        }

        return ans;
    }
};
// @lc code=end
