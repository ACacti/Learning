#### 权限修饰

|   权限    | 本类 | 本包的类 | 子类 | 非子类的外包类 |
| :-------: | :--: | :------: | :--: | :------------: |
|  public   |  是  |    是    |  是  |       是       |
| protected |  是  |    是    |  是  |       否       |
|  default  |  是  |    是    |  否  |       否       |
|  private  |  是  |    否    |  否  |       否       |

方法重写：

1. 子类重写的方法的方法名和形参列表与父类被重写的方法名和形参列表相同。
2. 子类重写的方法的权限修饰符不小于父类被重写的方法的权限修饰符。
   * 特殊情况：子类不能重写父类中生命为private权限的方法
3. 返回类型：
   * 父类被重写的方法的返回值类型是void，则子类重写的方法的返回值类型只能是void
   * 父类被重写的方法返回值是A类型，则子类重写的方法的返回值类型可以是A类或者A的子类。
   * 父类被重写的方法的返回值类型是基本数据类型，则子类重写方法的返回值类型必须是相同的返回值类型。
4. 子类重写的方法抛出的异常类型不大于父类被重写的方法跑出的异常类型。

#### 上转型

``` java
class A {
         public void print() {
                  System.out.println("A:print");
         }
}

class B extends A {
         public void print() {        
                  System.out.println("B:print");
         }
}

public class Test{
         public static void main(String args[])
         {
                  A a = new B();          //通过子类去实例化父类
                  a.print();//B:print
         }
}
```

上转型的意义：当我们需要多个同父的对象调用某个方法时,通过向上转换后,则可以确定参数的统一。

我的理解：相当于父类声明了一个虚函数，该函数父类的实现我们不关心，虚函数具体看子类实现。

上转型作用示例：

``` java
class A {
         public void print() {
                  System.out.println("A:print");
         }
}

class B extends A {
         public void print() {        
                  System.out.println("B:print");
         }
}

class C extends B {
         public void print() {        
                  System.out.println("C:print");
         }
}

public class Test{
         public static void func(A a)
         {
                  a.print();
         }

         public static void main(String args[])
         {
                  func(new B());  //等价于 A a =new B();
                  func(new C());  //等价于 C c =new C();
         }
}
```

#### 下转型

上转型示例中A的实例a无法调用B特有的属性，但实际内存中已经加载了B的所有属性。如果想要使用B的所有属性，可以使用下转型

``` java
B b = (B)a;
```

#### `instanceof` 关键字

1. `a instanceof A` ：判断对象a是否是A类（常在下转型时使用）

#### Object类

1. object类声明了一个空参的构造器
2. 如果在类的生命中为使用extends关键字知名其父类，则默认父类为java.lang.Object

#### == 和equals()的区别

* == 运算符
  1. 比较的事基本数据类型变量：比较两个类型保存的数据是否相等（不一定类型相同）。
  2. 比较的事引用数据类型变量：比较两个对象的地址值是否相同，即两个引用是否指向同一个对象实体。
* equals()方法
  1. 是一个方法，而非运算符
  2. 只能适用于引用数据类型
  3. Object类定义的equals()与==作用相同，都是比较两个对象的地址值是否相同。
  4. 但String、Date、File、包装类都重写了Object类的equals方法。

#### 注解（Annotation）

1. 生成文档相关的注解：

   `@author`, `@version`,`@see`,`@since`,`@param`,`@return`,`@exception`等。
   
2. 在编译时进行格式检查

   `@Override`:限定重写父类方法。

   `@Deprecated`:用于表示所修饰的元素（方法、类）已过时。

   `@SuppressWarnmings`:抑制编译器警告

3. 跟踪代码的依赖性，实现代替配置文件功能

   例如Servlet3.0中的`@WebServlet`.

4. 自定义注解：参照`@SupperessWarnings`定义

   * 注解声明为：`@interface`
   * 内部定义成员，通常用value表示
   * 可以指定成员的默认值，用default定义
   * 如果自定义注解没有成员，表明是一个标识作用

   示例：

   ``` java
   public @interface MyAnnotation {
       String value() default "hello";
   }
   ```

