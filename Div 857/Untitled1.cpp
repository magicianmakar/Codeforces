#include <bits/stdc++.h>

using namespace std;

int &fun(){
	static int x = 10;
	return x;
}

class Base{
	public:
		virtual void show() = 0;
};

void g(int a){
	a*2;
	cout<<a-1<<endl;
}

template<class A>
void g(A a){
	cout<<a+1<<endl;
}

int main(){
	cout<<is_array<int>::value;
	cout<<rank<char[10][10]>::value;
	cout<<is_array<string>::value;
	cout<<sizeof (void *)<<endl;
	cout<<true<<" "<<boolalpha<<false<<endl;
	fun() = 30;
	cout<<fun();
//	Base b;
	Base *bf;
	int a = 1;
	g(a);
	cout.setf(ios::hex , ios::basefield);cout<<100<<" ";
	cout.unsetf(ios::hex);cout<<100<<" ";
	int ae[] = {33 , 34 , 30};
	cout<<-2*[ae]<<endl;
}
