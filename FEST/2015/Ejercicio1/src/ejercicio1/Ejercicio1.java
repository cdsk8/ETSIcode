package ejercicio1;

import java.util.ArrayList;

public class Ejercicio1 {

    public static void main(String[] args) {
        System.out.println(comp(10000000));
    }
    
    public static int comp(int max){
        int res = 0;
        ArrayList<Integer> buenos = new ArrayList<Integer>();
        ArrayList<Integer> malos = new ArrayList<Integer>();
        ArrayList<Integer> tmp = new ArrayList<Integer>();
        buenos.add(89);
        malos.add(1);
        
        int n,newN;
        for(int i = 1; i <= max; i++){
            n = i;
            tmp.clear();
            while (true){
                if(buenos.contains(n)){
                    //tmp.remove(tmp.size());
                    //buenos.addAll(tmp);
                    buenos.add(i);
                    res++;
                    if(res % 100000 == 0)
                        System.out.println(res);
                    break;
                }else if(malos.contains(n)){
                    //malos.addAll(tmp);
                    malos.add(i);
                    break;
                }else{
                    newN = 0;
                    tmp.add(i);
                    for(int j = 0; j < String.valueOf(n).length();j++)
                        newN += Integer.parseInt(String.valueOf(n).charAt(j)+"") * Integer.parseInt(String.valueOf(n).charAt(j)+"");
                    n = newN;
                }
            }
        }
        
        return res;
    }
    
}
