/*
*版本：007
*作者：巨龙之路
*发布日期：2023年10月15日
*
*更新：此次更新增加了长度计算和重载了+运算符
*
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	
	class MyString {
		private:
			char *content;
			int length;
			
		public:
			//无参构造函数
			MyString();
			//有参构造函数
			MyString(const char* str);
			//拷贝构造函数
			MyString(const MyString& myStr);
			//析构函数
			~MyString();
			//获取长度
			int getLength();
			
			//重载<<运算符
			friend std::ostream& operator<<(std::ostream& os,const MyString& myStr);
			//在这里为什么要使用friend关键字？
			//因为如果不使用friend关键字的话，只能传入一个参数，而我需要传入两个参数。
			//加入friend关键字后就可以传入两个参数。
			
			//重载=运算符
			void operator=(const char* str);
			//重载+运算符
			MyString operator+(const MyString& myStr);
			
	};
	
	MyString::MyString(){
		content=nullptr;
		length=0;
	}
	
	MyString::MyString(const char* str){
		//计算传入的字符串的长度
		length=strlen(str);
		//根据传入的字符串的长度来给content申请内存
		content=new char[length];
		//复制传入的字符串的内容到content
		strcpy(content,str);
	}
	
	MyString::MyString(const MyString& myStr){
		this->content=myStr.content;
		this->length=myStr.length;
	}
	
	MyString::~MyString(){
		//释放内存空间
		delete[] content;
	}
	
	int MyString::getLength(){
		return length;
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
			length=strlen(str);
			//根据传入的字符串的长度来给content申请内存
			content=new char[length];
			//复制传入的字符串的内容到content
			strcpy(content,str);
		}
		else{
			//先删除content原来的内容
			delete[] content;
			//计算传入的字符串的长度
			length=strlen(str);
			//根据传入的字符串的长度来给content申请内存
			content=new char[length];
			//复制传入的字符串的内容到content
			strcpy(content,str);
		}
	}
	
	MyString MyString::operator+(const MyString& myStr){
		MyString result;
		result.content=new char(this->length+myStr.length+1);
		strcpy(result.content,this->content);
		strcat(result.content,myStr.content);
		return result;
	}
	
}

//int main(){
//	Mylib::MyString str("hello,world");
//	Mylib::MyString str2;
//	str2="hello";
//	Mylib::MyString str3(str2);
//	
//	std::cout<<"str:"<<str<<std::endl;
//	std::cout<<"str的长度:"<<str.getLength()<<std::endl;
//	std::cout<<"str2:"<<str2<<std::endl;
//	std::cout<<"str2的长度:"<<str2.getLength()<<std::endl;
//	std::cout<<"str3:"<<str3<<std::endl;
//	std::cout<<"str3的长度:"<<str3.getLength()<<std::endl;
//	
//	std::cout<<"str+str2:"<<str+str2<<std::endl;
//}
