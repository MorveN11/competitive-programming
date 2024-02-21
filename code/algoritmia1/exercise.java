import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class exercise {

  static BufferedWriter bw;
  static BufferedReader br;
  static StringTokenizer st;

  static class FastReader {
    public FastReader(String def) {
      if (def.equals("Local")) {
        try {
          br = new BufferedReader(
              new FileReader("/home/morven/Desktop/code/manuel-competitive/conf/main.in"));
          bw = new BufferedWriter(
              new FileWriter("/home/morven/Desktop/code/manuel-competitive/conf/main.out"));
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

  /**
   * Time Complexity: O(log(min(a, b)))
   */
  public int method(int a, int b) {
    while (b != 0) {
      int tmp = b;
      b = a % b;
      a = tmp;
    }
    return a;
  }

  public static void main(String[] args) throws IOException {
    FastReader reader = new FastReader(args.length >= 1 && args[0].equals("MorvenLocal") ? "Local" : "Normal");

    bw.flush();
    reader.close();
  }
}
