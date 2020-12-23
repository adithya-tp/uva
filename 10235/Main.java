import java.util.Scanner;
import java.math.BigInteger;

/*
    With Java's BigInteger class also have a probabilistic primality test function
    based on Miller-Rabin's algorithm and this is useful if you only need to make
    primality check calls for one or atmost a few prime numbers.

    A certainty of 10 in the function call for isProbablePrime is enough most
    of the time, since the P(prime) becomes 1 - (1/2)^certainty = 1 - (1/2)^10 = 0.9990234375 ~ 1.0
*/

class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()) {
            int num = sc.nextInt();
            BigInteger bn = BigInteger.valueOf(num);
            String rev = new StringBuffer(bn.toString()).reverse().toString();
            int rev_num = Integer.parseInt(rev);
            BigInteger bn_rev = BigInteger.valueOf(rev_num);
            System.out.printf("%d is ", num);
            if(!bn.isProbablePrime(10))
                System.out.printf("not prime.\n");
            else if(bn_rev.isProbablePrime(10))
                System.out.printf("emirp.\n");
            else
                System.out.printf("prime.\n");
        }
        sc.close();
    }
}