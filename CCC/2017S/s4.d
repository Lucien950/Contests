import std.stdio;
import std.algorithm;

struct edge {
    int src, des, w, o;

    int opCmp (ref const edge e) const {
        if(w != e.w) return w - e.w;
        else return o - e.o;
    }
};

const int MAXN = 100004, MAXM = 200004;
int N, M, D, ee, weight, days;
int[MAXN] ds;
edge[] edges;

void init() {
    for(int i=1;i<=N;i++) ds[i] = i;
}

int find(int x) {
    return ds[x] = (x == ds[x] ? x: find(ds[x]));
}

bool connected(int x, int y) {
    return find(x) == find(y);
}

bool merge(int x, int y) {
    int xr = find(x), yr = find(y);
    if(xr ^ yr) {
        ds[xr] = yr;
        return 1;
    }
    return 0;
}

void main() {
    scanf("%d%d%d", &N, &M, &D);
    for(int i=1, a, b, c;i<=M;i++) {
        scanf("%d%d%d", &a, &b, &c);
        if(i < N)
            edges ~= edge(a, b, c, 0);
        else
            edges ~= edge(a, b, c, 1);
    }

    //KRUSKALS BABEEEYYYYYY
    edges.sort();
    //UNIONFIND START
    init();
    int i, maxe=0;
    for(i=0;i<edges.length;i++) {
        //IF WE GOT A VALID SOLUTION
        if(ee == N - 1) break;
        auto e = edges[i];

        //IF THEY HAVE DIFFERENT ROOTS AND HAVE BEEN MERGED
        if(merge(e.src, e.des)) {
            ee++;
            //it is max because we are looking in order
            maxe = e.w;
            //if originally not on
            if(e.o)
                days ++;
        }
    }

    //Either days, or days - 1 is the answer
    //Want to replace a new edge with an old edge with same or lesser cost


    //IF THERE ARE EDGES THAT WERE ORIGINALLY ON, BUT NOW MUST BE TURNED OFF
    if(edges[i-1].o) {
        //RESET the graph (so all point to itself)
        init();

        //testing all the edges that haven't been used
        foreach(e;edges) {
            //IF THE NODES AREN't CONNECTED
            if(!connected(e.src, e.des)) {
                //edge.weight is smaller than the absolute max edge from the other graph
                //BASICALLY WE ARE MERGING ALL THE NODES THAT WERE ALTERNATIVES
                if(e.w < maxe || (e.w == maxe && !e.o))
                    //MERGE THEMMMM
                    merge(e.src, e.des);
                //IF edge was originally on, and edge weight is less than ENHANCER STRENGTH
                else if(!e.o && e.w <= D) {
                    //HAHA DAYS-1 TIME BABAYYYY
                    printf("%d", days - 1);
                    return;
                }
            }
        }
    }
    printf("%d", days);
}