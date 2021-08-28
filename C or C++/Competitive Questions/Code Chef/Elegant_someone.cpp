#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int a,b;
ll func(string s,int x,int y){
	char i='a'+x;
	char j='a'+y;
	ll temp=0;
	for(int k=0;k<s.size();k++){
		temp+=(k%2 ? (s[k]-j<0 ? 1LL*a*(j-s[k]) : 1LL*b*(s[k]-j) ) : (s[k]-i<0 ? 1LL*a*(i-s[k]) : 1LL*b*(s[k]-i) ) );
	}
	return temp;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,K;
		cin>>n>>K>>a>>b;
		string s;
		cin>>s;
		
		ll ans=INT_MAX;
		for(int k=0;k<=K;k++)
		for(int i=0;i<26;i++){
			int temp=0;
			if(i-k-1 >=0)ans=min(ans,func(s,i,i-k-1));
			//cout<<char('a'+i)<<" "<<char('a'+i-k-1)<<" "<<func(s,i,i-k-1)<<endl;
			if(i+k+1 <26)ans=min(ans,func(s,i,i+k+1));
			//out<<char('a'+i)<<" "<<char('a'+i+k+1)<<" "<<func(s,i,i+k+1)<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}