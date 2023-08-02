import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
public class Solution {
    public static void main(String args[]) throws Exception, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int t = 1; t < 11; t ++) {
            int n = Integer.parseInt(br.readLine());
            int [][] arr = new int[100][100];
            for(int i = 0; i < 100; i ++) {
                arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            }
            int r = 98;
            int c = start(arr[99]);
            while( r > 0) {
                if(c + 1 < 100 && arr[r][c+1] == 1) {
                    c ++;
                    arr[r][c] = 0;
                    continue;
                }
                if(0< c- 1 && arr[r][c-1] == 1) {
                    c--;
                    arr[r][c] = 0;
                    continue;
                }
                r--;
                arr[r][c] = 0;
            }
            System.out.println("#" + t + " " +c);
             
 
             
        }
    }
    public static int start(int[] arr) {
        for(int i = 0; i < 100; i ++) {
            if(arr[i] == 2) return i;
        }
        return 0;
    }
}
