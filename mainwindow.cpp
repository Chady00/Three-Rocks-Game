#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPlainTextEdit>
#include<QLabel>
#include<QColor>
#include <QApplication>
#include <QProcess>
#include<QTime>
#include<QString>
#include<QThread>
#include<QtDebug>
#include<QMessageBox>

////////////////////////////////////////////////
int counter_L=0;
int counter_R=0;
int temp=20;
int blink_flag=0;
////////////////////////////////////////////////
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //DISPLAYING background
    this->centralWidget()->setStyleSheet(
    "background-image:url(\"D:/imager.jpg\"); background-position: center;" );
  //  ui->label->setText("Engine Stole");
    ui->label->hide();
 timer = new QTimer(this);
 blinktimer= new QTimer(this);
 connect(blinktimer,SIGNAL(timeout()),this,SLOT(blink()));
 connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
 timer->start(1000);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::myfunction()
{
    Engine_turn();
    timer->stop();
    enable_buttons();

}

void MainWindow::blink()
{   blink_flag++;
    if(ui->label->isHidden())
            ui->label->show();
        else
           ui->label->hide();
    if(blink_flag==4){
        ui->label->hide();
        blinktimer->stop();
        blink_flag=0;
    }

}
void MainWindow::enable_buttons(){
    ui->one_zero->setEnabled(true);
    ui->one_one->setEnabled(true);
    ui->one_two->setEnabled(true);
    ui->two_one->setEnabled(true);
    ui->two_zero->setEnabled(true);
    ui->three_zero->setEnabled(true);
    ui->zero_one->setEnabled(true);
    ui->zero_two->setEnabled(true);
    ui->zero_three->setEnabled(true);

}

void MainWindow::disable_buttons(){
    ui->one_zero->setDisabled(true);
    ui->one_one->setDisabled(true);
    ui->one_two->setDisabled(true);
    ui->two_one->setDisabled(true);
    ui->two_zero->setDisabled(true);
    ui->three_zero->setDisabled(true);
    ui->zero_one->setDisabled(true);
    ui->zero_two->setDisabled(true);
    ui->zero_three->setDisabled(true);

}

////////////////////////////////////////////////

void MainWindow::check(){

    if(counter_L>=10){//check for 1 remaining
        ui->one_zero->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->one_zero->setDisabled(true);
        //disable 1,2 and 1,1
        ui->one_one->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->one_one->setDisabled(true);
        ui->one_two->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->one_two->setDisabled(true);

    }

    if(counter_L>=9){//check for 2 remaining
        ui->two_zero->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->two_zero->setDisabled(true);
        //disable 2,1
        ui->two_one->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->two_one->setDisabled(true);
    }

    if(counter_L>=8){//check for 3 remaining
        ui->three_zero->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->three_zero->setDisabled(true);
  }
  //////////////////////...........................////////////////////
    if(counter_R>=10){//check for 1 remaining
        ui->zero_one->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->zero_one->setDisabled(true);
        //disable 1,1 and 2,1
        ui->one_one->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->one_one->setDisabled(true);
        ui->two_one->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->two_one->setDisabled(true);

    }

    if(counter_R>=9){//check for 2 remaining
        ui->zero_two->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->zero_two->setDisabled(true);
        // disabe 1,2
        ui->one_two->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->one_two->setDisabled(true);

    }

    if(counter_R>=8){//check for 3 remaining
        ui->zero_three->setStyleSheet("QPushButton { color :#C5C4C4; }");
        ui->zero_three->setDisabled(true);
  }
    if(temp==0){
        QMessageBox::information(this,tr("YOU'VE MADE IT"),tr("You Win! You picked the last balls"));
    }
}

void MainWindow:: clear_one_right(){
    counter_R++;
    temp--;
   if(ui->rock_1R){
       delete ui->rock_1R;
       ui->rock_1R=nullptr;
   }
   else if(ui->rock_2R){
       delete ui->rock_2R;
       ui->rock_2R=nullptr;
      }
   else if(ui->rock_3R){
       delete ui->rock_3R;
       ui->rock_3R=nullptr;
      }
   else if(ui->rock_4R){
       delete ui->rock_4R;
       ui->rock_4R=nullptr;
   }
   else if(ui->rock_5R){
       delete ui->rock_5R;
       ui->rock_5R=nullptr;
   }
   else if(ui->rock_6R){
       delete ui->rock_6R;
       ui->rock_6R=nullptr;
   }
   else if(ui->rock_7R){
       delete ui->rock_7R;
       ui->rock_7R=nullptr;
   }
   else if(ui->rock_8R){
       delete ui->rock_8R;
       ui->rock_8R=nullptr;
   }
   else if(ui->rock_9R){
       delete ui->rock_9R;
       ui->rock_9R=nullptr;
   }
   else if(ui->rock_10R){
       delete ui->rock_10R;
       ui->rock_10R=nullptr;
   }

}


