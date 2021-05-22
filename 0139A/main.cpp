#pragma GCC optimize("O3")
#include <cstdio>
#include <utility>
#include <cctype>
#include <functional>
#include <array>

#include <vector>
#include <algorithm>
using namespace std;

#ifdef _WIN32
#define _U(s) _##s##_nolock
#define _CRT_DISABLE_PERFCRIT_LOCKS
#else
#define _U(s) s##_unlocked
#endif
#define gcu _U(getchar)
#define pcu _U(putchar)
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template
#define _TN typename
#define _TT _T <_TN T>
#define _HT _T <_TN H,_TN... T>
#define _I inline
#define _OP(t) _I operator t()
struct _in {
#ifdef _GLIBCXX_STRING
	_OP(string){string s;for(char c;c=gcu(),c!=' '&&c!='\n';)s+=c;return s;}
	//_OP(string){string s;char c;while(isspace(c = gcu()));do{s+=c;}while(c=gcu(),c!=' '&&c!='\n'&&c!=EOF);return s;}
#define _S
#endif
	_OP(char){char c=gcu();gcu();return c;}
	_OP(double){double d; scanf("%lf",&d); gcu();return d;}
	//_TT _OP(T){T n{},c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return n;}
	_TT _OP(T){T n{},m{1},c=gcu();if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
	//_TT _OP(T){T n{},m{1},c;while(isspace(c=gcu()));if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
#ifdef _GLIBCXX_VECTOR
#define _TI _T<_TN T=vector<int>, _TN I=_TN T::value_type>
	_TI _I T read(int n) {T v(n);for(I &i:v)i=*this;return v;}
	_TI _I T read(int n,function<int(_TN T::value_type)>f){T v(n);for(I &i:v)i=f(*this);return v;}
	_TI _I T read(int n,function<void(_TN T::value_type&,_TN T::value_type)>f){T v(n);for(I &i:v)f(i,*this);return v;}
#endif
	_T <int N, _TN T=int> array<T, N> read() { array<T, N> a; for (T &i: a) i = *this; return a;
}
} in;
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
#ifdef _S
_SCAN(string &o) {int c{gcu()};if(c==EOF)return false;else{ungetc(c,stdin);string t=move(in);o=t;return true;}}
#endif
_TT _SCAN(T &o) {int c{gcu()};return c==EOF?false:(ungetc(c,stdin),o=in,true);}
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(const char *s){while(*s)pcu(*s++);}
_OUT(char c){pcu(c);}
#ifdef _S
//_OUT(string &s){for(char c:s)pcu(c);}
_OUT(string s){for(char c:s)pcu(c);}
#endif
//_OUT(int n) {printf("%d",n);}
_TT _DEF(void,_OUTX,T n){if(n<10)pcu(n+'0');else _OUTX(n/10),pcu(n%10+'0');}
_TT _OUT(T n){if(n<0)pcu('-'),n=-n;_OUTX(n);}
//_TT _OUT(T n){static char b[20];char *p=b;T m=n<0?pcu('-'),-1:1;if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
_TT _OUT(initializer_list<T> &v){for(auto i{begin(v)};i!=end(v);i++)out(i==begin(v)?"":" "),out(*i);}
#ifdef _GLIBCXX_VECTOR
_TT _OUT(vector<T> &v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _OUT(H &&h, T... t){out(h);out(t...);}
_OUTL(){out('\n');}
_T <_TN... T> _OUTL(T... t){out(t...);outl();}
_T <_TN I, _TN... T> _OUTL(initializer_list<I> i, T... t){out(i);outl(t...);}
_T <_TN T=int>
struct range{
	T e,b=0,s=1;range(T b,T e,T s):e(e),b(b),s(s){} range(T b,T e): e(e), b(b){} range(T e):e(e){}
	struct it{T v,s; it(T v,T s):v(v),s(s){} operator T()const{return v;} _I operator T&(){return v;}T operator*()const{return v;}
		_I it& operator++(){v+=s;return *this;}}; it begin(){return {b,s};} it end(){return {e,s};}};
#define Range(b, ...) for([[maybe_unused]] auto b: range((int) __VA_ARGS__))
#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define tee(s,v) ({dbg(s,v);v;})

int main() {
	int n {in}, a {};
	vector<int> w = in.read(7, [&](int i) {return a = i + a;});
	outl(lower_bound(begin(w), end(w), n % a ?: a) - begin(w) + 1);
}

/* vim: set ts=4 noet: */
