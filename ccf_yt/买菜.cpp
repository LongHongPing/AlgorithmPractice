#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ans=0;//ans�洢���ս��
    cin>>n;
    vector<pair<int,int>>v1(n),v2(n);//�ֱ�洢СH��СW��װ��ʱ���
    for(int i=0;i<n;++i)
    	cin>>v1[i].first>>v1[i].second;
        //scanf("%d%d",&v1[i].first,&v1[i].second);
    for(int i=0;i<n;++i)
    	cin>>v2[i].first>>v2[i].second;
        //scanf("%d%d",&v2[i].first,&v2[i].second);
    for(pair<int,int>p1:v1)
        for(pair<int,int>p2:v2)
            if(p1.first<=p2.second&&p1.second>=p2.first)//�ж������ص�����
                ans+=min(p1.second,p2.second)-max(p1.first,p2.first);//�����ص�����
    cout<<ans;
    return 0;
}

