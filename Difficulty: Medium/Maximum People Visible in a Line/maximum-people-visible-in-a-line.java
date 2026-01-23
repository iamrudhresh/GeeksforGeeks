class Solution {

    public int maxPeople(int[] arr) {

        int n=arr.length;

    int[]leftMax=new int[n],rightMax=new int[n];

    ArrayDeque<Integer>st=new ArrayDeque<>();

    for(int i=0;i<n;i++){

        while(!st.isEmpty()&&arr[st.peek()]<arr[i])

        st.pop();

        leftMax[i]=st.isEmpty()?i+1:i-st.peek();

        st.push(i);

    }

    st.clear();

    for(int i=n-1;i>=0;i--){

        while(!st.isEmpty()&&arr[st.peek()]<arr[i])

        st.pop();

    rightMax[i]=st.isEmpty()?n-i:st.peek()-i;

    st.push(i);

    }

     int ans=1;

    for(int i=0;i<n;i++){

        ans=Math.max(ans,leftMax[i]+rightMax[i]-1);

    }

    return ans;

    }

}

 