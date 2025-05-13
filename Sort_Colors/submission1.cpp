class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n=nums.size(), x = 0, y = 0, z = n-1;
        while (y<=z){

            while (y<z && nums[y]!=2){
                if (nums[y]==0){
                    swap(nums[x], nums[y]);
                    x++;
                }
                y++;
            }

            while (y<z && nums[z]==2){
                z--;
            }

            swap(nums[y], nums[z]);
            if (nums[y] == 0){
                swap(nums[x], nums[y]);
                x++;
            }
            y++;
            z--;
        }
    }
};