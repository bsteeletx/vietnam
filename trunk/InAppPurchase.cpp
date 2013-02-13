#include "InAppPurchase.h"
#include "agk.h"

InAppPurchase::InAppPurchase(void)
{
#if (OS == IOS)
	purchaseID = 0;
#endif
}


InAppPurchase::~InAppPurchase(void)
{
}

#if (OS == IOS)
void InAppPurchase::activate(unsigned int ID)
{
	agk::InAppPurchaseActivate(ID);
}

void InAppPurchase::addProductID(Text ProductID)
{
	char normalized[64] = {""};
	
	strcpy(normalized, ProductID.getCString());

	agk::InAppPurchaseAddProductID(normalized);
}

bool InAppPurchase::getAvailable(int ID)
{
	return (bool) agk::GetInAppPurchaseAvailable(ID);
}

bool InAppPurchase::getState(void)
{
	return (bool) agk::GetInAppPurchaseState();
}

void InAppPurchase::setTitle(Text Title)
{
	char normalized[64] = {""};

	strcpy(normalized, Title.getCString());

	agk::InAppPurchaseSetTitle(normalized);
}
	
void InAppPurchase::setup(void)
{
	agk::InAppPurchaseSetup();
}

#endif