5. 元注解：

   Retention: 指定所修饰的Annotation的声明周期：

   * SOURCE
   * CLASS(默认)
   * RUNTIME

   只有声明为RUNTIME生命周期的注解才能被反射所获取

   示例：

   ``` java
   import java.lang.annotation.Retention;
   import java.lang.annotation.RetentionPolicy;
   
   @Retention(RetentionPolicy.RUNTIME)
   public @interface MyAnnotation {
       String value() default "hello";
   }
   ```

   Target:指定被修饰的Annotation能用于修饰那些程序元素

   Document：表示所修饰的注解被javadoc解析时被提取成文档

   Inherited:被它修饰的Annotation将具有继承性。

   

   一般只使用前两个注解。

6. JDK8新特性

   * 可重复注解（略）
   * 类型注解（略）

#### 泛型

1. 泛型类

   * 如果定义了泛型类没有指定泛型类型，则认为泛型类型为Object类型。

     示例：

     ``` java
     public class MyClass<T> {
         String a;
         T tdata;
         public MyClass(){
     
         }
         public MyClass(String a, T data){
             this.a = a;
             tdata = data;
         }
     }
     ```

   * 泛型类的继承

     * 子类继承父类时指明了泛型类型，则不再需要指明泛型

       ```java
       public class B<T> extends A<String>{
           public B(){
           }
       }
       ```

     * 子类继承父类时没有指明泛型类型，则需要指明泛型类型。

       ``` java
       public class B<T> extends A<T>{
           public B(){
           }
       }
       ```

     * ``` java
       class Father<T1, T2>{
           
       }
       //1)没有类型 擦除
       class Son1 extends Father{//等价于class Son1 extends Father<Object, Object>{}
       }
       //2)具体类型
       class Son2 extends Father<Integer, String>{}
       //3) 全部保留
       class Son3<T1,T2> extends Father<T1, T2>{}
       //4)部分保留
       class Son4<T2> extends Father<Integer, T2>{}
       //5) 部分保留
       class Son5<T2, A> extends Father<Integer, T2>{}
       
       ```

   * 静态方法中不能使用泛型类型。（泛型类在构造时才确定，静态方法确定早于类的构造）

   * 异常类不能使用泛型。

   * 新建T类型数组

     ``` java
     //T []arr = new T[10];编译不通过
     T []arr = (T [])new Object[10];
     ```

     

2. 泛型接口

3. 泛型方法

   ``` java
   public class MyClass {
       public <E> E foo(E a){
           return a;
       }
   }
   ```

   * 泛型方法可以是静态的（泛型参数是调用时确定的，并非实例化是确定的）

4. 通配符

   通配符：？

   类A是类B的父类，G<A> 和G<B>是没有关系的，二者的共同父类时G<?>

   示例：

   ``` java
   //本方法遍历打印任何List<T>类型的数据
   public void print(List<?> list){
       Iterator<?> iter = list.iterator();
       while(iterator.hasNext()){
           Object obj = iter.next();
           System.out.println(obj);
       }
   }
   ```

   * 通配符类型写入：对于类似List<?>就不能向内添数据，除非null
   * 通配符类型获取：允许读，读取的数据类型为Object

5. 有限制条件的通配符

   <? extends Number>: 只允许泛型为Number及Number子类的引用调用。

   <? super Number>: 只允许泛型为Number及Number父类的引用调用

   <? extends Comparable> :只允许泛型为实现Comparable接口的实现类的引用调用。

#### File类 

获取当前类路径：

```java
//EmailTaskApplicationTest是当前运行的类
EmailTaskApplicationTests.class.getClassLoader().getResourceAsStream("1.jpg")
```

File 类的一个对象，代表一个文件或者文件夹。File类声明在java.io下。

1. File类的构造

   ``` java
   public class Main {
       public static void main(String []args){
           //1.构造器1
           File file1 = new File("hello.txt");//相对路径
           File file2 = new File("D:\\Java\\hello.txt");//绝对路径
   
           //2.构造器2
           File file3 = new File("D:\\Java", "hello.txt");
   
           //3.构造器3
           File file4 = new File(new File("D:\\Java"), "hello.txt");
   
       }
   }
   ```

