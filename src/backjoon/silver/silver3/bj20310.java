import java.io.*;

public class Main {
    private void solution() throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        char[] arr = new char[str.length()];
        int cnt0 = 0;
        int cnt1 = 0;
        for(int i = 0; i < arr.length; i++){
            arr[i] = str.charAt(i);
            if(arr[i] == '0')
                cnt0++;
            else
                cnt1++;
        }
        cnt0 /= 2;
        cnt1 /= 2;

        for(int i = 0; i < str.length() && cnt1 != 0; i++){
            if(arr[i] == '1'){
                cnt1--;
                arr[i] = 0;
            }
        }

        for (int i = str.length() - 1; i >= 0 && cnt0 != 0; i--) {
            if (arr[i] == '0') {
                cnt0--;
                arr[i] = 0;
            }
        }

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i < str.length(); i++){
            if(arr[i] != 0)
                ans.append(arr[i]);
        }
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception{
        new Main().solution();
    }
}