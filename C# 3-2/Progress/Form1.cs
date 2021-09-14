using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Progress
{

    public partial class Form1 : Form
    {

        int Num = 0; //진행 숫자
        string OrgStr = ""; //결과 : 저장

        public Form1()
        {
            InitializeComponent();
        }

        private void btnRun_Click(object sender, EventArgs e)
        {
            Timer.Interval = int.Parse(speedTxt.Text);
            this.Timer.Enabled = true;
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            Num++; if (Num > 100) { 
                this.Timer.Enabled = false; return;
            }
            this.pbStatus.Value = Num; this.lblStatus.Text = OrgStr + Num.ToString() + "%";
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            OrgStr = this.lblStatus.Text;
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            Num = 0;
            this.Timer.Enabled = false;
            this.pbStatus.Value = Num; this.lblStatus.Text = OrgStr + Num.ToString() + "%";
        }
    }
}
