package backjoon.silver.silver2;
import java.io.*;
import java.util.Stack;

public class bj1874 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        Stack<Integer> stk = new Stack<>();
        int N = Integer.parseInt(br.readLine());
        int start = 0;

        while(N-- > 0){
            int val = Integer.parseInt(br.readLine());
            if(start < val) {
                for(int i = start + 1; i <= val; i++) {
                    stk.push(i);
                    sb.append('+').append('\n');
                }
                start = val;
            }

            if(stk.peek() != val) {
                System.out.println("NO");
                return;
            }

            stk.pop();
            sb.append('-').append('\n');
        }
        System.out.println(sb);
    }
}