void MainWindow::clear_two_right(){
    counter_R+=2;
    temp-=2;
         if(ui->rock_1R){
             delete ui->rock_1R;
             delete ui->rock_2R;
             ui->rock_1R=nullptr;
             ui->rock_2R=nullptr;
         }
         else if(ui->rock_2R){
             delete ui->rock_2R;
             delete ui->rock_3R;
             ui->rock_2R=nullptr;
             ui->rock_3R=nullptr;
            }
         else if(ui->rock_3R){
             delete ui->rock_3R;
             delete ui->rock_4R;
             ui->rock_3R=nullptr;
             ui->rock_4R=nullptr;
            }
         else if(ui->rock_4R){
             delete ui->rock_4R;
             delete ui->rock_5R;
             ui->rock_4R=nullptr;
             ui->rock_5R=nullptr;
         }
         else if(ui->rock_5R){
             delete ui->rock_5R;
             delete ui->rock_6R;
             ui->rock_5R=nullptr;
             ui->rock_6R=nullptr;
         }
         else if(ui->rock_6R){
             delete ui->rock_6R;
             delete ui->rock_7R;
             ui->rock_6R=nullptr;
             ui->rock_7R=nullptr;
         }
         else if(ui->rock_7R){
             delete ui->rock_7R;
             delete ui->rock_8R;
             ui->rock_7R=nullptr;
             ui->rock_8R=nullptr;
         }
         else if(ui->rock_8R){
             delete ui->rock_8R;
             delete ui->rock_9R;
             ui->rock_8R=nullptr;
             ui->rock_9R=nullptr;
         }
         else if(ui->rock_9R){
             delete ui->rock_9R;
             delete ui->rock_10R;
             ui->rock_9R=nullptr;
             ui->rock_10R=nullptr;
         }


}


void MainWindow::clear_three_right(){
    counter_R+=3;
    temp-=3;
         if(ui->rock_1R){
             delete ui->rock_1R;
             delete ui->rock_2R;
             delete ui->rock_3R;
             ui->rock_1R=nullptr;
             ui->rock_2R=nullptr;
             ui->rock_3R=nullptr;
         }
         else if(ui->rock_2R){
             delete ui->rock_2R;
             delete ui->rock_3R;
             delete ui->rock_4R;
             ui->rock_2R=nullptr;
             ui->rock_3R=nullptr;
             ui->rock_4R=nullptr;
            }
         else if(ui->rock_3R){
             delete ui->rock_3R;
             delete ui->rock_4R;
             delete ui->rock_5R;
             ui->rock_3R=nullptr;
             ui->rock_4R=nullptr;
             ui->rock_5R=nullptr;
            }
         else if(ui->rock_4R){
             delete ui->rock_4R;
             delete ui->rock_5R;
             delete ui->rock_6R;
             ui->rock_4R=nullptr;
             ui->rock_5R=nullptr;
             ui->rock_6R=nullptr;
         }
         else if(ui->rock_5R){
             delete ui->rock_5R;
             delete ui->rock_6R;
             delete ui->rock_7R;
             ui->rock_5R=nullptr;
             ui->rock_6R=nullptr;
             ui->rock_7R=nullptr;
         }
         else if(ui->rock_6R){
             delete ui->rock_6R;
             delete ui->rock_7R;
             delete ui->rock_8R;
             ui->rock_6R=nullptr;
             ui->rock_7R=nullptr;
             ui->rock_8R=nullptr;
         }
         else if(ui->rock_7R){
             delete ui->rock_7R;
             delete ui->rock_8R;
             delete ui->rock_9R;
             ui->rock_7R=nullptr;
             ui->rock_8R=nullptr;
             ui->rock_9R=nullptr;
         }
         else if(ui->rock_8R){
             delete ui->rock_8R;
             delete ui->rock_9R;
             delete ui->rock_10R;
             ui->rock_8R=nullptr;
             ui->rock_9R=nullptr;
             ui->rock_10R=nullptr;
         }


}



