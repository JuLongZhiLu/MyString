/*
*�汾��001
*���ߣ�����֮·
*�������ڣ�2023��10��13��
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	class MyString {
		private:
			char *content;
		public:
			//���캯��
			MyString(char* content) {
				this->content = content;
			}
			//��ȡ�ַ���������
			char* getContent() {
				return content;
			}
			//��ȡ�ַ����ĳ���
			int getLength(){
				return strlen(content);
			}
			//�ж�����MyString�ַ����Ƿ����
			bool operator==(const MyString& other) const {
				//��ûд��
			}
	};
}

int main() {
	Mylib::MyString str="Hello,world";
	std::cout << str.getContent() << std::endl;
	std::cout << "�ַ����ĳ���Ϊ:"<<str.getLength() << std::endl;
}
