#include<GLEW/GL/glew.h>
#include <GLFW\glfw3.h>
#include<iostream>
#include<fstream> 
#include<string>

using namespace std;
extern char shadertext[999];
extern  char str[200];
void checkfile(string & info) {
	
	std::ifstream sfile;
	sfile.open(info);
	while (!sfile.eof())
	{
		str[0] = '\0';
		sfile >> str;
		if (str[0] != '\0');
		{
			strcat(shadertext, str);
		}

	}
	sfile.close();

}
//void fileclear() {
//}
class sunduk {
public:
	

	
	






};