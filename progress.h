#ifndef PROGRESS_H
#define PROGRESS_H

#include <QString>
#include<QFile>
#include<QTextStream>
#include<QFileInfo>
#include "state.h"
namespace  {

class Progress
{
private:

public:
    Progress(){}
    static QString filename;

    static bool saveProgress(State *state){

        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            QTextStream stream( &file );
            stream << state->level << endl;
        }
    }

    static bool loadProgress(State *state){

        QFile file( filename );
        if ( file.open(QIODevice::ReadWrite) )
        {
            int level;
            QTextStream stream( &file );
            stream>>level;
            state->level=(Level)level;
            qDebug()<<"Dessirialized "<<state->level;
            return true;
        }
        return false;
    }

    static bool removeProgress(){
        QFile::remove(filename);
    }

    static bool progressExist(){
        QFileInfo check_file(filename);
        // check if file exists and if yes: Is it really a file and not a directory?
        if (check_file.exists() && check_file.isFile()) {
            return true;
        }
        return false;
    }
};
QString Progress::filename="finished.txt";
}

#endif // PROGRESS_H
