#ifndef KEY_H
#define KEY_H

#include <QDialog>
#include <QMutex>

namespace Ui {
class Key;
}

class Key : public QDialog
{
    Q_OBJECT

public:
    explicit Key(QWidget *parent = 0);
    int creatKey();
    int value () ;
    ~Key();

private:
    Ui::Key *ui;
    int key;
    QMutex mutex;
};

#endif // KEY_H
