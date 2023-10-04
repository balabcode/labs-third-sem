import java.util.Scanner;

interface Series{
    // static int elem;
    void getNext();
    void reset();
    void setStart(int n);
}

class ByTwos implements Series{
    // ByTwos(){

    // }
    static int elem;
    public void setStart(int n){
        elem = n;
    }
    public void getNext(){
        elem += 2;
        System.out.println("Next: "+elem);
    }
    public void reset(){
        elem = 0;
    }
}

class q3{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Series s = new ByTwos();
        System.out.println("Enter 0 to reset, 1 to get the next element, 2 to set the starting element, -1 to exit.");
        // int act = sc.nextInt();
        int act;
        do{
            System.out.print("Enter option: ");
            act = sc.nextInt();
            if(act == 0){
                s.reset();
            }
            else if(act == 1){
                s.getNext();
            }
            else if(act == 2){
                System.out.print("Enter starting number: ");
                int n = sc.nextInt();
                s.setStart(n);
            }
            else{
                break;
            }
        }while(act!=-1);
    }
}