import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        BigInteger bn = BigInteger.ZERO;
        while(sc.hasNextBigInteger()) {
            BigInteger num = sc.nextBigInteger();
            if(num.equals(BigInteger.ZERO)) break;
            bn = bn.add(num);
        }
        System.out.println(bn.toString());
        sc.close();
    }
}