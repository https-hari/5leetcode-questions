class Solution {
    public:
         int longestConsecutive(vector<int>& nums) {
            unordered_set<int> num_set(nums.begin(), nums.end());
            int longest = 0;
    
            for (int num : nums) {
                if (num_set.count(num - 1) == 0) { // Start of a sequence
                    int currentNum = num;
                    int count = 1;
                    
                    while (num_set.count(currentNum + 1)) {
                        num_set.erase(currentNum); // Remove to prevent future lookups
                        currentNum++;
                        count++;
                    }
                    
                    longest = max(longest, count);
                }
            }
            return longest;
        }
    };
