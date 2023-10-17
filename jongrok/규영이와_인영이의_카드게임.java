import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
public class Solution {
	static boolean[] v;
	static int[] tempt;
	static int win;
	static int lose;
	public static void main(String args[]) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t < T+1; t++) {
			String[] k = br.readLine().split(" ");
			int[] arr1 = new int[9];
			for(int i = 0; i < 9; i ++) arr1[i] = Integer.parseInt(k[i]);
			boolean[] ttt= new boolean[20];
			int[] arr2 = new int[9];
			int index = 0;
			for(int a : arr1) {
				ttt[a] = true;
			}
			for(int i = 1; i<19; i++) {
				if(!ttt[i]) {
					arr2[index++] = i;
					
				}
			}
			v = new boolean[9];
			tempt = new int[9];
			win = 0;
			lose = 0;
			permu(arr1,arr2,0);
			System.out.println("#" + t + " " + lose + " " + win);
			
			}
		}
		public static void permu(int[] arr1, int[] arr2, int index) {
			if(index == 9) {
				int a = 0;
				int b = 0;
				for(int i = 0; i <9; i++) {
					if(tempt[i] < arr1[i]) a += tempt[i] + arr1[i];
					if(arr1[i] < tempt[i]) b += tempt[i] + arr1[i];
				}
				if (a>b) lose++;
				if (a<b) win++;
				return;
			}
			for(int i =0;i<9;i++) {
				if(!v[i]) {
					v[i] = true;
					tempt[index] = arr2[i];
					permu(arr1,arr2,index+1);
					v[i] = false;
				}
			
			}
	}
	
	
}
