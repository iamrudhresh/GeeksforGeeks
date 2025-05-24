class Solution {
    public static int sumSubstrings(String s) {
        // code here
           int val=0, ans=0;
        for(int i=0;i<s.length();i++) {
            val=val*10+(s.charAt(i)-'0')*(i+1);
            ans=val+ans;
        }
        return ans;
    }
}