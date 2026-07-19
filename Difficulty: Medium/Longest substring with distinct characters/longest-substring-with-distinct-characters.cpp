class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int first = 0, second = 0, len = 0, n = s.size();
        vector<int>count(256, 0);
        
        while (second < n){
            while (count[s[second]]){
                count[s[first]] = 0;
                first++;
            }
            count[s[second]]++;
            second++;
            len = max(len, second-first);
        }
        
        return len;
    }
};
