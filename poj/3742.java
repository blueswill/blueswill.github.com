import java.math.*;
import java.util.*;
class Main{
    static BigInteger[] a=new BigInteger[300];
    static BigInteger[] b=new BigInteger[300];
    static BigInteger[][] C=new BigInteger[201][201];
    static int n,t;
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        C[0][0]=BigInteger.ZERO;
        C[1][1]=C[1][0]=BigInteger.ONE;
        for(int i=2;i<201;++i){
            C[i][0]=C[i][i]=BigInteger.ONE;
            for(int j=1;j<i;++j) C[i][j]=C[i-1][j].add(C[i-1][j-1]);
        }
        while(sc.hasNext()){
            n=sc.nextInt();t=sc.nextInt();
            for(int i=0;i<n+1;++i){
                a[i]=b[i]=sc.nextBigInteger();
            }
            for(int k=n-1;k>=0;--k){
                for(int i=k+1;i<=n;++i)
                    b[k]=b[k].subtract(
                            b[i].multiply(C[i][k].multiply(
                                    BigInteger.valueOf(-t).pow(i-k))));
            }
            for(int i=0;i<n;++i) System.out.print(b[i]+" ");
            System.out.println(b[n]);
        }
    }
}
