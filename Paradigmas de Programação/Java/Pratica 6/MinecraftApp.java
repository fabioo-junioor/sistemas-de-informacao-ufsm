
package sexta;

import java.util.ArrayList;
import java.util.List;

public class MinecraftApp {
    
    public static void main(String[] args) {
      ArrayList<Bloco> lista = new ArrayList<Bloco>();
      Terra t = new Terra();
      Grama g = new Grama();
      lista.add(t);
      lista.add(g);
      lista.add(g);
      lista.add(t);
      for(Bloco b1: lista) {
          b1.getNome();
          System.out.println("Bloco " + b1.nome + " adicionado");
      }
    }
}
