import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Random;

import static java.lang.Integer.parseInt;

/**
 * @author egor@egork.net
 */
public class Tests {
    static Random rand = new Random(239);
    static int[] qty = {15, 15, 15, 15, 15, 15};
    static int[] n = {8, 32, 32, 128, 128};
    static int[] r = {256, 32 * 10, 32 * 32, 128 * 14, 128 * 7};
    static int[] c = {256, 32 * 32, 32 * 10, 128 * 14, 128 * 7};

    public static void main(String[] args) throws FileNotFoundException {
        int testGroup = parseInt(args[0]);
        int firstTest = parseInt(args[1]);
        int manual = 0;
        if (testGroup == 2) {
            OutputWriter out;
            int cn = n[testGroup];
            int[] permutation = new int[cn];
            out = new OutputWriter(new FileOutputStream(Integer.toString(firstTest + manual++)));
            for (int i = 0; i < cn; i++) {
                permutation[i] = i;
            }
            out.printLine(cn, r[testGroup], c[testGroup]);
            out.printLine(permutation);
            out.close();
            out = new OutputWriter(new FileOutputStream(Integer.toString(firstTest + manual++)));
            out.printLine(cn, r[testGroup], c[testGroup]);
            for (int i = 0; i < 2; i++) {
                int a = rand.nextInt(cn);
                int b = rand.nextInt(cn);
                int temp = permutation[a];
                permutation[a] = permutation[b];
                permutation[b] = temp;
            }
            out.printLine(permutation);
            out.close();
            out = new OutputWriter(new FileOutputStream(Integer.toString(firstTest + manual++)));
            for (int i = 0; i < cn; i++) {
                permutation[i] = cn - i - 1;
            }
            out.printLine(cn, r[testGroup], c[testGroup]);
            out.printLine(permutation);
            out.close();
            out = new OutputWriter(new FileOutputStream(Integer.toString(firstTest + manual++)));
            out.printLine(cn, r[testGroup], c[testGroup]);
            for (int i = 0; i < 2; i++) {
                int a = rand.nextInt(cn);
                int b = rand.nextInt(cn);
                int temp = permutation[a];
                permutation[a] = permutation[b];
                permutation[b] = temp;
            }
            out.printLine(permutation);
            out.close();
        }
        for (int i = 0; i < qty[testGroup] - manual; i++) {
            OutputWriter out = new OutputWriter(new FileOutputStream(Integer.toString(i + firstTest + manual)));
            int cn = n[testGroup];
            out.printLine(cn, r[testGroup], c[testGroup]);
            int[] permutation = new int[cn];
            for (int j = 0; j < cn; j++) {
                permutation[j] = j;
            }
            if (testGroup == 0) {
                int first = rand.nextInt(cn);
                int second = rand.nextInt(cn);
                int temp = permutation[first];
                permutation[first] = permutation[second];
                permutation[second] = temp;
            } else {
                for (int j = 1; j < cn; j++) {
                    int at = rand.nextInt(j + 1);
                    int temp = permutation[j];
                    permutation[j] = permutation[at];
                    permutation[at] = temp;
                }
            }
            out.printLine(permutation);
            out.close();
        }
    }
}

class OutputWriter {
    private final PrintWriter writer;

    public OutputWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public OutputWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void print(char[] array) {
        writer.print(array);
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

    public void print(long[] array) {
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

    public void printLine(long[] array) {
        print(array);
        writer.println();
    }

    public void printLine() {
        writer.println();
    }

    public void printLine(Object... objects) {
        print(objects);
        writer.println();
    }

    public void print(char i) {
        writer.print(i);
    }

    public void printLine(char i) {
        writer.println(i);
    }

    public void printLine(char[] array) {
        writer.println(array);
    }

    public void printFormat(String format, Object... objects) {
        writer.printf(format, objects);
    }

    public void close() {
        writer.close();
    }

    public void flush() {
        writer.flush();
    }

    public void print(long i) {
        writer.print(i);
    }

    public void printLine(long i) {
        writer.println(i);
    }

    public void print(int i) {
        writer.print(i);
    }

    public void printLine(int i) {
        writer.println(i);
    }

    public void separateLines(int[] array) {
        for (int i : array) {
            printLine(i);
        }
    }
}
