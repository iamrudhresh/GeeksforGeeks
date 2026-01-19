class Solution {
    public String removeKdig(String s, int k) {
        Stack<Character> st = new Stack<>();

        for (char ch : s.toCharArray()) {
            while (!st.isEmpty() && k > 0 && st.peek() > ch) {
                st.pop();
                k--;
            }
            st.push(ch);
        }

        // If k still > 0, remove from end
        while (k > 0 && !st.isEmpty()) {
            st.pop();
            k--;
        }

        // Build result
        StringBuilder sb = new StringBuilder();
        for (char c : st) {
            sb.append(c);
        }

        // Remove leading zeros
        while (sb.length() > 1 && sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }

        return sb.length() == 0 ? "0" : sb.toString();
    }
}