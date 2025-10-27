class Solution {
    public ArrayList<ArrayList<Integer>> kSmallestPair(int[] arr1, int[] arr2, int k) {
        // code here
        TreeMap<Integer, ArrayList<ArrayList<Integer>>> tm = new TreeMap<>();
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        int k1 = k, temp = -1;
        
        for(int i=0;i<arr1.length;i++){
            for(int j=0;j<arr2.length;j++){
                if(k1!=0){
                    ArrayList<ArrayList<Integer>> al1 = new ArrayList<>();
                    ArrayList<Integer> al = new ArrayList<>();
                    al.add(arr1[i]);
                    al.add(arr2[j]);
                    
                    if(tm.containsKey(arr1[i]+arr2[j])){
                        al1 = tm.get(arr1[i]+arr2[j]);
                    }
                    
                    al1.add(al);
                    tm.put(arr1[i]+arr2[j], al1);
                    k1--;
                }else{
                    Map.Entry<Integer, ArrayList<ArrayList<Integer>>> entry = tm.lastEntry();
                    if(arr1[i]+arr2[j]>=entry.getKey()){
                        temp = j;
                        break;
                    }
                    
                    if(entry.getValue().size()==1){
                        tm.remove(entry.getKey());
                    }else{
                        ArrayList<ArrayList<Integer>> al = entry.getValue();
                        al.remove(al.size()-1);
                        tm.put(entry.getKey(), al);
                    }
                    
                    ArrayList<ArrayList<Integer>> al1 = new ArrayList<>();
                    ArrayList<Integer> al = new ArrayList<>();
                    al.add(arr1[i]);
                    al.add(arr2[j]);
                    
                    if(tm.containsKey(arr1[i]+arr2[j])){
                        al1 = tm.get(arr1[i]+arr2[j]);
                    }
                    
                    al1.add(al);
                    tm.put(arr1[i]+arr2[j], al1);
                }
            }
            if(temp==0) break;
        }
        
        for(Map.Entry<Integer, ArrayList<ArrayList<Integer>>> entry:tm.entrySet()){
            ArrayList<ArrayList<Integer>> al = entry.getValue();
            for(int i=0;i<al.size();i++){
                ans.add(al.get(i));
            }
        }
        
        return ans;
    }
}

