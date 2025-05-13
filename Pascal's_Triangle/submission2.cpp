class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;

        for (int i=1; i<=numRows; i++){

            vector<int> row;

            if (i==1){
                row.push_back(1);
            }
            else{
                int counter = 0;

                row.push_back(1);
                for (int j=1; j<=i-2; j++){
                    // For i=3----> previous row is 2nd =====> index(previous row) = 1
                    row.push_back(ans[i-2][counter] + ans[i-2][counter+1]);
                    counter++;
                }
                row.push_back(1);
            }

            ans.push_back(row);
        }

        return ans;

    }
};