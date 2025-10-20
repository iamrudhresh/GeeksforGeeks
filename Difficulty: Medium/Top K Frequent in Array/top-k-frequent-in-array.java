class Solution {
    public ArrayList<Integer> topKFreq(int[] arr, int k) {
        // Code here
        LinkedHashMap<Integer, ArrayList<Integer>> lm = new LinkedHashMap<>();
        HashMap<Integer, Integer> hm = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();
        
        for(int i=0;i<arr.length;i++){
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }

        for(int i=arr.length;i>0;i--){
            ArrayList<Integer> al = new ArrayList<>();
            lm.put(i, al);
        }
        
        for(Map.Entry<Integer, Integer> entry:hm.entrySet()){
            ArrayList<Integer> al = lm.get(entry.getValue());
            al.add(entry.getKey());
            lm.put(entry.getValue(), al);
        }
        
        for(Map.Entry<Integer, ArrayList<Integer>> entry:lm.entrySet()){
            ArrayList<Integer> al = entry.getValue();
            if(al.size()==0) continue;
            
            Collections.sort(al, Collections.reverseOrder());
            
            int i=0;
            while(k!=0 && i<al.size()){
                ans.add(al.get(i));
                i++;
                k--;
            }
            if(k==0){
                return ans;
            }
        }
        
        return ans;
    }
}