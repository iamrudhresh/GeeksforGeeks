class Solution {
    StringBuilder sb=new StringBuilder();
    ArrayList<Character> al=new ArrayList<Character>();
    public void append(char x) {
        // append x into document
        sb.append(x);
    }

    public void undo() {
        // undo last change
        al.add(sb.charAt(sb.length()-1));//c k 
        sb.deleteCharAt(sb.length()-1);
    }

    public void redo() {
        // redo changes
        if(al.size()>0){
            sb.append(al.get(al.size()-1));
            al.remove(al.size()-1);
        }
    }

    public String read() {
        // read the document
        return sb.toString();
    }
}