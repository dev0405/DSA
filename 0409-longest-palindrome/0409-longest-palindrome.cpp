class Solution {
public:
    int longestPalindrome(string s) {
        int len=0;
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        bool odd=false;
        for(auto it:mp){
            len+=(it.second/2)*2;
            if(it.second%2==1){
                odd=true;
            }
        }
        if(odd){
            len++;
        }
        return len;
    }
};