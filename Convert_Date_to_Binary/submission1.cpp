class Solution {
public:
    string reverse(string input){
        string output;
        int n = input.size();
        for (int i=n-1; i>=0; i--){
            output.push_back(input[i]);
        }
        return output;
    }

    string solve(int num){
        string ans = "";
        while (num){
            ans.push_back((num%2==0) ? '0' : '1');
            num = num/2;
        }
        if (ans == "") ans = ans + "0";
        return reverse(ans);
    }

    string convertDateToBinary(string date) {
        string ans;
        ans = ans + solve((date[0]-48)*1000 + (date[1]-48)*100 + (date[2]-48)*10 + (date[3]-48)) + "-" + solve((date[5]-48)*10 + (date[6]-48)) + "-" + solve((date[8]-48)*10 + (date[9]-48));
        return ans;
    }
};