import java.io.*;
import java.util.*;

public class s4 {
    public static void main(String[] args) throws IOException {
        // INPUT
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()), ans = 0, arr[] = new int[n+2], dp[][] = new int[n+2][n+2];
        String s = br.readLine();
        StringTokenizer st = new StringTokenizer(s);

        // Fill initial
        for(int i = 1; i<=n; i++){
            Arrays.fill(dp[i], -1);
            dp[i][i] = Integer.parseInt(st.nextToken());
            ans = Math.max(ans, dp[i][i]);
            arr[i] = arr[i - 1] + dp[i][i];
        }

        // Fill DP left right loop
        for(int distance = 1; distance <= n; distance++) {
            for(int l = 1; l + distance <= n; l++) {
                int r = l + distance, i = l, j = r;
                while(i + 1 <= j){
                    if(dp[l][i] != -1
                            && dp[j][r] != -1
                            && dp[l][i] == dp[j][r]){
                        if((i + 1 == j)||(dp[i + 1][j - 1] != -1))
                            dp[l][r] = Math.max(dp[l][r], arr[r] - arr[l-1]);
                    }
                    if(arr[i] - arr[l - 1] < arr[r] - arr[j - 1]) i++;
                    else j--;
                }
                ans = Math.max(ans, dp[l][r]);
            }
        }
        System.out.println(ans);
    }
}