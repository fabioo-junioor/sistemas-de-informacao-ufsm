package point;
import static java.lang.Math.*;

public class Point {
    private double x;
    private double y;
    
    public Point(){
        this.x = 0.0;
        this.y = 0.0;

    }
    public void modifica(double dx, double dy){
        System.out.println("x defaut: " + x);
        System.out.println("y defaut: " + y);
        x = x + dx;
        y = y + dy;
        System.out.println("x: " + x);
        System.out.println("y: " + y);

    }
    public double calc_dist(double x1, double x2, double y1, double y2){
        double dx, dy, distancia;
        dx = x2 - x1;
        dy = y1 - y2;
        distancia = sqrt(dx*dx + dy*dy);
        
        return distancia;

    }
}