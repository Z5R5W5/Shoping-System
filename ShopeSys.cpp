
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include<set>
#include<unordered_set>
#include<fstream>
#include<sstream>
#define custom_data "costomers.txt"
#define menu_data "menu_data.txt"
#define result_Q "result_quary.txt"
#define maneger_data "manger.txt"

using namespace std;
class Costomer;
class Maneger ;
void system_A_clothing_store();
void write_vector_vector(string path,vector<vector<string>>lines,bool save= true)
{
    auto stat = ios::in | ios::out | ios::app;
    if (!save)
    {
	stat = ios::in | ios::out | ios::trunc;
    }
   
    ofstream ofVV(path.c_str(), stat); 
	if (ofVV.fail()) {
		cout << "error in downloading the file" << '\n';
	}
    for(int i=0;i<lines.size();i++)
    {
        for(int j=0;j<5;j++)
        {
            ofVV<<lines[i][j]<<' ';
        }
        ofVV<<'\n';
    }
	
	ofVV.close();

}
void write_pair_file(string path,vector<pair<string,string>>lines,bool save = true)
{
    auto stat = ios::in | ios::out | ios::app;
    if (!save)
    {
	stat = ios::in | ios::out | ios::trunc;
    }
   
    ofstream ofPAI(path.c_str(), stat); 
	if (ofPAI.fail()) {
		cout << "error in downloading the file" << '\n';
	}
    for(int i=0;i<lines.size();i++)
    {
        ofPAI<<lines[i].first<<' '<<lines[i].second<<'\n';
    }
	
	ofPAI.close();

}

void writefile_lines(string path, vector<string> lines, bool save = true) 
{
	auto stat = ios::in | ios::out | ios::app;
    if (!save)
    {
	stat = ios::in | ios::out | ios::trunc;
    }
	ofstream ofin(path.c_str(), stat);
	if (ofin.fail())
    {
		cout << "error in downloading the file" << '\n';
	}
	for (auto i : lines) 
    {
		ofin << i <<'\n';
	}
	ofin.close();

}
vector<vector<string>> read_vector_vector(string path)
{
    
    vector<vector<string>> lines;
    ifstream file(path);

    if (!file)
    {
        cerr << "Unable to open file\n";
        return lines;
    }

    string line;
    while (getline(file, line))
    {
        vector<string> tempVec;
        stringstream ss(line);
        string word;

        while (ss >> word)
        {
            tempVec.push_back(word);
        }

        lines.push_back(tempVec);
    }

    file.close();
    return lines;
    
}
vector<pair<string,string>> read_pair_file(string path)
{
    vector<pair<string,string>>lines;
    pair<string,string>line;
    string SON,SSEC;
    ifstream ifPAI(path.c_str());
    if (ifPAI.fail())
    {
		cout << "error in downloading the file" << endl;
	}
    while(ifPAI>>SON>>SSEC)
    {
        line.first=SON;
        line.second=SSEC;
        lines.push_back(line);
    }
    return lines;
}

vector<string> readfile_lines(string path)
 {
	vector<string>lines;
	string line;
	ifstream ifin(path.c_str());
	if (ifin.fail()) 
    {
		cout << "error in downloading the file" << endl;
	}
	while (getline(ifin, line))
	{
		if (line.size() == 0)continue;
		lines.push_back(line);

	}
	ifin.close();
	return lines;
}

class Maneger 
{
private:
    int id_manger;
    string name_manger,password;

public:
    void manger_login();
    void menu_manger(Maneger MMG);
    void show_cous_request(Maneger MGR);
    void add_element_menu(Maneger MGR);
    void remove_element_menu(Maneger MGR);
    void add_second_manger(Maneger MGR);
    void show_menu_cou_data(Maneger MGR);

