import java.util.ArrayList;

import javax.print.DocFlavor.STRING;

public class Doctor {
    //Atributos
    static int id = 0; //autoincrementado
    String name; 
    String email;
    String speciality;

    

    Doctor(){
        System.out.println("Contruyendo el objeto Doctor");
    }

    Doctor(String name, String speciality){
        System.out.println("El nombre del Doctor asignado es: " + name);
        this.name = name;
        this.speciality = speciality;
        id++;
    }

    //Comportamientos
    public void showName(){
        System.out.println(name);
    }

    public void showId(){
        System.out.println("ID Doctor: " + id);
    }

    ArrayList<AvailableAppontment> availableappontments = new ArrayList<>();
    public void addAvailableappontment(String date, String time) {
        availableappontments.add(new Doctor.AvailableAppontment(date, time));
    }

    public ArrayList<AvailableAppontment> getAvailableAppontments(){
        return availableappontments;
    }

    public static class AvailableAppontment{
        private int id;
        private String date;
        private String time;
        //Available Appointment
        public  AvailableAppontment(String date, String time) {
            this.date=date;
            this.time=time;
            
        }
        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public String getDate() {
            return date;
        }

        public void setDate(String date) {
            this.date = date;
        }

        public String getTime() {
            return time;
        }

        public void setTime(String time) {
            this.time = time;
        }
        

    }
    
}

