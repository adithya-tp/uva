import java.util.Scanner;
import java.math.BigInteger;

/*
    Had to use Java BigInteger Class to solve this problem. C++ ain't 
    got no BigInteger Class in STL.
*/

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int case_no = 1;
        while(true) {
            int N = sc.nextInt(), F = sc.nextInt();
            if(N == 0 && F == 0) break;
            BigInteger sum = BigInteger.ZERO;
            for(int i = 0; i < N; i++) {
                BigInteger V = sc.nextBigInteger();
                sum = sum.add(V);
            }
            System.out.println("Bill #" + (case_no++) + " costs " + sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(F)));
            System.out.println();
        }
        sc.close();
    }
}