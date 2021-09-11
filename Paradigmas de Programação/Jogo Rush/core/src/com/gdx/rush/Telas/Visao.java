package com.gdx.rush.Telas;

import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.SpriteBatch;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.utils.Disposable;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;
import sun.font.Decoration;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.gdx.rush.Rush;

import java.awt.EventQueue;


public class Visao implements Disposable {
    public Stage stage;
    private Viewport visaoJogador;

    private static int pontos;
    private int tempo;
    private float count;
    private boolean fim;

    private static Label pontosLabel;
    private Label regressiva;

    public Visao(SpriteBatch spriteBatch, int tempo){
        this.pontos = 0;
        this.tempo = tempo;
        fim = false;
        visaoJogador = new FitViewport(Rush.largura, Rush.altura, new OrthographicCamera());
        stage = new Stage(visaoJogador, spriteBatch);

        Table table = new Table();
        table.top();
        table.setFillParent(true);

        regressiva = new Label(Integer.toString(this.tempo), new Label.LabelStyle(new BitmapFont(), Color.BLACK));
        pontosLabel = new Label(Integer.toString(this.pontos), new Label.LabelStyle(new BitmapFont(), Color.BLACK));

        table.add(pontosLabel).expand().padTop(-180);
        table.add(regressiva).expand().padTop(-180);

        stage.addActor(table);
    }

    public void setPontos(int valor){
        if(valor != 0) {
            pontos += valor;
            pontosLabel.setText(Integer.toString(this.pontos));
        }else{
            pontos = 0;
            pontosLabel.setText(Integer.toString(this.pontos));
        }
    }

    public void run(float deltaTime){
            count += deltaTime;
            if(count >= 1){
                if(tempo > 0){
                    tempo--;
                }else{
                    fim = true;
                    tempo = 0;
                    System.out.println("ACABOU O TEMPO!");
                }
                regressiva.setText(Integer.toString(this.tempo));
                count = 0;
            }
    }

    @Override
    public void dispose() {
        stage.dispose();

    }

    public boolean isFim() {
        return fim;
    }

    public void setFim(boolean fim) {
        this.fim = fim;
    }
}
