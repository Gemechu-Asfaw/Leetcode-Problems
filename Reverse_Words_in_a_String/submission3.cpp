class Solution {
public:
    string reverseWords(string s) {
        
        int size = s.size();
        int i=size-1;
        string ans = "";

        while (i>=0){

            while (i>=0 && s[i]==' '){
                i--;
            }

            int j=i;
            while (j>=0 && s[j]!=' '){
                j--;
            }

            for (int k=j+1; k<=i; k++){
                ans.push_back(s[k]);
            }

            i=j;
            while (i>=0 && s[i]==' '){
                i--;
            }

            if (i!=-1){
                ans.push_back(' ');
            }
        }

        return ans;

    }
};