// Link to problem: https://leetcode.com/problems/distribute-candies-to-people
//Time took to solve: 33:22

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people, 0);
        size_t index = 0;
        int turn = 1;
        
        while(candies > 0)
        {
            if(index >= result.size())
                index = 0;
            
            if(candies <= turn)
            {
                result.at(index) = result.at(index) + candies;
                candies = 0;
            }
            else
            {
                result.at(index) = result.at(index) + turn;
                candies = candies - turn;
            }
            turn++;
            index++;
        }
        
        return result;
    }
};
