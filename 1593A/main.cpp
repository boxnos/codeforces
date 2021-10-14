#if defined__GNUC__ && !defined __clang__
#pragma GCC optimize("Ofast")
#endif
#include <cstdio>
#include <utility>
#include <cctype>
#include <functional>
#include <array>

#include <algorithm>
using namespace std;
#define IO_
#define I_ inline
#define T_ template
#define TN_ typename
#define TT_ T_ <TN_ T>
#define HT_ T_ <TN_ H,TN_... T>
#define OP_(t) I_ operator t()
#ifdef IO_
namespace io {
	const int s=1<<18;char in[s],*i,*e,out[s],*o=out,*f=o+s-1;
	I_ char get(){return i==e?e=(i=in)+fread(in,1,s,stdin),i==e?EOF:*i++:*i++;}
	I_ void flush(){fwrite(out,1,o-out,stdout);o=out;}
	I_ void put(char c){*o++=c;if (o==f)flush();}
	struct flush_{~flush_(){flush();}} flush__;}
#define gcu io::get
#define pcu io::put
#else
#define gcu getchar
#define pcu putchar
#endif
struct in_ {
#ifdef _GLIBCXX_STRING
#define S_
	OP_(string){string s;for(char c;c=gcu(),c!=' '&&c!='\n';)s+=c;return s;}
	//OP_(string){string s;char c;while(isspace(c = gcu()));do{s+=c;}while(c=gcu(),c!=' '&&c!='\n'&&c!=EOF);return s;}
	I_ string read(int n,char c) {string v(n,c);for(char &i:v)i=gcu();gcu();return v;}
#endif
	OP_(char){char c=gcu();gcu();return c;}
#ifndef IO_
	OP_(double){double d; scanf("%lf",&d); gcu();return d;}
#endif
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
#define DEF_(r, n, ...) I_ r n(__VA_ARGS__) noexcept
#define OUT_(...) DEF_(void,out,__VA_ARGS__)
#define OUTL_(...) DEF_(void,outl,__VA_ARGS__)
OUT_(bool b){pcu('0'+b);}
OUT_(const char *s){while(*s)pcu(*s++);}
OUT_(char c){pcu(c);}
#ifdef S_
//OUT_(string &s){for(char c:s)pcu(c);}
OUT_(string s){for(char c:s)pcu(c);}
#endif
TT_ DEF_(void,OUTX_,T n){if(n<10)pcu(n+'0');else OUTX_(n/10),pcu(n%10+'0');}
TT_ OUT_(T n){if(n<0)pcu('-'),n=-n;OUTX_(n);}
TT_ OUT_(initializer_list<T> v){for(auto i{begin(v)};i!=end(v);++i)out(i==begin(v)?"":" "),out(*i);}
#ifdef _GLIBCXX_VECTOR
TT_ OUT_(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
HT_ OUT_(H &&h,T... t){out(h);out(t...);}
OUTL_(){out('\n');}
T_ <TN_... T> OUTL_(T... t){out(t...);outl();}
T_ <TN_ I,TN_... T> OUTL_(initializer_list<I> v,T... t){for(auto i{begin(v)};i!=end(v);++i)out(i==begin(v)?"":" "),out(*i);outl(t...);}
T_ <TN_ T=int> struct range{
	T e,b=0,s=1;range(T b,T e,T s):e(e),b(b),s(s){} range(T b,T e): e(e), b(b){} range(T e):e(e){}
	struct it{T v,s; it(T v,T s):v(v),s(s){} operator T()const{return v;} I_ operator T&(){return v;}T operator*()const{return v;}
		I_ it& operator++(){v+=s;return *this;}}; it begin(){return {b,s};} it end(){return {e,s};}};
#define Range(b,...)for([[maybe_unused]] auto b:range<int>((int) __VA_ARGS__))
#define dbg(...)fprintf(stderr,__VA_ARGS__)
using LL=long long;
#define tee(s,v)({dbg(s,v);v;})
#define TAPP(t,s)t tapp(t v){return tee(s, v);}
TAPP(char,"%c") TAPP(int,"%d") TAPP(LL,"%lld") TAPP(const char *, "%s") TAPP(bool, "%d")
#ifdef S_
string tapp(string s) {return tee("%s",s.c_str());}
#endif
TT_ T tapp(T v){for (auto i: v){tapp(i);dbg(" ");}return v;}
TT_ T tapl(T v){tapp(v);dbg("\n");return v;}

TT_ T sign(T a) {return (a > 0) - (a < 0);}
I_ int bsign(bool b){return b - !b;}
TT_ T eucdiv(T a, T b) {T t = a / b; return a % b < 0 ? t + sign(t): t;}
TT_ T eucmod(T a, T b) {T t = a % b; return t < 0 ? t + abs(b) : t;}

int main() {
	Range (t, in) {
		array<int, 3> a {in.read<3>()};
		int m = *max_element(begin(a), end(a));
		Range (i, 3)
			out(m - a[i] + (a[i] != m || m == a[(i + 1) % 3] || m == a[(i + 2) % 3]), ' ');
		outl();
	}
}

/* vim: set ts=4 noet: */
