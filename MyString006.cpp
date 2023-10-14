/*
*版本：006
*作者：巨龙之路和其他小伙伴
*发布日期：2023年10月14日
*
*更新：
*此次更新重新编写了MyString，因为之前的版本没有对内存进行管理，这样不利于后续的发展。
*这次只实现了基本的构造函数和输出功能。
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	
	class MyString {
		private:
			char *content;
			
		public:
			//无参构造函数
			MyString();
			//有参构造函数
			MyString(const char* str);
			//拷贝构造函数
			MyString(const MyString& myStr);
			//析构函数
			~MyString();
			//重载<<运算符
			friend std::ostream& operator<<(std::ostream& os,const MyString& myStr);
			//在这里为什么要使用friend关键字？
			//因为如果不使用friend关键字的话，只能传入一个参数，而我需要传入两个参数。
			//加入friend关键字后就可以传入两个参数。
			
			//重载=运算符
			void operator=(const char* str);
			
	};
	
	MyString::MyString(){
		content=nullptr;
	}
	
	MyString::MyString(const char* str){
		//计算传入的字符串的长度
		int strLength=strlen(str);
		//根据传入的字符串的长度来给content申请内存
		content=new char[strLength];
		//复制传入的字符串的内容到content
		strcpy(content,str);
	}
	
	MyString::MyString(const MyString& myStr){
		this->content=myStr.content;
	}
	
	MyString::~MyString(){
		//释放内存空间
		delete[] content;
	}
	
	std::ostream& operator<<(std::ostream& os,const MyString& myStr){
		//把myStr的content输出到os对象中
		os<<myStr.content;
		//返回os对象
		return os;
	}
	
	void MyString::operator=(const char* str){
		if(content==nullptr){
			//计算传入的字符串的长度
			int strLength=strlen(str);
			//根据传入的字符串的长度来给content申请内存
			content=new char[strLength];
			//复制传入的字符串的内容到content
			strcpy(content,str);
		}
		else{
			//先删除content原来的内容
			delete[] content;
			//计算传入的字符串的长度
			int strLength=strlen(str);
			//根据传入的字符串的长度来给content申请内存
			content=new char[strLength];
			//复制传入的字符串的内容到content
			strcpy(content,str);
		}
	}
	
}

//int main(){
//	Mylib::MyString str("hello,world");
//	Mylib::MyString str2;
//	str2="hello";
//	Mylib::MyString str3(str2);
//	std::cout<<"str:"<<str<<std::endl;
//	std::cout<<"str2:"<<str2<<std::endl;
//	std::cout<<"str3:"<<str3<<std::endl;
//}
