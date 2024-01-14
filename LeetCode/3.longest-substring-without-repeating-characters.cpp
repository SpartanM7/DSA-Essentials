/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string output;
        for(int i = 0; i < s.length() ; i++){
            if(output.find(s[i]) == std::string::npos){
                output.push_back(s[i]);
            }
            
        }
        cout << output.length() << endl;
        return 0;




    }
};
// @lc code=end

