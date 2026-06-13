class Solution {
  public:
    vector<int> windowsForArray(vector<int>&arr, int n){
        // first we will calculate the leftSmaller index
        vector<int>ansLeft(n,-1);
        stack<int>st;
        for (int i=0; i<n; i++){
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if (!st.empty()){
                ansLeft[i] = st.top();
            }
            st.push(i);
        }
        
        while (!st.empty()){
            st.pop();
        }
        
        // now we will find the nextGreater index
        vector<int>ansRight(n,n);
        for (int i=0; i<n; i++){
            while (!st.empty() && arr[i] < arr[st.top()]){
                ansRight[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        vector<int>ans(n);
        for (int i=0; i<n; i++){
            ans[i] = ansRight[i] - ansLeft[i] - 1;
        }
        
        return ans;
    }
  
    vector<int> maxOfMins(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int>windows = windowsForArray(arr, n);
        vector<int>ans(n+1, 0);
        // made the answer array to directly map the wo window sizes for each index
        // i.e., here we will do the window wise placement, 1-based indexing
        
        for (int i=0; i<n; i++){
            int len = windows[i];
            
            if (ans[len] < arr[i]){
                // also check if the present array element having this window size is the
                // maximum no with this window size, ie.e is it max of min
                ans[len] = arr[i];
            }
        }
/*    
Eg:
10 20 15 30 50 70 30 25

10: 8
20: 2
15: 6
30: 4
50: 2
70: 1
25: 1
        
ans (right now):
 0 70 50 0 30 0 15 0 10
*/      

        ans.erase(ans.begin(), ans.begin()+1);  // removing the first dummy index in the ans array
        
        for (int i=n-2; i>=0; i--){
            ans[i] = max(ans[i], ans[i+1]);
        }
        
        
        return ans;
    }
};