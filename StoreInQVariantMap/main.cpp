#include <QCoreApplication>
#include <QVariantMap>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVariantMap argumentsMap ;

    QString currentKey ;

    for (int i = 1 ; i < argc ; ++i){
        QString argument = QString :: fromUtf8(argv[i]) ;

        if(argument.startsWith("--")){

            currentKey = argument.mid(2) ;//Remove the  leading "--"
            argumentsMap.insert(currentKey,QVariant()) ;//Insert the argument as key with an empty value

        }else if (!currentKey.isEmpty()) {

            argumentsMap[currentKey]=argument;//Store the argument value using the current key

            currentKey.clear();//Clear the current key for the next argument

}

    }

    //Print out the Stored Commandline arguments
    qDebug()<<"Stored CommandLine arguments\n";
    qDebug()<<argumentsMap;

    return a.exec();
}
