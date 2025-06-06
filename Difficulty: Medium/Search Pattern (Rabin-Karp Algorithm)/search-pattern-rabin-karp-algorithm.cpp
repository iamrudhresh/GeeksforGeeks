class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
         // code here.
        int p=31;
        int mod=1e9+9;
        int n=pat.size();
        int m=txt.size();
        
        vector<long long>p_pow(m);
        p_pow[0]=1;
        for(int i=1;i<m;i++){
            p_pow[i]=(p_pow[i-1]*p)%mod;
        }
        
        // now we will create hash function for every prefix
        vector<long long>h_txt(m+1,0);
        for(int i=0;i<m;i++){
            h_txt[i+1]=(h_txt[i]+(txt[i]-'a'+1)*p_pow[i])%mod;
        }
        
        // created a polynomial like a0+a1p^1+...am-1p^m-1 in mod m space
        
        // now we have to do same for pat
        long long h_pat=0;
        for(int i=0;i<n;i++){
            h_pat=(h_pat+(pat[i]-'a'+1)*p_pow[i])%mod;
        }
        
        // now we have to check if txt[i..j]=pat[0..n-1]=h_pat
        // only thing we have to take care is we have same scale of polynomila
        // cause we have aip^i+...ajp^j
        // but actually to be same with pat
        // we should have aip^0+...ajp^n-1
        // so we will simple scale down
        vector<int>ans;
        for(int i=0;i+n<=m;i++){
            long long poly=(h_txt[i+n]+mod-h_txt[i])%mod;
            // +mod to avoid negative values
            // instead of doing inverse and dividing poly by p_pow
            // we can also scale up h+pat
            if(poly==(h_pat*p_pow[i])%mod){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};