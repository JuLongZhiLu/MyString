/*
*版本：003
*作者：巨龙之路
*发布日期：2023年10月13日
*
*更新：此次更新了字符串的判断相等操作
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
			MyString(char* content) {
				this->content = content;
				length=strlen(content);
			}
			//获取字符串的内容
			char* getContent() {
				return content;
			}
			//获取字符串的长度
			int getLength(){
				return length;
			}
			//判断两个MyString字符串是否相等
			bool operator==(const MyString& other){
				if(this->length!=other.length)
					return false;		
				for(int i=0;i<this->length;i++){
					if(this->content[i]!=other.content[i])
						return false;
				}
				return true;
			}
	};
}

int main() {
	Mylib::MyString str001="Hello,world";
	Mylib::MyString str002="wwwww,aaaad";
	if(str001==str002){
		std::cout<<"字符串相等"<<std::endl;
	}else{
		std::cout<<"字符串不相等"<<std::endl;
	}
	
}
