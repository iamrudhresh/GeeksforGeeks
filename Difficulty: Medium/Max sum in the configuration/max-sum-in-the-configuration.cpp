class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        // int n=arr.size();
        // int maxi=INT_MIN;
        // for(int r=0;r<n;r++)
        // {
        //     int sum=0;
        //     for(int i=0;i<n;i++)
        //     {
        //         sum+=i*arr[i];
        //     }
        //     maxi=max(maxi,sum);
            
        //     int first=arr[0];
        //     for(int i=0;i<n-1;i++)
        //     {
        //         arr[i]=arr[i+1];
        //     }
        //     arr[n-1]=first;
        // }
        // return maxi;
        // these approach is for beginner first we are doing the code as per the question and lastly we are doing left rotation to get the maximum
        
        int n=arr.size();
        int sum=0;
        int arrsum=0;
        for(int i=0;i<n;i++)
        {
            sum+=i*arr[i];
            arrsum+=arr[i];
        }
        int maxi=sum;
        for(int i=1;i<n;i++)
        {
            sum=sum+arrsum-n*arr[n-i];
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};