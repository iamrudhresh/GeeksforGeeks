class Solution {

    public int andInRange(int l, int r) {

        int shift = 0;

 

        // find common prefix

        while (l < r) {

            l >>= 1;

            r >>= 1;

            shift++;

        }

 

        // restore shifted bits

        return l << shift;

    }

}