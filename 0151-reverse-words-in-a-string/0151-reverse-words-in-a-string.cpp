class Solution {
public:
    string reverseWords(string s) {
        string word="";
        string result="";
        stack<string> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                word+=s[i];
            }else{
                if(!word.empty()){
                    st.push(word);
                    word="";
                }
            }
        }
        if(!word.empty()) st.push(word);
        while(!st.empty()){
            result+=st.top();
            st.pop();
            if(!st.empty()) result+=" ";
        }
        return result;
    }
};
