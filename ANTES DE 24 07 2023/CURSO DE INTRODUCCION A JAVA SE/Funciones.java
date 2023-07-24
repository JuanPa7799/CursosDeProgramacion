import java.time.YearMonth;

public class Funciones {
    public static void main(String[] args) {
        double y=3;
        double area = circulArea(y);
        System.out.println(circulArea(y));
        
        System.out.println(sphereArea(y));

        System.out.println(sphereVolumen(y));

        System.out.println("Pesos a dolares: "+ converToDolar(1000, "COP"));

        
    }
    public static double circulArea(double r){
        return Math.PI * Math.pow(r, 2);
    }
    public static double sphereArea (double r){
        return 4 * Math.PI * Math.pow(r, 2);
    }
    public static double sphereVolumen (double r){
        return (4/3) * Math.PI * Math.pow(r, 3);
    }

    /**
     * Descripcion: Esta funcion que especificamos convierte una moneda a una cantidad de dolares
     * 
     * @param quantity Cantidad de dinero
     * @param currency Tio de moneda
     * @return quantify Devuelve la cantidad actualizado en dolares
     */
    public static double converToDolar(double quantity, String currency) {
        switch (currency){
            case "MXM":
                quantity = quantity * 0.052;
                break;
            case "COP":
                quantity = quantity * 0.00031;
                break;
        }
        return quantity;
        
    }
    

}
