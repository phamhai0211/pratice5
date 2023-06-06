# include <iostream>
# include <fstream>
# include <iomanip>
#include<cstdio>
using namespace std;


typedef struct Cadidate 
{
    char id[40];
    char hoten[35];
    char sex[15];
    unsigned int year : 2;
    unsigned int scoreC:7;
    unsigned int scoreJava:7;
    unsigned int manage:7;
    unsigned int scoreE:7;
    unsigned int yearOfEx:7;
    void NHAP_CD();
    void INRA_CD();
    void SUA_CD();
    void BS_CD();
};

struct JobRequirment 

{

    char id[8];
    char hoten[35];
    char gioitinh[15];
    unsigned int scoreC : 7;
    unsigned int scoreJava : 7;
    unsigned int scoreE : 7;
    unsigned int manage : 7;
    unsigned int expOfYear;
    
    void NHAP_JOB_REQUIR();
    void INRA_JOB_REQUIR();
    void SUA_JOB_REQUIR();

    void BS_JOB();
};

void Cadidate::NHAP_CD()
{
    Cadidate CD;
    fstream FW;
    char ok;

    FW.open("Candidates.txt", ios::out);

    cout << "\n Nhap danh sach ung cu vien \n";

    while (1)

    {
        int c,java,eng, manage, exp, year;
        printf( "ID: "); fgets(CD.id, sizeof(CD.id), stdin);
        printf( "Ho va ten  : "); fgets(CD.hoten, sizeof(CD.hoten),stdin);
        printf( "Gioi tinh   : "); fgets(CD.sex, sizeof(CD.sex),stdin);
        cout << "Nhap nam sinh :"; cin >> year; CD.year = year; cin.ignore();
        printf( "diem ky nang c++");
         cin>>c;
         CD.scoreC = c; cin.ignore();
        printf( "diem ky nang Java");
        cin >> java;
        CD.scoreJava = java;
        cin.ignore();
        printf( " Diem ky nang quan ly : ");cin>>manage; CD.manage = manage; cin.ignore();
        printf(" Diem ky nang tieng anh : "); cin >> eng; CD.scoreE= eng; cin.ignore();
        printf("so nam kinh nghiem: "); cin>>exp; CD.yearOfEx=exp; cin.ignore();
        FW.write((char*)&CD, sizeof(CD));

        cout << "\n Tiep tuc (C/K) ?"; cin >> ok; cin.ignore();

        if ((ok == 'k') || (ok == 'K')) break;
    }

    FW.close();

}

void Cadidate::INRA_CD()

{

    Cadidate cd;

    fstream FR;

    FR.open("Candidates.txt", ios::in);

    if (FR.fail()) { cout << "\n Loi mo tep tin"; return; }

    cout << "\n danh sach Candidates \n";

    cout << setw(3) << "STT" << setw(11) << " " <<" ID " << setw(25) << "Ho Ten"

        << setw(11) << "Gioi tinh " << setw(11) <<"nam sinh"

        << setw(11) << "c++" << setw(11) << "java" << setw(11) << "tieng anh" << setw(11) << "quan ly"

        << setw(15) << "exp" << "\n";

    int TT = 1;
    while (FR.read((char*)&cd, sizeof(cd)))

    {

        cout << "\n" << setw(3) << TT << " ";

        cout << setw(11) << cd.id << setw(25) << cd.hoten << setw(11) <<cd.year<<setw(11) << cd.sex

            << setw(11) << cd.scoreC << setw(11) << cd.scoreJava << setw(11) << cd.scoreE << setw(11) << cd.manage << setw(15) << cd.yearOfEx << endl;
        TT = TT + 1;

    }

    FR.close();

}

void Cadidate::SUA_CD()

{

    Cadidate cd;
    fstream FW;
    int n; char ok;
   unsigned int c = 0,java = 0,year, manage, exp, eng;
    cout << "\n Nhap ban ghi can sua:";

    cin >> n; cin.ignore();

    FW.open("Candidates.txt", ios::in | ios::out);

    if (FW.fail()) { cout << " \n Loi mo tep "; return; }

    cout << "\n nhap du lieu sua lai:\n ";

    cout << "ID: "; cin.getline(cd.id, 10);

    cout << "Ho va ten : "; cin.getline(cd.id, 25);

    cout << "Gioi tinh : "; cin.getline(cd.sex, 10);
    cout << "nam sinh :"; cin >> year; cd.year = year; cin.ignore();
    cout << "Diem ky nang c++ ";
    cin >> c;
    cd.scoreC = c; cin.ignore();
    cout << "Diem ky nang java ";
    cin >> java;
    cd.scoreJava = java;
    cin.ignore();

    cout << " Diem ky nang quan ly : "; 
    cin >> manage;
    cd.manage = manage; cin.ignore();

    cout << " Diem ky nang tieng anh : ";
    cin>>eng;
    cd.scoreE = eng; cin.ignore();

    cout << "\nNhap nua khong (C/K) ? ";

    cin >> ok; cin.ignore();

    FW.seekp((n - 1) * sizeof(cd)); //chuyen con tron den ban ghi thu n

    if (ok == 'c' || ok == 'C') FW.write((char*)&cd, sizeof(cd)); //ghi lai ban ghi
    FW.close();
}

