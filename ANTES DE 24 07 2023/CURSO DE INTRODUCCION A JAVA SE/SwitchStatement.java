public class SwitchStatement {
    public static void main(String[] args) {
        String colorModeSelected = "Naranja";

        switch (colorModeSelected){
            case "Light":
                System.out.println("Seleccionaste el Light Mode");
                break;
            case "Night": //Ambar
                System.out.println("Seleccionaste Night Mode");
                break;
            case "Blue Dark": //Ambar
                System.out.println("Seleccionaste Blue Dark");
                break;
            case "Dark": //Ambar
                System.out.println("Seleccionaste Dark Mode");
                break;
                default:
                    System.out.println("Selecciona una opcion que sea correcta");
        }
    }
}
