package backjoon.silver.silver5;
import java.io.*;
import java.util.Scanner;

public class bj1789 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long S = Long.parseLong(br.readLine());
		
		//빼줄 값
		int N = 1;
		while(true) {
			if(S >= N) S -= N;
			//S보다 N이 작다면 반복을 종료해준다.
			else break;
			N++;
		}
		//--N을 해주는 이유는 N와 --는 순서상에 문제가 생기기에 N--를 하면 N을 출력하고 --를 한다.
		//그렇기에 빼주고 출력하기 위해 --를 앞에 두자.
		System.out.println(--N);
    }
}
