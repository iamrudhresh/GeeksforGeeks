class Solution {
    public static String caseSort(String s) {
        // code here
           List<Character> u=new ArrayList<>(),l=new ArrayList<>();
        char arr[]=s.toCharArray();
        for(char c:arr){
            if(c>='a' && c<='z') l.add(c);
            else u.add(c);
        }
        Collections.sort(u);
        Collections.sort(l);
        int j=0,k=0;
        for(int i=0;i<arr.length;i++){
            if(s.charAt(i)>='a' && s.charAt(i)<='z') arr[i]=l.get(k++);
            else arr[i]=u.get(j++);
        }
        return new String(arr);
    }
}