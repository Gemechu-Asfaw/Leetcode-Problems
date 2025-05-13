class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size(), maximum = INT_MIN, current_frequency = 0;
        unordered_map<int,int> frequency;

        // Storing the frequency of a number in frequency map
        for (int i=0; i<n; i++){
            frequency[nums[i]]++;
        }

        // Traversing the frequency map to get element with highest frequency
        for (auto pair:frequency){
            if (pair.second == maximum){
                current_frequency += pair.second;
            } else if (pair.second > maximum){
                maximum = pair.second;
                current_frequency = pair.second;
            }
        }

        return current_frequency;
    }
};