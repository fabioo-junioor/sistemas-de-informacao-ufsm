import java.util.ArrayList;

class Person {
  protected String name;
  public Person() {
    System.out.println("Construtor de Person");
    name = "Fulano";

  }
  public String getName() {
    return name;

  }
  public void setName(String name) {
    this.name = name;

  }
}

class Student extends Person {
  private String course;
  public Student() {
    System.out.println("Construtor de Student");
    course = "CC";

  }
  public boolean testName(char c) {
    return name.toCharArray()[0] == c;

  }  
}

class PhDStudent extends Student{
    public PhDStudent(){
        System.out.println("Construtor de PhDStudent");

    }
}

class Main {
  public static void main(String[] args) {
    Person p = new Person();
    Student s = new Student();
    PhDStudent ph = new PhDStudent();
    ArrayList<Person> lis = new ArrayList<Person>();
    lis.add(p);
    lis.add(s);
    s.setName("Beltrano");
    for (Person ref: lis) {
      System.out.println(ref.getName());
    }
        s.testName('f');

        System.out.println(p.equals(ph));
        System.out.println(s.equals(ph));        
    }
}