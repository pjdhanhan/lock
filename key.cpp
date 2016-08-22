#include "key.h"
#include "ui_key.h"

Key::Key(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Key)
{
    ui->setupUi(this);
    key=0;
}
Key::creatKey(){mutex.tryLock();++key;return key;mutex.unlock();}
Key::value(){mutex.tryLock();return key;mutex.unlock();}

Key::~Key()
{
    delete ui;
}
