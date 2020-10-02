class Solution {
public:
    
    int t[1000][1000];
    
    int get(string s1,string s2,int x,int y){
        if(x==0 && y==0)return 0;
        if(t[x][y]!=-1)return t[x][y];
        if(x==0 && y>0)return t[x][y]=y;
        if(x>0 && y==0)return t[x][y]=x;
        if(s1[x]==s2[y]){
            return t[x][y]=get(s1,s2,x-1,y-1);
        }else{
            return t[x][y]=1+min(get(s1,s2,x-1,y-1),min(get(s1,s2,x-1,y),get(s1,s2,x,y-1)));
        }
    }
    
    int minDistance(string s1, string s2) {
        s1='!'+s1;
        s2='!'+s2;
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                t[i][j]=-1;
            }
        }
        int ans=get(s1,s2,n-1,m-1);
        return ans;
    }
};