package ejercicio3b;

public class Ejercicio3b {
    
    /*
        Esta sí funciona.
        Está bajo licencia GNU y no dudaré en aplicarla.
        Quita tus manos de mi obra de arte.
    */

    public static void main(String[] args) {
        int[][] contenedor1 = {{2,0,1},{0,3,1},{1,1,1}};
        int[][] contenedor2 = {{20,73,35},{29,78,31},{90,1,74}};
        int[][] contenedor3 = {{465,19981,9879},{6113,8849,161130},{1261,81610,6849}};
        
        System.out.println("La cantidad de movimientos minimos es: "+calcular(contenedor1));
        System.out.println("La cantidad de movimientos minimos es: "+calcular(contenedor2));
        System.out.println("La cantidad de movimientos minimos es: "+calcular(contenedor3));
        
    }
    
    public static int calcular(int[][] contenedor){
        int tmp, min = -1;
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if(noIgual(i,j,k)){
                        tmp = sumar(i, j, k, contenedor);
                        if(tmp < min || min == -1)
                            min = tmp;
                    }
                }
            }
        }
        
        return min;
    }
    
    public static boolean noIgual(int i, int j, int k){
        return i != j && i != k && j != k;
    }
    
    public static int sumar(int a, int b, int c, int[][] contenedor){
        int[] seleccionadas = {a,b,c};
        System.out.println(a+" "+b+" "+c);
        int total = 0;
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++) 
                if(i != seleccionadas[j])
                    total += contenedor[i][j];
        return total;
    }
}
