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
public class TestElements {

    @Test
    public void testElement() {
        open("http://localhost/sites/index.html");
        assertEquals("<div id=\"texto\">Obter elemento com id: texto</div>", 
                $(By.id("texto")).toString());        
        assertEquals("<div id=\"texto\">Obter elemento com id: texto</div>", 
                $("#texto").toString());

        assertEquals("<input name=\"nomeInput\" type=\"text\" value=\"Obter elemento pelo value\"></input>", 
                $(By.name("nomeInput")).toString());
                
        assertEquals("<a title=\"Meu titulo\">Obter elemento com titulo: Meu titulo</a>", 
                $(by("title", "Meu titulo")).toString());        
        assertEquals("<a title=\"Meu titulo\">Obter elemento com titulo: Meu titulo</a>",
                $(byTitle("Meu titulo")).toString());
        
        assertEquals("<form id=\"idForm\"></form>",
                $(By.id("idForm")).toString());
        assertEquals("<form id=\"idForm\"></form>",
                $(by("id", "idForm")).toString());
       
    }
    
    @Test
    public void testElementFail(){
        open("http://localhost/sites/index.html");
        assertEquals("<div id=\"texto\">Obter elemento com id: textoo</div>", 
                $(By.id("texto")).toString());
                
        assertEquals("<a title=\"Meu titulo\">Obter elemento com titulo: Meu titulo</a>", 
                $(by("title", "Meu tituloo")).toString());
        
        assertEquals("<form id=\"idForm\"></form>",
                $(By.id("idFormm")).toString());
        
    }
}
