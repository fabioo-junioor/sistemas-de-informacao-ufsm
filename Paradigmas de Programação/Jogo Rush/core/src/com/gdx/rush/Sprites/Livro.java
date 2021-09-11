package com.gdx.rush.Sprites;

import com.badlogic.gdx.graphics.g2d.Sprite;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.*;
import com.gdx.rush.Rush;
import com.gdx.rush.Telas.Player;

public class Livro extends Sprite {
    private enum State {subindo, descendo}

    public World mundo;
    public Body corpo2;

    private State state;

    private TextureRegion texture;

    public Livro (World mundo, Player person, int pos) {
        super(person.getBook().findRegion("antique-book"));
        this.mundo = mundo;



        state = State.descendo;

        criaLivro(pos);
        criaTexturaLivro();
    }

    public void criaLivro(int pos){
        BodyDef defCorpo = new BodyDef();
        defCorpo.position.set(pos/ Rush.pixelMinuto,115/ Rush.pixelMinuto);
        defCorpo.type = BodyDef.BodyType.DynamicBody;
        corpo2 = mundo.createBody(defCorpo);

        FixtureDef fixtureDef = new FixtureDef();
        CircleShape shape = new CircleShape();
        shape.setRadius(4/ Rush.pixelMinuto);
        fixtureDef.shape = shape;
        corpo2.createFixture(fixtureDef);
    }

    public void criaTexturaLivro(){
        texture = new TextureRegion(getTexture(), 0, 0, 59, 61);
        setBounds(0, 0, 16/Rush.pixelMinuto, 20/Rush.pixelMinuto);
        setRegion(texture);
    }

    public Vector2 move() {
        if (corpo2.getLinearVelocity().y <= -2.0f) {
            state = State.subindo;
        } else if (corpo2.getLinearVelocity().y >= 2.0f) {
            state = State.descendo;
        }
        if (state == State.subindo) {
            return new Vector2(0, 0.4f);
        }
        return new Vector2(0, 0);
    }

    public void update(){
        setPosition(corpo2.getPosition().x - getWidth()/2, corpo2.getPosition().y - getHeight()/2);
    }

}