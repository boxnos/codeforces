#include <cstdio>
#include <cctype>
#include <utility>
using namespace std;

#define _gp(l) const auto gcu{getchar##l}; const auto pcu{putchar##l}
#ifdef __linux
_gp(_unlocked);
#else
_gp();
#endif
#define _DEF(r, n, ...) inline r n(__VA_ARGS__) noexcept
#define _T template<typename T>
#define _HT template<typename H,typename... T>
_T _DEF(T,in,int c){T n{};int m{1};while(isspace(c)){c=gcu();}if(c=='-')m=-1,c=gcu();do{n=10*n+(c-'0'),c=gcu();}while(c>='0'&&c<='9');return m*n;}
_DEF(int,in,){return in<int>(gcu());}
#define _SCAN(...) _DEF(bool,scan,__VA_ARGS__)
_SCAN(char &c){c=gcu();gcu();return c!=EOF;}
_T _SCAN(T &n){int c{gcu()};return c==EOF?false:(n=in<T>(c),true);}
#define _OUT(...) _DEF(void,out,__VA_ARGS__)
#define _OUTL(...) _DEF(void,outl,__VA_ARGS__)
_OUT(bool b){pcu('0'+b);}
_OUT(char c){pcu(c);}
#ifdef _GLIBCXX_STRING
_SCAN(string &s){int c;s="";for(;;){c=gcu();if(c=='\n'||c==' ')return true;else if(c==EOF)return false;s+=(char)c;}}
_OUT(string s){for(char c:s)pcu(c);}
#endif
_OUT(const char *s){while(*s)pcu(*s++);}
_T _OUT(T n){static char b[20];char *p{b};T m=n<0?pcu('-'),-1:1;if(!n)*p++='0';else while(n)*p++=(char)(n%10*m+'0'),n/=10;while(p!=b)pcu(*--p);}
_OUTL(){out('\n');}
#ifdef _GLIBCXX_VECTOR
_T _OUT(vector<T> v){for(T &x:v)out(&x == &v[0]?"":" "),out(x);}
#endif
_HT _SCAN(H &h,T&&... t){return scan(h)&&scan(t...);}
_HT _OUT(H&& h, T&&... t){out(h);out(move(t)...);}
template <typename... T> _OUTL(T&&... t){out(move(t)...);outl();}
struct range{int e,b{0},s{1};range(int _b,int _e,int _s):e(_e),b(_b),s(_s){}range(int _b,int _e):e(_e),b(_b){}range(int _e):e(_e){}
	struct it{int v,s;it(int _v,int _s):v(_v),s(_s){}operator int()const{return v;}operator int&(){return v;}int operator*()const{return v;}it& operator++(){v+=s;return *this;}};
	it begin(){return{b, s};}it end(){return{e,s};}};

int main() {
	int n {in() % 4};
	if (n == 1) // OK
		outl(0, " A");
	else if (n == 2) // OK
		outl(1, " B");
	else if (n == 3)
		outl(2, " A");
	else if (n == 0)
		outl(1, " A");
}

/* vim: set ts=4 noet: */
