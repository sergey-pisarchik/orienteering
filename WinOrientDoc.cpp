#include "data.h"

/////////////////////////////////////////////////////////////////////////////
void CWinOrientDoc::Serialize(CArchive& ar)
{
 int i, j, k, flag=0, ii;
 CSi64  Si64;
 if (ar.IsStoring())
	{   // Запись
        j = VERSION;    // номер версии
        ar << j;   
        //Участники
		//Сначала узнаем, сколько участников
		j =0; for( i = 0; i < MAX_DATA; i++) if( Data[i] != NULL ) j++;
		//Теперь, собственно запись
		ar << j; for(i=0; i<MAX_DATA; i++) if( Data[i] != NULL ) ar.Write(Data[i], sizeof(CData));

        //Коллективы
		//Сначала узнаем, сколько 
		j =0; for( i = 0; i < MAX_KOLL; i++) if( Koll[i] != NULL ) j++;
		//Теперь, собственно запись
		ar << j; for(i=0; i<MAX_KOLL; i++) if( Koll[i] != NULL ) ar.Write(Koll[i], sizeof(CKoll));

        //Группы
		//Сначала узнаем, сколько 
		j =0; for( i = 0; i < MAX_GRUP; i++) if( Grup[i] != NULL ) j++;
		//Теперь, собственно запись
		ar << j; for(i=0; i<MAX_GRUP; i++) if( Grup[i] != NULL ) ar.Write(Grup[i], sizeof(CGrup));

        //Дистанции
		//Сначала узнаем, сколько 
		j =0; for( i = 0; i < MAX_DIST; i++) if( Dist[i] != NULL ) j++;
		//Теперь, собственно запись
		ar << j; for(i=0; i<MAX_DIST; i++) if( Dist[i] != NULL ) { ar.Write(Dist[i], sizeof(CDist)); }


        //Инфо о соревнованиях
        Info.View        = View;
        Info.Pos         = POS;
        Info.View_Offset = OFFSET;
        ar.Write(&Info, sizeof(CInfo));

        //Финиш
		//Сначала узнаем, сколько 
		j =0; for( i = 0; i < MAX_FIN; i++) if( Fin[i] != NULL ) j++;
		//Теперь, собственно запись
		ar << j; for(i=0; i< MAX_FIN; i++) if( Fin[i] != NULL ) ar.Write(Fin[i], sizeof(CFin));

        //SI-64 отметки
		//В старом формате НЕ СОХРАНЯЮ, количество = 0
		j =0; ar << j;

        //инфо о КП (Adventure)
        j = 257;
        ar << j; for(i=0; i< 257; i++) if( Cp[i] != NULL ) ar.Write(Cp[i], sizeof(CCp));

        //SI
		//Сначала узнаем, сколько 
		j =0; for( i = 0; i < MAX_DATA; i++) if( Si[i] != NULL ) j++;
		//Теперь, собственно запись
		ar << j; for(i=0; i< MAX_DATA; i++) if( Si[i] != NULL ) ar.Write(Si[i], sizeof(CSi));

        j = 0;
        ar << j;
        ar << j;
        ar << j;
        ar << j;
	}
	else
	{   // Чтение
     ar >> j;
	 OnNewDocument(); //сделаем здесь, что бы при открытии другой версии не оставалось имя файла
     if( j == VERSION )
       {
        //Участники
		ar >> j; 
        CString ddd;
        for( i = 0; i < j; i++ ) { k = CreatPers(); ar.Read( Data[i], sizeof(CData));}
        //Коллективы
		ar >> j; 
        for( i = 0; i < j; i++ ) { k = CreatKoll(); ar.Read( Koll[i], sizeof(CKoll)); }
        //Группы
		ar >> j; for( i = 0; i < j; i++ ) { k = CreatGrup(); ar.Read( Grup[i], sizeof(CGrup)); }
        //Дистанции
		ar >> j; for( i = 0; i < j; i++ ) { k = CreatDist(); ar.Read( Dist[i], sizeof(CDist)); }
        //Инфо о соревнованиях
        ar.Read(&Info, sizeof(CInfo));
        //Финиш
		ar >> j; for( i = 0; i < j; i++ ) { k = CreatFin();  ar.Read( Fin[i], sizeof(CFin)); }
        //Si
        //если не ноль, значит есть данные в старом формате. Надо перепаковать в новый
		ar >> j;
        if( j )
            {
             flag = 1;
             for( i = 0; i < j; i++ )
              {
               k = CreatSi(); 
               ar.Read( &Si64, sizeof(CSi64));
               //теперь из старого формата перепакуемм в новый
               Si[i]->Nchip    = Si64.Nchip;
               Si[i]->Nstart   = Si64.Nstart;
               Si[i]->Ncp      = Si64.Ncp;
               Si[i]->Start    = Si64.Start;
               Si[i]->Finish   = Si64.Finish;
               Si[i]->Check    = Si64.Check;
               Si[i]->Clear    = Si64.Clear;
               for( ii = 0;  ii <  64; ii++) Si[i]->CP[ii] = Si64.CP[ii];
               for( ii = 64; ii < 200; ii++) { Si[i]->CP[ii].Num = 0; Si[i]->CP[ii].Tim = 0; }
              }
            }

        //ценность КП
		ar >> j; for( i = 0; i < j; i++ ) ar.Read( Cp[i], sizeof(CCp));
        //новое содержимое ЧИПов
		ar >> j; for( i = 0; i < j; i++ ) { k = CreatSi(); ar.Read( Si[i], sizeof(CSi)); }

        ReadNum();
        View   = Info.View;
        POS    = Info.Pos;
        OFFSET = Info.View_Offset;
        Info.LCD_ON = 0;        //выключим отображение на LCD

        if( flag )
            {
             AfxMessageBox("Внимание! Произведено преобразование базы в новый формат.\nЕсли необходимо оставить базу данных в старом формате - выйдите без сохранения и откройте базу данных более ранней версией программы");
            }
       }
       else
       {
        if( j == 11 )   //старая версия
           {
            CData_old Data_old;
            CKoll_old Koll_old;
            CGrup_old Grup_old;
            CDist_old Dist_old;
            CFin_old  Fin_old;
            CInfo_old Info_old;
            CInfo2_old Info2;
            CSi_old   Si_old;

            //участники
    		ar >> j;
            for( i = 0; i < j; i++ )
                {
                 k = CreatPers();
                 ar.Read( &Data_old, sizeof(CData_old));

                 strcpy( Data[i]->Name, Data_old.Name);
                 strcpy( Data[i]->Comment, "");
                 Data[i]->GR        = Data_old.GR;
                 Data[i]->Kwal      = Data_old.Kwal;
                 Data[i]->Gruppa    = Data_old.Gruppa;
                 Data[i]->Koll      = Data_old.Koll;
                 Data[i]->Etap      = Data_old.Etap;
                 Data[i]->N         = Data_old.N;
                 Data[i]->Tstart    = Data_old.Tstart;
                 Data[i]->Tfin      = Data_old.Tfin;
                 Data[i]->Res       = Data_old.Res;
//                 Data[i]->Shtr1     = 0;    //не использовалась раньше
//                 Data[i]->Shtr2     = 0;    //не использовалась раньше
                 Data[i]->Sum_Shtr  = Data_old.Sum_Shtr;
                 Data[i]->Mesto     = Data_old.Mesto;
                 Data[i]->Ochki     = Data_old.Ochki;
                 Data[i]->SI        = Data_old.SI;
                 Data[i]->ID        = Data_old.ID;
                 Data[i]->Sel       = Data_old.Sel;
                 Data[i]->WK        = Data_old.WK;
                 Data[i]->Lichno    = Data_old.Lichno;
                 Data[i]->Pol       = Data_old.Pol;
                 Data[i]->CombFlag  = Data_old.CombFlag;
                 Data[i]->Vereb     = Data_old.Vereb;
                 Data[i]->FinFlag   = Data_old.FinFlag;
                 Data[i]->Mno[0]    = Data_old.Mno1;
                 Data[i]->Mno[1]    = Data_old.Mno2;
                 Data[i]->Mno[2]    = Data_old.Mno3;
                 Data[i]->Mno[3]    = Data_old.Mno4;
                 Data[i]->Mno[4]    = Data_old.Mno5;
                 Data[i]->Sum_Mno   = Data_old.Sum_Mno;
                }
            //Коллективы
    		ar >> j;
            for( i = 0; i < j; i++ )
                {
                 k = CreatKoll();
                 ar.Read( &Koll_old, sizeof(CKoll_old));

                 Koll[i]->ID        = Koll_old.ID;
                 Koll[i]->N_pers_Base=Koll_old.N_pers_Base;
                 Koll[i]->N_pers_Fin= Koll_old.N_pers_Fin;
                 Koll[i]->N_pers_Sel= Koll_old.N_pers_Sel;
                 strcpy( Koll[i]->Name, Koll_old.Name );
                 strcpy( Koll[i]->Predstav, Koll_old.Predstav );
                 Koll[i]->Sel       = Koll_old.Sel;
                }
            //Группы
    		ar >> j;
            for( i = 0; i < j; i++ )
                {
                 k = CreatGrup();
                 ar.Read( &Grup_old, sizeof(CGrup_old));

                 Grup[i]->ID                = Grup_old.ID;
                 Grup[i]->N_pers_Base       = Grup_old.N_pers_Base;
                 Grup[i]->N_pers_Fin        = Grup_old.N_pers_Fin;
                 Grup[i]->N_pers_Sel        = Grup_old.N_pers_Sel;
                 strcpy( Grup[i]->Name, Grup_old.Name);
                 Grup[i]->NDist             = Grup_old.NDist;
                 Grup[i]->Sel               = (Grup_old.Sel) | 0x02;
                 Grup[i]->Vz_Arenda_Lgota   = Grup_old.Vz_Arenda_Lgota;
                 Grup[i]->Vz_Arenda_Norm    = Grup_old.Vz_Arenda_Norm;
                 Grup[i]->Vz_Chip_Lgota     = Grup_old.Vz_Chip_Lgota;
                 Grup[i]->Vz_Chip_Norm      = Grup_old.Vz_Chip_Norm;
                }
            //Дистанции
    		ar >> j;
            for( i = 0; i < j; i++ )
                {
                 k = CreatDist();
                 ar.Read( &Dist_old, sizeof(CDist_old));

                 Dist[i]->ID                = Dist_old.ID;
                 Dist[i]->Km                = Dist_old.Km;
                 Dist[i]->Kor               = Dist_old.Kor;
                 Dist[i]->Kp                = Dist_old.Kp;

                 int ll;
                 for( ll =0; ll < 100; ll++ ) Dist[i]->M_KP[ll] = Dist_old.M_KP[ll];
                 for( ll =0; ll < 100; ll++ ) Dist[i]->N_KP[ll] = Dist_old.N_KP[ll];

                 Dist[i]->N_pers_Base       = Dist_old.N_pers_Base;
                 Dist[i]->N_pers_Fin        = Dist_old.N_pers_Fin;
                 Dist[i]->N_pers_Sel        = Dist_old.N_pers_Sel;
                 Dist[i]->Nabor             = Dist_old.Nabor;
//                 Dist[i]->NachDist          = Dist_old.NachDist;
                 strcpy( Dist[i]->Name, Dist_old.Name);
//                 Dist[i]->Nevent            = Dist_old.Nevent;
                 Dist[i]->Sel               = Dist_old.Sel;
                 Dist[i]->Time              = Dist_old.Time;
                }
            //Инфо о соревнованиях
            ar.Read(&Info_old, sizeof(CInfo_old));

            strcpy( Info.Date,              Info_old.Date);
            strcpy( Info.Mesto,             Info_old.Mesto);
            int ii;
            for( ii = 0; ii< 4; ii++)
//                strcpy( Info.NachDist[ii],  Info_old.NachDist[ii]);
            strcpy( Info.Sudia,             Info_old.Sudia);
            strcpy( Info.Secret,            Info_old.Secret);

            Info.Mno[0]                     = Info_old.Mno1;
            Info.Mno[1]                     = Info_old.Mno2;
            Info.Mno[2]                     = Info_old.Mno3;
            Info.Mno[3]                     = Info_old.Mno4;
            Info.Mno[4]                     = Info_old.Mno5;

            strcpy( Info.Name[0],           Info_old.Name1 );
            strcpy( Info.Name[1],           Info_old.Name2 );
            strcpy( Info.Name[2],           Info_old.Name3 );

            for( ii = 3; ii< 10; ii++)
                strcpy( Info.Name[ii],      "");

            strcpy( Info.Raspiska,          "");

            Info.A                          = Info_old.A;
            Info.AutoSave                   = Info_old.AutoSave;
            Info.B                          = Info_old.B;
            Info.C                          = Info_old.C;
            Info.CardPrint                  = Info_old.CardPrint;
            Info.ChipWarning                = Info_old.ChipWarning;
            Info.Com                        = Info_old.Com;
            Info.Dst                        = Info_old.Dst;
            Info.Est1000                    = Info_old.Est1000;
            Info.Etap_Vereb                 = Info_old.Etap_Vereb;
            Info.Filtr_Dist                 = Info_old.Filtr_Dist;
            Info.Filtr_Etap                 = Info_old.Filtr_Etap;
            Info.Filtr_Grup                 = Info_old.Filtr_Grup;
            Info.Filtr_Koll                 = Info_old.Filtr_Koll;
            Info.Filtr_Sel                  = Info_old.Filtr_Sel;
            Info.Fin                        = Info_old.Fin;
            Info.Flag_Rasp                  = 0;
            Info.Kogo                       = Info_old.Kogo;
            Info.Kogo_Res                   = Info_old.Kogo_Res;
            Info.Kogo_Start                 = Info_old.Kogo_Start;
            Info.Kogo_Vereb                 = Info_old.Kogo_Vereb;
            Info.Kogo_wyp                   = Info_old.Kogo_wyp;
            Info.Koll_Vereb                 = Info_old.Koll_Vereb;
            Info.Krugi                      = Info_old.Krugi;
            Info.Kuda                       = Info_old.Kuda;
            Info.Mno_start                  = Info_old.Mno_start;
            Info.N_Cell                     = Info_old.N_Cell;
            Info.N_Cell_All                 = Info_old.N_Cell_All;
            Info.NewPage                    = Info_old.NewPage;
            Info.NoStart                    = Info_old.NoStart;
            Info.Ochki                      = Info_old.Ochki;
            Info.Offset                     = Info_old.Offset;
            Info.Only_Best                  = Info_old.Only_Best;
            Info.OnlySel                    = Info_old.OnlySel;
            Info.Otm                        = Info_old.Otm;
            Info.Pos                        = Info_old.Pos;
            Info.Precision                  = Info_old.Precision;
            Info.Print                      = Info_old.Print;
            Info.Print2                     = Info_old.Print2;
            Info.Print_NachDist             = Info_old.Print_NachDist;
            Info.Print_Speed                = Info_old.Print_Speed;
            Info.Print_Vznos                = Info_old.Print_Vznos;
            Info.PrintChip                  = Info_old.PrintChip;
            Info.PrintNomCp                 = Info_old.PrintNomCp;
            Info.PrintSI                    = Info_old.PrintSI;
            Info.PrintVar                   = Info_old.PrintVar;
            Info.ReadMno                    = Info_old.ReadMno;
            Info.Res_Wyp                    = Info_old.Res_Wyp;
            Info.ResAll                     = Info_old.ResAll;
            Info.Sel_Etap                   = Info_old.Sel_Etap;
            Info.Sel_Grup                   = Info_old.Sel_Grup;
            Info.Sel_Koll                   = Info_old.Sel_Koll;
            Info.Sel_Unsel                  = Info_old.Sel_Unsel;
            Info.SetNum_Start               = Info_old.SetNum_Start;
            Info.SetNum_Step                = Info_old.SetNum_Step;
            Info.SetTime_Start              = Info_old.SetTime_Start;
            Info.SetNum_Step                = Info_old.SetTime_Step;
            Info.SI_Manual                  = Info_old.SI_Manual;
            Info.Snd_Grup                   = Info_old.Snd_Grup;
            Info.Snd_Koll                   = Info_old.Snd_Koll;
            Info.Sor_Time                   = Info_old.Sor_Time;
            Info.Split_Place                = Info_old.Split_Place;
            Info.Start                      = Info_old.Start;
//            Info.Time_Grup                  = Info_old.Time_Grup;
//            Info.Time_Koll                  = Info_old.Time_Koll;
//            Info.Time_Pers                  = Info_old.Time_Pers;
            Info.View                       = Info_old.View;
            Info.View_Offset                = Info_old.View_Offset;
            Info.Wid                        = Info_old.Wid;
            Info.Wid_Est                    = Info_old.Wid_Est;
            Info.Wid_sort                   = Info_old.Wid_sort;
            //Финиш
    		ar >> j;
            for( i = 0; i < j; i++ )
                {
                 k = CreatFin();
                 ar.Read( &Fin_old, sizeof(CFin_old));
                 Fin[i]->Nom                = Fin_old.Nom;
                 Fin[i]->Sound              = Fin_old.Sound;
                 Fin[i]->Tfin               = Fin_old.Tfin & 0x00FFFFFF;
                }
            //Si
    		ar >> j;
            for( i = 0; i < j; i++ )
                {
                 k = CreatSi();
                 ar.Read( &Si_old, sizeof(CSi_old));
                 Si[i]->Check.Num   = 0;
                 Si[i]->Check.Tim   = 0;
                 Si[i]->Clear.Num   = 0;
                 Si[i]->Clear.Tim   = 0;
                 int ii;
                 for( ii = 0; ii < 36; ii++)
                    {
                     Si[i]->CP[ii].Num = Si_old.Cp_Num[ii];
                     Si[i]->CP[ii].Tim = Si_old.Cp_Tim[ii];
                    }
                 for( ; ii< MAX_CP; ii++)
                    {
                     Si[i]->CP[ii].Num = 0;
                     Si[i]->CP[ii].Tim = 0;
                    }

                 Si[i]->Finish.Num  = 0;
                 Si[i]->Finish.Tim  = Si_old.Tfin;
                 Si[i]->Start.Num   = 0;
                 Si[i]->Start.Tim   = Si_old.Tstart;
                 Si[i]->Nchip       = Si_old.Nchip;
                 Si[i]->Ncp         = Si_old.Ncp;
                 Si[i]->Nstart      = Si_old.Nstart;
                }
            //Инфо о соревнованиях-2
            char    *buf_tmp;
            buf_tmp = (char *)calloc(sizeof(CInfo2_old), 1);
            int nnn = ar.Read( buf_tmp, sizeof(CInfo2_old));
            if( nnn )
                {
                 memcpy( &Info2, buf_tmp, sizeof(CInfo2_old) );
                 int ii;
                 for( ii = 0; ii < 9; ii++)
                    {
                     strcpy( Info.Prich[ii], Info2.Name[ii]);
                     strcpy( Info.Text[ii],  Info2.Text[ii]);
                    }
                }
            free( buf_tmp );

            ReadNum();
            View   = Info.View;
            POS    = Info.Pos;
            OFFSET = Info.View_Offset;

            Info.LCD_ON = 0;        //выключим отображение на LCD
            AfxMessageBox("Произведено преобразование в формат WinOrient2 !\nВНИМАНИЕ: после преобразования Вы не сможете открывать этот файл старой программой!\nПроследите, что бы на всех компьютерах была установлена новая версия!");
           }
           else AfxMessageBox("Неизвестный формат или версия!");

    	}
    }
}
/////////////////////////////////////////////////////////////////////////////