void Cadidate::BS_CD()

{

    Cadidate cd;

    fstream FW;

    int n = FW.tellp() / sizeof(cd) + 1;

    char ok;

    cout << "\n them Candidate:";

    cin >> n; cin.ignore();

    if (FW.fail()) { cout << " \n Loi mo tep "; return; }

    FW.open("Candidates.txt", ios::in | ios::out | ios::app);

    FW.seekp(0, ios::end);

    while (1)

    {
        int c, java, eng, exp, manage, year;
        cout << "\nNhap ban ghi thu: " << n;
        cout << "ID: "; cin.getline(cd.id, 10);
        cout << "Ho va ten : "; cin.getline(cd.id, 25);
        cout << "Gioi tinh : "; cin.getline(cd.sex, 10);
        cout << "Nhap nam sinh: "; cin >> year; cd.year = year; cin.ignore();
        cout << "Diem ky nang c++ ";
        cin >> c;
        cd.scoreC = c; cin.ignore();
        cout << "Diem ky nang java";
        cin >> java;
        cd.scoreJava = java; cin.ignore();

        cout << " Diem ky nang quan ly : "; 
        cin>>manage;
        cd.manage = manage; cin.ignore();

        cout << " Diem ky nang tieng anh : "; cin>>eng; cd.scoreE = eng; cin.ignore();
        cout << "so nam kinh nghiem :";
        cin>>exp; cd.yearOfEx = exp; cin.ignore();
        FW.write((char*)&cd, sizeof(cd));

        cout << "\nNhap nua khong (C/K) ? ";

        cin >> ok; cin.ignore();

        n = n + 1;

        if (ok == 'k' || ok == 'K') break;

    }

    FW.close();

}

void JobRequirment::NHAP_JOB_REQUIR()

{

    JobRequirment jr;

    fstream FW;

    char ok;

    FW.open("Requirments.txt", ios::out);

    cout << "\n Nhap ds Job\n";

    while (1)

    {

       // tin.NHAP();
        int c, java, eng, manage, exp;
        cout << "id job: "; cin.getline(jr.id, 15);
        cout << "Ho va ten  : "; cin.getline(jr.hoten, 35);
        cout << "gioi tinh  : "; cin.getline(jr.gioitinh, 15);
        cout << "Diem ky nang c++ ";
        cin >> c;
        jr.scoreC = c; cin.ignore();
        cout << "Diem ky nang java ";
       cin>>java;
        jr.scoreJava = java;
        cin.ignore();

       printf( " ky nang tieng anh:  "); cin>>eng; jr.scoreE = eng; cin.ignore();

       printf(" ky nang quan ly: ");cin>>manage;jr.manage = manage; cin.ignore();
       printf("so nam kinh nghiem: "); cin>>exp; jr.expOfYear = exp; cin.ignore();
        FW.write((char*)&jr, sizeof(jr));

        cout << "\n Tiep tuc (C/K) ?"; cin >> ok; cin.ignore();

        if (ok == 'k' || ok == 'K') break;

    }

    FW.close();

}



void JobRequirment::INRA_JOB_REQUIR()

{
    int count;
    JobRequirment jr;

    fstream FR;

    FR.open("Requirments.txt", ios::in);

    if (FR.fail()) { cout << "\n Loi mo tep tin"; return; }

    cout << "\n Danh sach job \n";

    cout << setw(3) << "STT" << setw(11) << "ID" << setw(25) << "Ho Ten"

        << setw(11) << "Gioi tinh " << setw(11)

        << setw(11) << "c++" << setw(11) << "java" << setw(11) << "tieng anh" << setw(11) << "manage"

        << setw(15) << "nam kn" << "\n";

    int TT = 1;

    while (FR.read((char*)&jr, sizeof(jr)))

    {

        cout << "\n" << setw(3) << TT << " ";

        cout << setw(11) << jr.id << setw(25) << jr.hoten << setw(11) << jr.gioitinh

            << setw(11) << jr.scoreC << setw(11) << jr.scoreJava << setw(11) << jr.scoreE << setw(11) << jr.manage << setw(15) << jr.expOfYear << endl;

        TT = TT + 1;
        
    }
   
    FR.close();
   
}

void JobRequirment::SUA_JOB_REQUIR()

