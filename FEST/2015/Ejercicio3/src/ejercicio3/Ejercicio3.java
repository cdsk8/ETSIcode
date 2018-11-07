package ejercicio3;

public class Ejercicio3 {
    /*
        No funciona.
        Si eres capaz de hacerlo funcionar, puedes quedartelo.
        Como si quieres venderlo a una empresa de seguridad.
    */
    public static void main(String[] args) {
        int[][] contenedor1 = {{2,0,1},{0,3,1},{1,1,1}};
        int[][] contenedor2 = {{20,73,35},{29,78,31},{90,1,74}};
        int[][] contenedor3 = {{465,19981,9879},{6113,8849,161130},{1261,81610,6849}};
        
        int[][][] ordenada;
        int[] seleccionadas;
        /*
        ordenada = ordenar(contenedor1);
        seleccionadas = seleccionar(contenedor1, ordenada);
        System.out.println("La cantidad de movimientos minimos es: "+movimientos(contenedor1, seleccionadas));
        
        ordenada = ordenar(contenedor2);
        seleccionadas = seleccionar(contenedor2, ordenada);
        System.out.println("La cantidad de movimientos minimos es: "+movimientos(contenedor2, seleccionadas));
        */
        ordenada = ordenar(contenedor3);
        seleccionadas = seleccionar(contenedor3, ordenada);
        for (int i = 0; i < 3; i++) {
            System.out.println("SEL "+i+": "+seleccionadas[i]);
        }
        System.out.println("La cantidad de movimientos minimos es: "+movimientos(contenedor3, seleccionadas));
    }
    
    public static int[] seleccionar(int[][] contenedor, int[][][] ordenada){
        int[] seleccionadas = new int[3];
        
        for (int i = 0; i < 3; i++) {
            seleccionadas[i] = -2;
        }
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(ordenada[i][j][0]+"-"+ordenada[i][j][1]+"  ");
            }
            System.out.println("");
        }
        
        boolean puedes;
        for(int j = 0; j < 3; j++){
            int i = 0;
            boolean puesto = false;
            while(i < 3 && !puesto){
                puedes = true;
                for(int k = 0; puedes && k < 3; k++){
                    if(contiene(seleccionadas,ordenada[i][k][0]) && k != j && ordenada[i][j][0] == ordenada[i][k][0] && j != k && ordenada[i][k][1] > ordenada[i][j][1])
                        puedes = false;
                }
                if(puedes){
                    seleccionadas[j] = ordenada[i][j][0];
                    puesto = true;
                    i = 0;
                }
                i++;
            }
        }
        
        
        return seleccionadas;
    }
    
    public static int[][][] ordenar(int[][] contenedor){
        int[][][] ordenada = new int[3][3][2];
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ordenada[i][j][0] = -2;
                ordenada[i][j][1] = -2;
            }
        }
        
        int max;
        for(int i = 0; i < 3; i++){
            max = -1;
            for(int j = 0; j < 3; j++){
                if(contenedor[j][i] > max){
                    max = contenedor[j][i];
                    ordenada[0][i][0] = j;
                    ordenada[0][i][1] = max;
                }
            }
            max = -1;
            for(int j = 0; j < 3; j++){
                if(j != ordenada[0][i][0] && contenedor[j][i] > max){
                    max = contenedor[j][i];
                    ordenada[1][i][0] = j;
                    ordenada[1][i][1] = max;
                }
            }
            ordenada[2][i][0] = noEsta(ordenada,i);
            ordenada[2][i][1] = contenedor[ordenada[2][i][0]][i];
        }
        
        return ordenada;
    }
    
    public static boolean contiene(int[] array, int n){
        for(int i = 0; i < 3; i++)
            if(array[i] == n)
                return true;
        return false;
    }
    
    public static int noEsta(int[][][] ordenada, int i){
        boolean esta1, esta2, esta3;
        esta1 = esta2 = esta3 = false;
        for(int j = 0; j < 3; j++){
            if(ordenada[j][i][0] == 0)
                esta1 = true;
            if(ordenada[j][i][0] == 1)
                esta2 = true;
            if(ordenada[j][i][0] == 2)
                esta3 = true;
        }
        if(!esta1)
            return 0;
        if(!esta2)
            return 1;
        if(!esta3)
            return 2;
        return -1;
    }

    private static int movimientos(int[][] contenedor ,int[] seleccionadas) {
        int total = 0;
        for (int i = 0; i < 3; i++) 
            for (int j = 0; j < 3; j++) 
                if(i != seleccionadas[j])
                    total += contenedor[i][j];
        return total;
    }
}
