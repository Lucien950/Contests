#include<iostream>
#include<vector>

using namespace std;

struct Point{
public:
        Point (int _x=0, int _y=0){x=_x;y=_y;}
        int x,y;
        bool operator <(Point p){
              return (x<p.x||(x==p.x && y<p.y));
        }

};

struct Segment{
public:
        Segment(Point _p1=Point(0,0),Point _p2=Point(0,0),int _dir=1){
            if (_p2<_p1) swap(_p1,_p2);

            p1=_p1;
            p2=_p2;
            dir=_dir;
        }
        int d(){
            if(p1.y==p2.y) return 1;
            return -1;
        }
        int len(){
            if (d()==1) return p2.x-p1.x;
            return p2.y-p1.y;
        }

        Point p1,p2;
        int dir;
};
bool ret[100];
int main(){

        int lvl,wid,x,i,ii;
        cin>>lvl>>wid>>x;

//        segment is vector with Segment(from (0, 1) to (wid, 1) and direction 1)
        vector<Segment> arr(1,Segment(Point(0,1),Point(wid,1),1));
        Segment s;
        Point p1,p2,p3,p4;

//        ITERATE ON LEVELS
        for (ii=1;ii<=lvl;ii++){
//                WORK BACKWARDS ON ARRAY
                for (i=arr.size()-1;i>=0;i--){
//                      extract and wipe i from array
                        s=arr[i];
                        arr.erase(arr.begin()+i,arr.begin()+i+1);
                        if (s.d()==1){
//                              direction is (1)
                                p1=Point( s.p1.x+s.len()/3 , s.p1.y );
                                p2=Point( s.p1.x+s.len()/3 , s.p1.y+s.dir*s.len()/3 );
                                p3=Point(s.p1.x+2*s.len()/3,s.p1.y+s.dir*s.len()/3);
                                p4=Point(s.p1.x+2*s.len()/3,s.p1.y);

                        }
                        else{
                                p1=Point(s.p1.x,s.p1.y+s.len()/3);
                                p2=Point(s.p1.x+s.dir*s.len()/3,s.p1.y+s.len()/3);
                                p3=Point(s.p1.x+s.dir*s.len()/3,s.p1.y+2*s.len()/3);
                                p4=Point(s.p1.x,s.p1.y+2*s.len()/3);

                        }
                        arr.push_back(Segment(s.p1,p1,s.dir));
                        arr.push_back(Segment(p1,p2,-1));
                        arr.push_back(Segment(p2,p3,s.dir));
                        arr.push_back(Segment(p3,p4,1));
                        arr.push_back(Segment(p4,s.p2,s.dir));

                }
        }

        for (ii=0;ii<arr.size();ii++){
                if (arr[ii].p1.x==arr[ii].p2.x && arr[ii].p1.x==x)
                        for (i=arr[ii].p1.y;i<=arr[ii].p2.y;i++)
                                ret[i]=true;
                else if (arr[ii].p1.x<=x && x<=arr[ii].p2.x)
                        ret[arr[ii].p1.y]=true;
        }
        for (i=0;i<=81;i++)
                if (ret[i])
                        cout<<i<<" ";
        cout<<endl;

        return 0;
}