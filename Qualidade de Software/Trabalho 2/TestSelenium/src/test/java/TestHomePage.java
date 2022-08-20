/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/UnitTests/JUnit5TestClass.java to edit this template
 */
import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;

import io.github.bonigarcia.wdm.WebDriverManager;
import java.util.List;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.openqa.selenium.support.ui.Select;

/**
 *
 * @author FJ_011
 */
public class TestHomePage {
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
        String url = "https://www.asu.edu/";
        driver.get(url);
        driver.manage().window().maximize();
        
    }

    @AfterEach
    void teardown() {
        driver.quit();
        
    }
    
    // Teste #1
    // Testa o campo do tipo "a" para ver se o "text" confere.
    // Teste realizado pela "classe".
    @Test
    public void testTitlePage(){
        element = driver.findElement(By.className("title-subunit-name"));
        assertEquals("Arizona State University", element.getText());
        System.out.println("\nTeste #1");
        System.out.println("'Titulo' da pagina é: " + element.getText() + "\n");
               
    }
    
    // Teste #2
    // Testa o campo do tipo "input" para ver se esta funcional.
    // Teste realizado pelo "id".
    @Test
    public void testInput(){
        driver.findElement(By.id("edit-search")).sendKeys("teste");
        System.out.println("\nTeste #2");
        System.out.println("Campo do tipo 'input' esta funcional!\n");
        
    }
    
    // Teste #3
    // Testa o campo do tipo "select" para ver sua quantidade de "option".
    // Teste realizado pelo "id".
    @Test
    public void testSelect(){
        Select drop = new Select(driver.findElement(By.id("edit-interestarea")));
        int tamanho = drop.getOptions().size();
        assertEquals(18, tamanho);
        System.out.println("\nTeste #3");
        System.out.println("Quantidade de 'option' no 'select': " + tamanho + "\n");
        
    }
    
    // Teste #4
    // Testa o campo do tipo "radio" para ver se esta funcional e se seu 'value' confere.
    // Teste realizado pelo "id".
    @Test
    public void testRadio(){
       element = driver.findElement(By.id("edit-standing-graduate"));
       element.click();
       assertEquals("graduate", element.getAttribute("value"));
       System.out.println("\nTeste #4");
       System.out.println("Campo do tipo 'radio' esta funcional!");
       System.out.println("'value' do campo é: " + element.getAttribute("value") + "\n");
        
    }
    
    // Teste #5
    // Testa o campo do tipo "ul" para ver sua quantidade de "li".
    // O "li" da home não é printado por se tratar de uma "img".
    // Teste realizado pela "classe".
    @Test
    public void testMenu(){
        List<WebElement> element = driver.findElements(By.className("sc-furwcr"));
        int tamanho = 0;
        System.out.println("\nTeste #5");
        System.out.println("Quais são os 'li'.");
        for(WebElement elem : element){
            tamanho++;
            System.out.println(elem.getText());
            
        }
        assertEquals(10, tamanho);
        System.out.println("Quantidade de 'li' do menu é: " + tamanho + "\n");
        
    }
    
    @AfterAll
    public static void closeBrowser(){
        System.out.println("Fim dos testes da pagina inicial...\n");
        
    }
}
