package javab;
import java.util.*;

public class Program {
	int N;
	int M;
	int K;
	int[][] A;
	int[] x;
	int[] y;
	int[] z;

	int[][] map;
	ArrayList<Tree> treelist;
	ArrayList<Integer> temp;

	public Program(int N, int M, int K, int[][] A, int[] x, int[] y, int[] z) {
		this.N = N;
		this.M = M;
		this.K = K;
		this.A = A;
		this.x = x;
		this.y = y;
		this.z = z;

		treelist = new ArrayList<Tree>();		

		for(int i = 0; i < M; i++) {
			treeCreate(x[i], y[i], z[i]);
		}
		Collections.sort(treelist);
		mapCreate(N);

		for(int i = 0; i < K; i++) {
			if(treelist == null) {
				break;
			}
			spring();
			summer();
			fall();
			winter();
		}

		System.out.println(treelist.size());
	}

	public void spring() {
		int size = treelist.size();
		temp = new ArrayList<Integer>();
		int r;
		int c;
		int z;

		for(int i = 0; i < size ; i++) {
			r = treelist.get(i).x-1;
			c = treelist.get(i).y-1;
			z = treelist.get(i).z;
			if(map[r][c] >= z) {
				map[r][c] -= treelist.get(i).z;
				treelist.get(i).z += 1;
			}
			else {
				temp.add(i);
			}
		}
	}

	public void summer() {
		int size = temp.size();
		int r;
		int c;
		int reg;
		for(int i = size-1; i > -1; i--) {
			reg = temp.get(i);
			r = treelist.get(reg).x-1;
			c = treelist.get(reg).y-1;
			map[r][c] += (treelist.get(reg).z/2);			
			treelist.remove(reg);
			
		}
	}

	public void fall() {
		int size = treelist.size();
		int r;
		int c;
		int old;
		for(int i = 0; i < size; i++) {
			r = treelist.get(i).x;
			c = treelist.get(i).y;
			old = treelist.get(i).z;
			if(old%5 == 0) {
				if(r-1 > 0 && r-1 <= N && c-1 > 0 && c-1 <= N) {
					treeCreate(r-1, c-1, 1);
				}
				if(r-1 > 0 && r-1 <= N && c > 0 && c <= N) {
					treeCreate(r-1, c, 1);
				}
				if(r-1 > 0 && r-1 <= N && c+1 > 0 && c+1 <= N) {
					treeCreate(r-1, c+1, 1);
				}
				if(r > 0 && r <= N && c-1 > 0 && c-1 <= N) {
					treeCreate(r, c-1, 1);
				}
				if(r > 0 && r <= N && c+1 > 0 && c+1 <= N) {
					treeCreate(r, c+1, 1);
				}
				if(r+1 > 0 && r+1 <= N && c-1 > 0 && c-1 <= N) {
					treeCreate(r+1, c-1, 1);
				}
				if(r+1 > 0 && r+1 <= N && c > 0 && c <= N) {
					treeCreate(r+1, c, 1);
				}
				if(r+1 > 0 && r+1 <= N && c+1 > 0 && c+1 <= N) {
					treeCreate(r+1, c+1, 1);
				}
			}
		}
		Collections.sort(treelist);
	}


	public void winter() {
		for(int r = 0; r < N; r++) {
			for(int c = 0; c < N; c++) {
				map[r][c] += A[r][c];
			}
		}
	}

	public void mapCreate(int N) {
		map = new int[N][N];
		for(int i =0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				map[i][j] = 5;
			}
		}
	}

	public void treeCreate(int x, int y, int z) {
		Tree tree = new Tree(x, y, z);
		treelist.add(tree);
	}
}
