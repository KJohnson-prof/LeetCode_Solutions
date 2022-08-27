//Link to original problem: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result;
        
        for(size_t i = 0; i < nums.size(); i++)
        {
            for(size_t j = i + 1; j < nums.size(); j++)
            {
                if(nums.at(i) + nums.at(j) == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        
        return result;
    }
};
