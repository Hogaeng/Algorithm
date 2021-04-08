//Comment out package name when submit the code.
package b_20056_mageshark;
import java.util.Scanner;
import java.io.FileInputStream;
public class Main{
    private static final boolean file_cin=true;
    private static final String filename="b_20056_mageshark/mageshark_in.txt";
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
            //Write your code here.
        }
    }
}
