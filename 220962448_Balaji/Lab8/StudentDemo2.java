import java.util.Scanner;
import static java.lang.System.out;

class SeatsFilledException extends Exception{
    int regno;
    SeatsFilledException(int no){
        this.regno=no;
    }
    public String toString(){
        return "Cannot allot seats for "+this.regno+"\nAll Seats Filled";
    }
}

class Student{
    static int count=1;
    String sname;
    static int year=2023;
    String regno;
    Student(String name){
        this.sname=name;
        setRegNo();
    }
    private void setRegNo(){
        String y=String.valueOf(Student.year);
        String c=String.valueOf(Student.count);
        this.regno="";
        if(c.length()<2)
            c='0'+c;
        this.regno+=y.charAt(y.length()-2);
        this.regno+=y.charAt(y.length()-1);
        this.regno+=c;      
        Student.count++;
    }
    public void display(){
        System.out.println("Name: "+ this.sname);
        System.out.println("Year: "+ Student.year);
        System.out.print("RegNo: "+this.regno+"\n");
    }
}

class StudentDemo{
    public static void main(String[] args){
        Student s1=new Student("john");
        s1.display();
    }
}