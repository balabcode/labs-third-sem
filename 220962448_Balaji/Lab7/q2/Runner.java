import java.util.Scanner;
import myPackages.p1.Maximum;

public class Runner{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter 1 for individual elements, 2 for array, 3 for matrix: ");
        int act = sc.nextInt();
        if(act == 1){
            System.out.print("Enter a: ");
            int a = sc.nextInt();
            System.out.print("Enter b: ");
            int b = sc.nextInt();
            System.out.print("Enter c: ");
            int c = sc.nextInt();
            int max = Maximum.max(a,b,c);
            System.out.println("\nThe maximum number entered is: " + max);
        }
        if(act == 2){
            System.out.print("\nEnter number of elements: ");
            int n = sc.nextInt();
            int a[] = new int[n];
            System.out.print("\nEnter elements: ");
            for(int i = 0; i < n; i++){
                a[i] = sc.nextInt();
            }
            int max = Maximum.max(a);
            System.out.println("\nThe maximum number entered is: " + max);
        }
        if (act == 3){
            System.out.print("\nEnter number of rows: ");
            int r = sc.nextInt();
            System.out.print("Enter number of columns: ");
            int c = sc.nextInt();
            System.out.print("\nEnter elements: ");
            int a[][] = new int[r][c];
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    a[i][j] = sc.nextInt();
                }
            }
            int max = Maximum.max(a);
            System.out.println("\nThe maximum number entered is: " + max);
        }
        
    }    
}