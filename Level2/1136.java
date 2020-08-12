import java.io.*;
import java.util.Stack;

class Matrix{
    long a[][];
    int r, c;
    long mod;

    Matrix(int r, int c){
        this(r, c, 1000000007);
    }

    Matrix(int r, int c, long m){
        this.r = r;
        this.c = c;
        this.mod = m;
        a = new long[r][c];
    }

    static Matrix pow(Matrix A, long n){
        Matrix B = new Matrix(A.r, A.r);
        for(int i = 0; i < A.r; i++){
            B.a[i][i] = 1;
        }
        while(n > 0){
            if((n&1) == 1){
                B = mul(B, A);
            }
            A = mul(A, A);
            n >>>= 1;
        }
        return B;
    }

    static Matrix mul(Matrix A, Matrix B){
        Matrix C = new Matrix(A.r, B.c);
        for(int i = 0; i < A.r; i++){
            for(int j = 0; j < B.c; j++){
                for(int k = 0; k < A.c; k++){
                    C.a[i][j] += A.a[i][k]*B.a[k][j]%A.mod;
                    C.a[i][j] %= A.mod;
                }
            }
        }
        return C;
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        Matrix m = new Matrix(4, 4);
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i != j)  m.a[i][j] = 1;
            }
        }
        m = Matrix.pow(m, n);
        Matrix x = new Matrix(4, 1);
        x.a[0][0] = 1;
        x = Matrix.mul(m, x);
        System.out.println(x.a[0][0]);
    }
}
