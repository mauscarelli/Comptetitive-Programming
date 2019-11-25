import java.util.*;

class Conjunto extends Thread {
    volatile boolean continua = true;

    public void run(){
        func1();
    }

    synchronized void func1() {
        try {
            continua = false;
            System.out.print(" X");
            wait();
            System.out.print(" Y");
            notify();
            System.out.print(" Z");
        } catch (InterruptedException e) {

        }
    }

    synchronized void func2() {
        try {
            System.out.print(" A");
            notify();

            System.out.print(" B");
            wait();
            System.out.print(" C");
        } catch (InterruptedException e) {

        }
    }

    public static void main(String s[]) {
        Conjunto c = new Conjunto();
        c.start();
        while (c.continua);
        c.func2();
    }
}

/*
 * Pergunta Mal formulada, mas ele apresentará: Joao Maria Mariana Pedro
 * 
 * Pois o Set não permite elementos repetidos e a arvore organiza do menor para
 * o maior ().
 */