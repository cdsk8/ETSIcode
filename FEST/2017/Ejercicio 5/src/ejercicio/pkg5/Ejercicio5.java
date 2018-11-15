package ejercicio.pkg5;

public class Ejercicio5 {

    static int cantidad = 10;
    static Deposito depositos[] = new Deposito[cantidad];
    
    public static void main(String[] args) {
        int puestos = 0, columna = 1;
        while(puestos < cantidad){
            for (int i = 0; i < columna; i++) {
                if(puestos < cantidad)
                    depositos[puestos] = new Deposito();
                puestos++;
            }
            for (int i = 0; i < columna-1; i++) {
                depositos[1].setSalida1(null);
                depositos[1].setSalida2(null);
            }
            columna++;
        }
    }
    
}
