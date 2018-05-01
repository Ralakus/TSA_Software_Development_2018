import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.lang.System;
import java.util.Scanner;

public class Main{

    static public void main(String[] args){
        Scanner Input = new Scanner(System.in);

        long GenTo = 0;

        ArrayList<Boolean> Sieve = new ArrayList<Boolean>();

        System.out.println("Enter the amount of prime numbers to generate");

        boolean Proceed = false;
        
        while(!Proceed){
            try{
                while(!Input.hasNextLong()){
                    Input.next();
                }
                GenTo = Input.nextLong();
                if(GenTo > 0){
                    Proceed = true;
                }
                else{
                    Proceed = false;
                }
            }
            catch (Error e)
            {
                System.out.println(e);
                System.out.println("Enter an integer above 0!");
                Proceed = false;
            }
        }

        System.out.println("Resizing sieve...");

        for(long i = 0; i < GenTo; i++){
            Sieve.add(false);
        }

        System.out.println("Generating primes...");

        for(long i = 2; i < GenTo; i++){
            if(!Sieve.get((int)i)){
                for(long r = i + i; r < GenTo; r += i){
                    Sieve.set((int)r, true);
                }
            }
        }

        System.out.println("Writing to file...");

        try{
            WriteToFile(Sieve, GenTo);
        }
        catch (IOException e){
            System.out.println(e);
        }

        Input.close();

    }

    public static void WriteToFile(ArrayList<Boolean> Sieve, long GenTo) throws IOException{
        BufferedWriter OutStream = new BufferedWriter(new FileWriter("GeneratedPrimes0-" + GenTo));

        OutStream.write("");

        for(long i = 2; i < Sieve.size(); i++){
            if(!Sieve.get((int)i)){
                OutStream.append(new String(i + "\n"));
            }
        }

        OutStream.close();
    }

}