package ejercicio1;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Ejercicio1 {

    public static void main(String[] args) {
        System.out.println("Solucion: "+comp(10000000));
    }
    
    public static int comp(int max){
        int res = 0;
        ArrayList<int[]> buenos = new ArrayList<>();
        ArrayList<int[]> malos = new ArrayList<>();
        //ArrayList<int[]> tmp = new ArrayList<>();
        buenos.add(convertir(89));
        malos.add(convertir(1));
        
        int newN, nn;
        int[] n;
        for(int i = 1; i <= max; i++){
            //if(i % 100000 == 0)
            //    System.out.println(i);
            n = convertir(i);
            nn = i;
            //tmp.clear();
            while (true){
                if(dentro(buenos,n)){
                    //buenos = agregarTodos(buenos, tmp);
                    if(!dentro(buenos,convertir(i)))
                        buenos.add(convertir(i));
                    res++;
                    break;
                }else if(dentro(malos,n)){
                    //malos = agregarTodos(malos, tmp);
                    if(!dentro(malos,convertir(i)))
                        malos.add(convertir(i));
                    break;
                }else{
                    newN = 0;
                    //tmp.add(n);
                    for(int j = 0; j < n.length;j++)
                        newN += n[j]*n[j];
                    n = convertir(newN);
                }
            }
        }
        
        return res;
    }
    
    public static int[] convertir(int n){
        String Sn = Integer.toString(n);
        List<Integer> numerosTMP = new ArrayList<>();
        for (int i = 0; i < Sn.length(); i++) {
            if(Sn.charAt(i) != '0'){
                numerosTMP.add(Integer.valueOf(Sn.charAt(i)+""));
            }
                
        }
        int[] numeros = new int[numerosTMP.size()];
        for (int i = 0; i < numeros.length; i++) {
            numeros[i] = numerosTMP.get(i);
        }
        Arrays.sort(numeros);
        return numeros;
    }
    
    public static boolean comparar(int[] a, int[] b){
        if(a.length != b.length)
            return false;
        for (int i = 0; i < a.length; i++) {
            if(a[i] != b[i])
                return false;
        }
        return true;
    }
    
    public static boolean dentro(ArrayList<int[]> lista,int[] n){
        for (int j = 0; j < lista.size(); j++) {
            if(comparar(lista.get(j), n))
                return true;
        }
        return false;
    }

    private static ArrayList<int[]> agregarTodos(ArrayList<int[]> lista, ArrayList<int[]> tmp) {
        for (int i = 0; i < tmp.size(); i++) {
            if(!dentro(lista,tmp.get(i)))
                lista.add(tmp.get(i));
        }
        return lista;
    }
}
