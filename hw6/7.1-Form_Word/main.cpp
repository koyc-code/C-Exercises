//FormWord-inputmain1.cpp
#include"Form.h"

int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING");//�]�wInput
	form1.ProcessInputWord();//�B�zInput��T
	form1.SetFileName("words.txt");//�]�w�ɮצW��
	form1.Load_CompareWord();//Ū�ɨåB���
	form1.PrintFoundWords();//�L�X�ŦX���r
	return 0;
}