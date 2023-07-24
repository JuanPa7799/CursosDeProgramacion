public class forloop {
    static boolean isTurnOnLight = false;
    public static void main(String[] args) {
        turnOnOffLight();

        for (int i = 1; i <=10; i++) {
            printSOS();
        }
        
    }
    public static void printSOS() {
        System.out.println(". . . _ _ _ . . .");
    }
    public static boolean turnOnOffLight() {

        isTurnOnLight = (isTurnOnLight)?false:true;

        // if(isTurnOnLight){
        //     isTurnOnLight = false;
        // }else{
        //     isTurnOnLight= true;
        // }
        return isTurnOnLight;
    }
}
