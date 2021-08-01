#include <bits/stdc++.h> 
#define n 3 
using namespace std; 
  
int findLongestFromACell(int i, int j, int mat[n][n+1], int dp[n][n+1]) 
{ 
    if (i < 0 || i >= n || j < 0 || j >= n+1) 
        return 0; 
   
    if (dp[i][j] != -1) 
        return dp[i][j]; 
  
    int x = INT_MIN, y = INT_MIN, z = INT_MIN, w = INT_MIN; 
  
    if (j < n - 1+1 && mat[i][j] < mat[i][j + 1])
    {
        x = 1 + findLongestFromACell(i, j + 1, mat, dp);
    }
  
    if (j > 0 && mat[i][j] < mat[i][j - 1])
    {
        y = 1 + findLongestFromACell(i, j - 1, mat, dp);
    }
  
    if (i > 0 && mat[i][j] < mat[i - 1][j])
    {
        z = 1 + findLongestFromACell(i - 1, j, mat, dp); 
    }
  
    if (i < n - 1 && mat[i][j] < mat[i + 1][j]) 
    {
        w = 1 + findLongestFromACell(i + 1, j, mat, dp);
    }
  
    return dp[i][j] = max(x, max(y, max(z, max(w, 1)))); 
} 
  
int finLongestOverAll(int mat[n][n+1]) 
{ 
    int result = 1; 
  
    int dp[n][n+1]; 
    memset(dp, -1, sizeof dp); 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n+1; j++) { 
            if (dp[i][j] == -1) 
                findLongestFromACell(i, j, mat, dp); 
  
            result = max(result, dp[i][j]); 
        } 
    } 
  
    return result; 
} 
  
int main() 
{ 
    int mat[n][n+1] = { { 6, 1, 2, 3 }, 
                      { 4, 7, 6, 5 }, 
                      { 3, 8, 9, 0 } }; 
    cout << "Length of the longest path is "
         << finLongestOverAll(mat); 
    return 0; 
} 