#include <iostream>
using namespace std;
#include <fstream>
void encode(char* buf, int bytes)
{
	for(int i=0; i<bytes; i++)
		++*buf++;
}
int main(int argc, char* argv[])
{
	if(argc!=3){
		cout << argv[0] << " Դ�ļ� ���ļ�" << endl;
		return 0;
	}
	ifstream f1(argv[1],ios::binary|ios::in);
	if(!f1){
		cout << "��" << argv[1] << "�ļ�ʧ��" << endl;
		return 1;
	}
	ofstream f2(argv[2],ios::binary|ios::out);
	if(!f2){
		cout << "��" << argv[2] << "�ļ�ʧ��" << endl;
		return 2;
	}
	bool buf[1000];
	while(f1){
		f1.read(reinterpret_cast<char*>(buf),sizeof(buf));
		cout.write((char*)buf,f1.gcount());
		encode((char*)buf,f1.gcount());
		f2.write((char*)buf,f1.gcount());//��Ҫ��sizeof(buf)
	}
//	f1.close();
//	f2.close();
}