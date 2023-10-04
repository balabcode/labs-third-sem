package myPackages.p1;

public class Maximum{
    public static int max(int a, int b, int c){
        if(a > b && a > c)
            return a;
        else if (b > a && b > c)
            return b;
        else
            return c;
    }
    public static float max(float a, float b, float c){
        if(a > b && a > c)
            return a;
        else if (b > a && b > c)
            return b;
        else
            return c;
    }
    public static int max(int[] a){
        int m = a[0];
        for (int i = 1; i < a.length; i++){
            if(m < a[i]){
                m = a[i];
            }
        }
        return m;
    }
    public static int max(int[][] a){
        int m = a[0][0];
        for(int i = 0; i < a.length; i++){
            for(int j = 0; j < a[i].length; j++){
                if(m < a[i][j])
                    m = a[i][j];
            }
        }
        return m;
    }
}