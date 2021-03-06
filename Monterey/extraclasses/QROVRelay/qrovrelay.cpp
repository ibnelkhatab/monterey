/*
    Copyright (C) 2012  Chris Konstad (chriskon149@gmail.com)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "qrovrelay.h"
#include <QtDebug>

QROVRelay::QROVRelay(QObject *parent) :
    QObject(parent)
{
    enabled = false;
    lastState = enabled;
    name = "Relay";
    button = 0;
    hat = 2;
    pushButton = 0;
}

QString QROVRelay::getName()
{
    return name;
}

void QROVRelay::setName(QString n)
{
    name = n;
}

bool QROVRelay::getState()
{
    return enabled;
}

void QROVRelay::setState(bool s)
{
    enabled = s;
    if(lastState != enabled)
    {
        emit toggled(enabled);
        lastState = enabled;
    }
}

void QROVRelay::setButton(int b)
{
    button = b;
}

void QROVRelay::setHat(int h)
{
    hat = h;
}

int QROVRelay::getButton()
{
    return button;
}

int QROVRelay::getHat()
{
    return hat;
}

void QROVRelay::setQPushButton(QPushButton *pb)
{
    pushButton = pb;
    qDebug() << pushButton;
}

QPushButton* QROVRelay::getQPushButton()
{
    return pushButton;
}
