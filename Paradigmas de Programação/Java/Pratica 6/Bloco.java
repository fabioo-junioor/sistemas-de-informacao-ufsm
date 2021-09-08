
package sexta;

import java.util.ArrayList;
import java.util.List;

public abstract class Bloco {
    public String nome;
    boolean b;
    public abstract String getNome();
    public List<Bloco> Bloco(boolean b) {
        List<Bloco> lista = new ArrayList<>();
        return lista;
    }
}