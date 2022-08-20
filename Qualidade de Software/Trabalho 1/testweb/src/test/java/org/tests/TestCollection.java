/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package org.tests;
import static com.codeborne.selenide.CollectionCondition.size;
import static com.codeborne.selenide.Condition.*;
import static com.codeborne.selenide.Condition.text;
import org.testng.annotations.Test;
import static com.codeborne.selenide.Selenide.*;
import static org.junit.Assert.assertEquals;
/**
 *
 * @author Fabio
 */
public class TestCollection {
    
    @Test
    public void testCollectionTable(){
        open("http://localhost/sites/collection.html");
        $$("#tblGastos tr").shouldHave(size(4));
        
        assertEquals(true, $$("#tblGastos tr td").findBy(text("R$5000")).exists());
        assertEquals(false, $$("#tblGastos tr td").filterBy(text("Janeiro")).isEmpty());
        
    }
    
    @Test
    public void testCollectionTableFail(){
        open("http://localhost/sites/collection.html");
        $$("#tblGastos tr").shouldHave(size(2));
        
        assertEquals(true, $$("#tblGastos tr td").findBy(text("R$10")).exists());
        assertEquals(true, $$("#tblGastos tr td").filterBy(text("Janeiro")).isEmpty());
        
    }
}