{

    JobRequirment jr;

    fstream FW;

    int n; char ok;
    int c, java, eng, manage, exp;

    cout << "\n Nhap ban ghi can sua:";

    cin >> n; cin.ignore();

    FW.open("Requirments.txt", ios::in | ios::out);

    if (FW.fail()) { cout << " \n Loi mo tep "; return; }

    cout << "\n nhap du lieu sua lai:\n ";

    cout << "ID: "; cin.getline(jr.id, 10);

    cout << "Ho va ten : "; cin.getline(jr.id, 25);

    cout << "gioi tinh : "; cin.getline(jr.gioitinh, 10);

    cout << "Diem ky nang c++: ";
    cin>>c;
    jr.scoreC = c; cin.ignore();

    printf(" Diem ky nang java : "); cin>>java; jr.scoreJava = java; cin.ignore();
    printf("Diem ky nang tieng anh: "); cin>>eng; jr.scoreE = eng; cin.ignore();
    printf("Diem quan ly :"); cin>>manage; jr.manage = manage; cin.ignore();

    printf(" so nam kinh nghiem : "); cin>>exp; jr.expOfYear = exp; cin.ignore();

   printf("\nNhap nua khong (C/K) ? ");

    cin >> ok; cin.ignore();

    FW.seekp((n - 1) * sizeof(jr));

    if (ok == 'c' || ok == 'C') FW.write((char*)&jr, sizeof(jr));

    FW.close();

}

void JobRequirment::BS_JOB()

{

    JobRequirment jr;

    fstream FW;

    int n = FW.tellp() / sizeof(jr) + 1;

    char ok;

    cout << "\n Nhap ban ghi can Bo sung: ";

    cin >> n; cin.ignore();

    if (FW.fail()) { cout << " \n Loi mo tep "; return; }

    FW.open("Requirments.txt", ios::in | ios::out | ios::app);

    FW.seekp(0, ios::end);

    while (1)

    {
        int c, java, eng, manage, exp;
        cout << "\nNhap ban ghi thu: " << n;

        cout << "id : "; cin.getline(jr.id, 10);

        cout << "Ho va ten : "; cin.getline(jr.hoten, 25);

        cout << "gioi tinh : "; cin.getline(jr.gioitinh, 10);

        cout << "Diem ky nang c++";
        cin >> c;
        jr.scoreC = c; cin.ignore();
        cout << "diem ky nang java";
        cin >> java;
        jr.scoreJava = java; cin.ignore();
        cout << " Diem ky nang tieng anh : "; cin>>eng;  jr.scoreE = eng; cin.ignore();

        cout << " diem ki nang quan ly : "; cin>>manage;jr.manage = manage; cin.ignore();

        FW.write((char*)&jr, sizeof(jr));

        cout << "\nNhap nua khong (C/K) ? ";

        cin >> ok; cin.ignore();

        n = n + 1;

        if (ok == 'k' || ok == 'K') break;

    }

    FW.close();

}

void luachon() {

    cout << "\nNhap cac phim theo thu tu 1, 2, 3, 4...de thuc hien chuc nang ";
    cout << "\nNhan phim 1: Nhap thong tin Candidate";
    cout << "\nNhan phim 2: Nhap thong tin JobRequiment";
    cout << "\nNhan phim 3: Sua thong tin Candidate";
    cout << "\nNhan phim 4: Sua thong tin job";
    cout << "\nNhan phim 5: them thong tin  Candidate";
    cout << "\nNhan phim 6: them job";
    cout << "\nNhan phim 7: in ra thong tin Candidate";
    cout << "\nNhan phim 8: in ra thong tin JobRequment";
    cout << "\nNhan phim 0: Thoat khoi chuong trinh" << endl;

}

int main()

{

    Cadidate pm;

    JobRequirment jr;

    char so;

    while (1)

    {

        luachon();

        cin >> so; cin.ignore();

        switch (so)

        {

        case '1':

        {

            system("cls");
            
            pm.NHAP_CD(); break;

        }

        case '2':

        {

            system("cls");
            
            jr.NHAP_JOB_REQUIR(); break;

        }

        case '3':

        {

            system("cls");

            pm.SUA_CD(); break;

        }

        case '4':

        {
            system("cls");
            jr.SUA_JOB_REQUIR(); break;

        }

        case '5':

        {

            system("cls");

            cout << "\n thong tin ung vien : " << endl;

            pm.BS_CD();

            break;

        }

        case '6':

        {

            system("cls");

            cout << "\n thong tin job : " << endl;

            jr.BS_JOB();

            break;

        }

        case '7':

        {

            system("cls");

            cout << "\n danh sach thong tin ung vien " << endl;

            pm.INRA_CD();


            break;

        }
        case'8':{
            system("cls");
            cout << "\n danh sach cac job" << endl;
            jr.INRA_JOB_REQUIR();
            break;
        }
        case '0':

            exit(0);

        }

    }

}