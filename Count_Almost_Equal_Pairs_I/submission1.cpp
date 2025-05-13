class Solution {
public:
    bool isAlmostEqual(int x, int y){
        int diff = 0, count = 0;
        bool ans = false;
        while (x || y){
            if (x%10 != y%10){
                count++;
                if (count == 1) diff = x%10 + (y%10)*10;
                if (count == 2 && x%10==diff/10 && y%10==diff%10) ans = true;
            }
            x = x/10;
            y = y/10;
        }

        return count==0 || (count==2 && ans==true);
    }

    int countPairs(vector<int>& nums) {
        int n=nums.size(), ans = 0, x, y;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                x = nums[i];
                y = nums[j];
                if (isAlmostEqual(x, y)){
                    ans++;
                }
            }
        }

        return ans;
    }
};