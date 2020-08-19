import java.util.*;

public class Main{
    static int N = 110;
    static int M = 420;
    static int Inf = (int)1e9;
    
    static int[] e = new int[M];
    static int[] ne = new int[M];
    static int[] h = new int[N];
    static int idx = 0;
    
    static int[] w = new int[M];
    static int[] dist = new int[N];
    
    static int n, m;
    static int[] val = new int[N];
    static int[] st = new int[N];
    
    public static void main(String[] args){
        Arrays.fill(h, -1);
        
        Scanner cin = new Scanner(System.in);
        
        n = cin.nextInt();
        
        for (int i = 1; i <= n; i ++){
            val[i] = cin.nextInt();
        }
        
        m = cin.nextInt();
        
        for (int i = 0; i < m; i ++){
            int a = cin.nextInt() + 1;
            int b = cin.nextInt() + 1;
            st[b] ++;
            System.out.println(a + " " + b + " " + val[b]);
            add(a, b, val[b]);
        }
        
        for (int i = 1; i <= n; i ++){
            if (st[i] == 0){
                add(0, i, val[i]);
            }
        }
        
        int res = spfa();
        
        System.out.print(res);
    }
    
    static void add(int a, int b, int c){
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx ++;
    }
    
    static int spfa(){
        
        Arrays.fill(dist, 0);
        
        Queue<Integer> q = new LinkedList<>();
        
        q.add(0);
        
        dist[0] = 0;
        
        while (!q.isEmpty()){
            
            int a = q.remove();
            
            for (int i = h[a]; i != -1; i = ne[i]){
                int b = e[i];
                
                if (dist[b] < dist[a] + w[i]){
                    dist[b] = dist[a] + w[i];
                    q.add(b);
                }
            }
        }
        
        int res = -Inf;
        for (int i = 1; i <= n; i ++){
            res = Math.max(res, dist[i]);
        }
        
        return res;
    }
}