    //friend Costomer;
};
void Maneger ::show_menu_cou_data(Maneger MGR)
{
    
    vector<string>men_da;
    men_da=readfile_lines(menu_data);
    int i=1;
    cout<<"The Goods Vailable In The Store Is : \n";
    for(auto me : men_da)
    {
        cout<<i<<") "<<me<<'\n';
        i++;
    }
    menu_manger(MGR);
}
void Maneger:: show_cous_request(Maneger MGR)
{

    vector<vector<string>>LIN=read_vector_vector(custom_data);
    //cout<<LIN[1][4]<<'\n';

    for(int i=0;i<LIN.size();i++)
    {
        cout<<"Coustomer Number -> "<<i+1<<'\n';
        cout<<"Name : "<<LIN[i][0]<<'\n';
        cout<<"Email : "<<LIN[i][1]<<'\n';
        cout<<"Address : "<<LIN[i][2]<<'\n';
        cout<<"Name Good : "<<LIN[i][3]<<'\n';
        cout<<"Amount :"<<LIN[i][4]<<'\n';
        
       
    }
    int choise;
    cout<<"If you DONE Coustomer Recost Enter (1) or (0) exit \n";
    cin>>choise;
    if(choise==1)
    {
        string _EM,_MSS;
        cout<<"Enter Email Coustomer : \n";
        cin>>_EM;
        cout<<"Enter Massage TO Coustomer : \n";
        cin>>_MSS;
        vector<pair<string,string>>DONE_Q;
        
        DONE_Q=read_pair_file(result_Q);
        for(int i=0;i<DONE_Q.size();i++)
        {
            if(DONE_Q[i].first==_EM)
            {
                DONE_Q[i].second=_MSS;
            }
        }
        write_pair_file(result_Q,DONE_Q,false);
        cout<<"Message is Send \n";
        show_cous_request(MGR);

    }
    else 
    {
        menu_manger(MGR);
    }
}
void Maneger::add_element_menu(Maneger MGR)
{
    vector<string>MEN_DAT;
    ifstream MUN_R(menu_data);
    string lin;
    while(MUN_R>>lin)
    {
       MEN_DAT.push_back(lin); 
    }
    MUN_R.close();
    string go;
    cout<<"Enter New Good \n";
    cin>>go;
    MEN_DAT.push_back(go);
    writefile_lines(menu_data,MEN_DAT,false);

//     ofstream MUN_W(menu_data,ios ::app);
//    // MUN_W.seekp(0,ios::beg);

    cout<<"Adding Succesfuly \n";
    int choise;
    cout<<"To Adding Aother Enter (1) to Exite (0) :  \n";
    cin>>choise;
    if(choise==1)
    {
        add_element_menu(MGR);
    }
    else
    {
       menu_manger(MGR);
    }
    

} 
void Maneger ::remove_element_menu(Maneger MGR)
{
    vector<string>MEN_DAT;
    ifstream MUN_R(menu_data);
    string lin;
    while(MUN_R>>lin)
    {
       MEN_DAT.push_back(lin); 
    }
    MUN_R.close();
    int go;
    cout<<"Enter Number Good that You Del : \n";
    cin>>go;
    MEN_DAT.erase(MEN_DAT.begin()+go-1);

    writefile_lines(menu_data,MEN_DAT,false);

    cout<<"Deleting Succesfuly \n";
    int choise;
    cout<<"To Deleting Aother Enter (1) to Exite (0) :  \n";
    cin>>choise;
    if(choise==1)
    {
        remove_element_menu(MGR);
    }
    else
    {
       menu_manger(MGR);
    }
  


}
void Maneger :: add_second_manger(Maneger MGR)
{
    Maneger SECOND;
    cout<<"Enter user name : \n";
    cin>>SECOND.name_manger;
    cout<<"Enter Password : \n";
    cin>>SECOND.password;
    ofstream OFMAN(maneger_data,ios::app);
    OFMAN<<SECOND.name_manger<<' '<<SECOND.password<<'\n';
    OFMAN.close();
    cout<<"Adding sucssefuly \n";
    menu_manger(MGR);

}
void Maneger :: menu_manger(Maneger MGR){
    Maneger mgr=MGR;

    cout<<"Hello, "<<MGR.name_manger<<" This that Menu : \n";
    cout<<"1) Show Costomers Rquest \n";
    cout<<"2) Show Menu Goode \n";
    cout<<"3) Add Element In Menu \n";
    cout<<"4) Remove  Element In Menu \n";
    cout<<"5) Add Asistant Maneger \n";

    int choise;
    cout<<"Enter choise : \n";
    cin>>choise;
    if(choise==1)
    {
        show_cous_request(mgr);
    }
    else if(choise==2)
    {
        show_menu_cou_data(mgr);
    }
    else if(choise==3)
    {
       add_element_menu(mgr);

    }
    else if (choise==4)
    {
        remove_element_menu(mgr);
    }
    else if(choise==5)
    {
        add_second_manger(mgr);
    }
    else
    {
        cout<<"Wrong choise Try Again \n";
        menu_manger(mgr);
    }
    

}