void MainWindow:: clear_one_left(){
    counter_L++;
    temp--;
   if(ui->rock_1L){
       delete ui->rock_1L;
       ui->rock_1L=nullptr;
   }
   else if(ui->rock_2L){
       delete ui->rock_2L;
       ui->rock_2L=nullptr;
      }
   else if(ui->rock_3L){
       delete ui->rock_3L;
       ui->rock_3L=nullptr;
      }
   else if(ui->rock_4L){
       delete ui->rock_4L;
       ui->rock_4L=nullptr;
   }
   else if(ui->rock_5L){
       delete ui->rock_5L;
       ui->rock_5L=nullptr;
   }
   else if(ui->rock_6L){
       delete ui->rock_6L;
       ui->rock_6L=nullptr;
   }
   else if(ui->rock_7L){
       delete ui->rock_7L;
       ui->rock_7L=nullptr;
   }
   else if(ui->rock_8L){
       delete ui->rock_8L;
       ui->rock_8L=nullptr;
   }
   else if(ui->rock_9L){
       delete ui->rock_9L;
       ui->rock_9L=nullptr;
   }
   else if(ui->rock_10L){
       delete ui->rock_10L;
       ui->rock_10L=nullptr;
   }

}




////////////////////////////////////////////////

void MainWindow:: clear_two_left(){
    counter_L+=2;
    temp-=2;
         if(ui->rock_1L){
             delete ui->rock_1L;
             delete ui->rock_2L;
             ui->rock_1L=nullptr;
             ui->rock_2L=nullptr;
         }
         else if(ui->rock_2L){
             delete ui->rock_2L;
             delete ui->rock_3L;
             ui->rock_2L=nullptr;
             ui->rock_3L=nullptr;
            }
         else if(ui->rock_3L){
             delete ui->rock_3L;
             delete ui->rock_4L;
             ui->rock_3L=nullptr;
             ui->rock_4L=nullptr;
            }
         else if(ui->rock_4L){
             delete ui->rock_4L;
             delete ui->rock_5L;
             ui->rock_4L=nullptr;
             ui->rock_5L=nullptr;
         }
         else if(ui->rock_5L){
             delete ui->rock_5L;
             delete ui->rock_6L;
             ui->rock_5L=nullptr;
             ui->rock_6L=nullptr;
         }
         else if(ui->rock_6L){
             delete ui->rock_6L;
             delete ui->rock_7L;
             ui->rock_6L=nullptr;
             ui->rock_7L=nullptr;
         }
         else if(ui->rock_7L){
             delete ui->rock_7L;
             delete ui->rock_8L;
             ui->rock_7L=nullptr;
             ui->rock_8L=nullptr;
         }
         else if(ui->rock_8L){
             delete ui->rock_8L;
             delete ui->rock_9L;
             ui->rock_8L=nullptr;
             ui->rock_9L=nullptr;
         }
         else if(ui->rock_9L){
             delete ui->rock_9L;
             delete ui->rock_10L;
             ui->rock_9L=nullptr;
             ui->rock_10L=nullptr;
         }


}

void MainWindow:: clear_three_left(){
    temp-=3;
    counter_L+=3;
         if(ui->rock_1L){
             delete ui->rock_1L;
             delete ui->rock_2L;
             delete ui->rock_3L;
             ui->rock_1L=nullptr;
             ui->rock_2L=nullptr;
             ui->rock_3L=nullptr;
         }
         else if(ui->rock_2L){
             delete ui->rock_2L;
             delete ui->rock_3L;
             delete ui->rock_4L;
             ui->rock_2L=nullptr;
             ui->rock_3L=nullptr;
             ui->rock_4L=nullptr;
            }
         else if(ui->rock_3L){
             delete ui->rock_3L;
             delete ui->rock_4L;
             delete ui->rock_5L;
             ui->rock_3L=nullptr;
             ui->rock_4L=nullptr;
             ui->rock_5L=nullptr;
            }
         else if(ui->rock_4L){
             delete ui->rock_4L;
             delete ui->rock_5L;
             delete ui->rock_6L;
             ui->rock_4L=nullptr;
             ui->rock_5L=nullptr;
             ui->rock_6L=nullptr;
         }
         else if(ui->rock_5L){
             delete ui->rock_5L;
             delete ui->rock_6L;
             delete ui->rock_7L;
             ui->rock_5L=nullptr;
             ui->rock_6L=nullptr;
             ui->rock_7L=nullptr;
         }
         else if(ui->rock_6L){
             delete ui->rock_6L;
             delete ui->rock_7L;
             delete ui->rock_8L;
             ui->rock_6L=nullptr;
             ui->rock_7L=nullptr;
             ui->rock_8L=nullptr;
         }
         else if(ui->rock_7L){
             delete ui->rock_7L;
             delete ui->rock_8L;
             delete ui->rock_9L;
             ui->rock_7L=nullptr;
             ui->rock_8L=nullptr;
             ui->rock_9L=nullptr;
         }
         else if(ui->rock_8L){
             delete ui->rock_8L;
             delete ui->rock_9L;
             delete ui->rock_10L;
             ui->rock_8L=nullptr;
             ui->rock_9L=nullptr;
             ui->rock_10L=nullptr;
         }

}


