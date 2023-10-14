/*
*�汾��004
*���ߣ�����֮·
*�������ڣ�2023��10��14��
*
*���£��˴θ������ع��˴���
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	
	class MyString {
		private:
			char *content;
			int length;
		public:
			//���캯��
			MyString(char* content);
			//��ȡ�ַ���������
			char* getContent();
			//��ȡ�ַ����ĳ���
			int getLength();
			//�ж�����MyString�ַ����Ƿ����
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
//	std::cout<<"str�ַ��������ݣ�"<<str.getContent()<<std::endl;
//	std::cout<<"str���ȣ�"<<str.getLength()<<std::endl;
//	if(str==str2)
//		std::cout<<"str��str2���"<<std::endl;
//	else 
//		std::cout<<"str��str2�����"<<std::endl;
//}


