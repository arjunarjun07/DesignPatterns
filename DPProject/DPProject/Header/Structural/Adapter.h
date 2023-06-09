#ifndef ADAPTER_H

#define ADAPTER_H

#include "stdafx.h"

/*
About:
	- Adapter pattern is a structural design pattern that allows objects with incompatible interfaces to collaborate.
	
	- Getting the interface you want from the interface you have.
*/

/*
* example:
	Imagine that you’re creating a stock market monitoring app. The app downloads the stock data from multiple sources in XML format
	and then displays nice-looking charts and diagrams for the user. At some point, you decide to improve the app by integrating a
	smart 3rd-party analytics library. But there’s a catch: the analytics library only works with data in JSON format.
*/

/*
* Uses:
	- Use the Adapter class when you want to use some existing class, but its interface isn’t compatible with the rest of your code.
	- Use the pattern when you want to reuse several existing subclasses that lack some common functionality that can’t be added to the superclass.
*/

class IUsbDevice
{
public:
	virtual void Connect() = 0;
	virtual void Disconnect() = 0;
	virtual void TransferData() = 0;
};

class UsbDevice : public IUsbDevice
{
public:
	
	void Connect() override;

	void Disconnect() override;

	void TransferData() override;

};

class TypeCAdapter : public IUsbDevice
{
private:
	IUsbDevice* m_usbDevice;

public:
	TypeCAdapter(IUsbDevice* usbDevice);

	void Connect() override;

	void Disconnect() override;

	void TransferData() override;

	~TypeCAdapter();
};

#endif // !ADAPTER_H
