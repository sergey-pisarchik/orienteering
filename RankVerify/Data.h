#ifndef RV_DATA_H
#define RV_DATA_H

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

#define		MAX_DATA    30
#define		MAX_GRUP    10
#define		MAX_DIST    10
#define		MAX_KOLL    10
#define		MAX_FIN     20
#define		MAX_NUM     30

#define		MAX_CP      20

/////////////////////////////////////////////////////////////////////////////
// Данные про КП для Adventure
typedef struct
{
    unsigned int    Grup;               //группа
	char    Name[30];           //Наименование
    int     x, y;               //координаты, метров
    unsigned int    tabl;               //0-начисление очков, как обычно, 1 и 2 - из таблиц tabl1.txt и tabl2.txt 
    unsigned int    mode;               //режим: 0-смена группы 1- обычный
    unsigned int    ochki;              //очки
    unsigned int    Tideal;             //время идеального
    unsigned int    ochki_ideal;        //очки идеального
    unsigned int    persent;            //
    unsigned int    min;                //
    unsigned int    mode_korz;          //
    unsigned int    start;              //
    unsigned int    stop;               //
    unsigned int    stop_sec;           //
} CCp;
/////////////////////////////////////////////////////////////////////////////
//class CPunch:public
typedef struct
{
    char    Num;
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
	short int    Nom;
	int     Tfin;           //три байта - время, старший байт - буду номер КП хранить
    char    Sound;
} CFin;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char	Name[26];
	char	Comment[21];
	short int	GR;
	char    Kwal;
	short int	Gruppa;
    short int    Koll;

    char    Reserv9;
    short int    N;

    int     Tstart;
    int     Tfin;
    int     Res;

    int     Reserv10;           //Shtr1;              //Штраф-старшее слово
    int     Reserv11;           //Shtr2;              //Штраф-младшее слово
    short int    Sum_Shtr;           //Штраф-итог

    short int    Mesto;
    int     Ochki;
	int     SI;					//SI-card
	int     ID;

    char    Sel;				//отметка обычная
    char    WK,                 //бит
            Lichno,             //бит
            Pol,
            CombFlag;           //еще флаги: свой ЧИП, льгота (член федерации)
                                //0x01 - свой ЧИП
                                //0x02 - льгота
	int     Vereb;
	char	FinFlag;            //байт
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
    short int    N_pers_Base;        //Кол-во людей в коллективе (в базе)
    short int    N_pers_Fin;         //Кол-во людей в коллективе (в финише)
    short int    N_pers_Sel;         //Кол-во людей в коллективе (отмеченных)
	char    Sel;
} CKoll;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int     ID;                 //первый бит - признак: разрешено вып. разрядов
	char    Name[8+1];
    char    ms;
    char    kms;
	short int    NDist;

    short int    N_pers_Base;        //Кол-во людей в коллективе (в базе)
    short int    N_pers_Fin;         //Кол-во людей в коллективе (в финише)
    short int    N_pers_Sel;         //Кол-во людей в коллективе (отмеченных)
	char	Sel;                //маска 0x01 - отметка
                                //маска 0x02 - можно присваивать разряды

    short int    Vz_Arenda_Norm;     //стартовый взнос: норм,  арендованный ЧИП
    short int    Vz_Arenda_Lgota;    //стартовый взнос: льгот, арендованный ЧИП
    short int    Vz_Chip_Norm;       //стартовый взнос: норм,  свой ЧИП
    short int    Vz_Chip_Lgota;      //стартовый взнос: льгот, свой ЧИП
} CGrup;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	int     ID;                 //идентификатор
	char    Name[12];           //Наименование дистанции
    char    N_KP[100];          //дешифрованные номера КП
    short int    M_KP[100];          //метры до КП
    unsigned int	Km;                 //длина дистанции, метров
	unsigned int	Kor;                //№ стартового коридора
	unsigned int	Kp;                 //количество КП
	unsigned int	Nabor;              //набор высоты
	unsigned int	Time;               //контрольное время
	unsigned int	reserv2;            //
	unsigned int	reserv1;            //
    short int	N_pers_Base;        //Кол-во людей в дистанции (в базе)
    short int	N_pers_Fin;         //Кол-во людей в дистанции (в финише)
    short int	N_pers_Sel;         //Кол-во людей в дистанции (отмеченных)
	char	Sel;                //флаг отметки
} CDist;
/////////////////////////////////////////////////////////////////////////////
typedef struct
{
	char    Name[10][80];       //шапка
	char    Mesto[25];          //место проведения
	char    Secret[25];         //секретарь
	char    Sudia[25];          //главный судья
	char    Date[21];           //дата проведения
    char    Wid;                //вид соревнований:
	char	Wid_Est;            //
    char    ZamPoSTO[25];       //Зам по СТО
    char    Inspector[25];      //Инспектор
    char    reserv_txt[50];     //под имена файлов звука
	short int	Filtr_Koll,
			Filtr_Dist,
			Filtr_Grup,
			Filtr_Sel,
            Filtr_Etap,
            Sel_Koll,
            Sel_Grup,
            Sel_Etap;
    short int    A,                  //               B*Tуч
            B;                  // очки*10= A - --------
                                //              C*Tпобед
    short int    SetNum_Start,
            SetNum_Step;
    int     SetTime_Start,
            SetTime_Step;
    char	Wid_sort,
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
    int     Sor_Time2,          //штрафуемое время.                     !!! потом сделать INT, а не short int
            Sor_Time3,          //время, снимаются                      !!! потом сделать INT, а не short int
                                //               B*Tуч
                                // очки*10= A - --------
            C;                  //              C*Tпобед
    char    Kogo_Res,
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
    char    Limit;              //флаг - печатать контр. время
    char    Fin,                //Финиш:0-из протокола, 1-из финишной отметки, 2-посл.
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
    short int    Comment_GrupDNF,    //сколько показывать претендентов
            Comment_GrupDNS;    //сколько показывать н.старт
    short int    Reserv5,
            Reserv6;           
    int     Offset_Time_AMB;
    int     Shtraf;             //цена штрафа за невзятие КП
    char    Mno[10];            //надо ли учитывать в зачёт многодн.
    char    wyp_est;            //в выписке - эстафетный вариант номера 123-4
    char    BSM7;               //это-новая станция
    char    lichno_ochki;       //Давать ли личникам очки
	char    Prich[9][12];       //Причины снятия
	char    Text[9][12];        //Пункты правил
    char    Raspiska[90];       //текст расписки
    char    Reserv1;
    char    Etapov;             //Присвоение номеров в эстафете - количество этапов
    char    EstWK;              //В результ эст - если разные команды, значит в/к
    char    Zachet;             //Указывать в командных количество зачётных участников
    char    SI_2card;           //в поле комментарий пишется номер 2го ЧИПа
    char    Comment_Right;
    char    Comment_RightNom;
    char    Comment_RightKoll;
    char    Comment_GrupNom;
    char    Comment_GrupKoll;
    char    Flag_Rasp;          //признак-печатать расписку
    char    Print_Kod;          //Печатать код дисциплины
    char    Print_Comment;      //Печатать коментарий про участника
    char    LCD_ON;             //Признак, что надо генерить файл для LCD
    char    LCD_START;          //Что надо генерить файл для LCD - стартовую или финишную
    char    TABLO;              //выводить ли на табло
    char    GetNum;             //для неизвестного - ввод номера
    char    LCD_Rotate;         //повернуть на 90 градусов
    char    LCD_Line;           //Выделять строки через одну
    char    LCD_Refresh;        //время рефреша
    char    LCD_Font;           //Размер шрифта
    char    LCD_Mode;           //Режим: 0-при  чтении чипа, 1-таймер, 2-однократно
    char    LCD_Flag;           //Вставлять картинку флага
    char    On_line_site[60];
    char    server_name[15];
    char    Sent_mode;
    char    Line2;              //=1 - если надо печатать 2ю строку в сплитах
    char    Remake_Check;
    char    Small;              //размер шрифта в сплитах - 70%
    char    Rogain;             //стиль ADV-протокола, 1 - рогейн, 0 - обычный
    char    LCD_Result;
    char    LCD_Title;
    char    Stat;				//в результатах выводить статистику по КП
    char    Comment;            //в протоколах результатов - печатать комментарий
    char    Delta;              //В протоколах результатов - отставание
    char    Sprint;             //BS7-S - 0 - Обычная,1 - спринт моя 2- сринт Ромка/Пашка
    char    DNS;                //в комментаторском =1 - показывать не стартовавших
    char    DNF;                //в комментаторском =1 - показывать не финишировавших
    char    Best6;              //Тпоб=Усреднённомы времени 6ти
    char    Labir;              //Режим либиринта: добавлять запись, создавать участника, раскидывать по группам
} CInfo;
/////////////////////////////////////////////////////////////////////////////
///--------------начало объявления старых данных-------------
class CSi_old
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
class CFin_old
{
public:
	int		Nom;
	int     Tfin;
    char    Sound;
};
/////////////////////////////////////////////////////////////////////////////
class CData_old
{
public:
	int		nnn;
	char	Name[26];
	int		GR;
	int     Kwal;               //байт
	int		Gruppa;
    char	mmm[700];
};
/////////////////////////////////////////////////////////////////////////////
class CKoll_old
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
class CGrup_old
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
class CDist_old
{
public:
	int     ID;                 //идентификатор
    int     Error;              //Код/флаг ошибки
	char    Name[12];           //Наименование дистанции
//был 251 байт, теперь 3*80=240
    char    N_KP[80];     //дешифрованные номера КП
    short int    M_KP[80];           //метры до КП
//добиваем недостающие
    char    nonuse[11];
    unsigned int	Km;                 //длина дистанции, метров
	unsigned int	Kor;                //№ стартового коридора
	unsigned int	Kp;                 //количество КП
	unsigned int	Nabor;              //набор высоты
	unsigned int	Time;               //контрольное время
	unsigned int	Nevent;             //количество прохождений через финиш
	unsigned int	NachDist;           //№ нач.дистанции
    unsigned int	N_pers_Base;        //Кол-во людей в дистанции (в базе)
    unsigned int	N_pers_Fin;         //Кол-во людей в дистанции (в финише)
    unsigned int	N_pers_Sel;         //Кол-во людей в дистанции (отмеченных)
	int		Sel;                //флаг отметки
};
/////////////////////////////////////////////////////////////////////////////
class CInfo_old
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
	bool	Wid_Est;
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
class CInfo2_old     //в последствии объединить с CInfo
{
public:
	char    Name[9][12];        //Причины снятия
	char    Text[9][12];        //Пункты правил
};
///--------------конец объявления старых данных-------------

#endif // RV_DATA_H