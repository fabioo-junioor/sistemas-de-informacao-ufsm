package com.gdx.rush.Telas;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Input;
import com.badlogic.gdx.Screen;
import com.badlogic.gdx.graphics.GL20;
import com.badlogic.gdx.graphics.OrthographicCamera;
import com.badlogic.gdx.graphics.g2d.TextureAtlas;
import com.badlogic.gdx.maps.tiled.TiledMap;
import com.badlogic.gdx.maps.tiled.TmxMapLoader;
import com.badlogic.gdx.maps.tiled.renderers.OrthoCachedTiledMapRenderer;
import com.badlogic.gdx.math.Vector2;
import com.badlogic.gdx.physics.box2d.Box2DDebugRenderer;
import com.badlogic.gdx.physics.box2d.World;
import com.badlogic.gdx.utils.Array;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.badlogic.gdx.utils.viewport.Viewport;
import com.gdx.rush.Rush;
import com.gdx.rush.Sprites.Estudante;
import com.gdx.rush.Sprites.Livro;
import com.gdx.rush.utils.MapCreator;
import com.gdx.rush.utils.Points;
import com.gdx.rush.utils.Stats;

import java.util.Iterator;

public class Player implements Screen {
    private Rush jogo;
    private TextureAtlas person;
    private TextureAtlas book;

    private OrthographicCamera camera;
    private Viewport visaoJogo;

    private MapCreator criadorMapa;
    private TiledMap mapa;
    private OrthoCachedTiledMapRenderer renderizar;

    private Visao visao;
    private Points nota;
    private Stats stats;

    private World mundo;
    private Box2DDebugRenderer debug;
    private Estudante player;
    private Array<Livro> livros;

    public int level;
    public int tempo;

    public Player(Rush jogo, int level){
        person = new TextureAtlas("Pack_Estudante.pack");
        book = new TextureAtlas("Book_book.pack");
        this.jogo = jogo;
        this.level = level;


        tempo = 20 + (level % 2)*(30); // Niveis pares terao metade do tempo para serem completos
        criaVisaoJogo();
        visao = new Visao(jogo.batch, tempo);

        criadorMapa = new MapCreator();
        criaMapa(level);

        mundo = criadorMapa.CriaMundo(mapa, level);
        debug = new Box2DDebugRenderer();

        player = new Estudante(mundo, this);
        nota = new Points(this.player);
        stats = new Stats();

        livros = new Array<Livro>();
        for (int i = 0; i < 4; i++) {
            int pos = 800*i + 500;
            livros.add(new Livro(mundo, this, pos));
        }

    }

    public void criaVisaoJogo(){
        camera = new OrthographicCamera();
        visaoJogo = new FitViewport(Rush.largura/Rush.pixelMinuto, Rush.altura/Rush.pixelMinuto, camera);
    }

    public void criaMapa(int level){
        mapa = criadorMapa.carregaMapa(level);
        renderizar = criadorMapa.carregaRenderizador(mapa);
        camera.position.set(visaoJogo.getWorldWidth() / 2, visaoJogo.getWorldHeight() / 2, 0);
    }

    public void movimentacao(float deltaTime){
        if(Gdx.input.isKeyJustPressed(Input.Keys.W)) {
            player.pulo();
        }
        if(Gdx.input.isKeyPressed(Input.Keys.D)&&player.corpo2.getLinearVelocity().x <= 2){
                player.corpo2.applyLinearImpulse(new Vector2(0.1f, 0), player.corpo2.getWorldCenter(), true);
        }
        if(Gdx.input.isKeyPressed(Input.Keys.A)&&player.corpo2.getLinearVelocity().x >= -2){
            player.corpo2.applyLinearImpulse(new Vector2(-0.1f, 0), player.corpo2.getWorldCenter(), true);
        }

        for (Livro livro : livros) {
            livro.corpo2.applyLinearImpulse(livro.move(), livro.corpo2.getWorldCenter(), true);
        }

    }

    public void update(float deltaTime){
        movimentacao(deltaTime);
        mundo.step(1/60f, 5, 2);

        player.update(deltaTime);
        for (Livro livro : livros) {
            livro.update();
        }
        if (player.gameOver() || visao.isFim()) {
            stats.setNota(level, nota.calcNota(20, 5));
            stats.save();
            jogo.setScreen(new GameOver(jogo, player, level));
        } else if (player.wins()) {
            player.updateLivros();
            stats.setNota(level, nota.calcNota(20, 5));
            stats.save();
            jogo.setScreen(new GameOver(jogo, player, level));
        }

        for (Iterator<Livro> iter = livros.iterator(); iter.hasNext(); ) {
            Livro livro = iter.next();
            if (player.getBoundingRectangle().overlaps(livro.getBoundingRectangle())) {
                visao.setPontos(1);
                player.updateLivros();
                mundo.destroyBody(livro.corpo2);
                iter.remove();
            }
        }

        camera.position.x = player.corpo2.getPosition().x;
        camera.update();
        renderizar.setView(camera);
        visao.run(deltaTime);

    }

    public TextureAtlas getPerson(){
        return person;
    }

    public TextureAtlas getBook(){
        return book;
    }

    @Override
    public void show() {

    }

    @Override
    public void render(float delta) {
        update(delta);
        Gdx.gl.glClearColor(241, 250, 238, 0.9f);
        Gdx.gl.glClear(GL20.GL_COLOR_BUFFER_BIT);
        renderizar.render();

        debug.render(mundo, camera.combined);
        jogo.batch.setProjectionMatrix(visao.stage.getCamera().combined);
        jogo.batch.setProjectionMatrix(camera.combined);
        jogo.batch.begin();
        for (Livro livro : livros) {
            livro.draw(jogo.batch);
        }
        player.draw(jogo.batch);
        jogo.batch.end();
        visao.stage.draw();

    }

    @Override
    public void resize(int width, int height) {
        visaoJogo.update(width, height);
    }

    @Override
    public void pause() {

    }

    @Override
    public void resume() {

    }

    @Override
    public void hide() {

    }

    @Override
    public void dispose() {
        mapa.dispose();
        renderizar.dispose();
        mundo.dispose();
        debug.dispose();
        visao.dispose();

    }
}
