import java.math.BigDecimal;
import java.util.Scanner;
public class Main {
	public static void main(String[] args){
		Scanner cin=new Scanner(System.in);
		BigDecimal sum=new BigDecimal(0);
		while(cin.hasNext()){
			BigDecimal bg=new BigDecimal(cin.next());
			sum=sum.add(bg);
		}
		System.out.println(sum);
	}
}
