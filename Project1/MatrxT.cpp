#include <fstream>
#include <iostream>
using namespace std;

int main()
{

	unsigned short *CTdata;//����Ϊָ��
	unsigned short *CTdata1;
	int  Width = 512;
	int  Height = 512;
	int Numslice = 512;
	int Length = Width * Height*Numslice;
	int Length1 = Width*Numslice;//һ���ϳ�ͼ��
	CTdata = new unsigned short[Length];//��������һ�οռ�
	CTdata1 = new unsigned short[Length1];


	// �Զ�ģʽ���ļ�
	ifstream infile;
	infile.open("C:\\yanglei\\shuju\\Project1\\Debug\\����-CNU008269-head 512x512x512-ushort.raw", ios::binary);
	if (!infile.is_open())
	{
		std::cout << "False" << endl;
	}
	std::cout << "Reading from the file" << endl;
	infile.read((char*)CTdata, Length * sizeof(unsigned short));
	//cout << CTdata << endl;
	// �رմ򿪵��ļ�
	infile.close();


	/*	  for (int i=0; i<Length;i++)
	  {
	   CTdata[i] = i%10;
	  }
   */

	//��������
	//����̶�ȡ��choose1��(0<choose1<Length)��
	//������choose1<0,��ζ��ȡ�У�
	std::cout << "��������Ҫѡ�������" << endl;
	int choosel;
	cin >> choosel;
	if (choosel >= 0)
	{
		for (int i = 0; i < Length; i++)
		{
			if (i%Width == choosel)
			{
				int a = i / Width;
				*(CTdata1 + a) = *(CTdata + i);
			}
		}
	}
	else
	{
		int b=abs(choosel);
		int b1=(b-1)*Height*Width;
		for (int j = 0; j < Height*Width; j++)
		{
			*(CTdata1 + j) = *(CTdata + b1+j);
		}
	}

   // ��дģʽ���ļ�
	ofstream outfile;


	std::cout << "Writing to the file" << endl;
	//   cout << "Enter your name: "; 
	//   cin.getline(data, 100);

	outfile.open("C:\\yanglei\\shuju\\Project1\\Debug\\����-CNU008269-head 512x512x512-ushort_Tran2.raw", ios::binary);
	// ���ļ�д���û����������
	//outfile.flush();
	outfile.write((char*)CTdata1, Length1 * sizeof(unsigned short));

	// �رմ򿪵��ļ�
	outfile.close();

	delete[] CTdata;
	delete[] CTdata1;
	return 0;
}

