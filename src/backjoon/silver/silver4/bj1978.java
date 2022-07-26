package backjoon.silver.silver4;
import java.io.*;

public class bj1978 {

    public static void main (String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n];
        String[] input = br.readLine().split(" ");
        for(int i = 0;i < n;i++)
            nums[i] = Integer.parseInt(input[i]);

        int count = 0;
        a : for(int i = 0;i < n;i++){
            if(nums[i] % 2 == 0 || nums[i] == 1) {
                if(nums[i] == 2)
                    count++;
                continue;
            }
            for(int j = 3;j < nums[i];j += 2){
                if(nums[i] % j == 0)
                    continue a;
            }
            count++;
        }
        bw.write(count + "");
        bw.flush();
    }
}

/*    boolean is_Prime(int Number) {

        // 1 은 소수가 아니다.
        if(Number == 1){
            return false;
        }


        // 2 ~ Number-1 까지 중 나누어 떨어지는 약수가 있는지 판별
        // Number = 2 의 경우는 자연스럽게 for문을 검사하지 않게 됨
        아니면 2~제곱근까지만해도 가능

        for(int i = 2; i < Number; i++) {

            if(N % i == 0) return false;

        }

        // 위 두 조건에 걸리지 않으면 소수다.
        return true;
    } */