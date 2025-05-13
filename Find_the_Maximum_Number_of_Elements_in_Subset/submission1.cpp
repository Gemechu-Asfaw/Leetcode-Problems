class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int ans = 1;
        unordered_map<long,int> mapping;
        
        for (int i=0; i<nums.size(); i++){
            mapping[long(nums[i])]++;
        }
        
        for (auto i:mapping){
            
            int tempAns = 0;
            long tempNo = i.first;
            
            if (tempNo == 1){
                if (mapping[tempNo]%2==0){
                    ans = max(ans, mapping[tempNo]-1);
                } else{
                    ans = max(ans, mapping[tempNo]);
                }
            }
            else{
                while (mapping[tempNo]>=2 && mapping.find(tempNo*tempNo)!=mapping.end()){
                    tempAns = tempAns + 2;
                    tempNo = tempNo*tempNo;
                }
                ans = max(ans, tempAns+1);
            }
        }
        
        return ans;
    }
};