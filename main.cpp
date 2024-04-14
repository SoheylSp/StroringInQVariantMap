#include <QCoreApplication>
#include <QVariantMap>
#include <QDebug>
#include <QStringList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariantMap argumentsMap ;
    QString currentKey ;

    for ( int i = 1 ;i < argc ; ++i){

        QString argument = QString::fromUtf8(argv[i]) ;

        if(argument.startsWith("--")){

            currentKey = argument.mid(2) ;
            argumentsMap.insert(currentKey,QVariant()) ;//Insert Argument as key with an empty QVariantList


        }else if(! currentKey.isEmpty()){

            QStringList values = argument.split(',',QString::SkipEmptyParts);
            QVariantList doubleValues ;

            for(const QString & value:values){
                bool ok ;
                double num = value.toDouble(&ok) ;
                if(ok){
                    doubleValues.append(num) ;
                }

            }
            argumentsMap[currentKey] = doubleValues ;//Store the array of double numbers as the value using current key
            currentKey.clear();

        }

    }

    //Print out the stored command line arguments

    qDebug()<<"Stored Command line arguments \n";
    qDebug()<<argumentsMap ;


    return a.exec();
}
