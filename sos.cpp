//Problem Specification:-

//Given two strings str1 and str2, the task is to find the length of the shortest string that has both str1 and str2 as subsequences.

//Why will we follow the dynamic programming approach?

//Firstly, Dynamic Programming programming reduces a lot of computation time.The idea is to follow the simple recursive solution, use a lookup table to avoid recomputations.

//sample snippet for Dynamic Programming in c++



//Recursive definition of the problem:-

//The idea is to follow the simple recursive solution, use a lookup table to avoid recomputations. Before computing result for an input, we check if the result is already computed or not. If already computed, we return that result.


/*above is the recursive solution of the problem. Time complexity of the above solution exponential O(2min(m, n)).

Algorithm:-

step1:- Maintain a table to store values, here dp[n+1][m+1]

step2:- declare function superSeq(string str1, string srt2,int n ,int m ,vector<vector<int>> dp)

step3:- if m==0 or n==0 then dp[n][m]=n+m //base case

step4:- if dp[n][m]==0 then //if not previously computed

if str1[n-1]==str2[m-1] then //if n-1th character in str1 is equal to m-1th character in str2

dp[n][m] = superSeq(str1, srt2, n - 1, m - 1, dp) + 1;  //add +1 to previous because we got new equal characters

else //if n-1th character in str1 is not equal to m-1th character in str2

dp[n][m] = min(superSeq(srt1, str2, n - 1, m, dp) + 1, superSeq(str1, str2, n, m - 1, dp) + 1);

//find minimum of n-1 and m-1 characters

step5:- else // if previously computed

return dp[n][m];

step6: STOP

//sample code*/


#include <bits/stdc++.h>
using namespace std;

int superSeq(string X, string Y, int n, int m,vector<vector<int> > dp)
{

   if (m == 0 || n == 0) {
          dp[n][m] = n + m;
   }
   if (dp[n][m] == 0)
       if (X[n - 1] == Y[m - 1]) {
             dp[n][m] = superSeq(X, Y, n - 1, m - 1, dp) + 1;
       }

       else {
           dp[n][m] = min(superSeq(X, Y, n - 1, m, dp) + 1, superSeq(X, Y, n, m - 1, dp) + 1);
       }

   return dp[n][m];
}

// Driver Code
int main()
{
   string X = "AGGTB";
   string Y = "GXTXAYB";

   vector<vector<int> > dp(
       X.size() + 1, vector<int>(Y.size() + 1, 0));

   cout << "Length of the shortest supersequence is "
       << superSeq(X, Y, X.size(), Y.size(), dp)
       << endl;

   return 0;
}

/*Output:

Length of the shortest supersequence is 9
1) Find Longest Common Subsequence (lcs) of two given strings. For example, lcs of “hello” and “hell” is “hell”.
2) Insert non-lcs characters (in their original order in strings) to the lcs found above, and return the result.
Let us consider another example, str1 = “AGGTAB” and str2 = “GXTXAYB”. LCS of str1 and str2 is “GTAB”. Once we find LCS, we insert characters of both strings in order and we get “AGXGTXAYB”

Runtime analysis:-

Time complexity of the above dynamic solution is O(mn).*/
