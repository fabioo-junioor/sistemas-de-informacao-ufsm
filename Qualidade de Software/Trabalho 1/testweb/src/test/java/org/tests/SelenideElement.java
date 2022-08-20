/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package org.tests;
import org.testng.annotations.Test;
import static com.codeborne.selenide.Selenide.*;
import static com.codeborne.selenide.Condition.*;
import static com.codeborne.selenide.Selectors.*;
import static org.junit.Assert.assertEquals;
import org.openqa.selenium.By;

/**
 *
 * @author Fabio
 */
public class SelenideElement {
    
    @Test
    public void testSelenideElement(){
        open("http://localhost/sites/element.html");
        $("#btnEnviar").should(visible);        
        
        assertEquals(true, $("#btnEnviar").exists());
        assertEquals("Inglês", $(By.name("idioma")).val());
        assertEquals("Desenvolvedor", $(By.id("vaga")).getSelectedValue());
        
        $("#btnEnviar").pressEnter();
        
        $(By.name("nome")).setValue("Fabio");
        
        $(By.id("vaga")).selectOptionByValue("Suporte de TI");
        
    }
    
    @Test
    public void testSelenideElementFail(){
        open("http://localhost/sites/element.html");        
        assertEquals("Espanhol", $(By.name("idioma")).val());
        assertEquals("Suporte de TI", $(By.id("vaga")).getSelectedValue());
                
    }
    
}
