#include "mainform.h"
#include "ui_mainform.h"
#include "mainwindow.h"

mainForm::mainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainForm)
{
     ui->setupUi(this);

    alb_td = new ActivityLabel(ui->horizontalLayoutWidget);
    alb_td->setObjectName(QStringLiteral("alb_td"));
    alb_td->setMinimumSize(QSize(70, 70));
    alb_td->setMaximumSize(QSize(70, 70));
    alb_td->setAutoFillBackground(true);

    ui->horizontalLayout->addWidget(alb_td);

    alb_ta = new ActivityLabel(ui->horizontalLayoutWidget);
    alb_ta->setObjectName(QStringLiteral("alb_ta"));
    alb_ta->setMinimumSize(QSize(70, 70));
    alb_ta->setMaximumSize(QSize(70, 70));
    alb_ta->setAutoFillBackground(true);

    ui->horizontalLayout->addWidget(alb_ta);

    QPalette background;
    background.setBrush(QPalette::Background, QBrush(QPixmap(":/seven/imgs/背景.png")));
    this->setPalette(background);

    background.setBrush(QPalette::Background, QBrush(QPixmap(":/seven/imgs/跑道圆 中 按下.png")));
    ui->ql_setTime->setPalette(background);
    ui->ql_cql->setPalette(background);
    ui->ql_whl->setPalette(background);

    background.setBrush(QPalette::Background, QBrush(QPixmap(":/seven/imgs/td.png")));
    alb_ta->setPalette(background);

    background.setBrush(QPalette::Background, QBrush(QPixmap(":/seven/imgs/ta.png")));
    alb_td->setPalette(background);

    btnFlat_ = new QPushButton("Flat Button", this);
    btnFlat_->setFlat(true);
    btnFlat_->setGeometry(700,4090,100,40);


    connect(alb_ta, SIGNAL(clicked()), SLOT(timeAdd_tick()));
    connect(alb_td, SIGNAL(clicked()), SLOT(timeDel_tick()));
}


mainForm::~mainForm()
{
    delete ui;
}

int time_cnt = 0;

void mainForm::timeAdd_tick()
{
    time_cnt ++;
}

void mainForm::timeDel_tick()
{
    MainWindow::instance()->_switch_start_page();
}

ActivityLabel::ActivityLabel(QWidget *parent)
{

}

ActivityLabel::~ActivityLabel()
{

}

void ActivityLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        Q_UNUSED(ev)
            emit clicked();
    }
}
