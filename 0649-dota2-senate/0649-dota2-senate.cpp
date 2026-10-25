class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> rad;
        queue<int> dire;
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                rad.push(i);
            }else{
                dire.push(i);
            }
        }
        while(!rad.empty() && !dire.empty()){
            int ri=rad.front();
            int di=dire.front();
            rad.pop();
            dire.pop();
            if(ri<di){
                rad.push(ri+n);
            }else{
                dire.push(di+n);
            }
        }
        return rad.empty()?"Dire":"Radiant";
    }
};