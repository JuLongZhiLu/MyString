/*
*版本：001
*作者：巨龙之路
*发布日期：2023年10月13日
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	class MyString {
		private:
			char *content;
		public:
			//构造函数
			MyString(char* content) {
				this->content = content;
			}
			//获取字符串的内容
			char* getContent() {
				return content;
			}
			//获取字符串的长度
			int getLength(){
				return strlen(content);
			}
			//判断两个MyString字符串是否相等
			bool operator==(const MyString& other) const {
				//还没写完
			}
	};
}

int main() {
	Mylib::MyString str="Hello,world";
	std::cout << str.getContent() << std::endl;
	std::cout << "字符串的长度为:"<<str.getLength() << std::endl;
}
