class Solution {
    int findWays(int n) {
        // code here
        ArrayList<String>ans=new ArrayList<>();
        String s="";
        if(n%2!=0) return 0;
        helper(n/2,n/2,ans,s);
        return ans.size();
    }
    public void helper(int open,int close,ArrayList<String>ans,String s){
        if(open==0 && close==0){
            if(!ans.contains(s))   ans.add(s);
        }
        if(open>0){
            helper(open-1,close,ans,s+"(");
        }
        if(close>open){
            helper(open,close-1,ans,s+")");
        }
        
    }
    
}

