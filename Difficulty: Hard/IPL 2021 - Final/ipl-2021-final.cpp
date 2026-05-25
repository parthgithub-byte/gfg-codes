// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        int n = s.size();
        stack<int>st;
        vector<int>sequence(n,0);

        for (int i=0; i<n; i++){
            if (!st.empty()){
                if (s[i] == ')'){
                    if (s[st.top()] == '('){
                        sequence[st.top()] = 1;
                        sequence[i] = 1;
                        st.pop();
                    }
                    else{
                        st.push(i);
                    }
                }
                else{
                    st.push(i);
                }
            }
            else{
                st.push(i);
            }
        }

        int maxi = 0, count = 0;
        for (int i=0; i<n; i++){
            if (sequence[i] == 0){
                count = 0;
            }
            else {
                count++;
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};