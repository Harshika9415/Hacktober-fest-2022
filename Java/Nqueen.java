import java.io.*;
import java.util.*;

public class Nqueen {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
       
        boolean [][]vis = new boolean[n][n];
        printNQueens(vis,"",0);
    }
    public static boolean isQueenSafe(boolean chess[][], int row,int col){

        // upward column
        for(int i =0;i<row;i++){
            if(chess[i][col] == true){
                return false;
            }
        }

        // upward left diagonal 
        int l = row;
        int r = col;
        while(l>=0  && r>=0){
            if(chess[l][r] == true){
                return false;
            }
            l--;
            r--;
        }

        // upward right diagonal 
        l = row;
        r = col;
        while(l>=0 && r < chess.length){
            if(chess[l][r] ==true){
                return false;
            }
            l--;
            r++;

        }
        return true;
    }
    public static void printNQueens(boolean [][] chess, String qsf, int row) {

        if(row == chess.length){
            System.out.println(qsf+".");
            return;
        }

        for(int col=0;col<chess[0].length;col++){
            if(isQueenSafe(chess,row,col)){
                
                chess[row][col] = true;
                printNQueens(chess,qsf +row+"-"+col+", ",row+1);
                chess[row][col] = false;

            }
        }
    }
}