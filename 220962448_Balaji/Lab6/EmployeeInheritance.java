import java.util.Scanner;

class Employee {
    String Ename;
    int Eid;
    double Basic, DA, gross_Sal, IT, net_sal;

    public Employee() {
        Ename = "Default Employee";
        Eid = 0;
        Basic = 0.0;
    }

    public Employee(String name, int id, double basic) {
        Ename = name;
        Eid = id;
        Basic = basic;
    }

    void compute_net_sal() {
        DA = 0.52 * Basic;
        gross_Sal = Basic + DA;
        IT = 0.3 * gross_Sal;
        net_sal = gross_Sal - IT;
    }

    void display() {
        System.out.println("Employee ID: " + Eid);
        System.out.println("Employee Name: " + Ename);
        System.out.println("Basic Salary: " + Basic);
        System.out.println("Net Salary: " + net_sal);
    }
}

class FullTimeEmp extends Employee {
    double bonus, deductions;

    public FullTimeEmp(String name, int id, double basic, double bonus, double deductions) {
        super(name, id, basic);
        this.bonus = bonus;
        this.deductions = deductions;
    }

    void compute_net_sal() {
        super.compute_net_sal();
    }

    void display() {
        super.display();
        System.out.println("Bonus: " + bonus);
        System.out.println("Deductions: " + deductions);
    }
}

class PartTimeEmp extends Employee {
    int hoursWorked;
    static final double hourlyRate = 10.0;

    public PartTimeEmp(String name, int id, int hoursWorked) {
        super(name, id, 0);
        this.hoursWorked = hoursWorked;
    }

    void compute_net_sal() {
        super.compute_net_sal();
    }

    void display() {
        super.display();
        System.out.println("Hours Worked: " + hoursWorked);
        System.out.println("Hourly Rate: " + hourlyRate);
    }
}

public class EmployeeInheritance {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of Employees: ");
        int N = scanner.nextInt();
        scanner.nextLine();

        Employee[] Employees = new Employee[N];
        for (int i = 0; i < N; i++) {
            System.out.println("Enter details for Employee " + (i + 1));
            System.out.print("Enter Employee Name: ");
            String name = scanner.nextLine();
            System.out.print("Enter Employee ID: ");
            int id = scanner.nextInt();
            scanner.nextLine();

            System.out.println("Is this Employee Full-Time or Part-Time? (F/P): ");
            char EmployeeType = scanner.nextLine().charAt(0);

            if (EmployeeType == 'F' || EmployeeType == 'f') {
                System.out.print("Enter Basic Salary: ");
                double basic = scanner.nextDouble();
                System.out.print("Enter Bonus: ");
                double bonus = scanner.nextDouble();
                System.out.print("Enter Deductions: ");
                double deductions = scanner.nextDouble();
                Employees[i] = new FullTimeEmp(name, id, basic, bonus, deductions);
            } else if (EmployeeType == 'P' || EmployeeType == 'p') {
                System.out.print("Enter Hours Worked: ");
                int hoursWorked = scanner.nextInt();
                Employees[i] = new PartTimeEmp(name, id, hoursWorked);
            } else {
                System.out.println("Invalid input. Please enter 'F' for Full-Time or 'P' for Part-Time.");
                i--;
            }

            scanner.nextLine();
        }
        scanner.close();

        System.out.println("Employee Details and Net Salaries:");
        for (Employee Employee : Employees) {
            Employee.compute_net_sal();
            Employee.display();
        }
    }
}