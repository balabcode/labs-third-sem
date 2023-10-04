import java.util.Scanner;
class SeatsFilledException extends Exception{
    public String toString(){
        return "No seats left! Max is 25 students.";
    }
}
class Student{
    String name;
    String regno = "";
    String doj;
    static int count = 0;
    Scanner sc = new Scanner(System.in);
    Student() throws SeatsFilledException{
        System.out.print("Enter name: ");
        name = sc.nextLine();
        System.out.print("Enter date of joining: ");
        doj = sc.nextLine();
        count++;
        regno += doj.charAt(doj.length() -2);
        regno += doj.charAt(doj.length() -1);
        if (count > 25){
            throw new SeatsFilledException();
        }
        if (count < 10){
            regno += "0" + count;
        }
        else{
            regno += count;
        }
    }
    public void display(){
        System.out.println("Name: "+ this.name);
        System.out.println("Year: "+ doj);
        System.out.print("RegNo: "+this.regno+"\n");
    }
}
class StudentDemo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        for(int i = 0; i < 30; i++){
            try{
                Student student = new Student();
                student.display();
            }
            catch(SeatsFilledException e){
                System.out.println(e);
            }
        }
        sc.close();
    }
}