void Maneger:: manger_login(){
    Maneger maneger;
    vector<pair<string,string>>MAN_DAT;

    cout<<"Enter Your username or (-1) to exit : \n";
    cin>>maneger.name_manger;

    if(maneger.name_manger=="-1" )
    {
        system_A_clothing_store();
    }
    cout<<"Enter Your Password or (-1) to exit: \n";
    cin>>maneger.password;
   

    ifstream MANG_DA(maneger_data);
    string USR,PASS;

    while(MANG_DA>>USR>>PASS)
    {
        pair<string,string>par_md;
        par_md.first=USR;
        par_md.second=PASS;
        MAN_DAT.push_back(par_md);

    }
    MANG_DA.close();
    bool _tx=1;
    for(int i=0;i<MAN_DAT.size();i++)
    {
        if(MAN_DAT[i].first==maneger.name_manger&& MAN_DAT[i].second==maneger.password)
        {
            _tx=0;
            break;
        }

       // cout<<MAN_DAT[i].first<<' '<<MAN_DAT[i].second<<'\n';

    }
   // cout<<_tx<<'\n';
    if(_tx)
    {
        cout<<"Wrong in Username or Password \n";
        manger_login();

    }
    else
    {
        menu_manger(maneger);

    }

}
class Costomer
{
private:
    int id;
    string name_costomer,email,addres,name_good,amount;

public:
    Costomer()
    {
        id =1;
        email="no_email";
        addres="no_address";
    }
    void menu_cus();
    void buy_good();
    void quary_rest();
    friend Maneger;

};
void Costomer:: quary_rest()
{

    Costomer costomer;
    vector<pair<string,string>>COU_Qur;
    cout<<"Enter Your Email : \n";
    cin>>costomer.email;
    ifstream QU_RE_R(result_Q);
    string EMAIL,QUR;

    while(QU_RE_R>>EMAIL>>QUR)
    {
        pair<string,string>par_Q;
        par_Q.first=EMAIL;
        par_Q.second=QUR;
        COU_Qur.push_back(par_Q);

    }
    QU_RE_R.close();
    string Result_QU;
    bool _tx=1;
    for(int i=0;i<COU_Qur.size();i++)
    {
        if(COU_Qur[i].first==costomer.email)
        {
            Result_QU=COU_Qur[i].second;
            _tx=0;
            break;
        }

    }
    if(_tx)
    {
        cout<<"YOU Email Wrong Please Conform and Try Again \n";
        quary_rest();
    }
    else
    {
        cout<<"Your Result Is : "<<Result_QU<<'\n';
    }
    
    menu_cus();

}
void Insert_Email_Cou(string email,string res="NOT_RESULT_YET")
{
    ofstream QU_Re (result_Q,ios :: app);
    QU_Re<<email<<' '<<res<<'\n';
    QU_Re.close();
}
void INSERT_COS_DATA(string name,string email,string addr,string Goods,string Amount )
{
   // string delem="@";
   vector<vector<string>>COS_DA;
   vector<string>lin;
   lin.push_back(name);
   lin.push_back(email);
   lin.push_back(addr);
   lin.push_back(Goods);
   lin.push_back(Amount);
   COS_DA.push_back(lin);
   write_vector_vector(custom_data,COS_DA);
  
}

void Costomer ::buy_good()
{
    Costomer costomer;
    vector<string>datas_cos,data_cos;
    
    cout<<"Enter Your Name : \n";
    cin>>costomer.name_costomer;
    data_cos.push_back(costomer.name_costomer);

    cout<<"Enter Your Email : \n";
    cin>>costomer.email;
    data_cos.push_back(costomer.email);
    Insert_Email_Cou(costomer.email);
    cout<<"Enter Your Adress : \n";
    cin>>costomer.addres;
    data_cos.push_back(costomer.addres);


    cout<<"Enter Your Name Goods : \n";
    cin>>costomer.name_good;
    data_cos.push_back(costomer.name_good);

    cout<<"Enter Your Amount : \n";
    cin>>costomer.amount;
    data_cos.push_back(costomer.amount);
    for(auto& it : data_cos)
    {

        datas_cos.push_back(it);
    }
    INSERT_COS_DATA(costomer.name_costomer,costomer.email,costomer.addres,costomer.name_good,costomer.amount);
   // writefile_lines( custom_data,datas_cos);
    cout<<"Your Request Is Done\n";
    cout<<"=============================================\n";
    menu_cus();

}
void Costomer::menu_cus()
{
    Costomer costomer;
    vector<string>men_da;
    men_da=readfile_lines(menu_data);
    int i=1;
    cout<<"The Goods Vailable In The Store Is : \n";
    for(auto me : men_da)
    {
        cout<<i<<") "<<me<<'\n';
        i++;
    }
    int choise;
    cout<<"If You Want to\n";
    cout<<"1) Buy Think \t\t 2) Result Quary \t\t 3) EXIT \n";
    
    cin>>choise;
    if(choise==1)
    {
        costomer.buy_good();
    }
    else if(choise==2)
    {
        costomer.quary_rest();
    }
    else if(choise==3)
    {
        system_A_clothing_store();
    }
    else
    {
        menu_cus();
    }
}


void system_A_clothing_store()
{
    Costomer costomer;
    Maneger manger;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~HELLO IN CLOTHING STORE SYSTEM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"NOTE(1) : To write name of any thing (DONT) write space ->' ' Instead of that write'_'  \n";
    cout<<"          Example : Wrong 'Ziad ayman' ->  ->  ->  -> Right 'Ziad_ayman' \n";
    cout<<"NOTE(2) : The maneger's username and password are in a manger file \n\n";
    cout<<"1) customer \t\t 2)maneger\n";
    int choise;
    cout<<"Enter your choise :\n";
    cin>>choise;
   
    if(choise==1)
    {
       costomer.menu_cus();

    }
    else if(choise==2)
    {
        manger.manger_login();

    }

    else
    {
        cout<<"error choise\n";
        system_A_clothing_store();
    }
}
int main()
{
    system_A_clothing_store();

}