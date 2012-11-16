import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
    public static BigInteger fun(BigInteger a,BigInteger b,BigInteger c)
    {
        int n=2;
        BigInteger x=a,y=b,z=c;
        BigInteger ans;
        while(n<99)
        {
            n++;
            ans=BigInteger.valueOf(0);
            ans=ans.add(y);
            ans=ans.add(x);
            ans=ans.add(z);
            x=y;
            y=z;
            z=ans;
        }
        return z;
    }
    public static void main(String[] args)
    {
        BigInteger a,b,c;
        Scanner cin=new Scanner(System.in);
        while(cin.hasNext())
        {
            a=cin.nextBigInteger();
            b=cin.nextBigInteger();
            c=cin.nextBigInteger();
            BigInteger ans=fun(a,b,c);
            System.out.println(ans);
        }
    }
}
