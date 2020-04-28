using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2_WF
{
    public partial class Form1 : Form
    {
        Timer1 timer1;//Timer timer1
                      //  Timer timer22;
     
        public Form1()
        {
            InitializeComponent();
            timer1 = new Timer1(this);
            //timer22 = new Timer1(this, 100, 150,400, 150);
            timer2.Interval = 1000;
            timer2.Enabled = true;
            
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = this.CreateGraphics();
            timer1.Draw(g);
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            timer1.Time();
        }


        /*     private void Form1_MouseClick(object sender, MouseEventArgs e)
             {
                 int xm = e.X;
                 int ym = e.Y;
                 if (timer1.Inside(xm, ym))
                 {
                     timer1.Click(xm, ym);
                 }
             }
             */
    }
}
