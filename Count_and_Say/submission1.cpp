class Solution {
public:
    string getRleString(char contender, int count){
        string prefix = "";
        while (count){
            prefix = prefix + char(count%10 + 48);
            count = count/10;
        }
        reverse(prefix.begin(), prefix.end());
        return prefix + contender;
    }

    string countAndSay(int n) {
        string current = "1";
        for (int i=1; i<n; i++){
            string temp = "";
            char x = current[0];
            int count = 1;
            for (int i=1; i<=current.size(); i++){
                if (i==current.size()){
                    temp = temp + getRleString(x, count);
                } else if (current[i] == x){
                    count++;
                } else {
                    temp = temp + getRleString(x, count);
                    x = current[i];
                    count = 1;
                }
            }
            current = temp;
        }

        return current;
    }
};