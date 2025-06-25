class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
            unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        unordered_map<int,int>count;
        for(auto ele : mp){
            count[ele.second]++;
        }
        
        if(count.size()>2){
            return false;
        }
        else if(count.size()==1)return true;
        
        else if(count.size()==2){
            auto it = count.begin();
            int num1 = it->first;
            int freq1 = it->second;
            it++;
            int num2 = it->first;
            int freq2 = it->second;
            if(abs(freq1-freq2)>1){
                return false;
            }
            if((num1>num2 && freq1==1 && ((num1-num2)==1)) || (num1<num2 && freq2==1 && ((num2-num1)==1))){
                return true;
            }
            else if(num1==1 || num2==1){
                return true;
            }
        }
        return false;
    }
};