// name = messy_java_ok.java, type = java8

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




public class alksjdlkjsdkksdjs {}