2. File类的功能

   * 获取功能

     ``` java
     public String getAbsolutePath(); //获取绝对路径
     public String getPath(); //获取路径
     public String getName(); //获取名称
     public String getParent(); //获取上层文件目录路径，若无返回null
     public long length(); //获取文件长度（字节数）
     public long lastModified(); //获取最后一次修改时间，毫秒值
     public String[] list(); //获取目录下的所有文件或者文件目录的名称数组
     public File[] listFiles();//获取指定目录下的所有文件或者文件目录的File数组
     ```

   * 判断功能

     ``` java
     public boolean isDirectory(); //判断是否是文件目录
     public boolean isFile();//判断是否是文件
     public boolean exists();//判断是否存在
     public boolean canRead();//判断是否可读
     public boolean canWrite();//盘点是否可写
     public boolean isHidden(); //判断是否隐藏
     ```

   * 创建和删除

     ``` java
     public boolean createNewFile();//穿件文件，若文件存在则不创建，返回false
     public boolean mkdir(); //创建文件目录，若此目录不存在，就不创建了返回false
     public boolean mkdirs();//创建文件目录，如果上层文件目录不存在，一并创建
     public boolean delete(); //删除文件或者文件夹（不走回收站）
     
     ```

     

#### IO流

按照操作数据单位的不同分为：字节流（8bi），字符流（16bit).

| 抽象基类 |    字节流    | 字符流 |
| :------: | :----------: | :----: |
|  输入流  | InputStream  | Reader |
|  输出流  | OutputStream | Writer |

1. 流的体系结构

   |   抽象基类   |  节点流(文件流)  | 缓冲流               |
   | :----------: | :--------------: | -------------------- |
   | InputStream  | FileInputStream  | BufferedInputStream  |
   | OutputStrean | FileOutputStream | BufferedOutputStream |
   |    Reader    |    FileReader    | BufferedReader       |
   |    Writer    |    FileWriter    | BufferedWriter       |

   字符流读操作示例：

   ``` java
   public class Main {
       public static void main(String[] args){
           FileReader reader = null;
           try{
               reader = new FileReader(new File("D:\\hello.txt"));
               int data = reader.read();
               //int len = reader.read(char []);
               while (data != -1){
                   System.out.println((char)data);
                   data = reader.read();
               }
           }catch(IOException e){
               e.printStackTrace();
           }finally {
               if (reader != null){
                   try {
                       reader.close();
                   } catch (IOException e) {
                       e.printStackTrace();
                   }
               }
           }
   
       }
   }
   ```

   字符流写操作示例

   ``` java
   //本示例未做异常处理
   public class Main {
       public static void main(String[] args) throws IOException {
           FileWriter writer = new FileWriter(new File("D:\\hello.txt"));
           writer.write("Hello World!");
           writer.close();
       }
   }
   ```

   说明：

   * 输出操作： 对应的File可以不存在。
   * File对应的硬盘文件如果不存在，在输出的过程中，会自动创建此文件。
   * File对应的硬盘中的文件如果存在：
     * 如果流使用的构造器是：FileWriter(file, false)/FileWriter(file), 对原有文件的覆盖
     * FileWriter(file, true):对原有文件的追加内容

   字节流读操作

   ``` java
   public class Main {
       public static void main(String[] args) throws IOException {
           FileInputStream inputStream = new FileInputStream(new File("D:\\hello.txt"));
           byte[] bytes = new byte[8];//8个字节
           int len;
           while((len = inputStream.read(bytes)) != -1){
               String str = new String(bytes, 0, len);
               System.out.println(str);
           }
           inputStream.close();
       }
   }
   ```

2. 转换流

   * 转换流：属于字符流

     InputStreamReader:将一个字节输入流转换为字符的输入流

     OutputStreamWriter:将一个字符的输出流转换为字节的输出流

   使用举例

   ``` java
   public class Main {
       public static void main(String[] args) throws IOException {
           FileInputStream inputStream = new FileInputStream(new File("D:\\hello.txt"));
           InputStreamReader isr = new InputStreamReader(inputStream, "UTF-8");
           char []cbuf = new char[20];
           int len;
           while((len = isr.read(cbuf)) != -1){
               String str = new String(cbuf, 0, len);
               System.out.println(str);
           }
           isr.close();
       }
   }
   ```

