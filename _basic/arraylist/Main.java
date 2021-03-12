package arraylist;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.FileInputStream;
public class Main{
    private static final boolean file_cin=false;
    private static final String filename="basic/arraylist/arraylist.txt";
    public static void main(String[] args){
        if(file_cin){
            FileInputStream instream=null;
            try{
                instream = new FileInputStream(filename);
                System.setIn(instream);
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }
        Scanner in = new Scanner(System.in);
        int tmp=1;
        if(file_cin)
            tmp=in.nextInt();
	    for(int z=0;z<tmp;z++){
            int t[]={3,1,2};
            int n=5;
            List<Integer> tt= new ArrayList<Integer>(List.of(3,1,2));
            for(int i=0;i<tt.size();i++)
                System.out.print(tt.get(i)+" ");
        }
    }
}