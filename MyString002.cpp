/*
*�汾��002
*���ߣ�����֮·������С���
*�������ڣ�2023��10��13��
*
*���£��˴θ����˻�ȡ�ַ������ȵķ�ʽ
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
			bool operator==(const MyString& other) const {
				//��ûд��
			}
	};
}

int main() {
	Mylib::MyString str="Hello,world";
	std::cout << str.getContent() << std::endl;
	std::cout << "�ַ����ĳ���Ϊ:"<<str.getLength()<< std::endl;
}
