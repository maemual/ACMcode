import java.io.*;
import java.util.*;
import java.math.BigDecimal;
public class Main {

	public static void main(String args[]) throws Exception {
		//获取屏幕输入。
		Scanner cin = new Scanner(System.in);
		//记录之前输入的高精度小数。
		BigDecimal num;
		//记录乘方。
		int n;
		//记录输出的数据。
		String r;
		//循环获取所有的输入。
		while(cin.hasNextBigDecimal()){
			//获取输入的数据。
			num = cin.nextBigDecimal();
			n = cin.nextInt();
			//算乘方。
			num = num.pow(n);
			//去掉尾部的 0，并转换为无指数形式的字符串。
			r = num.stripTrailingZeros().toPlainString();
			//如果 s 是以 0. 开始的话。
			if(r.startsWith("0.")){
				//去掉第一个 0，题目要求去掉。
				r = r.substring(1);
			}
			//输出结果。
			System.out.println(r);
		}
	}
}
