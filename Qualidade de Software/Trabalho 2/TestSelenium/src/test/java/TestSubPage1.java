/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */

import io.github.bonigarcia.wdm.WebDriverManager;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

/**
 *
 * @author FJ_011
 */
public class TestSubPage1 {
    
    private static WebDriver driver;
    WebElement element;
    
    @BeforeAll
    public static void openBrowser() {
        WebDriverManager.chromedriver().setup();
        //System.setProperty("webdriver.chrome.driver", "C://Users//Graxaim//Documents//NetBeansProjects//chromedriver.exe");
        //driver = new ChromeDriver();    	
	//driver.manage().window().maximize();	
	//driver.manage().deleteAllCookies();
        
    }
    
    @BeforeEach
    void setup() {
        driver = new ChromeDriver();
        String url = "https://www.asu.edu/admission";
        driver.get(url);
        driver.manage().window().maximize();
        
    }

    @AfterEach
    void teardown() {
        driver.quit();
        
    }
    
    // Teste #6
    // Testa o campo do tipo "h3" para ver se a "tagName" confere.
    // Teste realizado pela "classe".
    @Test
    public void testH3(){
        element = driver.findElement(By.className("card-title"));
        assertEquals("h3", element.getTagName());
        System.out.println("\nTeste #6");
        System.out.println("O sub titulo é um 'h3': " + element.getTagName() + "\n");
               
    }
    
    // Teste #7
    // Testa o campo do tipo "button" para ver se esta funcional.
    // Teste realizado pela "classe".
    @Test
    public void testButtonBullet(){
       element = driver.findElement(By.className("glide__bullet"));
       element.click();
       System.out.println("\nTeste #7");
       System.out.println("Campo do tipo 'button' esta funcional!\n");
             
    }
    
    // Teste #8
    // Testa o campo do tipo "svg" para ver se a "tagName" confere.
    // Teste realizado pela "classe".
    @Test
    public void testSvgLinkedin(){
        element = driver.findElement(By.className("fa-linkedin"));
        assertEquals("svg", element.getTagName());
        System.out.println("\nTeste #8");
        System.out.println("Campo do tipo 'svg' esta funcional!\n");
             
    }
    
    // Teste #9
    // Testa o campo do tipo "cite" para ver se o "text" confere.
    // Teste realizado pela "classe". 
    @Test
    public void testCite(){
        element = driver.findElement(By.className("description"));
        assertEquals("Riverside, CA", element.getText());
        System.out.println("\nTeste #9");
        System.out.println("A 'cite' contem uma descrição: " + element.getText() + "\n");
               
    }
    
    @AfterAll
    public static void closeBrowser(){
        System.out.println("Fim dos testes da sub pagina 1...\n");
        
    }
}
