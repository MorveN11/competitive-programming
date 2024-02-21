import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {
  static BufferedWriter bw;
  static BufferedReader br;
  static StringTokenizer st;

  static class FastReader {
    public FastReader(String def) {
      if (def.equals("Local")) {
        try {
          br = new BufferedReader(
              new FileReader("/home/fundacion/Desktop/Diego/3 semestre/aloritmia/ICPC/main.in"));
          bw = new BufferedWriter(
              new FileWriter("/home/fundacion/Desktop/Diego/3 semestre/aloritmia/ICPC/main.out"));
        } catch (Exception e) {
          System.out.println(e);
        }
      } else {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
      }
    }

    String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    int nextInt() {
      return Integer.parseInt(next());
    }

    long nextLong() {
      return Long.parseLong(next());
    }

    double nextDouble() {
      return Double.parseDouble(next());
    }

    String nextLine() {
      String str = "";
      try {
        str = br.readLine();
      } catch (IOException e) {
        e.printStackTrace();
      }
      return str;
    }

    void close() throws IOException {
      br.close();
      bw.close();
    }
  }

  public static void main(String[] args) throws IOException {
    FastReader reader = new FastReader(args.length >= 1 && args[0].equals("DiegoLocal") ? "Local" : "");

    int n = reader.nextInt();
    long[] xi = new long[n];
    long[] yi = new long[n];

    for (int i = 0; i < n; i++) {
      xi[i] = reader.nextLong();
      yi[i] = reader.nextLong();
    }

    long maxx = xi[n - 1];
    long minx = xi[0];
    Double maxAngle = 0.0;

    for (int i = 1; i < n - 1; i++) {
      Double angleLeft = calculateAngle(xi[i], yi[i], minx, yi[i]);
      Double angleRight = calculateAngle(maxx - xi[i], yi[i], maxx, yi[i]);

      maxAngle = Math.max(maxAngle, Math.max(angleLeft, angleRight));
    }

    BigDecimal ans = BigDecimal.valueOf(maxAngle);
    ans = ans.setScale(20);
    bw.write(ans + "\n");
    bw.newLine();
    bw.flush();
    reader.close();
  }

  public static double calculateAngle(long dx, long dy, long x, long y) {
    return Math.toDegrees(Math.acos(dx / Math.sqrt(dx * dx + dy * dy)));
  }
}
