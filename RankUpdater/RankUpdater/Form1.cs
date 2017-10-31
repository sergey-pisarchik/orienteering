using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.IO;

using Excel = Microsoft.Office.Interop.Excel;
using Range = Microsoft.Office.Interop.Excel.Range;
//...



namespace WindowsApplication2
{
    
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
            dtpDate.Value = System.DateTime.Today;
            m_ParseSettings = new List<CParseSettings>();
            ReadParseSettings();
            comboBoxParseSettings.Items.Clear();
            for (int i =0; i<m_ParseSettings.Count; ++i)
            {
                comboBoxParseSettings.Items.Add(m_ParseSettings[i].m_Name);
            }
            comboBoxParseSettings.SelectedIndex = 0;
        }

        class CParseSettings
        {
            public String m_Name;
            public String m_BeginString;
            public int m_BeginSkeep;
            public String m_EndString;
            public int m_NameStart;
            public int m_NameLength;
            public int m_KvalStart;
            public int m_KvalLength;
        }
        List<CParseSettings> m_ParseSettings;

        public void ReadParseSettings()
        {
            m_ParseSettings.Clear();
            StreamReader fStream = new StreamReader((System.IO.Stream)File.OpenRead("Settings.ini"), System.Text.Encoding.GetEncoding(1251));
            String s = null;

            while ((s = fStream.ReadLine()) != null)
            {
                if (s == "---------------------BeginOfSheme---------------------")
                {
                    string a;
                    CParseSettings set = new CParseSettings();
                    set.m_Name = fStream.ReadLine();
                    set.m_BeginString = fStream.ReadLine();
                    a = fStream.ReadLine();
                    set.m_BeginSkeep = int.Parse(a);
                    a = fStream.ReadLine();
                    set.m_NameStart = int.Parse(a);
                    a = fStream.ReadLine();
                    set.m_NameLength = int.Parse(a);
                    a = fStream.ReadLine();
                    set.m_KvalStart = int.Parse(a);
                    a = fStream.ReadLine();
                    set.m_KvalLength = int.Parse(a);
                    set.m_EndString = fStream.ReadLine();
                    m_ParseSettings.Add(set);
                }
                
            }
        }

        

        class SMan
        {
            public void Read(String s, CParseSettings set)
            {
                //m_Name = s.Substring(5, 26).TrimEnd(' ').TrimStart(' ');
                //m_Kval = s.Substring(83, 4).TrimEnd(' ').TrimStart(' ');
                if (s.Length >= set.m_NameStart + set.m_NameLength)
                {
                    m_Name = s.Substring(set.m_NameStart, set.m_NameLength).TrimEnd(' ').TrimStart(' ');
                    m_Name = m_Name.Replace('Ё', 'Е');
                    m_Name = m_Name.Replace('ё', 'е');
                    while (m_Name.Contains("  "))
                        m_Name = m_Name.Replace("  ", " ");
                }
                else
                    m_Name = "";

                if (s.Length >= set.m_KvalStart)
                {
                    m_Kval = s.Substring(set.m_KvalStart, Math.Min(set.m_KvalLength, s.Length - set.m_KvalStart));
                    m_Kval = m_Kval.Replace('<', ' ');
                    m_Kval = m_Kval.Replace('>', ' ');
                    m_Kval = m_Kval.Replace('\\', ' ');
                    m_Kval = m_Kval.Replace('/', ' ');
                    m_Kval = m_Kval.Replace('b', ' ');
                    m_Kval = m_Kval.TrimEnd(' ').TrimStart(' ');
                }
                else
                {
                    m_Kval = "";
                }
                m_Kval = m_Kval.ToUpper();
            }

            public String m_Name;
            public String m_Kval;
        }

        private void ReadFile(List<SMan> people, String sHtmlFileName, CParseSettings set)
        {
            people.Clear();
            StreamReader fStream = new StreamReader((System.IO.Stream)File.OpenRead(sHtmlFileName), System.Text.Encoding.GetEncoding(1251));

            String s = null;
            
            while ((s = fStream.ReadLine()) != null)
            {
                if (s.Contains(set.m_BeginString))
                {
                    try
                    {
                        for (int i = 0; i < set.m_BeginSkeep; ++i)
                            s = fStream.ReadLine();

                        String sCurKval = "";
                        while ((s = fStream.ReadLine()) != null)
                        {
                            if (set.m_EndString.Length == 0)
                            {
                                if (s.Length == 0)
                                    break;
                            }
                            else
                            {
                                if (s.Contains(set.m_EndString))
                                    break;
                            }

                            SMan man = new SMan();
                            man.Read(s, set);
                            if (man.m_Kval.Length > 0)
                                sCurKval = man.m_Kval;
                            if (man.m_Name.Length > 0)
                            {
                                man.m_Kval = sCurKval;
                                people.Add(man);
                            }
                        }

                    }
                    catch (System.Exception ex)
                    {
                    	
                    }
                }
            }
            fStream.Close();
        }

        private void PrepareWorkSheet(Excel.Worksheet worksheet)
        {
            int i = 3;

            while (!(String.IsNullOrEmpty((worksheet.Cells[i, 1] as Range).Text.ToString())))
            {
                worksheet.Cells[i, 10] = "";
                worksheet.Cells[i, 15] = "";
                (worksheet.Cells[i, 10] as Range).Interior.Color = 0xffffff;
                (worksheet.Cells[i, 15] as Range).Interior.Color = 0xffffff;
                (worksheet.Cells[i, 1] as Range).Interior.Color = 0xffffff;
                ++i;
            }
        }

        private void HTMLSelect_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofDialog = new OpenFileDialog();
            ofDialog.Filter = "HTML files (*.htm;*.html)|*.htm;*.html";
            ofDialog.RestoreDirectory = true;
            if (ofDialog.ShowDialog() == DialogResult.OK)
                tbHTMLFileName.Text = ofDialog.FileName;
        }

        private void XLSSelect_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofDialog = new OpenFileDialog();
            ofDialog.Filter = "MS Excel files (*.xls)|*.xls";
            ofDialog.RestoreDirectory = true;
            if (ofDialog.ShowDialog() == DialogResult.OK)
                tbXLSFileName.Text = ofDialog.FileName;
        }

        private void Calculate_Click(object sender, EventArgs e)
        {
            if (String.IsNullOrEmpty(tbHTMLFileName.Text))
            {
                MessageBox.Show("Не выбран HTML файл.");
                return;
            }
            if (String.IsNullOrEmpty(tbXLSFileName.Text))
            {
                MessageBox.Show("Не выбран XLS файл.");
                return;
            }
            List<SMan> people = new List<SMan>();
            ReadFile(people, tbHTMLFileName.Text, m_ParseSettings[comboBoxParseSettings.SelectedIndex]);

            Excel.ApplicationClass excelApp = new Excel.ApplicationClass();
            Excel.Workbook workbook = excelApp.Workbooks.Open(tbXLSFileName.Text, false, false, 5, "", "", true, Excel.XlPlatform.xlWindows, "\t", false, false, 0, true, false, false);
            Excel.Worksheet worksheet = workbook.Sheets[1] as Excel.Worksheet;

            PrepareWorkSheet(worksheet); // скопируем текущие занчения "последнее"

            
            progressBar.Minimum = 0;
            progressBar.Maximum = people.Count;
            progressBar.Value = 0;
            progressBar.Visible = true;

            for (int i = 0; i < people.Count; ++i)
            {
                progressBar.Value++;
                if (!(people[i].m_Kval == "МС" || people[i].m_Kval == "КМС"))
                    continue;

                String sManName = people[i].m_Name;
                bool bFound = false;
                int j =3;
                for (; ; ++j)
                {
                    String sXlsMan = (worksheet.Cells[j, 1] as Range).Text.ToString();
                    if (sXlsMan.ToLower() == sManName.ToLower())
                    {
                        bFound = true;
                        break;
                    }
                    if (String.IsNullOrEmpty(sXlsMan))
                    {
                        break;
                    }
                }

                if (!bFound)
                {
                    worksheet.Cells[j, 1] = sManName;
                    (worksheet.Cells[j, 1] as Range).Interior.Color = 255;
                }

                int k;
                if (people[i].m_Kval == "КМС")
                    k = 14;
                else 
                    k = 9;
                

                String sLastTime = (worksheet.Cells[j, k] as Range).Text.ToString();

                bool bUpdate = true;
                try
                {
                    DateTime LastTime = DateTime.Parse(sLastTime);
                    if (LastTime >= dtpDate.Value)
                        bUpdate = false;
                }
                catch (System.Exception ex)
                {
                }
                if (bUpdate)
                {
                    worksheet.Cells[j, k + 1] = worksheet.Cells[j, k]; // Сохраним предыдущее значение.
                    (worksheet.Cells[j, k + 1] as Range).Interior.Color = 255;
                    worksheet.Cells[j, k] = dtpDate.Text;
                }
                
            }
            workbook.Close(true, tbXLSFileName.Text, false);
            excelApp.Quit();
            progressBar.Visible = false;
            MessageBox.Show("Обновление закончено.");
        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            // тест чтения файла
            if (String.IsNullOrEmpty(tbHTMLFileName.Text))
            {
                MessageBox.Show("Не выбран HTML файл.");
                return;
            }
            List<SMan> people = new List<SMan>();
            ReadFile(people, tbHTMLFileName.Text, m_ParseSettings[comboBoxParseSettings.SelectedIndex]);

            richTextBox1.Clear();
            for (int i=0; i < people.Count; ++i)
            {
                richTextBox1.AppendText(i.ToString() + ". " + people[i].m_Name + " " + people[i].m_Kval + "\n");
            }
        }

    }
}