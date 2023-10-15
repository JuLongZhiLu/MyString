/*
*�汾��007
*���ߣ�����֮·
*�������ڣ�2023��10��15��
*
*���£��˴θ��������˳��ȼ����������+�����
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
			//�޲ι��캯��
			MyString();
			//�вι��캯��
			MyString(const char* str);
			//�������캯��
			MyString(const MyString& myStr);
			//��������
			~MyString();
			//��ȡ����
			int getLength();
			
			//����<<�����
			friend std::ostream& operator<<(std::ostream& os,const MyString& myStr);
			//������ΪʲôҪʹ��friend�ؼ��֣�
			//��Ϊ�����ʹ��friend�ؼ��ֵĻ���ֻ�ܴ���һ��������������Ҫ��������������
			//����friend�ؼ��ֺ�Ϳ��Դ�������������
			
			//����=�����
			void operator=(const char* str);
			//����+�����
			MyString operator+(const MyString& myStr);
			
	};
	
	MyString::MyString(){
		content=nullptr;
		length=0;
	}
	
	MyString::MyString(const char* str){
		//���㴫����ַ����ĳ���
		length=strlen(str);
		//���ݴ�����ַ����ĳ�������content�����ڴ�
		content=new char[length];
		//���ƴ�����ַ��������ݵ�content
		strcpy(content,str);
	}
	
	MyString::MyString(const MyString& myStr){
		this->content=myStr.content;
		this->length=myStr.length;
	}
	
	MyString::~MyString(){
		//�ͷ��ڴ�ռ�
		delete[] content;
	}
	
	int MyString::getLength(){
		return length;
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
			length=strlen(str);
			//���ݴ�����ַ����ĳ�������content�����ڴ�
			content=new char[length];
			//���ƴ�����ַ��������ݵ�content
			strcpy(content,str);
		}
		else{
			//��ɾ��contentԭ��������
			delete[] content;
			//���㴫����ַ����ĳ���
			length=strlen(str);
			//���ݴ�����ַ����ĳ�������content�����ڴ�
			content=new char[length];
			//���ƴ�����ַ��������ݵ�content
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
//	std::cout<<"str�ĳ���:"<<str.getLength()<<std::endl;
//	std::cout<<"str2:"<<str2<<std::endl;
//	std::cout<<"str2�ĳ���:"<<str2.getLength()<<std::endl;
//	std::cout<<"str3:"<<str3<<std::endl;
//	std::cout<<"str3�ĳ���:"<<str3.getLength()<<std::endl;
//	
//	std::cout<<"str+str2:"<<str+str2<<std::endl;
//}
