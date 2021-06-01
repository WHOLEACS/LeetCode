#### string的方法库
* insert
    1. 在原串下标pos的字符前插入字符串str
        * basic_string& insert (size_type pos, const basic_string& str);
    2. str从下标pos1开始数的前n个字符插在原串下标为pos的字符前
        * basic_string& insert (size_type pos, const basic_string& str, size_type pos1, size_type n);
    3. 在原串下标为pos的字符前插入n个字符c
        * basic_string& insert (size_type pos, size_type n, char c);
    4. code
    ```c++
	#include<iostream>
	using namespace std;
	int main()
	{
		string str="hello";
		string s="Hahah";
		str.insert(1,s);//在原串下标为1的字符e前插入字符串s
		cout<<str<<endl;

		string str1="hello";
		char c='w';
		str1.insert(4,5,c);//在原串下标为4的字符o前插入5个字符c
		cout<<str1<<endl;

		string str2="hello";
		string s2="weakhaha";
		str2.insert(0,s2,1,3);//将字符串s2从下标为1的e开始数3个字符，分别是eak，插入原串的下标为0的字符h前
		cout<<str2<<endl;

		return 0;
	}
    ```
    5. [参考资料](https://blog.csdn.net/weixin_45845039/article/details/108909704)
