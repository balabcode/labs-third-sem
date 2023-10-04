import java.util.Scanner;
class InvalidDayException extends Exception{
    public String toString(){
        return ("This date is invalid!");
    }
}
class InvalidMonthException extends Exception{
    public String toString(){
        return ("This month is invalid!");
    }
}
class CurrentDate{
    int day;
    int month;
    int year;
    Scanner sc = new Scanner(System.in);
    public void createDate() throws InvalidDayException, InvalidMonthException{
        System.out.print("Enter the date as DD MM YYYY: ");
        day = sc.nextInt(); month = sc.nextInt(); year = sc.nextInt();
        if(month > 12)
            throw new InvalidMonthException();
        else if(day > 31)
            throw new InvalidDayException();
        else
            System.out.println("Date: " + day + "/" + month + "/" + year);
        
    }
}
public class CurrentDateDemo {
    public static void main(String[] args){
        CurrentDate cd = new CurrentDate();
        try{
            cd.createDate();
        }
        catch(InvalidMonthException e){
            System.out.println(e);
        }
        catch(InvalidDayException e){
            System.out.println(e);
        }
    }
}