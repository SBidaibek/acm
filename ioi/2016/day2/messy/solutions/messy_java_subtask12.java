import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */

// BEGIN CUT

class grader {
    private static Set<String> set = new HashSet<>();
    private static boolean compiled = false;
    private static int n;
    private static int[] p;
    private static int w;
    private static int r;

    public static void main(messy_java_subtask12.InputReader in, messy_java_subtask12.OutputWriter out) {
        n = in.readInt();
        w = in.readInt();
        r = in.readInt();
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.readInt();
        }
        int[] answer = new messy().restore_permutation(n, w, r);

        // BEGIN SECRET
        out.printLine("098d134608c94f7413faac591054ee35");
        if (Arrays.equals(answer, p)) {
            out.printLine("OK");
        } else {
            out.printLine("WA");
        }
        // END SECRET

        out.printLine(answer);
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

// END CUT

class messy {
    public int[] restore_permutation(int n, int w, int r) {
        char[] element = new char[n];
        Arrays.fill(element, '0');
        for (int i = 0; i < n; i++) {
            element[i] = '1';
            grader.add_element(new String(element));
        }
        grader.compile_set();
        int[] answer = new int[n];
        boolean[] was = new boolean[n];
        Arrays.fill(element, '0');
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (was[j]) {
                    continue;
                }
                element[j] = '1';
                if (grader.check_element(new String(element))) {
                    answer[j] = i;
                    was[j] = true;
                    break;
                }
                element[j] = '0';
            }
        }
        return answer;
    }

}

public class messy_java_subtask12 {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        subtask123 solver = new subtask123();
        solver.solve(1, in, out);
        out.close();
    }

    static class subtask123 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            // BEGIN CUT
            grader.main(in, out);
            // END CUT
        }

    }

    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;
        private InputReader.SpaceCharFilter filter;

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

        public boolean isSpaceChar(int c) {
            if (filter != null) {
                return filter.isSpaceChar(c);
            }
            return isWhitespace(c);
        }

        public static boolean isWhitespace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        public interface SpaceCharFilter {
            public boolean isSpaceChar(int ch);

        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void print(Object... objects) {
            for (int i = 0; i < objects.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(objects[i]);
            }
        }

        public void print(int[] array) {
            for (int i = 0; i < array.length; i++) {
                if (i != 0) {
                    writer.print(' ');
                }
                writer.print(array[i]);
            }
        }

        public void printLine(int[] array) {
            print(array);
            writer.println();
        }

        public void printLine(Object... objects) {
            print(objects);
            writer.println();
        }

        public void close() {
            writer.close();
        }

    }
}

