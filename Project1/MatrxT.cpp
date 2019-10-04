#include <fstream>
#include <iostream>
using namespace std;

int main()
{

	unsigned short *CTdata;//定义为指针
	unsigned short *CTdata1;
	int  Width = 512;
	int  Height = 512;
	int Numslice = 512;
	int Length = Width * Height*Numslice;
	int Length1 = Width*Numslice;//一幅合成图像
	CTdata = new unsigned short[Length];//连续开辟一段空间
	CTdata1 = new unsigned short[Length1];


	// 以读模式打开文件
	ifstream infile;
	infile.open("C:\\yanglei\\shuju\\Project1\\Debug\\白蚁-CNU008269-head 512x512x512-ushort.raw", ios::binary);
	if (!infile.is_open())
	{
		std::cout << "False" << endl;
	}
	std::cout << "Reading from the file" << endl;
	infile.read((char*)CTdata, Length * sizeof(unsigned short));
	//cout << CTdata << endl;
	// 关闭打开的文件
	infile.close();


	/*	  for (int i=0; i<Length;i++)
	  {
	   CTdata[i] = i%10;
	  }
   */

	//程序主体
	//如果固定取第choose1列(0<choose1<Length)；
	//若输入choose1<0,意味着取行；
	std::cout << "请输入所要选择的列数" << endl;
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

   // 以写模式打开文件
	ofstream outfile;


	std::cout << "Writing to the file" << endl;
	//   cout << "Enter your name: "; 
	//   cin.getline(data, 100);

	outfile.open("C:\\yanglei\\shuju\\Project1\\Debug\\白蚁-CNU008269-head 512x512x512-ushort_Tran2.raw", ios::binary);
	// 向文件写入用户输入的数据
	//outfile.flush();
	outfile.write((char*)CTdata1, Length1 * sizeof(unsigned short));

	// 关闭打开的文件
	outfile.close();

	delete[] CTdata;
	delete[] CTdata1;
	return 0;
}

