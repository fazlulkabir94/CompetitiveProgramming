//Boleyn Su's Template for Codeforces
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

#define lp for(;;)
#define rep(i,n) for (int i=0;i<(n);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=b;--i)
#define foreach(e,set,type) for (type::iterator e=(set).begin();e!=(set).end();++e)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,0)
#define sqr(x) (x)*(x)
#define lb(x) (x)&(-(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define prt(x) cout<<#x<<"="<<(x)<<endl
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)

typedef long long int lli;
typedef double db;
typedef char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<string> vs;
typedef pr<int, int> pii;
typedef pr<str,int> psi;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;
typedef prq<int> pqi;

const int oo=(~0u)>>1;
const lli ooll=(~0ull)>>1;
const db inf=1e100;
const db eps=1e-8;
const db pi=acos(-1.0);

template<typename type>inline bool cmax(type& a,const type& b){return a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){return a>b?a=b,true:false;}
template<typename type>inline int sgn(const type& x){return (x>0)-(x<0);}
template<>inline int sgn(const db& x){return (x>+eps)-(x<-eps);}
template<typename type>
void inc(vec<type>& st,int x,type inc){whl(x<sz(st)) st[x]+=inc,x+=lb(x);}
template<typename type>
type sum(vec<type>& st,int x){type s=0;while (x>0) s+=st[x],x-=lb(x);rtn s;}

int main()
{
	int n,k;
	cin>>n>>k;
	str l,r;
	cin>>l>>r;
	vvi adj(n*2);
	rep(i,n)
	{
		if (l[i]=='-'&&i+1<n&&l[i+1]=='-') adj[i].pb(i+1);
		if (l[i]=='-'&&i+1>=n) adj[i].pb(n*2);
		if (r[i]=='-'&&i+1<n&&r[i+1]=='-') adj[n+i].pb(n+i+1);
		if (r[i]=='-'&&i+1>=n) adj[n+i].pb(n*2);

		if (l[i]=='-'&&i-1>=0&&l[i-1]=='-') adj[i].pb(i-1);
		if (r[i]=='-'&&i-1>=0&&r[i-1]=='-') adj[n+i].pb(n+i-1);

		if (l[i]=='-'&&i+k<n&&r[i+k]=='-') adj[i].pb(n+i+k);
		if (l[i]=='-'&&i+k>=n) adj[i].pb(n*2);

		if (r[i]=='-'&&i+k<n&&l[i+k]=='-') adj[n+i].pb(i+k);
		if (r[i]=='-'&&i+k>=n) adj[n+i].pb(n*2);
	}
	vi d(n*2+1);
	qi q;
	q.push(0);
	d[0]=1;
	while (!q.empty())
	{
		int qh=q.front();
		q.pop();
		//prt(qh/n);
		//prt(qh%n);
		//prt(d[qh]);
		if (qh==n*2)
		{
			cout<<"YES"<<endl;
			rtn 0;
		}
		rep(i,sz(adj[qh]))
		{
			//prt(adj[qh][i]);
			if (adj[qh][i]==n*2||(!d[adj[qh][i]]&&adj[qh][i]%n>=d[qh]))
				q.push(adj[qh][i]),d[adj[qh][i]]=d[qh]+1;
		}
	}
	cout<<"NO"<<endl;
}

