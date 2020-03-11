//nguyễn quang vinh a36341 
#include <iostream>
#include <string.h>

using namespace std;
//Hàm đếm khoảng trắng
int demkhoangtrang(char s[]);
//Hàm xóa khoảng trắng thừa
//"__dau___hai_phong__" ->"dau hai phong"
void xoakhoangtrang(char s[]);
//Hàm chuyển kí tự thường thành kí tự hoa
void chuhoa(char s[]);
void chuthuong(char s[]);
void chuxenke(char s[]);
void chuanchuoi(char s[]);
int timkitutrongchuoi(char s[],char kitu);
int main()
{
	  char s1[100];
  	char kitu;
    cout<<"nhap xau";
  	cin.getline(s1,100);
    cout<<"nhap ki tu can tim:";
    cin>>kitu;
  	cout<<"khoang trang la: "<<demkhoangtrang(s1)<<endl;
    cout<<"bai 0:"<<s1<<endl;
  	xoakhoangtrang(s1);
  	//chuhoa(s1);
  	//cout<<s1<<endl
    cout<<"bai 1:"<<s1<<endl;
  	chuthuong(s1);
    cout<<"bai 2:"<<s1<<endl;
    chuxenke(s1);
    cout<<"bai 3:"<<s1<<endl;
  	chuanchuoi(s1);
    cout<<"bai 4:"<<timkitutrongchuoi(s1,kitu)<<endl;
  
  	return 0;
}
int demkhoangtrang(char s[]) 
{ 
	int d=0; 
	for(int i=0;i<strlen(s);i++)
	{ 
    	if(s[i]==' ')
    	d++; 
  	} 
    return d; 
}
//bai 0
void xoakhoangtrang(char s[])
{
  //"____dau___hai_phong__" ->"dau hai phong"
	int d=0,x=0;
  	char temp[100];
  	while(s[x]==' ')//Bỏ qua khoảng trắng đầu
	  x++;
  	//Khoảng trắng bên trong chuổi
  	for(int i=x;i<strlen(s);i++)
  	{
    	if(s[i]!=' ') //Các kí tự khác trống thì gán bình thường
    	{
      	temp[d]=s[i];
      	d++;
    	}
    	if ((s[i]==' ') && (s[i+1]!=' ')) //Kí tự trước bằng trống và sau khác trống thì lấy 1 khoảng trống
    	{
      	temp[d]=' ';
      	d++;
    	}
  	}
	  temp[d]='\0';//Kết thúc chuỗi kí tự là \0
	  strcpy(s,temp);//Copy chuối temp vào chuỗi s
}
//bai 1
void chuhoa(char s[])
{
	for(int i=0;i<strlen(s);i++)
  {
    if(s[i]>=97 && s[i]<=122)
    {
      s[i]=s[i]-32;
    }
  }
}
//bai 2
void chuthuong(char s[]){
  for(int i=0;i<strlen(s);i++)
  {
    if(s[i]>=65 && s[i]<=90)
    {
    	s[i]=s[i]+32;
    }
  }	
}
//bai2
void chuxenke(char s[]){
  for(int i=0;i<strlen(s);i++)
  {
    if(i%2==0){
      if(s[i]>=95 && s[i]<=122)
      {
        s[i]=s[i]-32;
      }
    }
    else{
      if(s[i]>=65 && s[i]<=90){
        s[i]=s[i]+32;
      }
    }
  }
}
void chuanchuoi(char s[])
{
  if((s[0]>=97)&&(s[0]<=122))
  {
	  s[0]=s[0]-32;
  }
  for(int i=0;i<strlen(s);i++)
  {
    if((s[i-1]!=' ')&&(s[i]==' ')&&(s[i+1]!=' '))
    {
      if((s[i+1]>=97)&&(s[i+1]<=122))
      {
        s[i+1]=s[i+1]-32;
      }
		}
  }
}
int timkitutrongchuoi(char s[],char kitu)
{
  int dem=1;
  for(int i=0;i<strlen(s);i++)
	{
		if(s[i]==' ')
		{
			dem=dem+1;
		}
    if(s[i]==kitu){
      return dem;
    }
	}
	return 0;
}
/*
Bài 0. Sửa lại cho đúng hàm xoakhoangtrang
Bài 1. Viết hàm đổi chữ hoa thành chữ thường 
Bài 2. Viết hàm đổi xen kẽ chữ hoa, chữ thường. VD: abCde->AbCdE 
Bài 3. Viế chuẩnt hàm chuỗi. Các từ cách nhau 1 dấu cách, chữ cái đầu viết hoa. VD: "daU   HAI phonG"->Dau Hai Phong (có thể sử dụng các hàm ở trên)
Bài 4. Viết hàm tìm kiếm 1 kí tự xem có trong chuỗi không, nếu có xuất ra vị trí của từ chứ kí tự đó. (Vd: xâu a là “ho chi minh”: nhập ‘m’=>kết quả là 3)
*/