#### 反射

反射主要API

* java.lang.Class: 代表一个类
* java.lang.reflect.Method:代表类的方法
* java.lang.reflect.Field:代表类的成员变量
* java.lang.reflect.Constructor:代表类的构造器

疑问1：通过直接new的方式或反射的方式都可以调用公共的结构，开发中到底用哪个？

建议：直接new。

什么时候用反射？反射的特征：动态性。

1. 关于java.lang.Class类的理解：

   * 类的加载过程：

     程序经过javax.exe命令后，会生成一个或多个字节码文件。接着我们使用java.exe命令对某字节码文件进行解释运行。相当于将某个字节码文件加载到内存中。此过程就称为类的加载。加载到内存中的类，我们就称为运行时的类，此运行时类，就作为Class的一个实例。

2. 获取Class实例的方式

   ``` java
   public class Main {
       public static void main(String[] args) throws IOException, ClassNotFoundException {
           //方式一：调用运行时类的属性： .class
           Class clazz1 = Person.class;
   
           //方式二：通过运行时类的对象，调用getClass()
           Person p1 = new Person();
           Class clazz2 = p1.getClass();
   
           //方式三：调用Class的静态方法：forName(String classPath)
           Class clazz3 = Class.forName("com.java.Person");
           
            //方式四：使用类的加载器
           ClassLoader loader = Main.class.getClassLoader();
           Class clazz4 = loader.loadClass("com.java.Person");
       }
   }
   ```

3. 可以有Class对象的类型

   * class

     外部类、成员（成员内部类，静态内部类），局部内部类，匿名内部类

   * interface:接口

   * []：数组(只要是数组的类型和维度一样，就是一个Class)

   * enum:枚举

   * annotation:注解

   * primitive type：基本数据类型

   * void

4. 读取配置文件

   ``` java
   public class Main {
       public static void main(String[] args) throws IOException, ClassNotFoundException {
           Properties pros = new Properties();
           //读取配置文件的方式一
           //此时文件默认在当前的module下
           FileInputStream fis = new FileInputStream("a.properties");
           pros.load(fis);
           
           //读取配置文件的方式二：
           //配置文件默认识别为：当前module的src下
           ClassLoader classLoader = Main.class.getClassLoader();
           InputStream is = classLoader.getResourceAsStream("a.properties");
           
       }
   }
   ```

5. Class类获取运行时类各种信息

   1. `Field[] getFields()`:获取当前运行时类及其父类中声明为public访问权限的属性

   2. `Field getField(String)`:返回反映此 `Class` 对象所表示的类或接口的指定公共成员字段。

   3. `Field[] getDeclaredFields()`:获取当前运行时类中声明的所有属性。（不包含父类中声明属性）

   4. `Field getDeclaredField(String )`:返回一个 `Field` 对象，该对象反映此 `Class` 对象所表示的类或接口的指定已声明字段。

   5. `Method []getMethods()`:获取当前运行时类及其所有父类中声明为public权限的方法

   6. `Method[] getDeclaredMethods`:获取当前运行时类中声明的所有方法。

   7. `public Constructor<T> getConstructor(Class<?>... parameterTypes)`:返回一个 Constructor 对象，它反映此 Class 对象所表示的类的指定公共构造方法(声明为public)

   8. `public Constructor<?>[] getConstructors()`:返回一个包含某些 `Constructor` 对象的数组，这些对象反映此 `Class`  对象所表示的类的所有公共构造方法。(声明为public)

   9. `getDeclaredConstructors`:获取当前运行时类中声明的所有的构造器。

   10. `Class getSuperclass()`:获取运行时类的父类

   11. `Type getGenericSuperclass()`:获取运行时类带泛型的父类。

   12. 获取运行时类的带泛型父类的泛型：

       ``` java
       //此块为功能型代码，不必深究
       Class clazz = Person.class;
       //获取带泛型的父类
       Type genericSuperclass = clazz.getGenericSuperclass();
       ParameterizedType paramType = (ParameterizedType) genericSuperclass;
       //获取泛型数组
       Type[] actualTypeArguments = paramType.getActualTypeArguments();
       ```

   13. `Class [] getInterfaces()`:获取运行时类实现的接口。

   14. `Package getPackage()`:获取运行时类所在包

   15. `Annotation[] getAnnotations()`:获取运行时类的注解。

