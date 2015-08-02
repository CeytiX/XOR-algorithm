#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int ctoi (char);

int main(int argc, char* argv[])
{
	if(argc >= 4)
	{
		string ifile_name = argv[1];
		string ofile_name = argv[2];

		char key = (char)(128*ctoi(argv[3][0]) + 64*ctoi(argv[3][1]) + 32*ctoi(argv[3][2]) + 16*ctoi(argv[3][3]) + 8*ctoi(argv[3][4]) + 4*ctoi(argv[3][5]) + 2*ctoi(argv[3][6]) + ctoi(argv[3][7]));
		
		ifstream ifile(ifile_name.c_str(), ifstream::binary);
		ofstream ofile(ofile_name.c_str(), ofstream::binary);

		ifile.seekg(0, ifile.end);
		int length = ifile.tellg();
		ifile.seekg(0, ifile.beg);

		char* buffer = new char[length];

		ifile.read(buffer, length);

		for(int i=0; i<length; i++)
		{
			buffer[i] = (char)(buffer[i] ^ key);
		}

		ofile.write(buffer, length);
	}
	else
	{
		cout << "Missing parameters" << endl;
	}

	return 0;
}

int ctoi (char value) //convert number_char to number
{
	return value - '0';
}
