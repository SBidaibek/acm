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
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Set;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Egor Kulikov (egor@egork.net)
 */
class messy {
    public int[] restore_permutation(int n, int w, int r) {
        char[] element = new char[n];
        for (int i = 1; i < (1 << n); i++) {
            if (Integer.bitCount(Integer.lowestOneBit(i) - 1) % 2 == 1) {
                for (int j = 0; j < n; j++) {
                    element[j] = (char) ('0' + (i >> j & 1));
                }
                grader.add_element(new String(element));
            }
        }
        grader.compile_set();
        boolean[] present = new boolean[1 << n];
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                element[j] = (char) ('0' + (i >> j & 1));
            }
            present[i] = grader.check_element(new String(element));
        }
        int[] answer = messy_java_subtask1.ArrayUtils.createOrder(n);
        for (int i = 0; i < n; i++) {
            boolean expected = i % 2 == 1;
            for (int j = i; j < n; j++) {
                boolean good = true;
                for (int k = 0; k < (1 << (n - i - 1)); k++) {
                    int address = (1 + 2 * k) << i;
                    int iBit = address >> i & 1;
                    int jBit = address >> j & 1;
                    address -= iBit << i;
                    address -= jBit << j;
                    address += iBit << j;
                    address += jBit << i;
                    if (present[address] != expected) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    if (i != j) {
                        answer[i] = j;
                        answer[j] = i;
                        return answer;
                    }
                    break;
                }
            }
        }
        return answer;
    }

}

// BEGIN CUT

class grader {
    private static Set<String> set = new HashSet<>();
    private static boolean compiled = false;
    private static int n;
    private static int[] p;
    private static int w;
    private static int r;

    public static void main(messy_java_subtask1.InputReader in, messy_java_subtask1.OutputWriter out) {
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

public class messy_java_subtask1 {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        subtask1 solver = new subtask1();
        solver.solve(1, in, out);
        out.close();
    }

    static class subtask1 {
        public void solve(int testNumber, InputReader in, OutputWriter out) {
            // BEGIN CUT
            grader.main(in, out);
            // END CUT
        }

    }

    static interface IntList extends IntReversableCollection {
        public abstract int get(int index);

        public abstract void removeAt(int index);

        default public IntIterator intIterator() {
            return new IntIterator() {
                private int at;
                private boolean removed;

                public int value() {
                    if (removed) {
                        throw new IllegalStateException();
                    }
                    return get(at);
                }

                public boolean advance() {
                    at++;
                    removed = false;
                    return isValid();
                }

                public boolean isValid() {
                    return !removed && at < size();
                }

                public void remove() {
                    removeAt(at);
                    at--;
                    removed = true;
                }
            };
        }

    }

    static interface IntStream extends Iterable<Integer>, Comparable<IntStream> {
        public IntIterator intIterator();

        default public Iterator<Integer> iterator() {
            return new Iterator<Integer>() {
                private IntIterator it = intIterator();

                public boolean hasNext() {
                    return it.isValid();
                }

                public Integer next() {
                    int result = it.value();
                    it.advance();
                    return result;
                }
            };
        }

        default public int compareTo(IntStream c) {
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                int i = it.value();
                int j = jt.value();
                if (i < j) {
                    return -1;
                } else if (i > j) {
                    return 1;
                }
                it.advance();
                jt.advance();
            }
            if (it.isValid()) {
                return 1;
            }
            if (jt.isValid()) {
                return -1;
            }
            return 0;
        }

    }

    static interface IntIterator {
        public int value() throws NoSuchElementException;

        public boolean advance();

        public boolean isValid();

    }

    static interface IntCollection extends IntStream {
        public int size();

        default public int[] toArray() {
            int size = size();
            int[] array = new int[size];
            int i = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                array[i++] = it.value();
            }
            return array;
        }

    }

    static interface IntReversableCollection extends IntCollection {
    }

    static class IntArray extends IntAbstractStream implements IntList {
        private int[] data;

        public IntArray(int[] arr) {
            data = arr;
        }

        public int size() {
            return data.length;
        }

        public int get(int at) {
            return data[at];
        }

        public void removeAt(int index) {
            throw new UnsupportedOperationException();
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

    static class ArrayUtils {
        public static int[] range(int from, int to) {
            return Range.range(from, to).toArray();
        }

        public static int[] createOrder(int size) {
            return range(0, size);
        }

    }


    static abstract class IntAbstractStream implements IntStream {

        public String toString() {
            StringBuilder builder = new StringBuilder();
            boolean first = true;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                if (first) {
                    first = false;
                } else {
                    builder.append(' ');
                }
                builder.append(it.value());
            }
            return builder.toString();
        }


        public boolean equals(Object o) {
            if (!(o instanceof IntStream)) {
                return false;
            }
            IntStream c = (IntStream) o;
            IntIterator it = intIterator();
            IntIterator jt = c.intIterator();
            while (it.isValid() && jt.isValid()) {
                if (it.value() != jt.value()) {
                    return false;
                }
                it.advance();
                jt.advance();
            }
            return !it.isValid() && !jt.isValid();
        }


        public int hashCode() {
            int result = 0;
            for (IntIterator it = intIterator(); it.isValid(); it.advance()) {
                result *= 31;
                result += it.value();
            }
            return result;
        }

    }

    static class Range {
        public static IntList range(int from, int to) {
            int[] result = new int[Math.abs(from - to)];
            int current = from;
            if (from <= to) {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current++;
                }
            } else {
                for (int i = 0; i < result.length; i++) {
                    result[i] = current--;
                }
            }
            return new IntArray(result);
        }

    }
}

