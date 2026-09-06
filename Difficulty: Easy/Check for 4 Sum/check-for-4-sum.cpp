class Solution {
  public:
    bool fourSum(vector<int>& arr, int x) {
        // code here
        int n=arr.size();
        unordered_map<int, vector<pair<int,int>>>mp;
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int sum=arr[i]+arr[j];
                int target=x-sum;
                
                if(mp.find(target)!=mp.end()){  // target sum exists
                    // vector iteration for the pairs
                    for (auto p: mp[target]){
                        if(p.first!=i && p.first!=j && p.second!=i && p.second!=j){ // checking if not duplicate
                            return true;
                        }
                    }
                }
                
                mp[sum].push_back({i, j});  // storing pair of index giving the sum, storing as index as arr values can be duplicate
            }
        }
        
        return false;        
    }
};