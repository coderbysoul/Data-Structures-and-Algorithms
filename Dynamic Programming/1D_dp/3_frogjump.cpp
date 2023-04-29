//Recursion
int f(int ind,vector<int>&heights)
{
    if(ind==0) return 0;
    int left=f(ind-1,heights)+abs(heights[ind]-heights[ind-1]);
    int right= INT_MAX;
    if(ind>1)
     right=f(ind-2,heights)+abs(heights[ind]-heights[ind-2]);
     return min(left,right);
}
int frogJump(int n,vector<int> &heights)
{
   return f(n-1,heights);
}

//Memoization
int f(int ind,vector<int>&heights,vector<int>&dp)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int left=f(ind-1,heights,dp)+abs(heights[ind]-heights[ind-1]);
    int right= INT_MAX;
    if(ind>1)
     right=f(ind-2,heights,dp)+abs(heights[ind]-heights[ind-2]);
     return dp[ind]=min(left,right);
}
int frogJump(int n,vector<int> &heights)
{ vector<int>dp[n+1,-1];
   return f(n-1,heights,dp);
}

//Tabulation
int frogJump(int n,vector<int> &heights)
{ vector<int>dp[n,0];
   dp[0]=0;
   for(int ind=1;ind<n;ind++)
   {
    int left=dp[ind-1]+abs(heights[ind]-heights[ind-1]);
    int right= INT_MAX;
    if(ind>1)
     right=dp[ind-2]+abs(heights[ind]-heights[ind-2]);
     
    dp[ind]=min(left,right) ;
   }
   return dp[n-1];
}

//Space Optimisation
int frogJump(int n,vector<int> &heights)
{ int prev2=0,prev=0;
   
   for(int ind=1;ind<n;ind++)
   {
    int left=prev+abs(heights[ind]-heights[ind-1]);
    int right= INT_MAX;
    if(ind>1)
     right=prev2+abs(heights[ind]-heights[ind-2]);
     
    int curr=min(left,right) ;
    prev2=prev;
    prev=curr;
   }
   return prev;
}

