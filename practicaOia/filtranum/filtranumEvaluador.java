import java.io.*;
import java.lang.*;
import java.util.*;

public class filtranumEvaluador {
    private static String nextLine = "";
    private static int nextIndex = 0;
    private static BufferedReader reader;
    
    private static String readToken() throws IOException {
        while (true) {
            while (nextIndex < nextLine.length() && nextLine.charAt(nextIndex) == ' ') nextIndex++;
            if (nextIndex == nextLine.length()) {
                nextLine = reader.readLine();
                nextIndex = 0;
            } else {
                break;
            }
        }
        int baseIndex = nextIndex++;
        while (nextIndex < nextLine.length() && nextLine.charAt(nextIndex) != ' ') nextIndex++;
        return nextLine.substring(baseIndex, nextIndex);
    }
    
    public static void main(String [] args) throws IOException {
        reader = new BufferedReader(new InputStreamReader(System.in));
        try (PrintWriter writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)))) {
            int N;
            N = Integer.parseInt(readToken());
            ArrayList<Integer> numeros;
            numeros = new ArrayList<>(N);
            for (int i0 = 0; i0 < N; i0++) {
                int aux0;
                aux0 = Integer.parseInt(readToken());
                numeros.add(aux0);
            }
            ArrayList<Integer> resultado;
            resultado = new ArrayList<>(0);
            int returnedValue;
            returnedValue = filtranum.filtranum(numeros, resultado);
            writer.println(returnedValue);
            for (int i = 0; i < resultado.size(); i++) {
                if (i > 0) writer.print(" ");
                writer.print(resultado.get(i));
            }
            writer.println();
        }
    }
}
