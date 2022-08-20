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
public class TestCondition {
    
    @Test
    public void testConditionForm(){
        open("http://localhost/sites/condition.html");
        
        $(By.id("meuForm")).should(visible);
        $(By.id("meuForm")).should(exist);
        
        $(By.id("nome")).should(name("nome"));
        $(By.id("nome")).should(value("Fabio"));
        $(By.id("nome")).should(type("text"));
        
        $(By.id("email")).should(focused);
        
        $(By.id("email")).should(enabled);
        
        $(By.id("meuParagrafo")).should(textCaseSensitive("Meu texto"));
    }
    
    @Test
    public void testConditionFormFail(){
        open("http://localhost/sites/condition.html");
        
        $(By.id("nome")).should(name("nomee"));
        $(By.id("nome")).should(value("Maria"));
        $(By.id("nome")).should(type("number"));
        
        $(By.id("email")).should(disabled);
        
    }
}
