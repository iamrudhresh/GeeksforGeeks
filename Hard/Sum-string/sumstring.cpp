//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
string sum(string s1,string s2)
{
   
   int i=s1.length()-1,j=s2.length()-1;
   vector<char>ans;
   
   int x,y,res,rem,carry;
   char ch;
   while(i>=0 and j>=0)
   {
       x=s1[i]-'0';
        y=s2[j]-'0';
        res=x+y+carry;
        rem=res%10;
        carry=res/10;
        ans.push_back(rem+'0');
        i--;
        j--;
        
       
   }
   while(i>=0)
   {
       x=s1[i]-'0';
        res=x+carry;
        rem=res%10;
        carry=res/10;
        ans.push_back(rem+'0');
        i--;
        
   }
   while(j>=0)
   {
      
        y=s2[j]-'0';
        res=y+carry;
        rem=res%10;
        carry=res/10;
        ans.push_back(rem+'0');
        j--;
   }
   while(carry)
   {
       int rem=carry%10;
       ans.push_back(rem+'0');
       carry/=10;
   }
   string t;
   int p;
   for( p=ans.size()-1;p>=0;p--)
   {
      if(ans[i]!='0')
      break;
   }
   while(p>=0)
   {
       t+=ans[p];
       p--;;
   }
   return t;
}

bool solve(string s,int pos,int l1,int l2)
{
   string s1=s.substr(pos,l1);
   string s2=s.substr(pos+l1,l2);
   string s3=sum(s1,s2);
   int n=s3.length();
   if(n>s.length()-pos-l1-l2)
   return 0;
   if(s.substr(pos+l1+l2,n)==s3)
   {
      if(pos+l1+l2+n==s.length())
      return 1;
      return solve(s,pos+l1,l2,n);
   }
   return 0;
}

int isSumString(string s)
   {
       int n=s.length();
       for(int i=1;i<n;i++)
       {
           for(int j=1;j+i<n;j++)
           {
               if(solve(s,0,i,j))
               return 1;
           }
       }
       return 0;
   }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends