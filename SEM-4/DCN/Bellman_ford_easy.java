import java.util.*;
class Bellman_ford_easy {
    public static void main(String[] args) {
        System.out.println("Try programiz.pro");
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter np. of vertices: ");
        int ver=sc.nextInt();
        int inf=999999;
        int[] dist=new int[ver];
        for(int i=0;i<ver;i++){
            dist[i]=inf;
        }
        System.out.println("Enter no. of edges: ");
        int edge=sc.nextInt();
        System.out.println("Enter root: ");
        int root=sc.nextInt();
        dist[root]=0;
        
        int u[]=new int[edge];
        int v[]=new int[edge];
        int wt[]=new int[edge];
        for(int i=0;i<edge;i++){
            System.out.println("Enter u,v,wt :");
            u[i]=sc.nextInt();
            v[i]=sc.nextInt();
            wt[i]=sc.nextInt();
        }
        
        for(int i=0;i<edge;i++){                 // main code segment
            for(int j=0;j<edge;j++){
                if (dist[u[j]]+wt[j]<=dist[v[j]]){
                    dist[v[j]]=dist[u[j]]+wt[j];
                }
            }
        }
        int f=0;
        
        for(int j=0;j<edge;j++){
            if (dist[u[j]]+wt[j]<dist[v[j]]){
                f=1;
            }
        }                                           // main code end
        
        if(f==1){
            System.out.print("negative cycle detected!!");
        }
        else{
            for(int j=0;j<ver;j++){
                System.out.print(dist[j]);
            }
        }
    }
}