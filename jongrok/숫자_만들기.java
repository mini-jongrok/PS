
import java.io.*;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;


public class Solution {

    static int T, N, max, min;
    static ArrayList<Integer> operator; // + - * /
    static int[] nums;
    static int[] perms;
    static boolean[] visited;
    static List<HashSet<String>> v;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        T = Integer.parseInt(st.nextToken());
        for (int tc = 1; tc <= T; tc++) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            operator = new ArrayList<>();
            nums = new int[N];
            perms = new int[N - 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 4; i++) {
                int tmp = 0;
                tmp = Integer.parseInt(st.nextToken());
                for (int j = 0; j < tmp; j++) {
                    operator.add(i); // 0 : +, 1 : -, 2 : *, 3 : /
                }
            }
            
            visited = new boolean[operator.size()];
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                nums[i] = Integer.parseInt(st.nextToken());
            }
            max = Integer.MIN_VALUE;
            min = Integer.MAX_VALUE;
            v = new ArrayList<>();
            for(int i = 0; i<operator.size();i++) {
            	v.add(new HashSet<String>());
            }
            perm(0);
            System.out.println("#"+tc+" " +Math.abs(max - min));
        }
    }
    static void perm(int depth) {
        if (depth == N - 1) {
            int res = 0;
            res = calc();
            max = Math.max(max, res);
            min = Math.min(min, res);
            return ;
        }
        
        
        for (int i = 0; i < operator.size(); i++) {
            if (visited[i] == true)continue;
            String s = makeS(perms,depth,operator.get(i));
            if (v.get(i).contains(s)) continue;
            v.get(i).add(s);
            visited[i] = true;
            perms[depth] = operator.get(i);
            perm(depth + 1);
            visited[i] = false;
        }
        
    }
    static int calc() {
        int ret = nums[0];
        int op = -1;
        for (int i = 1; i < N; i++) {
            op = perms[i - 1];
            if (op == 0) {
                ret += nums[i]; 
            }else if (op == 1) {
                ret -= nums[i];
            }else if (op == 2) {
                ret *= nums[i];
            }else {
                ret = (int)(ret / nums[i]);
            }
        }
        return ret;
    }
    
    static String makeS(int[] p, int depth,int i) {
    	StringBuilder br = new StringBuilder();
    	for(int k = 0; k <depth; k++) {
    		br.append(p[k]);
    	}
    	br.append(i);
    	return br.toString();
    }

}
