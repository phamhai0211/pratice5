# include <iostream>
# include <fstream>
# include <iomanip>
#include<cstdio>
#include<cstring>
using namespace std;


typedef struct Cadidate 
{
    char id[8];
    char hoten[40];
    char sex[4];
    unsigned int year : 8;
    unsigned int scoreC:7;
    unsigned int scoreJava:7;
    unsigned int manage:7;
    unsigned int scoreE:7;
    unsigned int yearOfEx:5;
    void NHAP_CD();
    void INRA_CD();
    void SUA_CD();
    void BS_CD();
    int SL();   
};

struct JobRequirment 

{

    char id[8];
    char hoten[100];
    char gioitinh[4];
    unsigned int year : 4;
    unsigned int scoreC : 7;
    unsigned int scoreJava : 7;
    unsigned int scoreE : 7;
    unsigned int manage : 7;
    unsigned int expOfYear;
    
    void NHAP_JOB_REQUIR();
    void INRA_JOB_REQUIR();
    void SUA_JOB_REQUIR();
    void BS_JOB();
    int SL_JOB();
};

// INPUT CANDIDATE
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
        printf( "ID: "); cin.getline(CD.id,8);
        printf( "Ho va ten  : "); cin.getline(CD.hoten,40);
        printf( "Gioi tinh   : "); cin.getline(CD.sex,4);
        cout << "Nhap nam sinh :"; cin >> year; CD.year = year; cin.ignore();
        do {
            printf( "diem ky nang c++ : ");
            cin>>c;
            
        } while ((c<0)||(c>100));
        CD.scoreC = c; cin.ignore();
        do {
            printf("diem ky nang Java: ");
            cin >> java;
        } while ((java < 0) || (java > 100)); 
        CD.scoreJava = java;cin.ignore();
        do {

        printf( " Diem ky nang quan ly : ");cin>>manage; 
        } while ((manage<0)||(manage>100));
        CD.manage = manage; cin.ignore();

        do {
            printf(" Diem ky nang tieng anh : "); cin >> eng;
        } while ((eng<0)||(eng>100));
         CD.scoreE= eng; cin.ignore();

         do {
            printf("so nam kinh nghiem: "); cin>>exp; 
         } while ((exp<0)||(exp>30));
        CD.yearOfEx=exp; cin.ignore();
        FW.write((char*)&CD, sizeof(CD));

        cout << "\n Tiep tuc (C/K) ?"; cin >> ok; cin.ignore();

        if ((ok == 'k') || (ok == 'K')) break;
    }

    FW.close();

}



// OUTPUT CANDIDATE
void Cadidate::INRA_CD()

{

    Cadidate cd;

    fstream FR;

    FR.open("Candidates.txt", ios::in);

    if (FR.fail()) { cout << "\n Loi mo tep tin"; return; }

    cout << "\n danh sach Candidates \n";

    cout << setw(3) << "STT" << setw(7) << " " <<" ID " << setw(11) << "Ho Ten"

        << setw(7) << "Gioi tinh " << setw(7) <<"nam sinh"

        << setw(7) << "c++" << setw(7) << "java" << setw(7) << "tieng anh" << setw(7) << "quan ly"

        << setw(7) << "exp" << "\n";

    int TT = 1;
    while (FR.read((char*)&cd, sizeof(cd)))

    {

        cout << "\n" << setw(3) << TT << " ";

        cout << setw(7) << cd.id << setw(11) << cd.hoten << setw(7) <<cd.year<<setw(7) << cd.sex

            << setw(7) << cd.scoreC << setw(7) << cd.scoreJava << setw(7) << cd.scoreE << setw(7) << cd.manage << setw(7) << cd.yearOfEx << endl;
        TT = TT + 1;

    }

    FR.close();

}

int Cadidate::SL() {
    Cadidate cd;
    fstream FR;
    FR.open("Candidates.txt", ios::in);
    if (FR.fail()) { cout << "\n Loi mo tep tin"; return 0; }

    int TT = 0;
    while (FR.read((char*)&cd, sizeof(cd)))

    {

       
        TT = TT + 1;

    }
    return TT;
    FR.close();
}

// EDIT CANDIDATE
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

    cout << "ID: "; cin.getline(cd.id, 8);

    cout << "Ho va ten : "; cin.getline(cd.id, 40);

    cout << "Gioi tinh : "; cin.getline(cd.sex, 4);
    cout << "nam sinh :"; cin >> year; cd.year = year; cin.ignore();
    do {
        cout << "Diem ky nang c++: ";
        cin >> c;
    } while ((c<0)||(c>100));
    cd.scoreC = c; cin.ignore();
    do {
        cout << "Diem ky nang java: ";
        cin >> java;
    } while ((java<0)||(java>100));
    cd.scoreJava = java;
    cin.ignore();

    do {
        cout << " Diem ky nang quan ly : ";
        cin >> manage;
    } while ((manage<0)||(manage>100));
    cd.manage = manage; cin.ignore();

    do {
        cout << " Diem ky nang tieng anh : ";
        cin>>eng;

    } while ((eng<0)||(java>0));
    cd.scoreE = eng; cin.ignore();

    do {
        cout << "so nam kinh nghiem: ";
        cin >> exp;
    } while ((exp<0)||(exp>30));
    cd.yearOfEx = exp; cin.ignore();

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
        cout << "ID: "; cin.getline(cd.id, 8);
        cout << "Ho va ten : "; cin.getline(cd.id, 40);
        cout << "Gioi tinh : "; cin.getline(cd.sex, 4);
        cout << "Nhap nam sinh: "; cin >> year; cd.year = year; cin.ignore();
        do {
            cout << "Diem ky nang c++ ";
            cin >> c;
        } while ((c<0)||(c>100));     
        cd.scoreC = c; cin.ignore();

        do {
            cout << "Diem ky nang java";
            cin >> java;
        } while ((java<0)||(java>100)); 
        cd.scoreJava = java; cin.ignore();

        do {
            cout << " Diem ky nang quan ly : ";
            cin >> manage;
        } while ((manage<0)||(manage>100));
        cd.manage = manage; cin.ignore();

        do {
             cout << " Diem ky nang tieng anh : "; cin>>eng;

        } while ((eng<0)||(eng>100));
        cd.scoreE = eng; cin.ignore();

        do {

            cout << "so nam kinh nghiem :";
            cin>>exp; 
        } while ((exp<0)||(exp>100));
        cd.yearOfEx = exp; cin.ignore();
        FW.write((char*)&cd, sizeof(cd));

        cout << "\nNhap nua khong (C/K) ? ";

        cin >> ok; cin.ignore();

        n = n + 1;

        if (ok == 'k' || ok == 'K') break;

    }

    FW.close();

}

