package com.gdx.rush.Telas;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.ScreenAdapter;
import com.badlogic.gdx.graphics.Color;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.BitmapFont;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.InputListener;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Image;
import com.badlogic.gdx.scenes.scene2d.ui.ImageButton;
import com.badlogic.gdx.scenes.scene2d.ui.Label;
import com.badlogic.gdx.scenes.scene2d.ui.TextField;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.ScreenUtils;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.gdx.rush.Rush;
import com.gdx.rush.Sprites.Estudante;
import com.gdx.rush.utils.Points;
import com.gdx.rush.utils.Stats;

public class GameOver extends ScreenAdapter {

    private Rush game;
    private Estudante player;
    private Stage stage;
    private Points pontuacao;
    private Stats stats;

    // Texturas e imagens
    private Texture menuB;
    private Texture menuPressedB;

    private Label notaLabel;

    Image backgroundImage;

    public int level;

    public GameOver(Rush game, Estudante player, int level){
        this.game = game;
        this.player = player;
        this.level = level;
        this.stats = new Stats();
    }

    @Override
    public void show() {

        stage = new Stage(new FitViewport(800, 400)); // Transformar em constantes
        Gdx.input.setInputProcessor(stage);

        backgroundImage = new Image(new Texture(Gdx.files.internal("MainMenuBackground.png"))); // Transformar em constante
        stage.addActor(backgroundImage);

        // Botoes //

        menuB = new Texture(Gdx.files.internal("PlayButton.png"));
        menuPressedB = new Texture("PlayButton.png");
        ImageButton menuButton = new ImageButton(
                new TextureRegionDrawable(new TextureRegion(menuB)),
                new TextureRegionDrawable(new TextureRegion(menuPressedB)));
        menuButton.setPosition(400, 200); // Transformar em constantes
        menuButton.addListener(new InputListener() {
            @Override
            public boolean touchDown (InputEvent event, float x, float y, int pointer, int button) {
                super.touchDown(event, x, y, pointer, button);

                game.setScreen(new LevelSelectionScreen(game));
                return true;
            }
        });

        stage.addActor(menuButton);

        float nota = stats.getNota(level);
        notaLabel = new Label("NOTA: " + nota, new Label.LabelStyle(new BitmapFont(), Color.BLACK));
        notaLabel.setPosition(400, 300);

        stage.addActor(notaLabel);
    }

    @Override
    public void render(float delta) {
        ScreenUtils.clear(0, 0, 0.2f, 1);
        stage.act(delta);
        stage.draw();
    }

    @Override
    public void resize (int width, int height) {
        super.resize(width, height);
    }

    @Override
    public void dispose() {
        stage.dispose();
    }
}
