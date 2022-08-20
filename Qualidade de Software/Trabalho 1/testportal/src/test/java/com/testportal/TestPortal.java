/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.testportal;
import static com.codeborne.selenide.Selenide.*;
import static com.codeborne.selenide.Condition.*;
import org.openqa.selenium.By;
import org.testng.annotations.Test;

/**
 *
 * @author fj_01
 */
public class TestPortal {
    String senha = String.format("%d", 131313);
    
    
    @Test
    public void testPortalAluno(){
        open("https://portal.ufsm.br/aluno/");        
        
        $(By.name("j_username")).setValue("201921050");
        $(By.name("j_password")).setValue(senha);
        $(By.name("enter")).pressEnter();
        
        $(("#item_institucional")).click();
        $$("#popup_institucional li a").findBy(text("Biblioteca")).click();
        
        $(By.id("geral")).setValue("qualidade de software");
        $(By.id("search-btn1")).pressEnter();
        
        $$(".table tbody tr td").findBy(text("ABNT NBR ISO/IEC 14598-6 : engenharia de software : "
                + "avaliacao de produto : parte 6 : "
                + "documentacao de modulos de avaliacao /")).should(exist).screenshot();
        
    }
    
    @Test
    public void testPortalAlunoFail(){
        open("https://portal.ufsm.br/aluno/");
        
        $(By.name("j_username")).setValue("201921050");
        $(By.name("j_password")).setValue(senha);
        $(By.name("enter")).pressEnter();
        
        $(("#item_institucional")).click();
        $$("#popup_institucional li a").findBy(text("Biblioteca")).click();
        
        $(By.id("geral")).setValue("qualidade de software");
        $(By.id("search-btn1")).pressEnter();
        
        $$(".table tbody tr td").findBy(text("selenide")).should(exist).screenshot();

        
    }
}