////////////////////////////////////////////////
void MainWindow::on_one_zero_clicked()
{// initially counter_L =10
 //  ui->label->setText("Engine Removed 1 Stone\n from the left");
   clear_one_left();
   check();
   disable_buttons();
   timer->start(2000);
   blinktimer->start(500);
}

void MainWindow::on_two_zero_clicked()
{
    clear_two_left();
    check();
    disable_buttons();
   timer->start(2000);
   blinktimer->start(500);
}


void MainWindow::on_three_zero_clicked()
{
    clear_three_left();
    check();
    disable_buttons();
    timer->start(2000);
    blinktimer->start(500);
}


void MainWindow::on_one_one_clicked()
{
    clear_one_left();
    clear_one_right();
    check();
    disable_buttons();
   timer->start(2000);
   blinktimer->start(500);

}


void MainWindow::on_two_one_clicked()
{   clear_two_left();
    clear_one_right();
    check();
    disable_buttons();
    timer->start(2000);
    blinktimer->start(500);
}



void MainWindow::on_zero_one_clicked()
{
    clear_one_right();
    check();
    disable_buttons();
    timer->start(2000);
    blinktimer->start(500);
}


void MainWindow::on_zero_two_clicked()
{
    clear_two_right();
    check();
    disable_buttons();
   timer->start(2000);
   blinktimer->start(500);
}


void MainWindow::on_zero_three_clicked()
{
    clear_three_right();
    check();
    disable_buttons();
    timer->start(2000);
    blinktimer->start(500);
}


void MainWindow::on_one_two_clicked()
{
    clear_one_left();
    clear_two_right();
    check();
    disable_buttons();
    timer->start(2000);
    blinktimer->start(500);
}

void MainWindow:: delay()
{
    QTime dieTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::on_pushButton_clicked()
{//reset
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void MainWindow::Engine_turn(){
//I want to make his turn at 16 ..1 12 ..8 ..4

//delay

if(temp==20){
    clear_one_right(); // Now counter_L + counter_R=1;
}
else if(temp==18){
   clear_one_right();
   clear_one_left();
}
else if(temp==17){
    clear_one_left();
}
else if(temp==16){//  BAD
    clear_two_right();
}
else if(temp==15){
    clear_three_left();
}
else if(temp==14){
    clear_two_right();
}
else if(temp==13){
    clear_one_right();
}
else if(temp==12){ // BAD
    clear_two_left();
}
else if(temp==11){
    if(counter_R<=7){
    clear_three_right();}
    else {clear_three_left();}
}
else if(temp==10){
    if(counter_R<=8){
    clear_two_right();}
    else {clear_two_left();}
}
else if(temp==9){
    if(counter_L<=9){
    clear_one_left();}
    else {clear_one_right();}
}
else if(temp==8){//  BAD
  if(counter_R<=9){
 clear_one_right();}
  else{clear_one_left();}
}
else if(temp==7){
    if(counter_L<=7){
    clear_three_left();}
    else {clear_three_right();}
}
else if(temp==6){
    if(counter_R<=8){
    clear_two_right();}
    else if(counter_L<=8){
    clear_two_left();}
    else{clear_one_right();
    clear_one_left();}
    }

else if (temp==5){
    if(counter_L<=9){
    clear_one_left();}
   else {clear_one_right();}
}
else if(temp==4){ //BAD
    if(counter_R<=8){
    clear_two_right();}
    else if(counter_L<=8){
    clear_two_left();}
    else{clear_one_right();
    clear_one_left();}
    }

else if(temp==3){
    if(counter_R<=9 && counter_L<=8){
        clear_one_right();
        clear_two_left();
    }
    else if(counter_R<=8 && counter_L<=9){
        clear_one_left();
        clear_two_right();
    }
    else if(counter_R<=7){
        clear_three_right();
    }
    else {clear_three_left();}
    QMessageBox::information(this,tr("GAME OVER"),tr("You lose! Engine picked the last 3 balls"));
}
else if (temp==2){
    if(counter_R<=8){
       clear_two_right();
   }
   else if(counter_L<=8){
       clear_two_left();
   }
    if(counter_R<=9 && counter_L<=9){
        clear_one_right();
        clear_one_left();
    }
else { qDebug()<<"I am waiting for engine";}
QMessageBox::information(this,tr("GAME OVER"),tr("You lose! Engine picked the last 2 balls"));
}
else if(temp==1){
    if(counter_R<=9){
    clear_one_right();}
    else{clear_one_left();}
    QMessageBox::information(this,tr("GAME OVER"),tr("You lose! Engine picked the last ball"));
}
if(temp>0)check();
}


