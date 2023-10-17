import java.io.*;
import java.util.*;
 
 
 
public class Solution {
    static int N;
    static int[] costs;
    static int [] months;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for(int t = 1; t < T+1; t++) {
            costs = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            months = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            N = 99999999;
            cal(0,0);
            N = Math.min(N, costs[3]);
            System.out.println("#" + t + " " + N);
        }
        
    }
     
    static void cal (int m, int cost) {
        if(m >=12) {
            N = Math.min(N, cost);
            return;
        }
        cal(m + 1, cost + costs[0]*months[m]);
        cal(m + 1, cost+ costs[1]);
        cal(m + 3, cost + costs[2]);
    }
}
