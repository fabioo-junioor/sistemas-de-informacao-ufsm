package com.gdx.rush.Telas;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.ScreenAdapter;
import com.badlogic.gdx.graphics.Texture;
import com.badlogic.gdx.graphics.g2d.TextureRegion;
import com.badlogic.gdx.scenes.scene2d.InputEvent;
import com.badlogic.gdx.scenes.scene2d.InputListener;
import com.badlogic.gdx.scenes.scene2d.Stage;
import com.badlogic.gdx.scenes.scene2d.ui.Image;
import com.badlogic.gdx.scenes.scene2d.ui.ImageButton;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.ScreenUtils;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.gdx.rush.Rush;

public class MainMenuScreen extends ScreenAdapter {

    private Rush game;
    private Stage stage;

    // Texturas e imagens
    private Texture playB;
    private Texture playPressedB;

    Image backgroundImage;

    public MainMenuScreen (Rush game) {
        this.game = game;
    }

    @Override
    public void show() {

        stage = new Stage(new FitViewport(800, 400)); // Transformar em constantes
        Gdx.input.setInputProcessor(stage);

        backgroundImage = new Image(new Texture(Gdx.files.internal("MainMenuBackground.png"))); // Transformar em constante
        stage.addActor(backgroundImage);

        // Botoes //

        playB = new Texture(Gdx.files.internal("PlayButton.png"));
        playPressedB = new Texture("PlayButton.png");
        ImageButton playButton = new ImageButton(
                new TextureRegionDrawable(new TextureRegion(playB)),
                new TextureRegionDrawable(new TextureRegion(playPressedB)));
        playButton.setPosition(400, 200); // Transformar em constantes
        playButton.addListener(new InputListener() {
            @Override
            public boolean touchDown (InputEvent event, float x, float y, int pointer, int button) {
                super.touchDown(event, x, y, pointer, button);

                game.setScreen(new LevelSelectionScreen(game)); // n sera aqui!!
                return true;
            }
        });

        stage.addActor(playButton);
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
