import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class GameItemTestGUI {

  public static void main(String[] args) {

    ArrayList<GameItem> bag = new ArrayList<GameItem>();
    ArrayList<ImageIcon> img = new ArrayList<ImageIcon>();

    bag.add(new Weapon("Sword", 3, true)); 
    bag.add(new Weapon("Rock", 1, false));
    bag.add(new Consumable("Potion", 0.5, "restore health"));
    bag.add(new Consumable("Food", 1.5, "sate hunger"));
    

    img.add(new ImageIcon("img-bags/rock.jpg"));
    img.add(new ImageIcon("img-bags/sword.jpg"));
    img.add(new ImageIcon("img-bags/potion.jpg"));
    img.add(new ImageIcon("img-bags/food.jpg"));
    
    // ListIterator: see https://www.baeldung.com/java-iterate-list
    ListIterator<GameItem> bagIterator = bag.listIterator();
    ListIterator<ImageIcon> imgIterator = img.listIterator();

    //ImageIcon image_sword = new ImageIcon("img-bags/sword.jpg");
    //ImageIcon image_rock = new ImageIcon("img-bags/rock.jpg");
    //ImageIcon image_potion = new ImageIcon("img-bags/potion.jpg");
    //ImageIcon image_food = new ImageIcon("img-bags/food.jpg");
    
    JLabel label = new JLabel(bagIterator.next().toString(), JLabel.CENTER);
    JLabel label2 = new JLabel(imgIterator.next(), JLabel.CENTER);

    JButton buttonNext = new JButton("Next >");
    buttonNext.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if (bagIterator.hasNext()) {   
          label.setText(bagIterator.next().toString()); 
          label2.setIcon(imgIterator.next());   
        }      
      }
    });    

    JPanel panel = new JPanel(new BorderLayout());
    panel.add(label, BorderLayout.CENTER);
    panel.add(label2, BorderLayout.CENTER);
    panel.add(buttonNext, BorderLayout.PAGE_END);


    JFrame f = new JFrame();
    f.add(panel);
    f.setSize(515, 515);
    f.setVisible(true);
  }
}






