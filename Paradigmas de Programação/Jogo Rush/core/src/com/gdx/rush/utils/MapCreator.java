package com.gdx.rush.utils;

import com.badlogic.gdx.maps.Map;
import com.badlogic.gdx.maps.MapObject;
import com.badlogic.gdx.maps.objects.RectangleMapObject;
import com.badlogic.gdx.maps.tiled.TiledMap;
import com.badlogic.gdx.maps.tiled.TmxMapLoader;
import com.badlogic.gdx.maps.tiled.renderers.OrthoCachedTiledMapRenderer;
import com.badlogic.gdx.math.Rectangle;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.*;
import com.gdx.rush.Rush;

public class MapCreator {

    private TmxMapLoader carregarMapa;

    public MapCreator () {
        carregarMapa = new TmxMapLoader();
    }

    public TiledMap carregaMapa (int level) {
        if (level == 1) {
            return carregarMapa.load("map1.tmx");
        } else if (level == 2) {
            return carregarMapa.load("map1.tmx");
        } else if (level == 3) {
            return carregarMapa.load("map4.tmx");   //stop
        } else if (level == 4) {
            return carregarMapa.load("map4.tmx");
        } else {
            return carregarMapa.load("map4.tmx");
        }
    }

    public OrthoCachedTiledMapRenderer carregaRenderizador (TiledMap mapa) {
        return carregaRenderizador(mapa, 1 / Rush.pixelMinuto);
    }

    public OrthoCachedTiledMapRenderer carregaRenderizador (TiledMap mapa, float escala) {
        return new OrthoCachedTiledMapRenderer(mapa, escala);
    }

    public World CriaMundo (TiledMap map, int level) {

        World mundo = new World(new Vector2(0, -10), true);
        Body corpo;
        BodyDef defCorpo = new BodyDef();
        PolygonShape shape = new PolygonShape();
        FixtureDef fixtureDef = new FixtureDef();

        if((level == 1)||(level == 2)) {
            for (MapObject obj : map.getLayers().get(2).getObjects().getByType(RectangleMapObject.class)) {
                Rectangle retangulo = ((RectangleMapObject) obj).getRectangle();

                defCorpo.type = BodyDef.BodyType.StaticBody;
                defCorpo.position.set((retangulo.getX() + retangulo.getWidth() / 2) / Rush.pixelMinuto, (retangulo.getY() + retangulo.getHeight() / 2) / Rush.pixelMinuto);

                corpo = mundo.createBody(defCorpo);
                shape.setAsBox((retangulo.getWidth() / 2) / Rush.pixelMinuto, (retangulo.getHeight() / 2) / Rush.pixelMinuto);
                fixtureDef.shape = shape;
                corpo.createFixture(fixtureDef);
            }

        }else if((level == 3)||(level == 4)) {
            for (MapObject obj : map.getLayers().get(2).getObjects().getByType(RectangleMapObject.class)) {
                Rectangle retangulo = ((RectangleMapObject) obj).getRectangle();

                defCorpo.type = BodyDef.BodyType.StaticBody;
                defCorpo.position.set((retangulo.getX() + retangulo.getWidth() / 2) / Rush.pixelMinuto, (retangulo.getY() + retangulo.getHeight() / 2) / Rush.pixelMinuto);

                corpo = mundo.createBody(defCorpo);
                shape.setAsBox((retangulo.getWidth() / 2) / Rush.pixelMinuto, (retangulo.getHeight() / 2) / Rush.pixelMinuto);
                fixtureDef.shape = shape;
                corpo.createFixture(fixtureDef);
            }
        }

        return mundo;
    }

}
