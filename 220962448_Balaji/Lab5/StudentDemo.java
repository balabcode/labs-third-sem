import java.util.Scanner;

class Student {
    String name;

    public Student(String name) {
        this.name = name;
    }

    public String extractInitials() {
        String[] names = name.split(" ");
        String temp = "";
        for (String name : names) {
            if (!name.isEmpty()) {
                temp += Character.toUpperCase(name.charAt(0));
            }
        }

        return temp;
    }

    public String removeWhitespace() {
        return name.replaceAll("\\s", "");
    }

    public static void findNamesWithSubstring(Student[] students, String substring) {
        System.out.println("Names containing '" + substring + "':");
        for (Student student : students) {
            if (student.name.contains(substring)) {
                System.out.println(student.name);
            }
        }
    }

    public static void sortStudents(Student[] students) {
        for (int i = 0; i < students.length - 1; i++) {
            for (int j = i + 1; j < students.length; j++) {
                if (students[i].name.compareToIgnoreCase(students[j].name) > 0) {
                    Student temp = students[i];
                    students[i] = students[j];
                    students[j] = temp;
                }
            }
        }
    }
}

class StudentDemo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of students: ");
        int n = scanner.nextInt();
        scanner.nextLine();
        Student[] students = new Student[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter name for student " + (i + 1) + ": ");
            String name = scanner.nextLine();
            students[i] = new Student(name);
        }

        System.out.println("Initials and Names without Whitespace:");
        for (Student student : students) {
            String initials = student.extractInitials();
            String nameWithoutWhitespace = student.removeWhitespace();

            System.out.println("Name: " + student.name);
            System.out.println("Initials: " + initials);
            System.out.println("Without Whitespace: " + nameWithoutWhitespace);
            System.out.println();
        }

        System.out.print("Enter a substring to search for in names: ");
        String substring = scanner.nextLine();
        Student.findNamesWithSubstring(students, substring);

        Student.sortStudents(students);
        System.out.println("Sorted Student Names:");
        for (Student student : students) {
            System.out.println(student.name);
        }

        scanner.close();
    }
}