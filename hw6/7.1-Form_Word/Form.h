#include<string>
#include <vector>
#include <fstream>
using namespace std;

class Form
{
private:
	string input;
	fstream file;
public:
	vector<string> words_match;
	void SetInputWord(string inputWord);//�]�wInput
	void ProcessInputWord();//�B�z Input ����T
	void SetFileName(string fileName);//�]�w�ɮצW��
	void Load_CompareWord();//Ū�ɨåB���
	void PrintFoundWords();//�L�X�ŦX���r
};
