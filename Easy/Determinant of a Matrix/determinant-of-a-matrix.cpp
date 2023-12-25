//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here 
        // Base case: If the matrix is 1x1, return the only element.
        if (n == 1)
            return matrix[0][0];

        int det = 0;

        // Iterate through the first row to calculate the determinant.
        for (int i = 0; i < n; i++)
        {
            // Calculate the cofactor for each element in the first row.
            int sign = (i % 2 == 0) ? 1 : -1;
            int cofactor = sign * matrix[0][i] * determinantOfMinor(matrix, n, 0, i);

            // Add the cofactor to the determinant.
            det += cofactor;
        }

        return det;
    }

    // Function to calculate the determinant of the minor matrix.
    int determinantOfMinor(vector<vector<int>> &matrix, int n, int row, int col)
    {
        // Create a new matrix (minorMatrix) excluding the current row and column.
        vector<vector<int>> minorMatrix(n - 1, vector<int>(n - 1, 0));

        int minorRow = 0, minorCol = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != row && j != col)
                {
                    minorMatrix[minorRow][minorCol++] = matrix[i][j];

                    if (minorCol == n - 1)
                    {
                        minorCol = 0;
                        minorRow++;
                    }
                }
            }
        }

        // Recursively calculate the determinant of the minorMatrix.
        return determinantOfMatrix(minorMatrix, n - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends