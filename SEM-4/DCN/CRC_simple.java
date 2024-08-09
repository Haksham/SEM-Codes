import java.util.*;

class CRC_simple {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter length of codeword: ");
        int cl = sc.nextInt();
        System.out.print("Enter length of gen: ");
        int gl = sc.nextInt();
        int[] code = new int[cl];
        int[] gen = new int[gl];
        System.out.print("Enter codeword: ");
        for (int i = 0; i < cl; i++) {
            code[i] = sc.nextInt();
        }
        System.out.print("Enter gen: ");
        for (int i = 0; i < gl; i++) {
            gen[i] = sc.nextInt();
        }
        int[] newc = new int[cl + gl - 1];

        for (int i = 0; i < code.length; i++) {
            newc[i] = code[i];
        }
        for (int i = code.length; i < newc.length; i++) {
            newc[i] = 0;
        }

        for (int i = 0; i < code.length; i++) { // main code start
            if (newc[i] == 1) {
                for (int j = 0; j < gen.length; j++) {
                    newc[i + j] ^= gen[j];
                }
            }
        } // main code end

        for (int i = 0; i < code.length; i++) { // printing final code
            newc[i] = code[i];
        }
        String s = " ";
        for (int i = 0; i < newc.length; i++) {
            s += newc[i];
        }
        System.out.print(s);
    }
}