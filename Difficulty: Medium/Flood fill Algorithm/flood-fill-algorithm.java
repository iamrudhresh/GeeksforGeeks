//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int m = Integer.parseInt(br.readLine().trim());
            int[][] image = new int[n][m];
            for (int i = 0; i < n; i++) {
                String[] S2 = br.readLine().trim().split(" ");
                for (int j = 0; j < m; j++) image[i][j] = Integer.parseInt(S2[j]);
            }
            int sr = Integer.parseInt(br.readLine().trim());
            int sc = Integer.parseInt(br.readLine().trim());
            int newColor = Integer.parseInt(br.readLine().trim());
            Solution obj = new Solution();
            int[][] ans = obj.floodFill(image, sr, sc, newColor);
            for (int i = 0; i < ans.length; i++) {
                for (int j = 0; j < ans[i].length; j++)
                    System.out.print(ans[i][j] + " ");
                System.out.println();
            }

            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}

class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int original = image[sr][sc] ; 
        Queue<Pair> q = new LinkedList<>() ; 
        int[] dx = {-1 , 1 , 0 , 0 } ; 
        int[] dy = {0 , 0 , -1 , 1 } ; 
        int n = image.length ; 
        int m = image[0].length ; 
        int[][] visited = new int[n][m] ; 
        q.offer(new Pair(sr , sc)) ; 
        image[sr][sc] = newColor ; 
        visited[sr][sc] = 1 ; 
        while(!q.isEmpty()){
            Pair p = q.poll() ; 
            int x = p.first ; 
            int y = p.second; 
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i] ; 
                int ny = y + dy[i] ; 
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && visited[nx][ny] == 0  && image[nx][ny] == original){
                    q.offer(new Pair(nx , ny)) ;
                    visited[nx][ny] = 1 ; 
                    image[nx][ny] = newColor ; 
                }
            }
        }
        return image; 
        
    }
}