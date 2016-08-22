#include "key.h"
#include "producer.h"
#include "consumer.h"
#include <QApplication>
#include <QSemaphore>
#include <QThread>
#include <stdio.h>
#include <qDebug>
#include <QTextStream>
#include <QWaitCondition>
const int DataSize=1000;
const int BufferSize=80;
int buffer[BufferSize];
int a[20];
QSemaphore freeBytes(BufferSize);
QSemaphore usedBytes(0);
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Producer producer;
    Consumer consumer;
    QWaitCondition buffer;
    producer.start();
    qDebug()<<"producer.start();";
    consumer.start();
    qDebug()<<"consumer.start();";
    producer.wait();
    qDebug()<<" producer.wait();";
    consumer.wait();
     qDebug()<<" consumer.wait();";
     buffer.wakeAll();
     qDebug()<<"结束啦";
    return a.exec();
}
void Producer::run()
{
    for(int i=0;i<DataSize;++i)
    {
       // qDebug()<<"haha";
        freeBytes.acquire();
        buffer[i%BufferSize]=(i%BufferSize);
        qDebug()<<"P"+(int)buffer[i%BufferSize];
     //   printf("p  %d", buffer[i%BufferSize]);
        usedBytes.release();
    }
}
void Consumer::run()
{
    for(int i=0;i<DataSize;i++)
    {

        usedBytes.acquire();
       // fprintf(stderr,"%d",buffer[i%BufferSize]);
       // qDebug()<<stderr;
      //   qDebug()<<"C"+(int)buffer[i%BufferSize];
       //  printf("p  "%d, i%BufferSize);
        if(i%16==0&&i!=0)
          //  fprintf(stderr,"\n");
        freeBytes.release();
    }
   // fprintf(stderr,"\n");
}
