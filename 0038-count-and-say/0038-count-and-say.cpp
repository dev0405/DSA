class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int k=1;k<n;k++){
            string ans="";
            int i=0;
            while(i<s.length()){
                int j=i;
                while(j<s.length() && s[i]==s[j]){
                    j++;

                }
                int count=j-i;
                ans+=to_string(count);
                ans+=s[i];
                i=j;

            }
            s=ans;
        }
        return s;
    }
};