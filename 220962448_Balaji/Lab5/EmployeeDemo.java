import java.util.*;

class Employee {
    private int empId;
    private String name;

    public Employee(int empId, String name) {
        this.empId = empId;
        this.name = name;
    }

    public String formatEmployeeName() {
        String temp = "";
        for (int i = 0; i < name.length(); i++) {
            if (i == 0 || name.charAt(i - 1) == ' ') {
                temp += Character.toUpperCase(name.charAt(i));
            } else {
                temp += Character.toLowerCase(name.charAt(i));
            }
        }
        return temp;

    }

    public String generateEmail() {
        String temp = "";
        String[] names = this.name.toLowerCase().split(" ");
        for (int i = 0; i < names.length; i++) {
            if (i == 0) {
                temp += names[i].charAt(0);
            } else
                temp += names[i];
        }
        temp += "@example.com";
        return temp;
    }
}

class EmployeeDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter First Name: ");
        String name = sc.nextLine();
        System.out.print("Enter Employee ID: ");
        int empId = sc.nextInt();
        Employee employee = new Employee(empId, name);

        String formattedName = employee.formatEmployeeName();
        String email = employee.generateEmail();

        System.out.println("Formatted Name: " + formattedName);
        System.out.println("Generated Email: " + email);
        sc.close();
    }
}