package aggregation;
public class Lutador{
    private String nome;
    private int idade;
    private float peso;
    private float altura;
    private String categoria;
    
    public Lutador(String nome, int idade, float peso, float altura){
        this.nome = nome;
        this.idade = idade;
        this.setPeso(peso);
        this.altura = altura;

    }
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        this.peso = peso;
        this.setCategoria();
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        this.altura = altura;
    }

    public String getCategoria() {
        return categoria;
    }

    public void setCategoria() {
        if(this.peso < 50){
            this.categoria = "nulo";

        } else if (this.peso <= 70){
            this.categoria = "leve";

        } else if (this.peso <= 80){
            this.categoria = "medio";

        } else if (this.peso <= 100){
            this.categoria = "pesado";

        } else {
            this.categoria = "nulo";
            
        }
    }    
}