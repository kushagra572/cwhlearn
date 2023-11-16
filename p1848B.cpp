#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> pos(k+1,0);
        vector<vector<int>> vs(k+1,{n});
        for(int i=0;i<=n;i++){
            int dis= i-pos[v[i]];
            vs[v[i]].pop_back();
            vs[v[i]].push_back(dis);
            vs[v[i]].push_back(n-i-1);
            pos[v[i]]=i+1;
        }
        int a = n;
        for(int i=0;i<=k;i++){
            sort(vs[i].rbegin(),vs[i].rend());
            if(vs[i].size()>1){
                a = min(a,max(vs[i][1],vs[i][0]/2));
            }
            else{
                a=min(a,vs[i][0]/2);
            }
        }
        cout<<a<<endl;
    }
    return 0;
}