6. Field

   1. 获取权限修饰符

      ``` java
      //权限修饰符
      int modifier = field.getModifiers();//为一整数
      Modifier.toString(modifier);//将整数代表的权限转换成字符串
      ```

   2. 获取数据类型

      ``` java
      //数据类型
      Class type = field.getType();
      ```

   3. 获取变量名

      ``` java
      //变量名
      field.getName();
      ```

   4. 设置指定属性名

      ``` java
      public class Main {
          public static void main(String[] args) throws IOException, ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchFieldException {
              Class<Person> clazz = Person.class;
              
              Person obj = clazz.newInstance();//clazz.getDeclaredConstructor().newInstance();
              //获取私有属性
              Field gender = clazz.getDeclaredField("gender");
              //设置私有属性为可更改
              gender.setAccessible(true);
              //修改属性
              gender.set(obj, "男");
      
          }
          class Person{
              public Person(){
      
              }
              public int age;
              private String gender;
          }
      }
      ```

   5. 调用指定方法

      ``` java
      public class Main {
          public static void main(String[] args) throws IOException, ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchFieldException, NoSuchMethodException, InvocationTargetException {
              Class<Person> clazz = Person.class;
      
              Person obj = clazz.newInstance();//clazz.getDeclaredConstructor().newInstance()
              Method foo = clazz.getDeclaredMethod("foo");
              //保证该方法是可访问的
              foo.setAccessible(true);
              //调用
              foo.invoke(obj, "hello");
              /*
              如果foo是静态方法
              foo.invoke(Person.class, "hellow");
               */
          }
          class Person{
              public Person(){
      
              }
              private void foo(String x){
                  System.out.println(x);
      
              }
              private String gender;
          }
      }
      ```

   6. 调用运行时类的构造器

      ``` java
      public class Main {
          public static void main(String[] args) throws IOException, ClassNotFoundException, IllegalAccessException, InstantiationException, NoSuchFieldException, NoSuchMethodException, InvocationTargetException {
              Class<Person> clazz = Person.class;
      
              Person obj = clazz.newInstance();//clazz.getDeclaredConstructor().newInstance()
              Constructor constructor = clazz.getDeclaredConstructor(String.class, int.class);
              constructor.setAccessible(true);
              Person person = (Person) constructor.newInstance("Tom", 10);
          }
          class Person{
              public Person(){
      
              }
              private Person(String a, int b){
                  //TO DO
              }
          }
      }
      ```

      

7. Method类

   1. 获取注解

      ``` java
      Annotation[] annotation = method.getAnnotations();
      ```

   2. 获取方法权限修饰符

      ``` java
      Modifier.toString(method.getModifies());
      ```

   3. 获取返回值类型

      ``` java
      method.getReturnType().getName();
      ```

   4. 获取方法名

      ``` java
      method.getName();
      ```

   5. 获取形参列表

      ``` java
      Class []parameterTypes = method.getParameterTypes();
      parameterTypes
      ```

   6. 获取抛出的异常

      ``` java
      Class[] exceptionTypes = metho.getExceptions()
      ```

      

#### 单例

1. 懒汉式

   ``` java
   public class Singleton {  
       private static Singleton instance;  
       private Singleton (){}  
       public static synchronized Singleton getInstance() {  
       if (instance == null) {  
           instance = new Singleton();  
       }  
       return instance;  
       }  
   }
   ```

2. 饿汉式

   ``` java
   public class Singleton {  
       private static Singleton instance = new Singleton();  
       private Singleton (){}  
       public static Singleton getInstance() {  
       return instance;  
       }  
   }
   ```

   