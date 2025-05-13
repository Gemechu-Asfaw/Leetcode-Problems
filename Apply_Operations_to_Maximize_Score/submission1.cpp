class Solution {
public:
    int getPrimeScore(int n){
        int ans = 0, i = 2;
        while (i*i <= n){
            if (n%i==0){
                ans++;
                while (n%i==0){
                    n = n/i;
                }
            }
            i++;
        }

        if (n > 1) ans++;
        return ans;
    } 

    int power(long long x, long long n){
        long long ans = 1;
        while (n>0){
            if (n==1){
                ans = (ans*x)%int(1e9+7);
                n = 0;
            } else if (n%2==0){
                x = (x*x)%int(1e9+7);
                n = n/2;
            } else {
                ans = (ans*x)%int(1e9+7);
                x = (x*x)%int(1e9+7);
                n = n/2;
            }
        }
        return ans;
    }

    int maximumScore(vector<int>& nums, int k) {
        
        long long score = 1; 
        int n = nums.size();
        vector<int> primes(n);
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        priority_queue<pair<int, int>> pq;

        for (int i=0; i<n; i++){
            primes[i] = getPrimeScore(nums[i]);
            pq.push({nums[i], i});
        }

        for (int i=0; i<n; i++){
            while (!st.empty() && primes[st.top()]<primes[i]){
                int top = st.top();
                st.pop();
                right[top] = i;
            }

            if (!st.empty()){
                left[i] = st.top();
            }

            st.push(i);
        }

        while (!pq.empty() && k>0){
            pair<int, int> top = pq.top();
            int index = top.second, value = top.first;
            pq.pop();

            long long possibilities = 1LL*(index-left[index])*(right[index]-index);
            score = (score*power(value, min((long long)k, possibilities)))%int(1e9+7);
            k = k - possibilities;
        }

        return (int)score;
    }
};