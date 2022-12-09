#include <iostream>
#include <fstream>

using namespace std;
int del;
bool m_cmt=false;

string rem_cmt(string str){
int n=str.length();
string res="";
bool s_cmt=false;

for(int i=0;i<n;i++){
    if(str[i]=='/'&&str[i+1]=='/'){
        s_cmt=true;
        m_cmt=false;
        del++;
        break;
    }
    else if(str[i]=='/'&&str[i+1]=='*'&&m_cmt==false){
        m_cmt=true;
        i++;
        del++;
    }
    else if(str[i]=='*'&&str[i+1]=='/'&&m_cmt==false){
        m_cmt=false;
        i++;
        del++;
        s_cmt=false;
    }
    else if(s_cmt==false&&m_cmt==false){
        res+=str[i];
    }


}

return res;
}

int main()
{
    fstream fin, fout;
    fin.open("input.txt");
    fout.open("output.txt");
    string str;
    while(getline(fin,str)){
            ///cout<<str<<endl;
       string ss= rem_cmt(str);
       fout<<ss<<endl;
    }
    cout<<"number of deletion "<<del<<endl;

    fin.close();
    fout.close();

    return 0;
}
