#include "EmsCart.h"

#include <QDebug>

EmsCart::EmsCart(QObject *parent) :
    QObject(parent)
{
    m_deviceHandle = nullptr;
    m_interfaceClaimed = false;
}

EmsCart::~EmsCart()
{
}

bool EmsCart::init()
{
    int result = libusb_init(NULL);
    if (result < 0) {
        qCritical() << "Failed to initialize libusb";
        return false;
    }
    return true;
}