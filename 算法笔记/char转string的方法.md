#### char转string
1. 利用赋值号直接赋值，**因为string是一个指针，存储的值是所指向的地址，而char型存储的是内容，所以不可以直接用赋值号赋值**
```c++
	char a = 40;
	string b = a; 
	/*
	错误。因为string是一个指针，存储的值是所指向的地址，而char型存储的是内容，所以不可以直接用赋值号赋值
	*/
	 
	 
	const char* a = "hello";
	string b = a;       //正确
	 
	const char[] a  = "hello";
	string b = a;        //正确
```
2. 利用string构造函数
```c++
	string();

	string (const string& str);

	string (const string& str, size_t pos, size_t len = npos);

	string (const char* s);

	string (const char* s, size_t n);

	string (size_t n, char c);

	template <class InputIterator>
	string  (InputIterator first, InputIterator last);

	string (initializer_list<char> il);

	string (string&& str) noexcept;
```
所以，我们需要把char转成string时，可以这么操作
```c++
    char a = 48;

    string b(a);   //这种写法是错误的，不可以直接传过去。

    //利用string(size_t n, char c)
    string b(1,a); //正
```
> 参考：[c++ char转换成string](https://www.cnblogs.com/daybreaking/p/12365099.html)
