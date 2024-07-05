
import java.util.Scanner;

class additional {
    public static void main(String[] args) {
        int n = 4;
        int[] arr = new int[] { 1, 2, 2, 1, 4, 5, 2, 3, 4, 2, 4, 1 };
        int[] dist = new int[] { 0, 999, 999, 999 };
        int f = 0;
        for (int q = 0; q < n; q++) {
            for (int i = 0; i < n - 1; i++) {
                if (dist[i] + arr[3 * i + 2] < dist[i + 1]) {
                    dist[i + 1] = dist[i] + arr[3 * i + 2];
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (dist[i] + arr[3 * i + 2] < dist[i + 1]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            for (int i = 0; i < n; i++) {
                System.out.print(dist[i] + "  ");
            }
        } else {
            System.out.print("-ve cylce exist");
        }
        System.out.print("\n");
        for (int i = 0; i < 3 * n; i += 3) {
            System.out.print("((" + arr[i] + "," + arr[i + 1] + ")," + arr[i + 2] + ")  ");
        }
    }
}