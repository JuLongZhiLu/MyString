/*
*�汾��003
*���ߣ�����֮·
*�������ڣ�2023��10��13��
*
*���£��˴θ������ַ������ж���Ȳ���
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
			MyString(char* content) {
				this->content = content;
				length=strlen(content);
			}
			//��ȡ�ַ���������
			char* getContent() {
				return content;
			}
			//��ȡ�ַ����ĳ���
			int getLength(){
				return length;
			}
			//�ж�����MyString�ַ����Ƿ����
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
		std::cout<<"�ַ������"<<std::endl;
	}else{
		std::cout<<"�ַ��������"<<std::endl;
	}
	
}
