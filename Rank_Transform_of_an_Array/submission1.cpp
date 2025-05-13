class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        int n = arr.size(), smallest=INT_MIN, rank=0;
        vector<pair<int,int>> arrSorted;

        for (int i=0; i<n; i++){
            arrSorted.push_back({arr[i], i});
        }

        sort(arrSorted.begin(), arrSorted.end());
        
        for (int i=0; i<n; i++){
            if (arrSorted[i].first > smallest){
                smallest = arrSorted[i].first;
                rank++;
            }
            arr[arrSorted[i].second] = rank;
        }

        return arr;
    }
};