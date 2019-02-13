import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

/**
 * @author egor@egork.net
 */
class messy {
    public int[] restore_permutation(int n, int w, int r) {
        doWrites(n);
        grader.compile_set();
        int[] answer = new int[n];
        doReads(n, answer);
        return answer;
    }

    private int n;
    private char[] address;

    private void read(int[] t, int[] answer, int step, int w) {
        if (t.length == 1) {
            answer[t[0]] = w;
            return;
        }
        int[] t0 = new int[t.length / 2];
        int att0 = 0;
        int[] t1 = new int[t.length / 2];
        int att1 = 0;
        Arrays.fill(address, '1');
        for (int j : t) {
            address[j] = '0';
        }
        for (int j : t) {
            address[j] = '1';
            if (!grader.check_element(new String(address))) {
                t0[att0++] = j;
            } else {
                t1[att1++] = j;
            }
            address[j] = '0';
        }
        read(t0, answer, step + 1, w);
        read(t1, answer, step + 1, w + (1 << step));
    }

    public void doReads(int n, int[] answer) {
        int[] order = new int[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        read(order, answer, 0, 0);
    }

    public void doWrites(int n) {
        this.n = n;
        address = new char[n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(address, '0');
            address[i] = '1';
            if (i % 2 == 1) {
                grader.add_element(new String(address));
            }
        }
        int log = Integer.bitCount(n - 1);
        for (int length = 1; length < log; length++) {
            for (int i = 0; i < (1 << length); i++) {
                helper(length, i);
            }
        }
    }

    private void helper(int length, int w) {
        Arrays.fill(address, '1');
        for (int i = w; i < n; i += (1 << length)) {
            address[i] = '0';
        }
        int j = w;
        for (int i = 0; i < (n / (1 << length)); i++) {
            address[j] = '1';
            if (i % 2 == 1) {
                grader.add_element(new String(address));
            }
            address[j] = '0';
            j += 1 << length;
        }
    }

}

// BEGIN CUT
public class messy_java_ok {
    public static void main(String[] args) {
        grader.main(args);
    }
}


/**
 * @author egor@egork.net
 */
class grader {
    private static Set<String> set = new HashSet<>();
    private static boolean compiled = false;
    private static int n;
    private static int[] p;
    private static int w;
    private static int r;

    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        n = in.readInt();
        w = in.readInt();
        r = in.readInt();
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.readInt();
        }
        int[] answer = new messy().restore_permutation(n, w, r);

        // BEGIN SECRET
        System.out.println("098d134608c94f7413faac591054ee35");
        if (Arrays.equals(answer, p)) {
            System.out.println("OK");
        } else {
            System.out.println("WA");
        }
        // END SECRET

        System.out.print(answer[0]);
        for (int i = 1; i < n; i++) {
            System.out.print(" " + answer[i]);
        }
        System.out.println();
    }

    public static void add_element(String x) {
        if (--w < 0 || compiled || !check(x)) {
            System.out.println("WA");
            System.exit(0);
        }
        set.add(x);
    }

    private static boolean check(String x) {
        if (x.length() != n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (x.charAt(i) != '0' && x.charAt(i) != '1') {
                return false;
            }
        }
        return true;
    }

    public static boolean check_element(String x) {
        if (--r < 0 || !compiled || !check(x)) {
            System.out.println("WA");
            System.exit(0);
        }
        return set.contains(x);
    }

    public static void compile_set() {
        if (compiled) {
            System.out.println("WA");
            System.exit(0);
        }
        compiled = true;
        Set<String> compiledSet = new HashSet<>();
        char[] compiledElement = new char[n];
        for (String s : set) {
            for (int i = 0; i < n; i++) {
                compiledElement[i] = s.charAt(p[i]);
            }
            compiledSet.add(new String(compiledElement));
        }
        set = compiledSet;
    }
}

class InputReader {
    private InputStream stream;
    private byte[] buf = new byte[1024];
    private int curChar;
    private int numChars;

    public InputReader(InputStream stream) {
        this.stream = stream;
    }

    public int read() {
        if (numChars == -1) {
            throw new InputMismatchException();
        }
        if (curChar >= numChars) {
            curChar = 0;
            try {
                numChars = stream.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (numChars <= 0) {
                return -1;
            }
        }
        return buf[curChar++];
    }

    public int readInt() {
        int c = read();
        while (isSpaceChar(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int res = 0;
        do {
            if (c < '0' || c > '9') {
                throw new InputMismatchException();
            }
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isSpaceChar(c));
        return res * sgn;
    }

    public static boolean isSpaceChar(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}

// END CUT
