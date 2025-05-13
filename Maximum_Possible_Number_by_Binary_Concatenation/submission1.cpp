class Solution {
public:
    int getBinary(int num){
        int length = 0;
        while (num){
            num = num/2;
            length++;
        }
        return length;
    }

    int evaluate(vector<int> nums, vector<int> binary, vector<int> order){
        int digit1 = order[2], digit2 = order[1], digit3 = order[0];
        return nums[digit1] + (nums[digit2]<<(binary[digit1])) + (nums[digit3]<<(binary[digit1]+binary[digit2]));
    }

    int maxGoodNumber(vector<int>& nums) {
        int num, ans = 0;
        vector<int> binary(3);
        vector<int> order = {0,1,2};

        for (int i=0; i<3; i++){
            num = nums[i];
            binary[i] = getBinary(num);
        }

        for (int i=0; i<6; i++){
            ans = max(ans, evaluate(nums, binary, order));
            next_permutation(order.begin(), order.end());
        }

        return ans;
    }
};