class Solution {
    public int minOperations(int[] arr) {
        // code here
        PriorityQueue<Double>pq=new PriorityQueue<>((a,b)-> Double.compare(b,a));
        double sum=0;
        for(int ele:arr){
            pq.offer((double)ele);
            sum+=(double)ele;
        }
        double div=sum/2;
        int operation=0;
        while(sum>div){
            double top=pq.poll()/2;
            sum-=top;
            pq.offer(top);
            operation++;
        }
        return operation;
    }
}