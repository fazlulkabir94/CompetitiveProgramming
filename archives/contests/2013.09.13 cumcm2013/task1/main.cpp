#ifndef DEBUG
//https://github.com/boleynsu/acmicpc-codes/blob/master/templates/Core.hpp
/*
 * Package: StandardCodeLibrary.Core
 * */
//引进常用的头文件并使用std名字空间;
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

//用于减少代码量的宏;
#define lp for(;;)
#define repf(i,a,b) for (int i=(a);i<(b);++i)
#define ft(i,a,b) for (int i=(a);i<=(b);++i)
#define fdt(i,a,b) for (int i=(a);i>=(b);--i)
#define rrepf(i,a,b) fdt(i,(a)-1,b)
#define rep(i,n) repf(i,0,n)
#define rrep(i,n) rrepf(i,n,0)
#define for_nonempty_subsets(subset,set) for (int subset=set;subset;subset=(subset-1)&(set))
#define for_in_charset(i,charset) for (cstr i=(charset);*i;i++)
#define whl while
#define rtn return
#define fl(x,y) memset((x),char(y),sizeof(x))
#define clr(x) fl(x,char(0))
#define cpy(x,y) memcpy(x,y,sizeof(x))
#define sf scanf
#define pf printf
#define vec vector
#define pr pair
#define que queue
#define prq priority_queue
#define itr iterator
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define ins insert
#define ers erase
#define lb lower_bound
#define ub upper_bound
#define rnk order_of_key
#define sel find_by_order
#define sz(x) (int((x).size()))
#define all(x) (x).begin(),(x).end()
#define srt(x) sort(all(x))
#define uniq(x) srt(x),(x).erase(unique(all(x)),(x).end())
#define rev(x) reverse(all(x))
#define shf(x) random_shuffle(all(x))
#define nxtp(x) next_permutation(all(x))

//调试相关的宏;
#ifndef DEBUG
#define prt(x) (cerr)
#define asrtWA(s) do if(!(s))exit(0);whl(0)
#define asrtTLE(s) do if(!(s))whl(1);whl(0)
#define asrtMLE(s) do if(!(s))whl(new int);whl(0)
#define asrtOLE(s) do if(!(s))whl(1)puts("OLE");whl(0)
#define asrtRE(s) do if(!(s))*(int*)0=0;whl(0)
#define runtime() (cerr)
#define input(in) freopen(in,"r",stdin)
#define output(out) freopen(out,"w",stdout)
#else
#define prt(x) cerr<<"第"<<__LINE__<<"行\t: "<<#x"\t="<<(x)<<endl
#define asrtWA(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtTLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtMLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtOLE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define asrtRE(s) do if(!(s))cerr<<"assert("#s")"<<endl;whl(0)
#define runtime() cerr<<"Used: "<<db(clock())/CLOCKS_PER_SEC<<"s"<<endl
#define input(in)
#define output(out)
#endif

//常用数据类型;
typedef long long int lli;
typedef double db;
typedef const char* cstr;
typedef string str;
typedef vec<int> vi;
typedef vec<vi> vvi;
typedef vec<lli> vl;
typedef vec<vl> vvl;
typedef vec<bool> vb;
typedef vec<vb> vvb;
typedef vec<char> vc;
typedef vec<vc> vvc;
typedef vec<str> vs;
typedef pr<int,int> pii;
typedef pr<lli,lli> pll;
typedef pr<db,db> pdd;
typedef vec<pii> vpii;
typedef vec<pll> vpll;
typedef vec<pdd> vpdd;
typedef map<int,int> mii;
typedef map<str,int> msi;
typedef map<char,int> mci;
typedef set<int> si;
typedef set<str> ss;
typedef que<int> qi;

//常用常量:int的最大值;lli的最大值;db的误差相关常数;欧拉常数;圆周率;移动向量;取模使用的除数;
int oo=(~0u)>>1;
lli ooll=(~0ull)>>1;
db inf=1e+10;
db eps=1e-10;
db gam=0.5772156649015328606;
db pi=acos(-1.0);
int dx[]={1,0,-1,0,1,-1,-1,1,0};
int dy[]={0,1,0,-1,1,1,-1,-1,0};
int MOD=1000000007;

