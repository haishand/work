import java.io.PrintStream;

public class AmoebaDivTwo   {
public int count(String[] table, int K) {
        int n = table.length;
        int m = table[0].length();
        int[][] tbl = new int[n][m];
        for(int i=0; i<table.length; i++) {
            for(int j=0; j<table[i].length(); j++) {
                tbl[i][j] = 0;
                if(table[i].charAt(j) == 'A') {
                    tbl[i][j] = 1;
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                boolean rflag = true;
                for(int r = j; r<=j+K-1; r++) {
                    if(r==m || tbl[i][r] == 0) {
                        rflag = false;
                        break;
                    }
                }
                if(rflag) {
                    System.out.printf("(%d,%d) r\n", i, j);
                    ++ans;
                }
                boolean cflag = true;
                for(int c=i; c<=i+K-1; c++) {
                    if(c==n || tbl[c][j] == 0) {
                        cflag = false;
                        break;
                    }
                }
                if(K!=1 && cflag) {
                    System.out.printf("(%d,%d) c\n", i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }

}
