class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int fiveCoin = 0, tenCoin = 0, n = bills.size();
        for (int i=0; i<n; i++){
            if (bills[i] == 5){
                fiveCoin++;
            } else if (bills[i] == 10){
                tenCoin++;
                if (fiveCoin){
                    fiveCoin--;
                } else {
                    return false;
                }
            } else {
                if (fiveCoin && tenCoin){
                    fiveCoin--;
                    tenCoin--;
                } else if (fiveCoin >= 3){
                    fiveCoin = fiveCoin - 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};