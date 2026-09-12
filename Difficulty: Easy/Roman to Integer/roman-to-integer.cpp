class Solution {
  public:
    int romanToInteger(string &s) {
        // code here
        unordered_map<char,int>number={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        int i=0, sum=0, n=s.size();
        if(n==1){
            return number[s[0]];
        }
        
        while(i<n-1){
            if(number[s[i]]<number[s[i+1]]){
                sum-=number[s[i]];
            }
            else{
                sum+=number[s[i]];
            }
            i++;
        }
        sum+=number[s[n-1]];
        
        return sum;
    }
};