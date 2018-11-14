package ejercicio.pkg4;

import java.util.ArrayList;

public class Ejercicio4 {
    
    //static int[] pesos = {7000,1000,400,650,500};
    //static int[] precios = {1500000,70000,400000,300000,200000};
    
    static int[] pesos = {7000,200,620,300,3440,220,1777,800,950,2300,1250,1987,5000,2300,800,5300,4300,2100};
    static int[] precios = {150000,7000,40000,3000,2000,10000,3000,3000,8000,150000,30000,699099,100050,10000,20000,30000,1500};
    
    static int max = 0;
    static int maxPeso = 8000;
    
    public static void main(String[] args) {
        ArrayList<Integer> lista = new ArrayList<>();
        iter(lista, -1);
        
    }
    
    public static void iter(ArrayList<Integer> lista, int agregar){
        ArrayList<Integer> Nlista = new ArrayList<>();
        for (int i = 0; i < lista.size(); i++) {
            Nlista.add(lista.get(i));
        }
        if(agregar != -1){
            Nlista.add(agregar);
        }
        
        if(peso(Nlista) < maxPeso){
            int ganas = ganas(Nlista);
            if(ganas > max){
                max = ganas;
                System.out.println("MAX: "+dibujar(Nlista)+"  Ganas: "+ganas+"  Peso: "+peso(Nlista));
            }
            
            boolean puedes;
            for (int i = 0; i < precios.length; i++) {
                puedes = true;
                for (int j = 0; j < Nlista.size(); j++) {
                    if(Nlista.get(j) == i) puedes = false;
                }
                if(puedes){
                    //System.out.println("Tengo: "+dibujar(Nlista)+"  Agregar: "+i);
                    iter(Nlista,i);
                }
            }
        }
    }
    
    public static int ganas(ArrayList<Integer> lista){
        int total = 0;
        for (int i = 0; i < lista.size(); i++) {
            total += precios[lista.get(i)];
        }
        return total;
    }
    
    public static int peso(ArrayList<Integer> lista){
        int total = 0;
        for (int i = 0; i < lista.size(); i++) {
            total += pesos[lista.get(i)];
        }
        return total;
    }
    
    public static String dibujar(ArrayList<Integer> lista){
        StringBuilder total = new StringBuilder("");
        for (int i = 0; i < lista.size(); i++) {
            total.append((lista.get(i))+1).append("  ");
        }
        return total.toString();
    }
}