int JobRequirment::SL_JOB() {
    JobRequirment jr;
    fstream FR;
    FR.open("Requirments.txt", ios::in);
    if (FR.fail()) { cout << "\n Loi mo tep tin"; return 0; }

    int TT = 0;
    while (FR.read((char*)&jr, sizeof(jr)))

    {
        TT = TT + 1;
    }
    return TT;
    FR.close();
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
        cout << "id job: "; cin.getline(jr.id, 8);
        cout << "Ho va ten  : "; cin.getline(jr.hoten, 100);
        cout << "gioi tinh  : "; cin.getline(jr.gioitinh, 15);
        do {
            cout << "Diem ky nang c++: ";
            cin >> c;

        } while ((c<0)||(c>100));
        jr.scoreC = c; cin.ignore();

        do {
            cout << "Diem ky nang java: ";
            cin >> java;
        } while ((java<0)||(java>100));
        
        jr.scoreJava = java;
        cin.ignore();

        do {
             printf( " ky nang tieng anh:  "); cin>>eng;

        } while ((eng<0)||(eng>100));
       jr.scoreE = eng; cin.ignore();

       do {
           printf(" ky nang quan ly: "); cin >> manage;
       } while (manage<0||manage>100);
       jr.manage = manage; cin.ignore();

       do {
           printf("so nam kinh nghiem: "); cin >> exp;
       } while ((exp<0)||(exp>30));
       jr.expOfYear = exp; cin.ignore();
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
    do {
        cout << "Diem ky nang c++: ";
        cin>>c;
    } while ((c<0)||(c>100));
    jr.scoreC = c; cin.ignore();

    do {
        printf(" Diem ky nang java : "); cin >> java;
    } while ((java<0)||(java>100));
    jr.scoreJava = java; cin.ignore();

    do {
        printf("Diem ky nang tieng anh: "); cin >> eng;
    } while ((eng<0)||(eng>100));
    jr.scoreE = eng; cin.ignore();

    do {
        printf("Diem quan ly :"); cin>>manage; 
    } while ((manage<0)||(manage>100));
    jr.manage = manage; cin.ignore();

    do {
        printf(" so nam kinh nghiem : "); cin >> exp;
    } while ((exp<0)||(exp>30));
    jr.expOfYear = exp; cin.ignore();

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

        cout << "id : "; cin.getline(jr.id, 8);

        cout << "Ho va ten : "; cin.getline(jr.hoten, 100);

        cout << "gioi tinh : "; cin.getline(jr.gioitinh, 4);

        do {
            cout << "Diem ky nang c++";
            cin >> c;
        } while ((c<0)||(c>100));
        jr.scoreC = c; cin.ignore();

        do {
            cout << "diem ky nang java";
            cin >> java;

        } while ((java<0)||(java>100));
        jr.scoreJava = java; cin.ignore();

        do {
            cout << " Diem ky nang tieng anh : "; cin>>eng;  
        } while ((eng<0)||(eng>100));
        jr.scoreE = eng; cin.ignore();

        do {
            cout << " diem ki nang quan ly : "; cin >> manage;
        } while ((manage<0)||(manage>100));
        jr.manage = manage; cin.ignore();

        do {
            cout << "so nam kinh nghiem: "; cin >> exp;
        } while ((exp<0)||(exp>30));
        jr.expOfYear = exp; cin.ignore();
        FW.write((char*)&jr, sizeof(jr));

        cout << "\nNhap nua khong (C/K) ? ";

        cin >> ok; cin.ignore();

        n = n + 1;

        if (ok == 'k' || ok == 'K') break;

    }

    FW.close();

}

void luachon() {
    Cadidate cd;
    JobRequirment jr;
    cout << "so luong Candidate dang co: " << cd.SL() << endl;
    cout << "so luong Job dang co: " << jr.SL_JOB() << endl;
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
typedef struct FNC {

};
int main()

{
    
    Cadidate cd;

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
            
            cd.NHAP_CD(); break;

        }

        case '2':

        {

            system("cls");
            
            jr.NHAP_JOB_REQUIR(); break;

        }

        case '3':

        {

            system("cls");

            cd.SUA_CD(); break;

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

            cd.BS_CD();

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

            cd.INRA_CD();


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
    return 0;
}