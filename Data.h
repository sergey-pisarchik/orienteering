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
// Данные про КП для Adventure
typedef struct
{
    UINT    Grup;               //группа
	char    Name[30];           //Наименование
    int     x, y;               //координаты, метров
    UINT    tabl;               //0-начисление очков, как обычно, 1 и 2 - из таблиц tabl1.txt и tabl2.txt 
    UINT    mode;               //режим: 0-смена группы 1- обычный
    UINT    ochki;              //очки
    UINT    Tideal;             //время идеального
    UINT    ochki_ideal;        //очки идеального
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
	int     Tfin;           //три байта - время, старший байт - буду номер КП хранить
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

    int     Reserv10;           //Shtr1;              //Штраф-старшее слово
    int     Reserv11;           //Shtr2;              //Штраф-младшее слово
    WORD    Sum_Shtr;           //Штраф-итог

    WORD    Mesto;
    int     Ochki;
	int     SI;					//SI-card
	int     ID;

    BYTE    Sel;				//отметка обычная
    BYTE    WK,                 //бит
            Lichno,             //бит
            Pol,
            CombFlag;           //еще флаги: свой ЧИП, льгота (член федерации)
                                //0x01 - свой ЧИП
                                //0x02 - льгота
	int     Vereb;
	BYTE	FinFlag;            //байт
	int		Mno[10];
    int     Sum_Mno;            //сумма многодневки
    int     Etap;
    int     Shtraf;             //штраф в режиме Adventure
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
    WORD    N_pers_Base;        //Кол-во людей в коллективе (в базе)
    WORD    N_pers_Fin;         //Кол-во людей в коллективе (в финише)
    WORD    N_pers_Sel;         //Кол-во людей в коллективе (отмеченных)
	BYTE    Sel;
} CKoll;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int     ID;                 //первый бит - признак: разрешено вып. разрядов
	char    Name[8+1];
    char    ms;
    char    kms;
	WORD    NDist;

    WORD    N_pers_Base;        //Кол-во людей в коллективе (в базе)
    WORD    N_pers_Fin;         //Кол-во людей в коллективе (в финише)
    WORD    N_pers_Sel;         //Кол-во людей в коллективе (отмеченных)
	BYTE	Sel;                //маска 0x01 - отметка
                                //маска 0x02 - можно присваивать разряды

    WORD    Vz_Arenda_Norm;     //стартовый взнос: норм,  арендованный ЧИП
    WORD    Vz_Arenda_Lgota;    //стартовый взнос: льгот, арендованный ЧИП
    WORD    Vz_Chip_Norm;       //стартовый взнос: норм,  свой ЧИП
    WORD    Vz_Chip_Lgota;      //стартовый взнос: льгот, свой ЧИП
} CGrup;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	int     ID;                 //идентификатор
	char    Name[12];           //Наименование дистанции
    BYTE    N_KP[100];          //дешифрованные номера КП
    WORD    M_KP[100];          //метры до КП
    UINT	Km;                 //длина дистанции, метров
	UINT	Kor;                //№ стартового коридора
	UINT	Kp;                 //количество КП
	UINT	Nabor;              //набор высоты
	UINT	Time;               //контрольное время
	UINT	reserv2;            //
	UINT	reserv1;            //
    WORD	N_pers_Base;        //Кол-во людей в дистанции (в базе)
    WORD	N_pers_Fin;         //Кол-во людей в дистанции (в финише)
    WORD	N_pers_Sel;         //Кол-во людей в дистанции (отмеченных)
	BYTE	Sel;                //флаг отметки
} CDist;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char    Name[10][80];       //шапка
	char    Mesto[25];          //место проведения
	char    Secret[25];         //секретарь
	char    Sudia[25];          //главный судья
	char    Date[21];           //дата проведения
    BYTE    Wid;                //вид соревнований:
	BYTE	Wid_Est;            //
    char    ZamPoSTO[25];       //Зам по СТО
    char    Inspector[25];      //Инспектор
    char    reserv_txt[50];     //под имена файлов звука
	WORD	Filtr_Koll,
			Filtr_Dist,
			Filtr_Grup,
			Filtr_Sel,
            Filtr_Etap,
            Sel_Koll,
            Sel_Grup,
            Sel_Etap;
    WORD    A,                  //               B*Tуч
            B;                  // очки*10= A - --------
                                //              C*Tпобед
    WORD    SetNum_Start,
            SetNum_Step;
    int     SetTime_Start,
            SetTime_Step;
    BYTE	Wid_sort,
            Print_Speed,        //в сплитах - скорость
            Split_Place,        //в протоколе результатов в сплитах - место на этапе
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
            Print_NachDist;     //Печатать нач.диста.
    int     Sor_Time2,          //штрафуемое время.                     !!! потом сделать INT, а не WORD
            Sor_Time3,          //время, снимаются                      !!! потом сделать INT, а не WORD
                                //               B*Tуч
                                // очки*10= A - --------
            C;                  //              C*Tпобед
    BYTE    Kogo_Res,
            Only_Best,
            SI_Print_Shapka,    //Snd_On,
            SI_MnogoSutok,
            SI_New_Vid,
            SI_Add,             //повторное чтение ЧИПа - не затирать, а дописывать
            Sel_Unsel,
            Pos,                //позиция при сохранении
            Kuda,               //0-печатать на принтер, 1-HTML
            View_Offset;        //смещение при сохранении
    int     Sor_Time;           //Начало соревнований - для SportIdent
    BYTE    Limit;              //флаг - печатать контр. время
    BYTE    Fin,                //Финиш:0-из протокола, 1-из финишной отметки, 2-посл.
            Start,              //Старт:0-из базы,      1-из стартов. отметки, 2-перв.
            Otm,                //проверять ли отметку и как
            Print,              //печатать информашку
            Print2,             //печатать снятому 2-ю информашку
            Offset,             //Смещение при печати, см
            AutoSave,           //==1, если включен режим автосохранения
            View,               //Режим при сохранении
            Res_Wyp,            //1-печатать выполнение разрядов
            Send_Dubl,          //=1, если слать в интернет количество финишей
            Com,                //номер СОМ-порта
            Snd_Koll,           //озвучивать ли коллектив
            Snd_Grup,           //озвучивать ли группу
            ResAll,             //печатать все прохождения через финиш
            PrintChip,          //печатать содержимое ЧИПов
            Precision,          //точность: 0-1 сек, 1-0,1 сек, 2-0,01 сек
            NoStart,            //печатать не стартовавших
			PrintNomCp,			//печатать в протоколах со сплитами № КП
            ReadMno,            //какой день многодневки читаем
            Krugi,              //печатать результаты с учётом количества кругов
            Ochki,              //0-нет,1-есть
            Est1000,            //в финише дополнять до 4-х значных
            ChipWarning,        //Выдавать диагностику при SI
			Kogo_wyp,//
			Kogo,//
            Ext_Html,           //HTML со ссылками в протоколах
            Dsq_Limit,          //снимать за превышение контрольного времени
            NewPage,
            PrintVar,           //печатать вариант рассеивания в эстафетах
            Mno_start;          //надо ли из многодневки генерить гандикап
    WORD    Comment_GrupDNF,    //сколько показывать претендентов
            Comment_GrupDNS;    //сколько показывать н.старт
    WORD    Reserv5,
            Reserv6;           
    int     Offset_Time_AMB;
    int     Shtraf;             //цена штрафа за невзятие КП
    BYTE    Mno[10];            //надо ли учитывать в зачёт многодн.
    BYTE    wyp_est;            //в выписке - эстафетный вариант номера 123-4
    BYTE    BSM7;               //это-новая станция
    BYTE    lichno_ochki;       //Давать ли личникам очки
	char    Prich[9][12];       //Причины снятия
	char    Text[9][12];        //Пункты правил
    char    Raspiska[90];       //текст расписки
    BYTE    Reserv1;
    BYTE    Etapov;             //Присвоение номеров в эстафете - количество этапов
    BYTE    EstWK;              //В результ эст - если разные команды, значит в/к
    BYTE    Zachet;             //Указывать в командных количество зачётных участников
    BYTE    SI_2card;           //в поле комментарий пишется номер 2го ЧИПа
    BYTE    Comment_Right;
    BYTE    Comment_RightNom;
    BYTE    Comment_RightKoll;
    BYTE    Comment_GrupNom;
    BYTE    Comment_GrupKoll;
    BYTE    Flag_Rasp;          //признак-печатать расписку
    BYTE    Print_Kod;          //Печатать код дисциплины
    BYTE    Print_Comment;      //Печатать коментарий про участника
    BYTE    LCD_ON;             //Признак, что надо генерить файл для LCD
    BYTE    LCD_START;          //Что надо генерить файл для LCD - стартовую или финишную
    BYTE    TABLO;              //выводить ли на табло
    BYTE    GetNum;             //для неизвестного - ввод номера
    BYTE    LCD_Rotate;         //повернуть на 90 градусов
    BYTE    LCD_Line;           //Выделять строки через одну
    BYTE    LCD_Refresh;        //время рефреша
    BYTE    LCD_Font;           //Размер шрифта
    BYTE    LCD_Mode;           //Режим: 0-при  чтении чипа, 1-таймер, 2-однократно
    BYTE    LCD_Flag;           //Вставлять картинку флага
    char    On_line_site[60];
    char    server_name[15];
    char    Sent_mode;
    BYTE    Line2;              //=1 - если надо печатать 2ю строку в сплитах
    BYTE    Remake_Check;
    BYTE    Small;              //размер шрифта в сплитах - 70%
    BYTE    Rogain;             //стиль ADV-протокола, 1 - рогейн, 0 - обычный
    BYTE    LCD_Result;
    BYTE    LCD_Title;
    BYTE    Stat;				//в результатах выводить статистику по КП
    BYTE    Comment;            //в протоколах результатов - печатать комментарий
    BYTE    Delta;              //В протоколах результатов - отставание
    BYTE    Sprint;             //BS7-S - 0 - Обычная,1 - спринт моя 2- сринт Ромка/Пашка
    BYTE    DNS;                //в комментаторском =1 - показывать не стартовавших
    BYTE    DNF;                //в комментаторском =1 - показывать не финишировавших
    BYTE    Best6;              //Тпоб=Усреднённомы времени 6ти
    BYTE    Labir;              //Режим либиринта: добавлять запись, создавать участника, раскидывать по группам
} CInfo;
/////////////////////////////////////////////////////////////////////////////
///--------------начало объявления старых данных-------------
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
// Может упаковать Sound в Nom?
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
	int     Kwal;               //байт
	int		Gruppa;
    int     Koll;
    int     Mno3;
    int     Mno4;
    int     Etap;               //байт
    int     N;
    int     Tstart;
    int     Tfin;
    int     Res;
    int     Sum_Shtr;           //Штраф-итог
    int     Mesto;
    int     Shtr1;              //Штраф-старшее слово -------------------------------- нигде не используется!!!
    int     Ochki;
    int     Sum_Mno;            //сумма многодневки
	int     SI;					//SI-card
	int     ID;
    BYTE    WK,                 //бит
            Lichno,             //бит
            Pol,
            CombFlag;           //еще флаги: свой ЧИП, льгота (член федерации)
                                //0x01 - свой ЧИП
                                //0x02 - льгота
    int     Shtr2;              //Штраф-младшее слово -------------------------------- нигде не используется!!!
    BOOL    Sel;				// отметка обычная
    int     reserv2;
	int		Mno5;
	int		Vereb,
			FinFlag,            //байт
			Mno1,
            Mno2;				//двухдневка
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
    int     Error;              //Код/флаг ошибки
    int     N_pers_Base;        //Кол-во людей в коллективе (в базе)
    int     N_pers_Fin;         //Кол-во людей в коллективе (в финише)
    int     N_pers_Sel;         //Кол-во людей в коллективе (отмеченных)
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
    int     Vz_Arenda_Norm;     //стартовый взнос: норм,  арендованный ЧИП
    int     N_pers_Base;        //Кол-во людей в коллективе (в базе)
    int     N_pers_Fin;         //Кол-во людей в коллективе (в финише)
    int     N_pers_Sel;         //Кол-во людей в коллективе (отмеченных)
	int		Sel;
    int     Vz_Arenda_Lgota;    //стартовый взнос: льгот, арендованный ЧИП
    int     Vz_Chip_Norm;       //стартовый взнос: норм,  свой ЧИП
    int     Vz_Chip_Lgota;      //стартовый взнос: льгот, свой ЧИП
};
/////////////////////////////////////////////////////////////////////////////
class CDist_old:public CObject
{
public:
	int     ID;                 //идентификатор
    int     Error;              //Код/флаг ошибки
	char    Name[12];           //Наименование дистанции
//был 251 байт, теперь 3*80=240
    BYTE    N_KP[80];     //дешифрованные номера КП
    WORD    M_KP[80];           //метры до КП
//добиваем недостающие
    BYTE    nonuse[11];
    UINT	Km;                 //длина дистанции, метров
	UINT	Kor;                //№ стартового коридора
	UINT	Kp;                 //количество КП
	UINT	Nabor;              //набор высоты
	UINT	Time;               //контрольное время
	UINT	Nevent;             //количество прохождений через финиш
	UINT	NachDist;           //№ нач.дистанции
    UINT	N_pers_Base;        //Кол-во людей в дистанции (в базе)
    UINT	N_pers_Fin;         //Кол-во людей в дистанции (в финише)
    UINT	N_pers_Sel;         //Кол-во людей в дистанции (отмеченных)
	int		Sel;                //флаг отметки
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
            Print_Speed,        //в сплитах - скорость
            Split_Place,        //в протоколе результатов в сплитах - место на этапе
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
            Print_NachDist;     //Печатать нач.диста.
    int     A,                  //               B*Tуч
            B,                  // очки*10= A - --------
            C,                  //              C*Tпобед
            reserv8;
    int     Kogo_Res,
            Only_Best,
            Snd_On,
            Sel_Koll,
            Sel_Grup,
            Sel_Etap,
            Sel_Unsel,
            Pos,                //позиция при сохранении
            Kuda,               //0-печатать на принтер, 1-HTML
            View_Offset;        //смещение при сохранении
    int     Sor_Time;           //Начало соревнований - для SportIdent
    char    Chip_or_Nomer,      //Что определяет - ЧИП или Номер в ЧИПе
            Fin,                //Финиш:0-из протокола, 1-из финишной отметки, 2-посл.
            Start,              //Старт:0-из базы,      1-из стартов. отметки, 2-перв.
            Otm,                //проверять ли отметку и как
            Print,              //печатать информашку
            Print2,             //печатать снятому 2-ю информашку
            Offset,             //Смещение при печати, см
            AutoSave,           //==1, если включен режим автосохранения
            View,               //Режим при сохранении
            Res_Wyp,            //1-печатать выполнение разрядов
            Spec,               //режим спецфильтра: 0-ненул№ 1-нефинишир
            Com,                //номер СОМ-порта
            Snd_Koll,           //озвучивать ли коллектив
            Snd_Grup,           //озвучивать ли группу
            ResAll,             //печатать все прохождения через финиш
            PrintChip,          //печатать содержимое ЧИПов
            Precision,          //точность: 0-1 сек, 1-0,1 сек, 2-0,01 сек
            NoStart,            //печатать не стартовавших
			PrintNomCp,			//печатать в протоколах со сплитами № КП
            Mno1,               //надо ли учитывать в зачёт многодн. 1 день
            Mno2,               //надо ли учитывать в зачёт многодн. 2 день
            Mno3,               //надо ли учитывать в зачёт многодн. 3 день
            Mno4,               //надо ли учитывать в зачёт многодн. 4 день
            Mno5,               //надо ли учитывать в зачёт многодн. 5 день
            ReadMno,            //какой день многодневки читаем
            Krugi,              //печатать результаты с учётом количества кругов
            Ochki,              //0-нет,1-есть
            Est1000,            //в финише дополнять до 4-х значных
            ChipWarning,        //Выдавать диагностику при SI
			Kogo_wyp,//
			Kogo,//
            Video_On,
            Video_Porog,
            NewPage,
            PrintVar,           //печатать вариант рассеивания в эстафетах
            Mno_start;          //надо ли из многодневки генерить гандикап
    int     Time_Koll,          //длительность коллектива, мс
            Time_Grup,          //длительность группы, мс
            Time_Pers;          //длительность участника, мс
};
// добавить текст расписки и флаг: надо ли печатать расписку
class CInfo2_old:public CObject     //в последствии объединить с CInfo
{
public:
	char    Name[9][12];        //Причины снятия
	char    Text[9][12];        //Пункты правил
};
///--------------конец объявления старых данных-------------

