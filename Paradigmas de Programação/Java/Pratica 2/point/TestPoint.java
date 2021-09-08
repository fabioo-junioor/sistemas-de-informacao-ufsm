package point;
public class TestPoint {
    public static void main(String[] args) {
        double dist;
        Point p = new Point();
        p.modifica(8.3, 9);
        //p.modifica(1, 1);
        
        dist = p.calc_dist(10, 9, 11, 7);
        System.out.println("Distancia: "+ dist);
    }
    
}