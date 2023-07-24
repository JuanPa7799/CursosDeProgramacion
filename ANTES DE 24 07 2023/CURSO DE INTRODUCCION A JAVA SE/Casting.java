public class Casting {
    public static void main(String[] args) {
        
        //En un año  ubicar 30 perritos 
        //Cuantos perritos ubique al mes?
        double monthlyDogs = 30.0 /12.0;
        System.out.println(monthlyDogs);

        //Estimacion

        int estimatedMonthlyDogs = (int)monthlyDogs;
        System.out.println(estimatedMonthlyDogs);

        //exactitud
        int a = 30;
        int b = 12;
        System.out.println((double)a/b);

        double c = (double)a/b;
        System.out.println(c);

        char n = '1';
        int nT = n;
        System.out.println(nT);

        short nS = (short)n;
        System.out.println(nS);
        

    }
}