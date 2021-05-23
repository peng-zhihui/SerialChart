#ifndef COMMON_H
#define COMMON_H

#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QList>
#include <QIODevice>
#include <QCoreApplication>
#include <QByteArray>
#include <QHash>
#include <QPair>
#include <QtGlobal>
#include <QPainter>
#include <QSettings>
#include <math.h>


#define MIN(A,B)  (((A)<(B)) ? (A) : (B) )
#define MAX(A,B)  (((A)>(B)) ? (A) : (B) )
#define PUT_IN_RANGE(V,VMIN,VMAX) MAX(VMIN,MIN(VMAX,V))
#define MAP_TO_RANGE(V,VMIN0,VMAX0,VMIN1,VMAX1) ( (VMIN1) +  ( (V) - (VMIN0) ) * ( (VMAX1) - (VMIN1) ) / ( (VMAX0) - (VMIN0) ) )

#endif // COMMON_H