//常用函数:最大最小值更新;数学相关函数;输入和输出;树状数组;并查集;可合并堆;
template<typename type>inline bool cmax(type& a,const type& b){rtn a<b?a=b,true:false;}
template<typename type>inline bool cmin(type& a,const type& b){rtn b<a?a=b,true:false;}
template<typename type>inline type sqr(const type& x){rtn x*x;}
template<typename type>inline type mod(const type& x){rtn x%MOD;}
inline int sgn(const db& x){rtn (x>+eps)-(x<-eps);}
inline int dbcmp(const db& a,const db& b){rtn sgn(a-b);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& x){rtn mp(-x.x,-x.y);}
template<typename type>inline pr<type,type> operator+(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x+b.x,a.y+b.y);}
template<typename type>inline pr<type,type> operator-(const pr<type,type>& a,const pr<type,type>& b){rtn mp(a.x-b.x,a.y-b.y);}
template<typename type>inline pr<type,type> operator*(const pr<type,type>& a,const type& b){rtn mp(a.x*b,a.y*b);}
template<typename type>inline pr<type,type> operator/(const pr<type,type>& a,const type& b){rtn mp(a.x/b,a.y/b);}
template<typename type>inline pr<type,type>& operator-=(pr<type,type>& a,const pr<type,type>& b){rtn a=a-b;}
template<typename type>inline pr<type,type>& operator+=(pr<type,type>& a,const pr<type,type>& b){rtn a=a+b;}
template<typename type>inline pr<type,type>& operator*=(pr<type,type>& a,const type& b){rtn a=a*b;}
template<typename type>inline pr<type,type>& operator/=(pr<type,type>& a,const type& b){rtn a=a/b;}
template<typename type>inline type cross(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.y-a.y*b.x;}
template<typename type>inline type dot(const pr<type,type>& a,const pr<type,type>& b){rtn a.x*b.x+a.y*b.y;}
template<typename type>inline type gcd(type a,type b){if(b)whl((a%=b)&&(b%=a));rtn a+b;}
template<typename type>inline type lcm(type a,type b){rtn a*b/gcd(a,b);}
inline lli bin_pow(lli x,lli y){lli z=1;whl(y){if(y&1)z=mod(z*x);x=mod(sqr(x)),y>>=1;}rtn z;}
template<typename istream,typename first_type,typename second_type>inline istream& operator>>(istream& cin,pr<first_type,second_type>& x){rtn cin>>x.x>>x.y;}
template<typename ostream,typename first_type,typename second_type>inline ostream& operator<<(ostream& cout,const pr<first_type,second_type>& x){rtn cout<<x.x<<" "<<x.y;}
template<typename istream,typename type>inline istream& operator>>(istream& cin,vec<type>& x){rep(i,sz(x))cin>>x[i];rtn cin;}
template<typename ostream,typename type>inline ostream& operator<<(ostream& cout,const vec<type>& x){rep(i,sz(x))cout<<x[i]<<(i+1==sz(x)?"":" ");rtn cout;}
inline ostream& pdb(int prcs,db x){rtn cout<<setprecision(prcs)<<fixed<<(sgn(x)?(x):0);}
template<typename type>inline void bit_inc(vec<type>& st,int x,type inc){whl(x<sz(st))st[x]+=inc,x|=x+1;}
template<typename type>inline type bit_sum(const vec<type>& st,int x){type s=0;whl(x>=0)s+=st[x],x=(x&(x+1))-1;rtn s;}
template<typename type>inline type bit_kth(const vec<type>& st,int k){int x=0,y=0,z=0;whl((1<<(++y))<=sz(st));rrep(i,y){if((x+=1<<i)>sz(st)||z+st[x-1]>k)x-=1<<i;else z+=st[x-1];}rtn x;}
inline void make_set(vi& st){rep(i,sz(st))st[i]=i;}
inline int find_set(vi& st,int x){int y=x,z;whl(y!=st[y])y=st[y];whl(x!=st[x])z=st[x],st[x]=y,x=z;rtn y;}
inline bool union_set(vi& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?st[a]=b,true:false;}
inline void make_set(vpii& st){rep(i,sz(st))st[i]=mp(i,1);}
inline int find_set(vpii& st,int x){int y=x,z;whl(y!=st[y].x)y=st[y].x;whl(x!=st[x].x)z=st[x].x,st[x].x=y,x=z;rtn y;}
inline bool union_set(vpii& st,int a,int b){a=find_set(st,a),b=find_set(st,b);rtn a!=b?(st[a].y>st[b].y?st[a].x=b,st[a].y+=st[b].y:st[b].x=a,st[b].y+=st[a].y),true:false;}
template<typename type>inline void merge(type& a,type& b){if(sz(a)<sz(b))swap(a,b);whl(sz(b))a.ins(*b.begin()),b.ers(b.begin());}

