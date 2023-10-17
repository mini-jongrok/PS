import java.util.Scanner;
class Solution
{
    public static void main(String args[]) throws Exception
    {
        Scanner scanner = new Scanner(System.in);
        int [] dx = {0,1,0,-1};
        int [] dy = {1,0,-1,0};
        int d,cnt,x,y;
        int N = scanner.nextInt();
        for (int t = 1; t < N + 1; t++ ) {
            int size = scanner.nextInt();
            int[][] arr = new int[size][size];
            d = 0; cnt = 1;
            x = 0; y = 0;
            arr[0][0] = cnt++;
            while (cnt < size*size + 1) {
                while (0<= x +dx[d] && x + dx[d] < size && 0<=y+dy[d] && y+dy[d] < size && arr[x +dx[d]][y+dy[d]] == 0) {
                    arr[x +dx[d]][y+dy[d]] = cnt ++;
                    x += dx[d];
                    y += dy[d];
                }
                d = (d+1) % 4;
            }
            System.out.println("#" + t);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j ++) {
                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();
            }
        }
        scanner.close();
    }
}
