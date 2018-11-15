package ejercicio.pkg5;

public class Deposito {
    Deposito salida1 = null, salida2 = null;
    int agua = 0;

    public void setSalida1(Deposito salida1) {
        this.salida1 = salida1;
    }

    public void setSalida2(Deposito salida2) {
        this.salida2 = salida2;
    }

    public int getAgua() {
        return agua;
    }
    
    
    public void echar(int cantidad){
        if(cantidad > 1000){
            cantidad = 1000;
            int sobrante = cantidad - 1000;
            if(salida2 == null){
                salida1.echar(sobrante);
            }else{
                salida1.echar(sobrante/2);
                salida2.echar(sobrante/2);
            }
        }
    }
}
