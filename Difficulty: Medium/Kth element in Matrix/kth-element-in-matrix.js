/**
 * @param {number[][]} matrix
 * @param {number} k
 * @returns {number}
 */

class Solution {
    kthSmallest(matrix, k) {
        // code here
               let ans=[];
        for (let i of matrix){
    for (let j of i){
        ans.push(j);
    }
}
ans.sort((a,b)=>a-b);
return ans[k-1];
    }
}