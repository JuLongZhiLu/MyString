/*
*版本：004
*作者：巨龙之路
*发布日期：2023年10月14日
*
*更新：此次更新了重构了代码
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	
	class MyString {
		private:
			char *content;
			int length;
		public:
			//构造函数
			MyString(char* content);
			//获取字符串的内容
			char* getContent();
			//获取字符串的长度
			int getLength();
			//判断两个MyString字符串是否相等
			bool operator==(const MyString& other);
	};
	
	MyString::MyString(char* content) {
		this->content = content;
		length=strlen(content);
	}
	
	char* MyString::getContent() {
		return content;
	}
	
	int MyString::getLength(){
		return length;
	}
	
	bool MyString::operator==(const MyString& other){
		if(this->length!=other.length)
			return false;		
		for(int i=0;i<this->length;i++){
			if(this->content[i]!=other.content[i])
				return false;
		}
		return true;
	}
	
}

//int main(){
//	Mylib::MyString str="Hello,world";
//	Mylib::MyString str2="abcde";
//	std::cout<<"str字符串的内容："<<str.getContent()<<std::endl;
//	std::cout<<"str长度："<<str.getLength()<<std::endl;
//	if(str==str2)
//		std::cout<<"str和str2相等"<<std::endl;
//	else 
//		std::cout<<"str和str2不相等"<<std::endl;
//}


