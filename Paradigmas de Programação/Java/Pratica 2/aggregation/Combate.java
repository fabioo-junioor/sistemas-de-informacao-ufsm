package aggregation;
public class Combate{
    private Lutador desafiado;
    private Lutador desafiante;
    int rounds;

    public void marcarLuta(Lutador l1, Lutador l2, int rounds){
        if (l1.getCategoria() == l2.getCategoria()) {
            if(l1 != l2){
               this.desafiado = l1;
               this.desafiante = l2;
               System.out.println("O combate ocorreu entre " + l1.getNome() + " e " + l2.getNome());
               System.out.println("Teve duracao de " + rounds + " rounds");
            
            } else {
                System.out.println("Informe lutadores diferentes! ");
           
            }
        }else{
            this.desafiado = null;
            this.desafiante = null;
            System.out.println("Os lutadores nao sao do mesmo peso! ");
       
        }
    }
    public Lutador getDesafiado() {
        return desafiado;
    }

    public void setDesafiado(Lutador desafiado) {
        this.desafiado = desafiado;
    }

    public Lutador getDesafiante() {
        return desafiante;
    }

    public void setDesafiante(Lutador desafiante) {
        this.desafiante = desafiante;
    }

    public int getRounds() {
        return rounds;
    }

    public void setRounds(int rounds) {
        this.rounds = rounds;
    }
} 