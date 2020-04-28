using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab2_WF
{
    class Timer1
    {

        //отображение 
        int x, y; //координаты
        int width, heigth;// size
        int widthT, heigthT;
        int header_higth;//
        int bigH, minH, bigM, minM, bigS, minS;
        //Окно ввода 
        //int xin, yin;
        //TextBox text1,text2,text3,text4,text5,text6;
        //функционал 
        //int mode;// operetiong mode
        //string mode_file;
        //int second;//Time 
        ComboBox port1;
        ComboBox port2;
        ComboBox port3;
        Form1 parent;// Form1 объект 
                     //      ComboBox modes;
        Button give1, give2, give3;
        // Label onesixth, twosixths, threesixth, foursixth, fivesixth, sixsixth;
        Button start, stop, abort;
        string[] hour_nums = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24" };
        string[] minutes_nums = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59" };
        string[] seconds_nums = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59" };


        public Timer1(Form1 form)
        {

            x = y = 10;
            width = 600;
            heigth = 200;
            widthT = 70;
            heigthT = 100;
            header_higth = 250;
            parent = form;


            port1 = new ComboBox();
            port1.Left = x + 4;//положение
            port1.Top = y + 170;//положение
            port1.Width = 50;
            port1.Height = 10;
            port1.Items.AddRange(hour_nums);
            port1.Text = "0";
            parent.Controls.Add(port1);
            //   mode_file = "Wait1.jpg";

            /*  onesixth = new Label();
              onesixth.Left = x + 4;
              onesixth.Top = y + 20;
              onesixth.Width = 70;
              onesixth.Height = 100;
            //  onesixth.Items.AddRange(hour_nums);
              onesixth.Text = "0";
              parent.Controls.Add(onesixth);
              */
            give1 = new Button();
            give1.Left = x + 60;
            give1.Top = y + 170;
            give1.Width = 70;
            give1.Height = 25;
            give1.Text = "Добавить";
            give1.Click += new EventHandler(gvie1Click);
            parent.Controls.Add(give1);

            port2 = new ComboBox();
            port2.Left = x + 230;//положение
            port2.Top = y + 170;//положение
            port2.Width = 50;
            port2.Height = 10;
            port2.Items.AddRange(minutes_nums);
            port2.Text = "0";
            parent.Controls.Add(port2);


            give2 = new Button();
            give2.Left = x + 285;
            give2.Top = y + 170;
            give2.Width = 70;
            give2.Height = 25;
            give2.Text = "Добавить";
            give2.Click += new EventHandler(give2Click);
            parent.Controls.Add(give2);


            port3 = new ComboBox();
            port3.Left = x + 460;//положение
            port3.Top = y + 170;//положение
            port3.Width = 50;
            port3.Height = 10;
            port3.Items.AddRange(seconds_nums);
            port3.Text = "0";
            parent.Controls.Add(port3);


            give3 = new Button();
            give3.Left = x + 515;
            give3.Top = y + 170;
            give3.Width = 70;
            give3.Height = 25;
            give3.Text = "Добавить";
            give3.Click += new EventHandler(give3Click);
            parent.Controls.Add(give3);


            start = new Button();
            start.Left = x + 230;
            start.Top = y + 140;
            start.Width = 70;
            start.Height = 25;
            start.Text = "Старт";

            // Это нужно сделать для всех кнопок :)
            // И если на других стандартных объектах 
            // хотите события обрабатывать - тоже :) :(
            start.Click += new EventHandler(startClick);

            parent.Controls.Add(start);


            stop = new Button();
            stop.Left = x + 300;
            stop.Top = y + 140;
            stop.Width = 70;
            stop.Height = 25;
            stop.Text = "Стоп";
            stop.Click += new EventHandler(stopClick);
            parent.Controls.Add(stop);


            abort = new Button();
            abort.Left = x + 370;
            abort.Top = y + 140;
            abort.Width = 70;
            abort.Height = 25;
            abort.Text = "Cброс";
            abort.Click += new EventHandler(abortClick);
            parent.Controls.Add(abort);

        }



        private void gvie1Click(object sender, EventArgs e)
        {
            bigH += Convert.ToInt32(port1.Text) / 10;
            minH += Convert.ToInt32(port1.Text) % 10;
            if (minH >= 10)
            {
                bigH += minH / 10;
                minH = minH % 10;
            }
        }

        private void give2Click(object sender, EventArgs e)
        {
            bigM += Convert.ToInt32(port2.Text) / 10;
            minM += Convert.ToInt32(port2.Text) % 10;
            if (minM >= 10)
            {
                bigM += minM / 10;
                minM = minM % 10;
            }
            if (bigM >= 6)
            {
                minH++;
                bigM = 0;
            }
        }

        private void give3Click(object sender, EventArgs e)
        {
            bigS += Convert.ToInt32(port3.Text) / 10;
            minS += Convert.ToInt32(port3.Text) % 10;
            if (minS >= 10)
            {
                bigS += minS / 10;
                minS = minS % 10;
            }
            if (bigS >= 6)
            {
                minM++;
                bigS = 0;
            }
        }

        private void abortClick(object sender, EventArgs e)
        {
            bigH = 0;
            minH = 0;
            bigM = 0;
            minM = 0;
            bigS = 0;
            minS = 0;
            MessageBox.Show("Обнулено");
        }

        private void stopClick(object sender, EventArgs e)
        {
          
            MessageBox.Show("Работает :)");
        }

        private void startClick(object sender, EventArgs e)
        {
            MessageBox.Show("Работает :)");

        }

        internal void Time()
        {
            if(minS>0)
            {
                minS--;
            }
            else
            {
                if(bigS>0)
                {
                    bigS--;
                    minS = 9;
                }
                else
                {
                    if(minM>0)
                    {
                        minM--;
                        bigS = 5;
                        minS = 9;
                    }
                    else
                    {
                        if(bigM>0)
                        {
                            bigM--;
                            minM = 9;
                        }
                        else
                        {
                            if(minH>0)
                            {
                                minH--;
                                bigM = 5;
                                minM = 9;
                            }
                            else
                            {
                                if(bigH>0)
                                {
                                    bigH--;
                                    minH = 9;
                                }
                            }
                        }
                    }
                }
            }
            
        }

        /*  internal bool Inside(int xm, int ym)
          {
              /*  if (xm < x + 60 || xm > x + 60 + 70)//give1
                {
                    return false;
                }
                if (ym < y + 170 || ym > y + 170 + 25)
                {
                    return false;
                }
                if (xm < x + 285 || xm > x + 285 + 70)//give2
                {
                    return false;
                }
                if (ym < y + 170 || ym > y + 170 + 25)
                {
                    return false;
                }
                if (xm < x + 515 || xm > x + 515 + 70)//give3
                {
                    return false;
                }
                if (ym < y + 170 || ym > y + 170 + 25)
                {
                    return false;
                }
                if (xm < x + 230 || xm > x + 230 + 70)//start
                {
                    return false;
                }
                if (ym < y + 170 || ym > y + 170 + 25)
                {
                    return false;
                }
                if (xm < x + 300 || xm > x + 300 + 70)//stop
                {
                    return false;
                }
                if (ym < y + 170 || ym > y + 170 + 25)
                {
                    return false;
                }
                if (xm < x + 370 || xm > x + 370 + 70)//abort
                {
                    return false;
                }
                if (ym < y + 170 || ym > y + 170 + 25)
                {
                    return false;
                }

                return true;

              if (xm >= x + 60 && xm <= x + 60 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//give1
              {
                  return true;
              }
              if (xm >= x + 285 && xm <= x + 285 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//give2
              {
                  return true;
              }
              if (xm >= x + 515 && xm <= x + 515 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//give3
              {
                  return true;
              }
              if (xm >= x + 230 && xm <= x + 140 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//start
              {
                  return true;
              }
              if (xm >= x + 300 && xm <= x + 140 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//stop
              {
                  return true;
              }
              if (xm >= x + 370 && xm <= x + 370 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//abort
              {
                  return true;
              }
              return true;
          }
          internal void Click(int xm, int ym)
          {
              if (xm >= x + 60 && xm <= x + 60 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//give1
              {
                  bigH += Convert.ToInt32(port1.Text) / 10;
                  minH += Convert.ToInt32(port1.Text) % 10;
                  if (minH >= 10)
                  {
                      bigH += minH / 10;
                      minH = minH % 10;
                  }
              }
              if (xm >= x + 285 && xm <= x + 285 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//give2
              {
                  bigM += 0;
                  minM += 0;
              }
              if (xm >= x + 515 && xm <= x + 515 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//give3
              {
                  bigS += 0;
                  minS += 0;
              }
              if (xm >= x + 230 && xm <= x + 140 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//start
              {

              }
              if (xm >= x + 300 && xm <= x + 140 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//stop
              {

              }
              if (xm >= x + 370 && xm <= x + 370 + 70 && ym >= y + 170 && ym <= y + 170 + 25)//abort
              {
                  bigH = 0;
                  bigM = 0;
                  bigS = 0;
                  minH = 0;
                  minM = 0;
                  minS = 0;

           }*/
    
        internal void Draw(Graphics g)
        {
            //Основа
            g.FillRectangle(Brushes.Azure, x, y, width, heigth);
            g.DrawRectangle(Pens.Black, x, y, width, heigth);
            //циферблат
            g.DrawRectangle(Pens.Black, x + 4, y + 20, widthT, heigthT);
            g.DrawRectangle(Pens.Black, x + 104, y + 20, widthT, heigthT);
            g.DrawRectangle(Pens.Black, x + 200, y + 20, widthT, heigthT);
            g.DrawRectangle(Pens.Black, x + 300, y + 20, widthT, heigthT);
            g.DrawRectangle(Pens.Black, x + 400, y + 20, widthT, heigthT);
            g.DrawRectangle(Pens.Black, x + 500, y + 20, widthT, heigthT);
            //double points
            g.DrawRectangle(Pens.Black, x + 183, y + 45, 8, 8);
            g.FillRectangle(Brushes.Black, x + 183, y + 45, 8, 8);
            g.DrawRectangle(Pens.Black, x + 183, y + 80, 8, 8);
            g.FillRectangle(Brushes.Black, x + 183, y + 80, 8, 8);

            g.DrawRectangle(Pens.Black, x + 381, y + 45, 8, 8);
            g.FillRectangle(Brushes.Black, x + 381, y + 45, 8, 8);
            g.DrawRectangle(Pens.Black, x + 381, y + 80, 8, 8);
            g.FillRectangle(Brushes.Black, x + 381, y + 80, 8, 8);

            //Цифры
            g.DrawString(bigH.ToString(), new Font("Arial", 80), Brushes.Blue, x - 6, y + 10);
            g.DrawString(minH.ToString(), new Font("Arial", 80), Brushes.Blue, x + 94, y + 10);
            g.DrawString(bigM.ToString(), new Font("Arial", 80), Brushes.Blue, x + 190, y + 10);
            g.DrawString(minM.ToString(), new Font("Arial", 80), Brushes.Blue, x + 290, y + 10);
            g.DrawString(bigS.ToString(), new Font("Arial", 80), Brushes.Blue, x + 390, y + 10);
            g.DrawString(minS.ToString(), new Font("Arial", 80), Brushes.Blue, x + 490, y + 10);
        }
    }
}
