//leetcode 1784
class Solution {
public:
    bool checkOnesSegment(string s) {
        int count = 0;
        int n = s.size();
        int i=0;
        while(i<n){
            if(s[i] == '1'){
                count++;
                while(i<n && s[i]=='1'){
                    i++;
                }
            }
            else{
                i++;
            }
        }
        if(count>1){
            return false;
        }
        else{
            return true;
        }
    }
};

//in this question we just have to check if count of 1 segment is more than one so just return false else return true 
