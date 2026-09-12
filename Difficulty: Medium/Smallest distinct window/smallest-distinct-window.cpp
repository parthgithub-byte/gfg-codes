class Solution {
  public:
    int findSubString(string& str) {
        // code here
        set<char>unique(str.begin(), str.end());
        int diff=unique.size();
        
        vector<int>count(256,0);
        
        int first=0, second=0, n=str.size();
        int ans=n;
        while(second<n){
            while(diff && second<n){
                if (count[str[second]]==0){
                    diff--;
                }
                count[str[second]]++;
                second++;
            }
            
            ans = min(ans, second-first);
            while(diff!=1){
                ans = min(ans, second-first);
                count[str[first]]--;
                if(count[str[first]]==0)    diff++;
                first++;
            }
        }
        
        return ans;
    }
};