package backjoon.silver.silver5;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class a2751 {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringBuilder sb = new StringBuilder();

		/*
		  -1000000 ~ 1000000
		  기준점 0 = index 100000 으로 생각
		*/
        boolean[] arr = new boolean[2000001];

        int N = Integer.parseInt(br.readLine());

        for(int i = 0; i < N; i++) {
            arr[Integer.parseInt(br.readLine()) + 1000000] = true;
        }

        for(int i = 0; i < arr.length; i++) {
            if(arr[i])
                sb.append((i - 1000000)).append('\n');
        }

        bw.write(sb.toString());
        bw.flush();
    }

    // i: 정렬된 왼쪽 리스트에 대한 인덱스
    // j: 정렬된 오른쪽 리스트에 대한 인덱스
    // k: 정렬될 리스트에 대한 인덱스
    /* 2개의 인접한 배열 list[left...mid]와 list[mid+1...right]의 합병 과정 */
    /* (실제로 숫자들이 정렬되는 과정) */
    /*static void merge(int[] list, int left, int mid, int right){
        int i = left;
        int j = mid + 1;
        int k = left;
        int[] sorted = new int[list.length];
        // 분할 정렬된거 합병
        while(i<=mid && j<=right) {
            if (list[i] <= list[j])
                sorted[k++] = list[i++];
            else
                sorted[k++] = list[j++];
        }
        // 남아 있는 값들을 일괄 복사
        if(i>mid){
            for(int l=j; l<=right; l++)
                sorted[k++] = list[l];
        }
        // 남아 있는 값들을 일괄 복사
        else{
            for(int l=i; l<=mid; l++) {
                sorted[k++] = list[l];
            }
        }
        for(int l = left;l <= right;l++)
            list[l] = sorted[l];
    }*/

    //static void merge_sort(int list[], int left, int right){
        /*if(left<right){
            int mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
            merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
            merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
            merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
        }*/

        /*
         * 1 - 2 - 4 - 8 - ... 식으로 1부터 서브리스트를 나누는 기준을 두 배씩 늘린다.
         */
        //for(int size = 1; size <= right; size += size) {

            /*
             * 두 부분리스트을 순서대로 병합해준다.
             * 예로들어 현재 부분리스트의 크기가 1(size=1)일 때
             * 왼쪽 부분리스트(low ~ mid)와 오른쪽 부분리스트(mid + 1 ~ high)를 생각하면
             * 왼쪽 부분리스트는 low = mid = 0 이고,
             * 오른쪽 부분리스트는 mid + 1부터 low + (2 * size) - 1 = 1 이 된다.
             *
             * 이 때 high가 배열의 인덱스를 넘어갈 수 있으므로 right와 둘 중 작은 값이
             * 병합되도록 해야한다.
             */
            /*for(int l = 0; l <= right - size; l += (2 * size)) {
                int low = l;
                int mid = l + size - 1;
                int high = Math.min(l + (2 * size) - 1, right);
                merge(list, low, mid, high);		// 병합작업
            }
        }
    }*/
}