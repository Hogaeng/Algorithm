package javab;
import java.io.*;
import java.util.*;

public class Main{
    public static void main(String[] args){

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String s = br.readLine();
	StringTokenizer st = new StringTokenizer(s);
	String array[];

	int N, M, K;
	int[][] A;
	int[] x;
	int[] y;
	int[] z;

	N = Integer.parseInt(st.nextToken());
	M = Integer.parseInt(st.nextToken());
	K = Integer.parseInt(st.nextToken());
	array = s.split(" ");

	if(1 <= N && N <= 10 &&
		1<= M && M <= (N*N) &&
		1 <= K && K <= 1000) {
	    A = new int[N][N];
	    x = new int[M];
	    y = new int[M];
	    z = new int[M];

	    for(int r = 0; r < N; r++) {
		s = br.readLine();
		st =  new StringTokenizer(s);
		for(int c = 0; c < N; c++) {
		    A[r][c] = Integer.parseInt(st.nextToken());
		    if(1 > A[r][c] && A[r][c] > 100) {
			return;
		    }
		}
		array = s.split(" ");
	    }

	    for(int i = 0; i < M; i++) {

		s = br.readLine();
		st =  new StringTokenizer(s);
		x[i] = Integer.parseInt(st.nextToken());
		y[i] = Integer.parseInt(st.nextToken());
		z[i] = Integer.parseInt(st.nextToken());
		if(1 > z[i] && z[i] > 10) {
		    return;
		}
	    }
	    Program exam = new Program(N, M, K, A, x, y, z);
	    br.close();
		}
	else {
	    return;
	}
    }
}
