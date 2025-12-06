#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0,end=(s.size()-1);
        while(st<end){
            swap(s[st++],s[end--]);
        }
    }
};
int main(){
    vector<char> string1={'h','e','l','l','o'};
    Solution obj;
    obj.reverseString(string1);

    for (char c : string1) {
        cout << c << " ";
    }
    cout << endl;    

    return 0;
}