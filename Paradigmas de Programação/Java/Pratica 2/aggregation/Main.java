package aggregation;
public class  Main{
    public static void main(String[] args) {
       Lutador l1 = new Lutador("joao", 30, 55.0f, 1.60f);
       Lutador l2 = new Lutador("carlos", 25, 75.0f, 1.70f);
       Lutador l3 = new Lutador("patrick", 31, 57.0f, 1.65f);

       Combate A22 = new Combate();
       A22.marcarLuta(l1, l3, 5); 
    }    
}