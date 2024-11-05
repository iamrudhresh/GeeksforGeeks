//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class DriverClass {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] arr = new int[n][n];

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) arr[i][j] = sc.nextInt();

            GFG g = new GFG();
            g.rotate(arr);
            printMatrix(arr);

            System.out.println("~");
        }
    }

    static void printMatrix(int arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) System.out.print(arr[i][j] + " ");
            System.out.println("");
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class GFG {
    static void rotate(int mat[][]) {
        // Code Here
         int a1 = mat.length;
    int a2 = mat[0].length;
    int arr[][] = new int[a1][a2];
    int end=a2-1;
    for(int i =0;i<a1;i++){
        end = a2-1;
        for(int j = 0;j<a2;j++){
            arr[i][j] = mat[end][i];
            end--;
        }
        
    }
    for(int i = 0;i<a1;i++){
        for(int j = 0;j<a2;j++){
            mat[i][j] = arr[i][j];
    }
}
}
}