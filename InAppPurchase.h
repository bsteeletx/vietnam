#pragma once

#include "Text.h"
#include "../Defines.h"

class InAppPurchase
{
public:
	InAppPurchase(void);
	~InAppPurchase(void);
#if (OS == IOS)
	void activate(unsigned int ID);
	void addProductID(Text productID);

	bool getAvailable(int ID);
	bool getState(void);

	void setTitle(Text Title);
	void setup(void);

private:
	unsigned int purchaseID;
#endif
};

