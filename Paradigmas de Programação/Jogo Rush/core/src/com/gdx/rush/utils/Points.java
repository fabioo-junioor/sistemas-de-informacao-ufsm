package com.gdx.rush.utils;

import com.gdx.rush.Sprites.Estudante;

import static java.lang.Math.*;

public class Points {

    private Estudante player;
    private float rightProba;
    private float wrongProba;

    public Points (Estudante player) {
        this(player, 0.9f, 0.8f);
    }

    public Points (Estudante player, float rightProba, float wrongProba) {
        this.player = player;
        this.rightProba = rightProba; // Probabilidade de acertar as questoes que o aluno sabe
        this.wrongProba = wrongProba; // Probabilidade de errar as questoes que o aluno nao sabe
    }

    public float calcNota (int nQuestions, int nLivros) {
        float ratio = (float) player.getLivros() / (float) nLivros; // Ter tds os livros significa saber todas questoes

        System.out.println("livros: " + player.getLivros());
        System.out.println("livros: " + ratio);

        int diff = 0;
        int rightAnswers = (int) ceil(ratio * nQuestions); // Calculo de quantas questoes o aluno sabe
        int wrongAnswers = nQuestions - rightAnswers;

        System.out.println("certas: " + rightAnswers);

        double right = random();
        if (right > rightProba) { // Calculo para saber se o aluno errou alguma questao que ele sabia
            diff = (int) floor(rightAnswers * rightProba) - rightAnswers;
        }

        double wrong = random();
        if (wrong > wrongProba) { // Calculo para saber se o aluno acertou alguma questao que ele nao sabia
            diff += wrongAnswers - (int) floor(wrongAnswers * wrongProba);
        }

        rightAnswers += diff;

        return ((float) rightAnswers / (float) nQuestions)*10;
    }


}
