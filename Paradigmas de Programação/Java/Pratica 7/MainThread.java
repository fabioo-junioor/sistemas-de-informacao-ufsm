import java.util.Date;
import java.util.Random;

class MyThread extends Thread {
    private char id;
    public MyThread(char id) {
        this.id = id;
    }
    public void run() {
        for (int count = 0; count < 10; count++) {
            System.out.println("Thread " + id + " counting: " + count);
        }
    }
}
class MyRunnable implements Runnable {
    private char id;
    public MyRunnable(char id) {
        this.id = id;
    }
    public void run() {
        for (int count = 0; count < 10; count++) {
            System.out.println("Runnable " + id + " counting: " + count);
        }
    }
}

class Derivada extends Thread {
    private char id;
    private Date hora;
    public Derivada (char c, String string) {
        this.hora = new Date();
        this.id = c;
    }
    public void run() {
        for (int count = 0; count < 20; count++) {
            System.out.println("Thread " + id + " hora: " + hora + " counting: " + count);
        }
    }
}

class Derivada2 implements Runnable{
    public void run() {
        for (int i = 0; i < 10; i++) {
            Random random = new Random();
            int aux = random.nextInt(100);
            System.out.println("Numero Random: " + aux);
        }
    }
}

class MainThread {
  public static void main(String[] args) {
        MyThread t1 = new MyThread('A');
        Thread t2 = new Thread(new MyRunnable('B'));
        Derivada t3 = new Derivada('C',"");
        Thread t4 = new Thread(new Derivada2());

        t1.start();
        t2.start();
        t3.start();
        t4.start();
  }
}