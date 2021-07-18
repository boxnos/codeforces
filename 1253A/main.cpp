#if defined__GNUC__ && !defined __clang__
#pragma GCC optimize("O3")
#endif
#include <cstdio>
#include <utility>
#include <cctype>
#include <functional>
#include <array>

#include <string>
#include <algorithm>
#include <climits>
using namespace std;

#ifdef _WIN32
#define U_(s) _##s##_nolock
#define _CRT_DISABLE_PERFCRIT_LOCKS
#else
#define U_(s) s##_unlocked
#endif
#define gcu U_(getchar)
#define pcu U_(putchar)
#define DEF_(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define T_ template
#define TN_ typename
#define TT_ T_ <TN_ T>
#define HT_ T_ <TN_ H,TN_... T>
#define I_ inline
#define OP_(t) I_ operator t()
struct in_ {
#ifdef _GLIBCXX_STRING
	OP_(string){string s;for(char c;c=gcu(),c!=' '&&c!='\n';)s+=c;return s;}
	//OP_(string){string s;char c;while(isspace(c = gcu()));do{s+=c;}while(c=gcu(),c!=' '&&c!='\n'&&c!=EOF);return s;}
#define S_
#endif
	OP_(char){char c=gcu();gcu();return c;}
	OP_(double){double d; scanf("%lf",&d); gcu();return d;}
	//TT_ OP_(T){T n{},c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return n;}
	TT_ OP_(T){T n{},m{1},c=gcu();if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
	//TT_ OP_(T){T n{},m{1},c;while(isspace(c=gcu()));if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
#ifdef _GLIBCXX_VECTOR
#define TI_ T_<TN_ T=vector<int>, TN_ I=TN_ T::value_type>
	TI_ I_ T read(int n) {T v(n);for(I &i:v)i=*this;return v;}
	TI_ I_ T read(int n,function<int(TN_ T::value_type)>f){T v(n);for(I &i:v)i=f(*this);return v;}
	TI_ I_ T read(int n,function<void(TN_ T::value_type&,TN_ T::value_type)>f){T v(n);for(I &i:v)f(i,*this);return v;}
#endif
	T_ <int N, TN_ T=int> array<T, N> read() {array<T, N> a;for (T &i: a)i=*this;return a;}
} in;
#define SCAN_(...) DEF_(bool,scan,__VA_ARGS__)
#ifdef S_
SCAN_(string &o) {int c{gcu()};if(c==EOF)return false;else{ungetc(c,stdin);string t=move(in);o=t;return true;}}
#endif
TT_ SCAN_(T &o) {int c{gcu()};return c==EOF?false:(ungetc(c,stdin),o=in,true);}
HT_ SCAN_(H &h,T&&... t){return scan(h)&&scan(t...);}
#define OUT_(...) DEF_(void,out,__VA_ARGS__)
#define OUTL_(...) DEF_(void,outl,__VA_ARGS__)
OUT_(bool b){pcu('0'+b);}
OUT_(const char *s){while(*s)pcu(*s++);}
OUT_(char c){pcu(c);}
#ifdef S_
//OUT_(string &s){for(char c:s)pcu(c);}
OUT_(string s){for(char c:s)pcu(c);}
#endif
//OUT_(int n) {printf("%d",n);}
TT_ DEF_(void,OUTX_,T n){if(n<10)pcu(n+'0');else OUTX_(n/10),pcu(n%10+'0');}
TT_ OUT_(T n){if(n<0)pcu('-'),n=-n;OUTX_(n);}
//TT_ OUT_(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
TT_ OUT_(initializer_list<T> &v){for(auto i{begin(v)};i!=end(v);++i)out(i==begin(v)?"":" "),out(*i);}
#ifdef _GLIBCXX_VECTOR
TT_ OUT_(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
HT_ OUT_(H &&h, T... t){out(h);out(t...);}
OUTL_(){out('\n');}
T_ <TN_... T> OUTL_(T... t){out(t...);outl();}
T_ <TN_ I, TN_... T> OUTL_(initializer_list<I> i, T... t){out(i);outl(t...);}
T_ <TN_ T=int> struct range{
	T e,b=0,s=1;range(T b,T e,T s):e(e),b(b),s(s){} range(T b,T e): e(e), b(b){} range(T e):e(e){}
	struct it{T v,s; it(T v,T s):v(v),s(s){} operator T()const{return v;} I_ operator T&(){return v;}T operator*()const{return v;}
		I_ it& operator++(){v+=s;return *this;}}; it begin(){return {b,s};} it end(){return {e,s};}};
#define Range(b, ...) for([[maybe_unused]] auto b: range((int) __VA_ARGS__))
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using LL = long long;
#define tee(s,v) ({dbg(s,v);v;})
#define TAPP(t, s) t tapp(t v) {return tee(s, v);}
TAPP(char, "%c") TAPP(int, "%d") TAPP(LL, "%lld")
#ifdef S_
string tapp(string s) {return tee("%s", s.c_str());}
#endif
TT_ T tapp(T v){for (auto i: v){tapp(i);dbg(" ");}return v;}
TT_ T tapl(T v){tapp(v);dbg("\n");return v;}

int main() {
	Range (t, in) {
		int n {in}, c {}, d {INT_MAX};
		vector<int> a {in.read(n)};
		Range (i, n) {
			int x {(int) in - a[i]};
			if (d != x) {
				d = x;
				if (x < 0)
					c = -1;
				else if (x && c >= 0)
					c++;
			}
		}
		outl(c == 0 || c == 1 ? "YES" : "NO");
	}
}

/* vim: set ts=4 noet: */
