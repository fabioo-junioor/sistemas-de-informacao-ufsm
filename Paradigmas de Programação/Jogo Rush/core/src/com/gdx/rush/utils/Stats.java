package com.gdx.rush.utils;

import com.badlogic.gdx.Gdx;
import com.badlogic.gdx.Preferences;

public class Stats {

    Preferences notas;

    public Stats () {
        this.notas = Gdx.app.getPreferences("notas");
    }

    public void setNota (int level, float nota) {
        String notaStr = "level_" + level;

        this.notas.putFloat(notaStr + "_nota", nota);
    }

    public float getNota (int level) {
        String notaStr = "level_" + level + "_nota";

        return this.notas.getFloat(notaStr);
    }

    public boolean exame (int levelExame) {
        float nota = 0.0f;
        int level;
        for (int i = 1; i < 4; i++) {
            level = levelExame-i;
            if (this.notas.getFloat("level_" + level + "_nota", -1.0f) == -1.0f) {
                return false;
            }
            nota += this.notas.getFloat("level_" + level + "_nota");
        }
        return nota / 3.0f < 7.0f;
    }

    public void save () {
        this.notas.flush();
    }




}
