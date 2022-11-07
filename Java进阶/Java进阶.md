* 同步锁和互斥锁
  
  * 互斥性：
    
    当使用多个`synchronized`锁定读个代码片段，并且指定了相同的同步监视器对象时，那么这些代码片段之间就是互斥的，多个线程不能同时执行它们
    
    ```java
    public class SyncDemo4 {
        public static void main(){
    
            Boo boo = new Boo();
            Thread t1 = new Thread(){
                public void run(){
                    boo.methodA();
                }
            };
            Thread t2 = new Thread(){
                public void run(){
                    boo.methodB();
                }
            };
    
            t1.start();
            t2.start();
        }
    }
    class Boo{
        public synchronized void methodA(){
            Thread t = Thread.currentThread();
            try{
                System.out.println(t.getName() + "methodA正在执行");
            }catch (Exception e){
                e.printStackTrace();
            }
            System.out.println(t.getName() + "methodA执行完毕");
        }
    
        public synchronized void methodB(){
            Thread t = Thread.currentThread();
            try{
                System.out.println(t.getName() + "methodB正在执行");
            }catch (Exception e){
                e.printStackTrace();
            }
            System.out.println(t.getName() + "methodB执行完毕");
        }
    }
    ```
