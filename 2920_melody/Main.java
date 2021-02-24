package melody;
import java.util.Scanner;
import java.io.FileInputStream;
public class Main{
    private static final boolean file_cin=true;
    private static final String filename="2920_melody/melody_in.txt";
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
            int tt[] = new int[8];
            for(int i=0;i<8;i++)
                tt[i]=in.nextInt();
            int i=0;
            String status=new String();//0 ascending, 1 descending, 2 mixed
            do{
                int t=tt[i];
                if(i==0){
                    if(t-tt[i+1]==1)
                        status="descending";
                    else if(t-tt[i+1]==-1)
                        status="ascending";
                    else
                        status="mixed";
                }
                else{
                    if(status=="descending")
                        if(t-tt[i+1]!=1){
                            status="mixed";
                            break;
                        }
                    if(status=="ascending")
                        if(t-tt[i+1]!=-1){
                            status="mixed";
                            break;
                        }
                }
                i++;
            }while(i<7);
            System.out.println(status);
        }
            
    }
}