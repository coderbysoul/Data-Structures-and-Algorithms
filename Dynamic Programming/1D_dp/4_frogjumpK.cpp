//Recursion->Memoization->Tabulation->Space Optimisation
//Recursion

int f(int ind,int k,vector<int>&heights)
{
    if(ind==0) return 0;
    int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    
    if(ind-j>=0)
    {
      int jump=f(ind-j,k,heights)+abs(heights[ind]-heights[ind-j]);
      minSteps=min(minSteps,jump);
    }
    return minSteps;
}
int frogJump(int n,vector<int> &heights,int k)
{
   return f(n-1,k,heights);
}

//Memoization
int f(int ind,int k,vector<int>&heights,vector<int>&dp)
{
    if(ind==0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    for(int j=1;j<=k;j++)
    
    if(ind-j>=0)
    {
      int jump=f(ind-j,k,heights,dp)+abs(heights[ind]-heights[ind-j]);
      minSteps=min(minSteps,jump);
    }
    return dp[ind]=minSteps;
}
int frogJump(int n,int k,vector<int> &heights)
{ vector<int>dp[n+1,-1];

   return f(n-1,k,heights,dp);
}

//Tabulation
int frogJump(int n,int k,vector<int> &heights)
{ vector<int>dp[n,0];
   dp[0]=0;
   for(int ind=1;ind<n;ind++)
   {
   int minSteps=INT_MAX;
    for(int j=1;j<=k;j++)
    
    if(ind-j>=0)
    {
      int jump=dp[ind-j]+abs(heights[ind]-heights[ind-j]);
      minSteps=min(minSteps,jump);
    }
   }
   return dp[n-1];
}

//Space Optimisation
int frogJump(int n,int k,vector<int> &heights)
{ int prev=0;
   
   for(int ind=1;ind<n;ind++)
   {
    int minJump=INT_MAX;
    for(int j=1;j<=k;j++)
    {
        if(ind-j>=0)
        {
            int jump=prev+abs(heights[ind]-heights[ind-j]);
            minJump=min(minJump,jump);
        }
    }
    
    prev=minJump;
   }
   
   return prev;
}

