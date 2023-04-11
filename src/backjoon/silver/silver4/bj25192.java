package backjoon.silver.silver4;

public class bj25192 {
    public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int ans = 0;
		HashSet<String> hs = new HashSet<>();
		
		while(N-->0) {
		    String name = sc.next();
		    
		    if(name.equals("ENTER")){
		        hs = new HashSet<>();
		        continue;
		    }
		    if(!hs.contains(name)){
		        hs.add(name);
		        ans++;
		    }
		}
		System.out.println(ans);
	}
}
