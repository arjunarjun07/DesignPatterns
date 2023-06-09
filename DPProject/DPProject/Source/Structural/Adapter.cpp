#include "Structural\Adapter.h"

void UsbDevice::Connect()
{
	std::cout << "UsbDevice::Connect" << std::endl;
}

void UsbDevice::Disconnect()
{
	std::cout << "UsbDevice::Disconnect" << std::endl;
}

void UsbDevice::TransferData()
{
	std::cout << "UsbDevice::TransferData" << std::endl;
}

TypeCAdapter::TypeCAdapter(IUsbDevice* usbDevice)
{
	m_usbDevice = usbDevice;
}

void TypeCAdapter::Connect()
{
	std::cout << "TypeCAdapter::Connect" << std::endl;
	m_usbDevice->Connect();
}

void TypeCAdapter::Disconnect()
{
	std::cout << "TypeCAdapter::Disconnect" << std::endl;
	m_usbDevice->Disconnect();
}

void TypeCAdapter::TransferData()
{
	std::cout << "TypeCAdapter::TransferData" << std::endl;
	m_usbDevice->TransferData();
}

TypeCAdapter::~TypeCAdapter()
{
	if (m_usbDevice)
	{
		delete m_usbDevice;
	}
}
