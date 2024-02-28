import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class D {

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

    boolean hasNext() throws IOException {
      return br.ready();
    }
  }

  static int LCS(String str1, String str2) {
    int n = str1.length(), m = str2.length();
    int[][] dp = new int[n + 1][m + 1];

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);

        if (str1.charAt(i - 1) == str2.charAt(j - 1)) {
          dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
      }
    }

    return dp[n][m];

  }

  public static void main(String[] args) throws IOException {
    FastReader reader = new FastReader(args.length >= 1 && args[0].equals("MorvenLocal") ? "Local" : "Normal");

    String str1, str2;
    while ((str1 = reader.nextLine()) != null && !str1.isEmpty()) {
      str2 = reader.nextLine();
      bw.write(LCS(str1, str2) + "\n");
    }
    bw.flush();
    reader.close();
  }
}
