package com.test;

import java.util.*;
import java.io.*;

public class Main {
    static int[] dx = {-1,-1,0,1,1,1,0,-1};
    static int[] dy = {0,1,1,1,0,-1,-1,-1};
    static char[][] arr;
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        PriorityQueue<int[]> l = new PriorityQueue<>(Comparator.comparing(x -> x[0]));
        for(int t = 1; t < T +1; t++) {
            int N = Integer.parseInt(br.readLine());
            int cnt = 0;
            arr = new char[N][N];
            Queue<int []> q = new LinkedList<>();
            for(int i = 0; i <N; i++) arr[i] = br.readLine().toCharArray();
            for(int i = 0; i < N; i++) {
                for(int j = 0; j <N; j ++) {
                    if(!check(i,j)) continue;
                    int n = GetNum(i,j);
                    l.add(new int[] {-n,i,j});
                }
            }
            while(!l.isEmpty()) {
                int[] node = l.remove();
                if(arr[node[1]][node[2]] != '.') continue;
                cnt ++;
                arr[node[1]][node[2]]= '1';
                q.add(new int[] {node[1],node[2]});
                while(!q.isEmpty()){
                    int[] node2 = q.remove();
                    for(int k = 0; k <8; k ++) {
                        int x = dx[k] + node2[0];
                        int y = dy[k] + node2[1];
                        if(0<=x && x<arr.length && 0<= y && y<arr.length && arr[x][y] != '*' && arr[x][y] != '1') {
                            arr[x][y] = '1';
                            if(check(x,y)) q.add(new int[] {x,y});
                        }
                    }
                }
            }
            for(int i = 0; i < arr.length; i++) {
                for(int j = 0; j < arr.length; j ++) {
                    if (arr[i][j] == '.') cnt ++;
                }
            }
            System.out.println("#" + t + " " + cnt);
        }
    }
    public static boolean check(int r, int c) {
        for(int i = 0; i < 8; i ++) {
            int x = r + dx[i];
            int y = c +dy[i];
            if(0<=x && x<arr.length && 0<= y && y<arr.length) {
                if( arr[x][y] == '*') return false;
            }
        }
        return true;
    }
    public static int GetNum(int r, int c){
        int cnt = 0;
        for(int i = 0; i < 8; i ++){
            int x = r + dx[i];
            int y = c + dy[i];
            if(0<=x && x<arr.length && 0<= y && y <arr.length) cnt ++;
        }
        return cnt;
    }

}
