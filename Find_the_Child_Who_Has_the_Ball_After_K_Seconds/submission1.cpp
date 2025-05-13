class Solution {
public:
    int numberOfChild(int n, int k) {
        int turns = k/(n-1);
        k = k%(n-1);
        return turns%2==0 ? k : n-1-k;
    }
};