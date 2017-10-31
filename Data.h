#define     VERSION     21
#define     VERSION2    "14.11.2009"

#define     MAX_REV     9

#define     PERS        0
#define     KOLL        1
#define     GRUP        2
#define     DIST        3
#define     FIN         4
#define     CHIP        5
#define     COMMENT     6
#define     START       7
#define     ADV         8

#define		MAX_DATA    30000
#define		MAX_GRUP    10000
#define		MAX_DIST    10000
#define		MAX_KOLL    10000
#define		MAX_FIN     20000
#define		MAX_NUM     30000

#define		MAX_CP      200

/////////////////////////////////////////////////////////////////////////////
// ������ ��� �� ��� Adventure
typedef struct
{
    UINT    Grup;               //������
	char    Name[30];           //������������
    int     x, y;               //����������, ������
    UINT    tabl;               //0-���������� �����, ��� ������, 1 � 2 - �� ������ tabl1.txt � tabl2.txt 
    UINT    mode;               //�����: 0-����� ������ 1- �������
    UINT    ochki;              //����
    UINT    Tideal;             //����� ����������
    UINT    ochki_ideal;        //���� ����������
    UINT    persent;            //
    UINT    min;                //
    UINT    mode_korz;          //
    UINT    start;              //
    UINT    stop;               //
    UINT    stop_sec;           //
} CCp;
/////////////////////////////////////////////////////////////////////////////
//class CPunch:public
typedef struct
{
    BYTE    Num;
    int     Tim;
} CPunch;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int     Nchip;
    int     Nstart;
    int     Ncp;
    CPunch  Start,
            Finish,
            Check,
            Clear,
            CP[64];
} CSi64;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int     Nchip;
    int     Nstart;
    int     Ncp;
    CPunch  Start,
            Finish,
            Check,
            Clear,
            CP[200];
} CSi;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	WORD    Nom;
	int     Tfin;           //��� ����� - �����, ������� ���� - ���� ����� �� �������
    BYTE    Sound;
} CFin;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char	Name[26];
	char	Comment[21];
	WORD	GR;
	BYTE    Kwal;
	WORD	Gruppa;
    WORD    Koll;

    BYTE    Reserv9;
    WORD    N;

    int     Tstart;
    int     Tfin;
    int     Res;

    int     Reserv10;           //Shtr1;              //�����-������� �����
    int     Reserv11;           //Shtr2;              //�����-������� �����
    WORD    Sum_Shtr;           //�����-����

    WORD    Mesto;
    int     Ochki;
	int     SI;					//SI-card
	int     ID;

    BYTE    Sel;				//������� �������
    BYTE    WK,                 //���
            Lichno,             //���
            Pol,
            CombFlag;           //��� �����: ���� ���, ������ (���� ���������)
                                //0x01 - ���� ���
                                //0x02 - ������
	int     Vereb;
	BYTE	FinFlag;            //����
	int		Mno[10];
    int     Sum_Mno;            //����� �����������
    int     Etap;
    int     Shtraf;             //����� � ������ Adventure
    int     reserv7;
    int     reserv6;
    int     reserv5;
    int     reserv4;
    int     reserv3;
    int     reserv2;
    int     reserv1;
    int     reserv0;
} CData;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	int     ID;
	char    Name[20+1];
	char    Predstav[20+1];
    WORD    N_pers_Base;        //���-�� ����� � ���������� (� ����)
    WORD    N_pers_Fin;         //���-�� ����� � ���������� (� ������)
    WORD    N_pers_Sel;         //���-�� ����� � ���������� (����������)
	BYTE    Sel;
} CKoll;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int     ID;                 //������ ��� - �������: ��������� ���. ��������
	char    Name[8+1];
    char    ms;
    char    kms;
	WORD    NDist;

    WORD    N_pers_Base;        //���-�� ����� � ���������� (� ����)
    WORD    N_pers_Fin;         //���-�� ����� � ���������� (� ������)
    WORD    N_pers_Sel;         //���-�� ����� � ���������� (����������)
	BYTE	Sel;                //����� 0x01 - �������
                                //����� 0x02 - ����� ����������� �������

    WORD    Vz_Arenda_Norm;     //��������� �����: ����,  ������������ ���
    WORD    Vz_Arenda_Lgota;    //��������� �����: �����, ������������ ���
    WORD    Vz_Chip_Norm;       //��������� �����: ����,  ���� ���
    WORD    Vz_Chip_Lgota;      //��������� �����: �����, ���� ���
} CGrup;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	int     ID;                 //�������������
	char    Name[12];           //������������ ���������
    BYTE    N_KP[100];          //������������� ������ ��
    WORD    M_KP[100];          //����� �� ��
    UINT	Km;                 //����� ���������, ������
	UINT	Kor;                //� ���������� ��������
	UINT	Kp;                 //���������� ��
	UINT	Nabor;              //����� ������
	UINT	Time;               //����������� �����
	UINT	reserv2;            //
	UINT	reserv1;            //
    WORD	N_pers_Base;        //���-�� ����� � ��������� (� ����)
    WORD	N_pers_Fin;         //���-�� ����� � ��������� (� ������)
    WORD	N_pers_Sel;         //���-�� ����� � ��������� (����������)
	BYTE	Sel;                //���� �������
} CDist;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char    Name[10][80];       //�����
	char    Mesto[25];          //����� ����������
	char    Secret[25];         //���������
	char    Sudia[25];          //������� �����
	char    Date[21];           //���� ����������
    BYTE    Wid;                //��� ������������:
	BYTE	Wid_Est;            //
    char    ZamPoSTO[25];       //��� �� ���
    char    Inspector[25];      //���������
    char    reserv_txt[50];     //��� ����� ������ �����
	WORD	Filtr_Koll,
			Filtr_Dist,
			Filtr_Grup,
			Filtr_Sel,
            Filtr_Etap,
            Sel_Koll,
            Sel_Grup,
            Sel_Etap;
    WORD    A,                  //               B*T��
            B;                  // ����*10= A - --------
                                //              C*T�����
    WORD    SetNum_Start,
            SetNum_Step;
    int     SetTime_Start,
            SetTime_Step;
    BYTE	Wid_sort,
            Print_Speed,        //� ������� - ��������
            Split_Place,        //� ��������� ����������� � ������� - ����� �� �����
            Print_Vznos,
			OnlySel,
			N_Cell,
			Dst,
            N_Cell_All,
            CardPrint,
            Kogo_Vereb,
            Etap_Vereb,
            Koll_Vereb,
            Kogo_Start,
            PrintSI,
            SI_Manual,
            Print_NachDist;     //�������� ���.�����.
    int     Sor_Time2,          //���������� �����.                     !!! ����� ������� INT, � �� WORD
            Sor_Time3,          //�����, ���������                      !!! ����� ������� INT, � �� WORD
                                //               B*T��
                                // ����*10= A - --------
            C;                  //              C*T�����
    BYTE    Kogo_Res,
            Only_Best,
            SI_Print_Shapka,    //Snd_On,
            SI_MnogoSutok,
            SI_New_Vid,
            SI_Add,             //��������� ������ ���� - �� ��������, � ����������
            Sel_Unsel,
            Pos,                //������� ��� ����������
            Kuda,               //0-�������� �� �������, 1-HTML
            View_Offset;        //�������� ��� ����������
    int     Sor_Time;           //������ ������������ - ��� SportIdent
    BYTE    Limit;              //���� - �������� �����. �����
    BYTE    Fin,                //�����:0-�� ���������, 1-�� �������� �������, 2-����.
            Start,              //�����:0-�� ����,      1-�� �������. �������, 2-����.
            Otm,                //��������� �� ������� � ���
            Print,              //�������� ����������
            Print2,             //�������� ������� 2-� ����������
            Offset,             //�������� ��� ������, ��
            AutoSave,           //==1, ���� ������� ����� ��������������
            View,               //����� ��� ����������
            Res_Wyp,            //1-�������� ���������� ��������
            Send_Dubl,          //=1, ���� ����� � �������� ���������� �������
            Com,                //����� ���-�����
            Snd_Koll,           //���������� �� ���������
            Snd_Grup,           //���������� �� ������
            ResAll,             //�������� ��� ����������� ����� �����
            PrintChip,          //�������� ���������� �����
            Precision,          //��������: 0-1 ���, 1-0,1 ���, 2-0,01 ���
            NoStart,            //�������� �� ������������
			PrintNomCp,			//�������� � ���������� �� �������� � ��
            ReadMno,            //����� ���� ����������� ������
            Krugi,              //�������� ���������� � ������ ���������� ������
            Ochki,              //0-���,1-����
            Est1000,            //� ������ ��������� �� 4-� �������
            ChipWarning,        //�������� ����������� ��� SI
			Kogo_wyp,//
			Kogo,//
            Ext_Html,           //HTML �� �������� � ����������
            Dsq_Limit,          //������� �� ���������� ������������ �������
            NewPage,
            PrintVar,           //�������� ������� ����������� � ���������
            Mno_start;          //���� �� �� ����������� �������� ��������
    WORD    Comment_GrupDNF,    //������� ���������� ������������
            Comment_GrupDNS;    //������� ���������� �.�����
    WORD    Reserv5,
            Reserv6;           
    int     Offset_Time_AMB;
    int     Shtraf;             //���� ������ �� �������� ��
    BYTE    Mno[10];            //���� �� ��������� � ����� �������.
    BYTE    wyp_est;            //� ������� - ���������� ������� ������ 123-4
    BYTE    BSM7;               //���-����� �������
    BYTE    lichno_ochki;       //������ �� �������� ����
	char    Prich[9][12];       //������� ������
	char    Text[9][12];        //������ ������
    char    Raspiska[90];       //����� ��������
    BYTE    Reserv1;
    BYTE    Etapov;             //���������� ������� � �������� - ���������� ������
    BYTE    EstWK;              //� ������� ��� - ���� ������ �������, ������ �/�
    BYTE    Zachet;             //��������� � ��������� ���������� �������� ����������
    BYTE    SI_2card;           //� ���� ����������� ������� ����� 2�� ����
    BYTE    Comment_Right;
    BYTE    Comment_RightNom;
    BYTE    Comment_RightKoll;
    BYTE    Comment_GrupNom;
    BYTE    Comment_GrupKoll;
    BYTE    Flag_Rasp;          //�������-�������� ��������
    BYTE    Print_Kod;          //�������� ��� ����������
    BYTE    Print_Comment;      //�������� ���������� ��� ���������
    BYTE    LCD_ON;             //�������, ��� ���� �������� ���� ��� LCD
    BYTE    LCD_START;          //��� ���� �������� ���� ��� LCD - ��������� ��� ��������
    BYTE    TABLO;              //�������� �� �� �����
    BYTE    GetNum;             //��� ������������ - ���� ������
    BYTE    LCD_Rotate;         //��������� �� 90 ��������
    BYTE    LCD_Line;           //�������� ������ ����� ����
    BYTE    LCD_Refresh;        //����� �������
    BYTE    LCD_Font;           //������ ������
    BYTE    LCD_Mode;           //�����: 0-���  ������ ����, 1-������, 2-����������
    BYTE    LCD_Flag;           //��������� �������� �����
    char    On_line_site[60];
    char    server_name[15];
    char    Sent_mode;
    BYTE    Line2;              //=1 - ���� ���� �������� 2� ������ � �������
    BYTE    Remake_Check;
    BYTE    Small;              //������ ������ � ������� - 70%
    BYTE    Rogain;             //����� ADV-���������, 1 - ������, 0 - �������
    BYTE    LCD_Result;
    BYTE    LCD_Title;
    BYTE    Stat;				//� ����������� �������� ���������� �� ��
    BYTE    Comment;            //� ���������� ����������� - �������� �����������
    BYTE    Delta;              //� ���������� ����������� - ����������
    BYTE    Sprint;             //BS7-S - 0 - �������,1 - ������ ��� 2- ����� �����/�����
    BYTE    DNS;                //� ��������������� =1 - ���������� �� ������������
    BYTE    DNF;                //� ��������������� =1 - ���������� �� ��������������
    BYTE    Best6;              //����=����������� ������� 6��
    BYTE    Labir;              //����� ���������: ��������� ������, ��������� ���������, ����������� �� �������
} CInfo;
/////////////////////////////////////////////////////////////////////////////
///--------------������ ���������� ������ ������-------------
class CSi_old:public CObject
{
public:
    int     Nchip;
    int     Nstart;
    int     Tstart;
    int     Tfin;
    int     Ncp;
    int     Cp_Num[36];
    int     Cp_Tim[36];
};
/////////////////////////////////////////////////////////////////////////////
// ����� ��������� Sound � Nom?
class CFin_old:public CObject
{
public:
	int		Nom;
	int     Tfin;
    BYTE    Sound;
};
/////////////////////////////////////////////////////////////////////////////
class CData_old:public CObject
{
public:
	char	Name[26];
	int		GR;
	int     Kwal;               //����
	int		Gruppa;
    int     Koll;
    int     Mno3;
    int     Mno4;
    int     Etap;               //����
    int     N;
    int     Tstart;
    int     Tfin;
    int     Res;
    int     Sum_Shtr;           //�����-����
    int     Mesto;
    int     Shtr1;              //�����-������� ����� -------------------------------- ����� �� ������������!!!
    int     Ochki;
    int     Sum_Mno;            //����� �����������
	int     SI;					//SI-card
	int     ID;
    BYTE    WK,                 //���
            Lichno,             //���
            Pol,
            CombFlag;           //��� �����: ���� ���, ������ (���� ���������)
                                //0x01 - ���� ���
                                //0x02 - ������
    int     Shtr2;              //�����-������� ����� -------------------------------- ����� �� ������������!!!
    BOOL    Sel;				// ������� �������
    int     reserv2;
	int		Mno5;
	int		Vereb,
			FinFlag,            //����
			Mno1,
            Mno2;				//����������
};
/////////////////////////////////////////////////////////////////////////////
class CKoll_old:public CObject
{
public:
	int     ID;
	char    Name[20+1];
	char    Predstav[20+1];
	char    Adress[100+1];
	char    Email[30+1];
    int     Error;              //���/���� ������
    int     N_pers_Base;        //���-�� ����� � ���������� (� ����)
    int     N_pers_Fin;         //���-�� ����� � ���������� (� ������)
    int     N_pers_Sel;         //���-�� ����� � ���������� (����������)
    int     reserv2;
	int		Sel,
			reserv3,
			reserv4,
			reserv5;
};
/////////////////////////////////////////////////////////////////////////////
class CGrup_old:public CObject
{
public:
	int     ID;
	char    Name[10];
	int     NDist;
    int     Vz_Arenda_Norm;     //��������� �����: ����,  ������������ ���
    int     N_pers_Base;        //���-�� ����� � ���������� (� ����)
    int     N_pers_Fin;         //���-�� ����� � ���������� (� ������)
    int     N_pers_Sel;         //���-�� ����� � ���������� (����������)
	int		Sel;
    int     Vz_Arenda_Lgota;    //��������� �����: �����, ������������ ���
    int     Vz_Chip_Norm;       //��������� �����: ����,  ���� ���
    int     Vz_Chip_Lgota;      //��������� �����: �����, ���� ���
};
/////////////////////////////////////////////////////////////////////////////
class CDist_old:public CObject
{
public:
	int     ID;                 //�������������
    int     Error;              //���/���� ������
	char    Name[12];           //������������ ���������
//��� 251 ����, ������ 3*80=240
    BYTE    N_KP[80];     //������������� ������ ��
    WORD    M_KP[80];           //����� �� ��
//�������� �����������
    BYTE    nonuse[11];
    UINT	Km;                 //����� ���������, ������
	UINT	Kor;                //� ���������� ��������
	UINT	Kp;                 //���������� ��
	UINT	Nabor;              //����� ������
	UINT	Time;               //����������� �����
	UINT	Nevent;             //���������� ����������� ����� �����
	UINT	NachDist;           //� ���.���������
    UINT	N_pers_Base;        //���-�� ����� � ��������� (� ����)
    UINT	N_pers_Fin;         //���-�� ����� � ��������� (� ������)
    UINT	N_pers_Sel;         //���-�� ����� � ��������� (����������)
	int		Sel;                //���� �������
};
/////////////////////////////////////////////////////////////////////////////
class CInfo_old:public CObject
{
public:
	char    Name1[80];          //
	char    Name2[80];
	char    Name3[80];
	char    Mesto[25];
	char    Secret[25];
	char    Sudia[25];
	char    Date[21];
    int     Wid;
	BOOL	Wid_Est;
    char    NachDist[4][25];
	int		Filtr_Koll,
			Filtr_Dist,
			Filtr_Grup,
			Filtr_Sel;
    int     Filtr_Etap;
    int     SetNum_Start,
            SetNum_Step;
    int     SetTime_Start,
            SetTime_Step;
    char	Wid_sort,
            Print_Speed,        //� ������� - ��������
            Split_Place,        //� ��������� ����������� � ������� - ����� �� �����
            Print_Vznos;
	int		Video_X,//
			Video_Y,//
			OnlySel,
			N_Cell,
			Dst,
            N_Cell_All,
            Video_Bri;
    char    CardPrint,
            Kogo_Vereb,
            Etap_Vereb,
            Koll_Vereb,
            Kogo_Start,
            PrintSI,
            SI_Manual,
            Print_NachDist;     //�������� ���.�����.
    int     A,                  //               B*T��
            B,                  // ����*10= A - --------
            C,                  //              C*T�����
            reserv8;
    int     Kogo_Res,
            Only_Best,
            Snd_On,
            Sel_Koll,
            Sel_Grup,
            Sel_Etap,
            Sel_Unsel,
            Pos,                //������� ��� ����������
            Kuda,               //0-�������� �� �������, 1-HTML
            View_Offset;        //�������� ��� ����������
    int     Sor_Time;           //������ ������������ - ��� SportIdent
    char    Chip_or_Nomer,      //��� ���������� - ��� ��� ����� � ����
            Fin,                //�����:0-�� ���������, 1-�� �������� �������, 2-����.
            Start,              //�����:0-�� ����,      1-�� �������. �������, 2-����.
            Otm,                //��������� �� ������� � ���
            Print,              //�������� ����������
            Print2,             //�������� ������� 2-� ����������
            Offset,             //�������� ��� ������, ��
            AutoSave,           //==1, ���� ������� ����� ��������������
            View,               //����� ��� ����������
            Res_Wyp,            //1-�������� ���������� ��������
            Spec,               //����� �����������: 0-����� 1-���������
            Com,                //����� ���-�����
            Snd_Koll,           //���������� �� ���������
            Snd_Grup,           //���������� �� ������
            ResAll,             //�������� ��� ����������� ����� �����
            PrintChip,          //�������� ���������� �����
            Precision,          //��������: 0-1 ���, 1-0,1 ���, 2-0,01 ���
            NoStart,            //�������� �� ������������
			PrintNomCp,			//�������� � ���������� �� �������� � ��
            Mno1,               //���� �� ��������� � ����� �������. 1 ����
            Mno2,               //���� �� ��������� � ����� �������. 2 ����
            Mno3,               //���� �� ��������� � ����� �������. 3 ����
            Mno4,               //���� �� ��������� � ����� �������. 4 ����
            Mno5,               //���� �� ��������� � ����� �������. 5 ����
            ReadMno,            //����� ���� ����������� ������
            Krugi,              //�������� ���������� � ������ ���������� ������
            Ochki,              //0-���,1-����
            Est1000,            //� ������ ��������� �� 4-� �������
            ChipWarning,        //�������� ����������� ��� SI
			Kogo_wyp,//
			Kogo,//
            Video_On,
            Video_Porog,
            NewPage,
            PrintVar,           //�������� ������� ����������� � ���������
            Mno_start;          //���� �� �� ����������� �������� ��������
    int     Time_Koll,          //������������ ����������, ��
            Time_Grup,          //������������ ������, ��
            Time_Pers;          //������������ ���������, ��
};
// �������� ����� �������� � ����: ���� �� �������� ��������
class CInfo2_old:public CObject     //� ����������� ���������� � CInfo
{
public:
	char    Name[9][12];        //������� ������
	char    Text[9][12];        //������ ������
};
///--------------����� ���������� ������ ������-------------

