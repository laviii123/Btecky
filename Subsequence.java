import java.util.ArrayList;

public class Subsequence {
    public static void sequen(int n,ArrayList <Integer> arr,int ar[],int lengtht){
        if(n==ar.length){
           System.out.println(arr.toString());
           return;
            }
        
            arr.add(ar[n]);
            sequen(n+1, arr,ar,lengtht);
            arr.remove(arr.size()-1);
            sequen(n+1, arr, ar,lengtht);
        }
        public static void main(String args[]){
            int ar[]={3,1,2};
            ArrayList<Integer> arr= new ArrayList<>();
            sequen(0, arr, ar,3);
        }
    }

