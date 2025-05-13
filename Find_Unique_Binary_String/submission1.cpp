class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        string ans = "";
        bool isUsed = false;
        int n = nums.size();
        vector<int> track(n, 0);

        for (int i=0; i<n; i++){
            int count = 0, missing = n;
            for (int j=0; j<n; j++){
                if (nums[i][j] == '1'){
                    count++;
                    missing = j;
                }
            }

            if (count == 1){
                track[missing] = 1;
            }
        }

        for (int i=0; i<n; i++){
            if (track[i] == 0 && !isUsed){
                ans.push_back('1');
                isUsed = true;
            } else {
                ans.push_back('0');
            }
        }

        return ans;
    }
};