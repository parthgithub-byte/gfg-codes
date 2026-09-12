class Solution {
  public:
    string convertToRoman(int n) {
        // code here
        vector<int>number={
            {1000, 900, 500, 400, 100, 90, 50, 40,10, 9, 5, 4, 1}
        };
        vector<string>roman={
            {"M", "CM", "D", "CD", "C", "XC", "L", "XL","X", "IX","V","IV","I"}
        };
        
        string ans="";
        int i=0;
        while(n!=0){
            while(n<number[i]){
                i++;
            }
            ans+=roman[i];
            n-=number[i];
        }
        
        return ans;
    }
};