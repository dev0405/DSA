class Solution {
public:
    string decodeString(string s) {
        stack<int> numstack;
        stack<string> strstack;
        string currstr="";
        int currnum=0;
        for(char c:s){
            if(isdigit(c)){
                currnum=currnum*10+(c-'0');
            }
            else if(c=='['){
                numstack.push(currnum);
                strstack.push(currstr);
                currstr="";
                currnum=0;
            }else if(c==']'){
                int repeatTimes=numstack.top();
                numstack.pop();
                string prevStr=strstack.top();
                strstack.pop();
                string temp;
                for(int i=0;i<repeatTimes;i++){
                    temp+=currstr;
                }
                currstr=prevStr+temp;
            }else{
                currstr+=c;
            }
        }
        return currstr;
    }
};