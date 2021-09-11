package com.gdx.rush.Sprites;

import com.badlogic.gdx.graphics.g2d.Animation;
import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Body;
import com.badlogic.gdx.physics.box2d.BodyDef;
import com.badlogic.gdx.physics.box2d.CircleShape;
import com.badlogic.gdx.physics.box2d.FixtureDef;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.utils.Array;
import com.gdx.rush.Rush;
import com.gdx.rush.Telas.MainMenuScreen;
import com.gdx.rush.Telas.Player;
import com.gdx.rush.Telas.Visao;

public class Estudante extends Sprite {
    private enum State {pulo, estado, queda, caminha}
    public World mundo;
    public Body corpo2;
    private TextureRegion estadoPerson;

    public State estadoAtual;
    public State estadoAnterior;
    private Animation estudantePulo;
    private Animation estudanteCaminha;

    private int livros;
    private float tp;

    public Estudante(World mundo, Player person){
        super(person.getPerson().findRegion("running-1"));
        this.mundo = mundo;
        this.livros = 0;
        criaPerson();
        criaTexturaPerson();
        criaMovimentoPerson();

        estadoAtual = State.estado;
        estadoAnterior = State.estado;
        tp = 0;

    }
    public void criaPerson(){
        BodyDef defCorpo = new BodyDef();
        defCorpo.position.set(210/ Rush.pixelMinuto,32/ Rush.pixelMinuto);
        defCorpo.type = BodyDef.BodyType.DynamicBody;
        corpo2 = mundo.createBody(defCorpo);

        FixtureDef fixtureDef = new FixtureDef();
        CircleShape shape = new CircleShape();
        shape.setRadius(4/ Rush.pixelMinuto);
        fixtureDef.shape = shape;
        corpo2.createFixture(fixtureDef);

    }
    public State getState(){
        if((corpo2.getLinearVelocity().y > 0 && estadoAtual == State.pulo)||(corpo2.getLinearVelocity().y < 0 && estadoAnterior == State.pulo)){
            return State.pulo;
        }
        if(corpo2.getLinearVelocity().y < 0){
            return State.queda;
        }
        if(corpo2.getLinearVelocity().x != 0){
            return State.caminha;
        }
        return  State.estado;
    }

    public void pulo(){
        if(estadoAtual != State.pulo){
            corpo2.applyLinearImpulse(new Vector2(0, 4f), corpo2.getWorldCenter(), true);
            estadoAtual = State.pulo;
        }
    }

    public void update(float deltaTime){
        setPosition(corpo2.getPosition().x - getWidth()/2, corpo2.getPosition().y - getHeight()/2);
        setRegion(getDist(deltaTime));
    }

    public void criaTexturaPerson(){
        estadoPerson = new TextureRegion(getTexture(), 0, 0, 41, 70);
        setBounds(0, 0, 16/Rush.pixelMinuto, 20/Rush.pixelMinuto);
        setRegion(estadoPerson);
    }

    public void criaMovimentoPerson(){
        Array<TextureRegion>  dist = new Array<TextureRegion>();
        for (int i=0; i<4; i++){
            dist.add(new TextureRegion(getTexture(), i*64, 0, 42, 70));
        }
        estudanteCaminha = new Animation(0.1f, dist);
        dist.clear();

        for (int i=0; i<4; i++){
            dist.add(new TextureRegion(getTexture(), 0, 0, 42, 70));
        }
        estudantePulo = new Animation(0.1f, dist);
    }

    public TextureRegion getDist(float deltaTime){
        estadoAtual = getState();
        TextureRegion regiao;
        switch (estadoAtual){
            case pulo: regiao = (TextureRegion) estudantePulo.getKeyFrame(tp);
                break;
            case caminha: regiao = (TextureRegion) estudanteCaminha.getKeyFrame(tp, true);
                break;
            case queda:
            default: regiao = estadoPerson;
                break;

        }
        if(estadoAtual == estadoAnterior){
            tp = tp + deltaTime;
        }else{
            tp = 0;
        }
        estadoAnterior = estadoAtual;
        return regiao;
    }

    public boolean gameOver(){
        return ((corpo2.getPosition().y < 0)&&(corpo2.getPosition().y > -0.1));
    }
    public boolean wins(){
        return((corpo2.getPosition().x > 38.0) && (corpo2.getPosition().x < 38.1));
    }

    public int getLivros(){
        return livros;
    }
    public void updateLivros(){
        this.livros++;
    }
}