//初始化;
struct Initializer{
#ifndef DEBUG
Initializer(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
#else
~Initializer(){runtime();}
#endif
}initializer;

////非标准;
//#define for_each(e,s) for (__typeof__((s).begin()) e=(s).begin();e!=(s).end();++e)
//#include <ext/rope>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/tag_and_trait.hpp>
//typedef __gnu_cxx::rope<char> rope;
//template<typename key,typename value>class ext_map:public __gnu_pbds::tree<key,value,less<key>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>{};
//#define ctz __builtin_ctz
//#define clz __builtin_clz
//#define bc __builtin_popcount
#else
//上面部分的代码生成的Precompiled Headers
#include <Core>
#endif

const int LIGHTEST_BLACK=30;

void read(vvi& c,cstr path)
{
	FILE* file=fopen(path,"r+b");

	char header[54];
	fread(header,sizeof (char),54,file);

	int w=*(int*)&header[18],h=*(int*)&header[22];

	char tab[1024];
	fread(tab,sizeof (char),1024,file);

	char data[w*h];
	fread(data,sizeof (char),w*h,file);
	c=vvi(h,vi(w));
	rep(i,h)
		rep(j,w)
			c[h-1-i][j]=(unsigned char)data[i*w+j];
}

void write(vec<vvi>& cs,vi& lst,vvi& cost,vi& lcost,vi& rcost)
{
	ofstream cout("output/cost.txt");
	cout<<"Lcost:"<<endl<<lcost<<endl;
	cout<<"Rcost:"<<endl<<rcost<<endl;
	cout<<"Cost:"<<endl;
	rep(i,sz(cost)) cout<<cost[i]<<endl;
	ofstream tout("output/table.txt");
	tout<<lst<<endl;
	FILE* file=fopen("output/picture.bmp","w+b");
	char header[54]={
		'B','M',
		0,0,0,0,
		0,0,
		0,0,
		54,0,0,0,
		40,0,0,0,
		0,0,0,0,
		0,0,0,0,
		1,0,
		8,0,
		0,0,0,0,
		0,0,0,0,
		0x13,0x0B,0,0,
		0x13,0x0B,0,0,
		0,0,0,0,
		0,0,0,0
	};
	int w=0,h=sz(cs.front());
	rep(i,sz(lst)) w+=sz(cs[lst[i]].front());
	*(int*)&header[18]=w;
	*(int*)&header[22]=h;
	*(int*)&header[2]=54+1024+w*h;
	*(int*)&header[46]=w*h;
	fwrite(header,sizeof (char),54,file);

	rep(i,256)
	{
		char palette[4]={(char)i,(char)i,(char)i,0};
		fwrite(palette,sizeof (char),4,file);
	}

	rrep(i,h)
		rep(j,sz(lst))
			rep(k,sz(cs[lst[j]][i]))
				fwrite(&cs[lst[j]][i][k],sizeof (char),1,file);
}

int main(int argc,char* argv[])
{
	int n;
	n=19;

	vec<vvi> cs(n);
	rep(i,n)
	{
		vvi& c=cs[i];
		char path[1024];
		sprintf(path,"input/%03d.bmp",i);
		read(c,path);
		sprintf(path,"output/%03d.txt",i);
		ofstream fout(path);
		rep(i,sz(c))
		{
			rep(j,sz(c[i])) fout<<(c[i][j]?'*':' ');
			fout<<endl;
		}
	}
	vvi cost(n,vi(n));
	vi lcost(n),rcost(n);
	rep(i,n)
	{
		rep(j,n) rep(k,sz(cs[i])) cost[i][j]+=abs(cs[i][k].back()-cs[j][k].front());
		rep(j,sz(cs[i])) lcost[i]+=255-cs[i][j].front(),rcost[i]+=255-cs[i][j].back();
	}

	vvi dp(1<<n,vi(n,+oo));
	vvi opt(1<<n,vi(n));
	repf(i,1,1<<19)
	{
		rep(j,n) if (i&(1<<j))
		{
			int pi=i^(1<<j);
			if (pi)
			{
				rep(pj,n) if (pi&(1<<pj))
					if (cmin(dp[i][j],dp[pi][pj]+cost[pj][j]))
						opt[i][j]=pj;
			}
			else
			{
				dp[i][j]=lcost[j];
			}
		}
	}
	int ans=+oo,st=(1<<n)-1,op;
	rep(i,n) if (cmin(ans,dp[st][i]+rcost[i])) op=i;
	vi lst;
	rep(i,n)
	{
		lst.pb(op);
		int tmp=op;
		op=opt[st][op];
		st^=1<<tmp;
	}
	rev(lst);
	write(cs,lst,cost,lcost,rcost);
}
