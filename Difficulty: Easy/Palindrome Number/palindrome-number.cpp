class Solution {
  public:
    bool isPalindrome(int n) {
        // code here
        string s=to_string(abs(n));
        bool ans=true;
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                ans=false;
                break;
            }
        }
        return ans;
    }
};