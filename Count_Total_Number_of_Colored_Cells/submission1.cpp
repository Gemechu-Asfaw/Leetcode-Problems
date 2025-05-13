class Solution {
public:
    long long coloredCells(int n) {
        if (n==1) return 1;
        long long longN = n;
        return longN*longN + (longN-1)*(longN-1);
    }
};