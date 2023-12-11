// optimisation is required
// 1. two hashmap method
// 2. one hashmap method

/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> output;
        for (int i = 0; i < nums.size() ; i++)
        {
            for (int j  = i+1; j < nums.size(); j++)
            {
                if((nums[i] + nums[j]) == target){
                    output.push_back(i);
                    output.push_back(j);
                }
            }


            
        }
        return output;
        


    }
};
// @lc code=end

