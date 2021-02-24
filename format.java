//자바 파일이름은 반드시 Main.java
//제출시 패키지 커멘트 아웃
package format;
import java.util.Scanner;
import java.io.FileInputStream;
public class Main{
    private static final boolean file_cin=true;
    private static final String filename="0000_format/format_in.txt";
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
        int tmp;
        if(file_cin)
            tmp=in.nextInt();
	    for(int z=0;z<tmp;z++){
        }
    }
}