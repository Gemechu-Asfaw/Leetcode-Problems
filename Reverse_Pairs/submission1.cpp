class Solution {
private:
    void merge(vector<int>& nums, int start, int end, int mid){

        int left = start, right = mid+1, index = 0;
        int *temp = (int*)calloc(end-start+1, sizeof(int));

        while (left<=mid || right<=end){
            if (left<=mid && right<=end){
                if (nums[left] <= nums[right]){
                    temp[index] = nums[left];
                    left++;
                } else {
                    temp[index] = nums[right];
                    right++;
                }
            } else if (left<=mid){
                temp[index] = nums[left];
                left++;
            } else {
                temp[index] = nums[right];
                right++;
            }
            index++;
        }

        for (int i=0; i<index; i++){
            nums[i+start] = temp[i];
        }

        free(temp);
    }

    int solve(vector<int>& nums, int start, int end){

        if (start>=end){
            return 0;
        }

        int mid = start + (end-start)/2;
        int left = solve(nums, start, mid);
        int right = solve(nums, mid+1, end);

        int current = 0, i = mid, j = end;
        while (i>=start && j>mid){
            if (1.0*nums[i]/2 > 1.0*nums[j]){
                current = current + j - mid;
                i--;
            } else {
                j--;
            }
        }

        merge(nums, start, end, mid);
        return left + right + current;
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, n-1);
    }
};