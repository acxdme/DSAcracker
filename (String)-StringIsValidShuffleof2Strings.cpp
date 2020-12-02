/*
This is primarily a dp question named  Interleaving Strings.
Time complexity  : O(N*M)
Space complexity : O(N*M)
My approach : create a boolean dp[n+1][m+1] with correct values in first row and first column , populate the rest of the dp appropriately.
*/

class Solution {
public:
    
    bool helper (string& s1, string& s2, string& s3)
    {
        int row = s1.size();
        int col = s2.size();
        bool dp[row+1][col+1];
        memset(dp,false,sizeof(dp));
        dp[0][0] = true;   // empty s1 and s2 with empty s3 is true base case
        
        for(int i=1;i<=row;i++)  // initializing first row 
            if(s1[i-1] == s3[i-1])   // if string-1 char is equal  string-3's char then dp[i][0] = dp[i-1][0]
                dp[i][0] = dp[i-1][0];
        
         for(int i=1;i<=col;i++) // initializing first column
            if(s2[i-1] == s3[i-1]) // if string-2 char is equal  string-3's char then dp[0][i] = dp[0][i-1]
                dp[0][i] = dp[0][i-1];
        
        for(int i=1;i<=row;i++)
        {
            for(int j=1;j<=col;j++)
            {
                if(s3[i+j-1] == s1[i-1])  // if string-1's char is equal to string-3's then value is above
                    dp[i][j] = dp[i-1][j];
                if(s3[i+j-1] == s2[j-1])
                     dp[i][j] = dp[i][j] or dp[i][j-1];
                
            }
        }
        
        return dp[row][col];
        
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();
        if(n1+n2 != n3) return false;
        
        bool result = helper(s1,s2,s3);
        
        return result;
        
    }
};
