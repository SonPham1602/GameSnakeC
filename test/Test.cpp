#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int Error_Game;
struct Tao_Do 
{
	int x;
	int y;
};
struct profile
{
	string Name;
	string PassWord;
	Tao_Do pause_game;
	int hightscore;
};
bool test_pass(string pass)
{
	int dem=0;
	for(int i=0;i<pass.length();i++)
	{
		if(pass[i]>'0' && pass[i]<'9')
		{
			dem++;
		}
	}
	if(dem==0 || pass.length()<8)
		return false;
	return true;
}
void creat_profile(profile &New)
{
	string Name;
	cout<<"Name:";
	getline(cin,Name);
	New.Name.append(Name);
	New.Name.append(".txt");
	do 
	{
		cout<<"PassWord:";
		getline(cin,New.PassWord);
		if(!test_pass(New.PassWord));
	} while (!test_pass(New.PassWord));
	New.hightscore=0;
	New.pause_game.x=0;
	New.pause_game.y=0;
}
void update_profile(fstream &File , profile New)
{
	File.open(New.Name,ios::out);
	File<<New.PassWord;
	File<<"\n\r";
	File<<New.pause_game.x;
	File<<"\n\r";
	File<<New.pause_game.y;
	File<<"\n\r";
	File<<New.hightscore;
	File.close();
}
bool open_profile(fstream &File,profile New)
{
	string temp;
	string Name;
	cout<<"Name:";
	getline(cin,Name);
	New.Name.append(Name);
	New.Name.append(".txt");
	cout<<"PassWord:";
	getline(cin,New.PassWord);
	File.open(New.Name,ios::in);
	if(!File.is_open())
	{
		Error_Game=1;//error open file Game;
		File.close();
		return false;
	}
	getline(File,temp);
	if(temp.compare(New.PassWord)!=0)
	{
		return false;
	}
	File.close();
	return true;
}

void main()
{
	fstream file;
	profile New;
	profile temp;
	cout<<"tao profile:"<<endl;
	creat_profile(New);
	update_profile(file,New);
	cout<<"log in:"<<endl;
	if(open_profile(file,temp))
	{
	cout<<"file ton tai"<<endl;
	}
	else
	cout<<"file khong ton tai";
	system("pause");
}