/*
*�汾��006
*���ߣ�����֮·������С���
*�������ڣ�2023��10��14��
*
*���£�
*�˴θ������±�д��MyString����Ϊ֮ǰ�İ汾û�ж��ڴ���й������������ں����ķ�չ��
*���ֻʵ���˻����Ĺ��캯����������ܡ�
*/
#include <iostream>
#include <string.h>

namespace Mylib {
	
	class MyString {
		private:
			char *content;
			
		public:
			//�޲ι��캯��
			MyString();
			//�вι��캯��
			MyString(const char* str);
			//�������캯��
			MyString(const MyString& myStr);
			//��������
			~MyString();
			//����<<�����
			friend std::ostream& operator<<(std::ostream& os,const MyString& myStr);
			//������ΪʲôҪʹ��friend�ؼ��֣�
			//��Ϊ�����ʹ��friend�ؼ��ֵĻ���ֻ�ܴ���һ��������������Ҫ��������������
			//����friend�ؼ��ֺ�Ϳ��Դ�������������
			
			//����=�����
			void operator=(const char* str);
			
	};
	
	MyString::MyString(){
		content=nullptr;
	}
	
	MyString::MyString(const char* str){
		//���㴫����ַ����ĳ���
		int strLength=strlen(str);
		//���ݴ�����ַ����ĳ�������content�����ڴ�
		content=new char[strLength];
		//���ƴ�����ַ��������ݵ�content
		strcpy(content,str);
	}
	
	MyString::MyString(const MyString& myStr){
		this->content=myStr.content;
	}
	
	MyString::~MyString(){
		//�ͷ��ڴ�ռ�
		delete[] content;
	}
	
	std::ostream& operator<<(std::ostream& os,const MyString& myStr){
		//��myStr��content�����os������
		os<<myStr.content;
		//����os����
		return os;
	}
	
	void MyString::operator=(const char* str){
		if(content==nullptr){
			//���㴫����ַ����ĳ���
			int strLength=strlen(str);
			//���ݴ�����ַ����ĳ�������content�����ڴ�
			content=new char[strLength];
			//���ƴ�����ַ��������ݵ�content
			strcpy(content,str);
		}
		else{
			//��ɾ��contentԭ��������
			delete[] content;
			//���㴫����ַ����ĳ���
			int strLength=strlen(str);
			//���ݴ�����ַ����ĳ�������content�����ڴ�
			content=new char[strLength];
			//���ƴ�����ַ��������ݵ�content
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
