/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */

import io.github.bonigarcia.wdm.WebDriverManager;
import java.util.List;
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
public class TestSubPage2 {
    
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
        String url = "https://www.asu.edu/about/facts-and-figures";
        driver.get(url);
        driver.manage().window().maximize();
        
    }

    @AfterEach
    void teardown() {
        driver.quit();
        
    }
    
    // Teste #10
    // Testa o campo do tipo "table" para ver sua quantidade de "tr".
    // Teste realizado pela "classe".
    @Test
    public void testTable(){
        List<WebElement> element = driver.findElements(By.tagName("tr"));
        int tamanho = 0;
        System.out.println("\nTeste #10");
        System.out.println("Quais são os 'tr'.");
        for(WebElement elem : element){
            tamanho++;
            System.out.println(tamanho + "- " + elem.getText());
            
        }
        assertEquals(9, tamanho);
        System.out.println("Quantidade de 'tr' da tabela é: " + tamanho + "\n");
               
    }
    
    @AfterAll
    public static void closeBrowser(){
        System.out.println("Fim dos testes da sub pagina 2...\n");
        
    }
}
