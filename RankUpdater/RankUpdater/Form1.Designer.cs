namespace WindowsApplication2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btSelectHTML = new System.Windows.Forms.Button();
            this.progressBar = new System.Windows.Forms.ProgressBar();
            this.label1 = new System.Windows.Forms.Label();
            this.tbHTMLFileName = new System.Windows.Forms.TextBox();
            this.tbXLSFileName = new System.Windows.Forms.TextBox();
            this.btSelectXLS = new System.Windows.Forms.Button();
            this.btCalculate = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.dtpDate = new System.Windows.Forms.DateTimePicker();
            this.comboBoxParseSettings = new System.Windows.Forms.ComboBox();
            this.label4 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.buttonTestRead = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btSelectHTML
            // 
            this.btSelectHTML.Location = new System.Drawing.Point(371, 33);
            this.btSelectHTML.Name = "btSelectHTML";
            this.btSelectHTML.Size = new System.Drawing.Size(24, 23);
            this.btSelectHTML.TabIndex = 0;
            this.btSelectHTML.Text = "...";
            this.btSelectHTML.UseVisualStyleBackColor = true;
            this.btSelectHTML.Click += new System.EventHandler(this.HTMLSelect_Click);
            // 
            // progressBar
            // 
            this.progressBar.Location = new System.Drawing.Point(3, 548);
            this.progressBar.Name = "progressBar";
            this.progressBar.Size = new System.Drawing.Size(392, 21);
            this.progressBar.Style = System.Windows.Forms.ProgressBarStyle.Continuous;
            this.progressBar.TabIndex = 1;
            this.progressBar.Visible = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 115);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(151, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "3. Введите дату выполнения";
            // 
            // tbHTMLFileName
            // 
            this.tbHTMLFileName.Enabled = false;
            this.tbHTMLFileName.Location = new System.Drawing.Point(12, 35);
            this.tbHTMLFileName.Name = "tbHTMLFileName";
            this.tbHTMLFileName.Size = new System.Drawing.Size(353, 20);
            this.tbHTMLFileName.TabIndex = 2;
            this.tbHTMLFileName.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // tbXLSFileName
            // 
            this.tbXLSFileName.Enabled = false;
            this.tbXLSFileName.Location = new System.Drawing.Point(12, 78);
            this.tbXLSFileName.Name = "tbXLSFileName";
            this.tbXLSFileName.Size = new System.Drawing.Size(353, 20);
            this.tbXLSFileName.TabIndex = 2;
            this.tbXLSFileName.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btSelectXLS
            // 
            this.btSelectXLS.Location = new System.Drawing.Point(371, 78);
            this.btSelectXLS.Name = "btSelectXLS";
            this.btSelectXLS.Size = new System.Drawing.Size(24, 23);
            this.btSelectXLS.TabIndex = 0;
            this.btSelectXLS.Text = "...";
            this.btSelectXLS.UseVisualStyleBackColor = true;
            this.btSelectXLS.Click += new System.EventHandler(this.XLSSelect_Click);
            // 
            // btCalculate
            // 
            this.btCalculate.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btCalculate.Location = new System.Drawing.Point(3, 510);
            this.btCalculate.Name = "btCalculate";
            this.btCalculate.Size = new System.Drawing.Size(392, 32);
            this.btCalculate.TabIndex = 0;
            this.btCalculate.Text = "5. Нажмите для окончательного рассчета";
            this.btCalculate.UseVisualStyleBackColor = true;
            this.btCalculate.Click += new System.EventHandler(this.Calculate_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 21);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(117, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "1 Выберите html файл";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 64);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(110, 13);
            this.label3.TabIndex = 3;
            this.label3.Text = "2 Выберите xls файл";
            // 
            // dtpDate
            // 
            this.dtpDate.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dtpDate.Location = new System.Drawing.Point(169, 115);
            this.dtpDate.MaxDate = new System.DateTime(2100, 12, 31, 0, 0, 0, 0);
            this.dtpDate.MinDate = new System.DateTime(2000, 1, 1, 0, 0, 0, 0);
            this.dtpDate.Name = "dtpDate";
            this.dtpDate.Size = new System.Drawing.Size(226, 20);
            this.dtpDate.TabIndex = 4;
            // 
            // comboBoxParseSettings
            // 
            this.comboBoxParseSettings.FormattingEnabled = true;
            this.comboBoxParseSettings.Location = new System.Drawing.Point(12, 162);
            this.comboBoxParseSettings.Name = "comboBoxParseSettings";
            this.comboBoxParseSettings.Size = new System.Drawing.Size(383, 21);
            this.comboBoxParseSettings.TabIndex = 5;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(12, 146);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(183, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "4. Выберите схему распознавания";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(12, 209);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(383, 262);
            this.richTextBox1.TabIndex = 6;
            this.richTextBox1.Text = "";
            // 
            // buttonTestRead
            // 
            this.buttonTestRead.Location = new System.Drawing.Point(260, 478);
            this.buttonTestRead.Name = "buttonTestRead";
            this.buttonTestRead.Size = new System.Drawing.Size(133, 23);
            this.buttonTestRead.TabIndex = 7;
            this.buttonTestRead.Text = "Тест чтения файла";
            this.buttonTestRead.UseVisualStyleBackColor = true;
            this.buttonTestRead.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(407, 579);
            this.Controls.Add(this.buttonTestRead);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.comboBoxParseSettings);
            this.Controls.Add(this.dtpDate);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tbXLSFileName);
            this.Controls.Add(this.tbHTMLFileName);
            this.Controls.Add(this.progressBar);
            this.Controls.Add(this.btCalculate);
            this.Controls.Add(this.btSelectXLS);
            this.Controls.Add(this.btSelectHTML);
            this.Name = "Form1";
            this.Text = "Программа пересчета разрядов";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btSelectHTML;
        private System.Windows.Forms.ProgressBar progressBar;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox tbHTMLFileName;
        private System.Windows.Forms.TextBox tbXLSFileName;
        private System.Windows.Forms.Button btSelectXLS;
        private System.Windows.Forms.Button btCalculate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.DateTimePicker dtpDate;
        private System.Windows.Forms.ComboBox comboBoxParseSettings;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button buttonTestRead;
    }
}

