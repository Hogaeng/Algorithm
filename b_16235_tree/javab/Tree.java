package javab;
public class Tree implements Comparable<Tree> {

	int x;
	int y;
	int z;
	
	public Tree(int x, int y, int z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getZ() {
		return z;
	}

	public void setZ(int z) {
		this.z = z;
	}

	@Override
	public int compareTo(Tree t) {
		// TODO Auto-generated method stub
		if(this.z < t.getZ()) {
			return -1;
		}
		else if(this.z > t.getZ()) {
			return 1;
		}
		return 0;
	}
}
