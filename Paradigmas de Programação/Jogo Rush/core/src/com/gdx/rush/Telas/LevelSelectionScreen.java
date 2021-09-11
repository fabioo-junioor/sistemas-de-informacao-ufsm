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
import com.badlogic.gdx.scenes.scene2d.ui.Table;
import com.badlogic.gdx.scenes.scene2d.utils.TextureRegionDrawable;
import com.badlogic.gdx.utils.Align;
import com.badlogic.gdx.utils.Array;
import com.badlogic.gdx.utils.ScreenUtils;
import com.badlogic.gdx.utils.viewport.FitViewport;
import com.gdx.rush.Rush;
import com.gdx.rush.utils.Stats;
import org.w3c.dom.Text;

import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;

public class LevelSelectionScreen extends ScreenAdapter {

    private Rush game;
    private Stage stage;
    private Table table;

    private String[] mapsList = {"Paradigmas de programacao", "Lab 1", "LA"}; // Array pode vir de outro lugar
    private int level;
    private Stats stats;

    public LevelSelectionScreen (Rush game) {
        this.game = game;
        this.stats = new Stats();
    }

    private void NavigationButtons () {
        Texture navTexture = new Texture(Gdx.files.internal("LeftRightButtons.png"));

        ImageButton leftButton = new ImageButton(
                new TextureRegionDrawable(new TextureRegion(navTexture, navTexture.getWidth()/2, navTexture.getHeight())),
                new TextureRegionDrawable(new TextureRegion(navTexture, navTexture.getWidth()/2, navTexture.getHeight()))
        );
        leftButton.addListener(new InputListener() {
            @Override
            public boolean touchDown (InputEvent event, float x, float y, int pointer, int button) {
                super.touchDown(event, x, y, pointer, button);

                game.setScreen(new MainMenuScreen(game));
                return true;
            }
        });
        leftButton.setPosition(10, 10);
        this.stage.addActor(leftButton);
    }

    @Override
    public void show () {

        this.stage = new Stage(new FitViewport(800, 400)); // Transformar em constantes
        Gdx.input.setInputProcessor(stage);

        Image backgroundImage = new Image(new Texture(Gdx.files.internal("MainMenuBackground.png"))); // Transformar em constante
        this.stage.addActor(backgroundImage);

        NavigationButtons();

        table = new Table();
        table.setWidth(stage.getWidth());
        table.align(Align.center | Align.top);
        table.setPosition(0, 400);

        // Estilo dos botoes

        Texture levelTexture = new Texture(Gdx.files.internal("levelButtons.png"));

        TextureRegionDrawable p1Drawable = new TextureRegionDrawable(new TextureRegion(levelTexture, 0,                           0,
                levelTexture.getWidth()/4, levelTexture.getHeight()));
        TextureRegionDrawable p2Drawable = new TextureRegionDrawable(new TextureRegion(levelTexture, levelTexture.getWidth()/4,   0,
                levelTexture.getWidth()/4, levelTexture.getHeight()));
        TextureRegionDrawable p3Drawable = new TextureRegionDrawable(new TextureRegion(levelTexture, levelTexture.getWidth()*2/4, 0,
                levelTexture.getWidth()/4, levelTexture.getHeight()));
        TextureRegionDrawable exDrawable = new TextureRegionDrawable(new TextureRegion(levelTexture, levelTexture.getWidth()*3/4, 0,
                levelTexture.getWidth()/4, levelTexture.getHeight()));

        level = 1;
        for (int i = 0; i < 1; i++) {
            final ImageButton p1Button = new ImageButton(p1Drawable, p1Drawable);
            p1Button.setName(Integer.toString(level));
            p1Button.addListener(new InputListener() {
                @Override
                public boolean touchDown (InputEvent event, float x, float y, int pointer, int button) {
                    super.touchDown(event, x, y, pointer, button);
                    game.setScreen(new Player(game, Integer.parseInt(event.getListenerActor().getName())));
                    return true;
                }
            });
            level++;

            ImageButton p2Button = new ImageButton(p2Drawable, p2Drawable);
            p2Button.setName(Integer.toString(level));
            p2Button.addListener(new InputListener() {
                @Override
                public boolean touchDown (InputEvent event, float x, float y, int pointer, int button) {
                    super.touchDown(event, x, y, pointer, button);
                    game.setScreen(new Player(game, Integer.parseInt(event.getListenerActor().getName())));
                    return true;
                }
            });
            level++;

            ImageButton p3Button = new ImageButton(p3Drawable, p3Drawable);
            p3Button.setName(Integer.toString(level));
            p3Button.addListener(new InputListener() {
                @Override
                public boolean touchDown (InputEvent event, float x, float y, int pointer, int button) {
                    super.touchDown(event, x, y, pointer, button);
                    game.setScreen(new Player(game, Integer.parseInt(event.getListenerActor().getName())));
                    return true;
                }
            });
            level++;

            table.add(p1Button).pad(10);
            table.add(p2Button).pad(10);
            table.add(p3Button).pad(10);

            if (stats.exame(level)) {
                ImageButton exButton = new ImageButton(exDrawable, exDrawable); // Botao so sera desenhado a partir de um condicao
                exButton.setName(Integer.toString(level));
                exButton.addListener(new InputListener() {
                    @Override
                    public boolean touchDown(InputEvent event, float x, float y, int pointer, int button) {
                        super.touchDown(event, x, y, pointer, button);
                        game.setScreen(new Player(game, Integer.parseInt(event.getListenerActor().getName())));
                        return true;
                    }
                });
                table.add(exButton).pad(10);
            }
            level++;

            table.row();
        }

        stage.addActor(table);
    }

    @Override
    public void render (float delta) {
        ScreenUtils.clear(0, 0, 0.2f, 1);
        this.stage.act(delta);
        this.stage.draw();
    }

    @Override
    public void resize (int width, int height) {
        super.resize(width, height);
    }

    @Override
    public void dispose () {
        stage.dispose();
    }
}
