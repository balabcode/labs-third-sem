import java.util.Scanner;
class PushException extends Exception{
    public String toString(){
        return ("PushException: The stack is full!");
    }
}

class PopException extends Exception{
    public String toString(){
        return ("PopException: The stack is empty!");
    }
}

class Stack{
    int[] arr;
    int top;
    Stack(int size){
        arr = new int[size];
        top = -1;
    }
    boolean isFull(){
        return (this.top == this.arr.length - 1);
    }
    boolean isEmpty(){
        return (this.top < 0);
    }
    public void push(int n) throws PushException{
        if(this.isFull())
            throw new PushException();
        else
            arr[++top] = n;
    }
    public int pop() throws PopException{
        if(this.isEmpty())
            throw new PopException();
        else
            return arr[top--];
    }
    public void display(){
        for(int i = 0; i <= this.top; i++){
            System.out.print(arr[i] + "  ");
        }
        System.out.println();
    }
}

class StackExceptionsLmao{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter size: ");
        int n = sc.nextInt();
        Stack stack = new Stack(n);
        int op;
        System.out.println("Enter 1 to push, 2 to pop, 3 to display, 0 to exit.");
        do{
            System.out.print("Option: ");
            op = sc.nextInt();
            switch(op){
                case 1:
                    System.out.print("Number to push: ");
                    int num = sc.nextInt();
                    try{
                        stack.push(num);
                    }
                    catch(PushException e){
                        System.out.println(e);
                    }
                    break;
                case 2:
                    try{
                        System.out.println("Popped: " + stack.pop());
                    }
                    catch(PopException e){
                        System.out.println(e);
                    }
                    break;
                case 3:
                    stack.display();
                    break;
                default:
                    break;
            }
        }while(op!=0);
        sc.close();
    }
}