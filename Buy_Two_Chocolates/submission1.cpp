class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        // Cosidering the first two elements as the smallest number (initially)
        int first = prices[0], second = prices[1], size = prices.size();
        if (second < first){
            swap(first,second);
        }

        // Processing the entire array and checking if there exists any value smaller than first or second variable
        for (int i=2; i<size; i++){
            if (prices[i] < first){
                second = first;
                first = prices[i];
            } else if (prices[i] < second){
                second = prices[i];
            }
        }

        // Returing the final value
        int cost = first + second;
        if (cost > money){
            return money;
        } else {
            return money - cost;
        }
    }
};