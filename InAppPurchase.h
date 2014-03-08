#pragma once

#include "Text.h"
#include "../Defines.h"

class InAppPurchase
{
public:
	InAppPurchase(void);
	~InAppPurchase(void);
#if (OS != WINDOWS)
	void Activate(unsigned int ID);
	void AddProductID(Text productID);

	bool GetAvailable(int ID);
	bool GetState(void);

	void Restore(void); //TODO: Fill out

	void SetTitle(Text Title);
	void Setup(void);

private:
	unsigned int purchaseID;
#endif
};

