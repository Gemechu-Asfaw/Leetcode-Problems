class Solution {
public:
    int solve(vector<int> cost, int size, int index, unordered_map<int,int> &mapping){

        if (index+1==size || index+2==size){
            return cost[index];
        }
        else if (mapping.find(index)!=mapping.end()){
            return mapping[index];
        }

        int oneStep = solve(cost, size, index+1, mapping);
        int twoStep = solve(cost, size, index+2, mapping);
        int ans = cost[index] + min(oneStep,twoStep);
        mapping[index] = ans;
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {

        unordered_map<int,int> mapping;
        int size=cost.size();

        int left = solve(cost,size,0,mapping);
        int right = solve(cost,size,1,mapping);
        return min(left,right);
    }
};