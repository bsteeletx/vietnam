#include "RayCast.h"
#include "agk.h"

RayCast::RayCast(Object Casting, Vector Direction, float radius, bool useSlide)
{
	if (radius == 0.0f)
	{
		if(agk::ObjectRayCast(Casting.getID(), Direction.getStartPointX(), Direction.getStartPointY(), Direction.getStartPointZ(), Direction.getEndPointX(), Direction.getEndPointY(), Direction.getEndPointZ()) == 1)
		{
			if (agk::GetObjectRayCastNumHits())
				rayCastID = agk::GetObjectRayCastHitID(0);
		}
	}
	else if (!useSlide)
	{
		if(agk::ObjectSphereCast(Casting.getID(), Direction.getStartPointX(), Direction.getStartPointY(), Direction.getStartPointZ(), Direction.getEndPointX(), Direction.getEndPointY(), Direction.getEndPointZ(), radius) == 1)
		{
			if (agk::GetObjectRayCastNumHits())
				rayCastID = agk::GetObjectRayCastHitID(0);
		}
	}
	else
	{
		if(agk::ObjectSphereSlide(Casting.getID(), Direction.getStartPointX(), Direction.getStartPointY(), Direction.getStartPointZ(), Direction.getEndPointX(), Direction.getEndPointY(), Direction.getEndPointZ(), radius) > 0)
		{
			if (agk::GetObjectRayCastNumHits())
				rayCastID = agk::GetObjectRayCastHitID(0);
		}
	}
}

RayCast::RayCast(Vector Direction, RayCastMode value, int groupInfo)
{
	rayCastID = 0;

	switch (value)
	{
	case PHYSICS:
		num2DHits = agk::PhysicsRayCast(Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	case PHYSICS_CATEGORY:
		num2DHits = agk::PhysicsRayCastCategory(groupInfo, Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	case PHYSICS_GROUP:
		num2DHits = agk::PhysicsRayCastGroup(groupInfo, Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	case SPRITE:
		num2DHits = agk::SpriteRayCast(Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	case SPRITE_CATEGORY:
		num2DHits = agk::SpriteRayCastCategory(groupInfo, Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	case SPRITE_GROUP:
		num2DHits = agk::SpriteRayCastGroup(groupInfo, Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	case SPRITE_SINGLE:
		num2DHits = agk::SpriteRayCastSingle(groupInfo, Direction.getStartPointX(), Direction.getStartPointY(), Direction.getEndPointX(), Direction.getEndPointY());
		break;
	}		
}

RayCast::~RayCast(void)
{
}

float RayCast::getFraction(void)
{
	return agk::GetRayCastFraction();
}

Point RayCast::getNormal(void)
{
	return Point(getNormalX(), getNormalY());
}

float RayCast::getNormalX(void)
{
	return agk::GetRayCastNormalX();
}

float RayCast::getNormalY(void)
{
	return agk::GetRayCastNormalY();
}

Point RayCast::getObjectBounce(void)
{
	return Point(getObjectBounceX(), getObjectBounceY(), getObjectBounceZ());
}

float RayCast::getObjectBounceX(void)
{
	return agk::GetObjectRayCastBounceX(rayCastID);
}

float RayCast::getObjectBounceY(void)
{
	return agk::GetObjectRayCastBounceY(rayCastID);
}

float RayCast::getObjectBounceZ(void)
{
	return agk::GetObjectRayCastBounceZ(rayCastID);
}

float RayCast::getObjectDistance(void)
{
	return agk::GetObjectRayCastDistance(rayCastID);
}
	
unsigned int RayCast::getObjectHitID(void)
{
	return agk::GetObjectRayCastHitID(rayCastID);
}

Point RayCast::getObjectNormal(void)
{
	return Point(getObjectNormalX(), getObjectNormalY(), getObjectNormalZ());
}

float RayCast::getObjectNormalX(void)
{
	return agk::GetObjectRayCastNormalX(rayCastID);
}

float RayCast::getObjectNormalY(void)
{
	return agk::GetObjectRayCastNormalY(rayCastID);
}

float RayCast::getObjectNormalZ(void)
{
	return agk::GetObjectRayCastNormalZ(rayCastID);
}

Point RayCast::getObjectPosition(void)
{
	return Point(getObjectX(), getObjectY(), getObjectZ());
}

unsigned short RayCast::getObjectNumHits(void)
{
	return agk::GetObjectRayCastNumHits();
}

Point RayCast::getObjectSlide(void)
{
	return Point(getObjectSlideX(), getObjectSlideY(), getObjectSlideZ());
}

float RayCast::getObjectSlideX(void)
{
	return agk::GetObjectRayCastSlideX(rayCastID);
}

float RayCast::getObjectSlideY(void)
{
	return agk::GetObjectRayCastSlideY(rayCastID);
}

float RayCast::getObjectSlideZ(void)
{
	return agk::GetObjectRayCastSlideZ(rayCastID);
}

float RayCast::getObjectX(void)
{
	return agk::GetObjectRayCastX(rayCastID);
}

float RayCast::getObjectY(void)
{
	return agk::GetObjectRayCastX(rayCastID);
}

float RayCast::getObjectZ(void)
{
	return agk::GetObjectRayCastZ(rayCastID);
}

Point RayCast::getPosition(void)
{
	return Point(getX(), getY());
}

unsigned int RayCast::getSpriteID(void)
{
	return agk::GetRayCastSpriteID();
}

float RayCast::getX(void)
{
	return agk::GetRayCastX();
}

float RayCast::getY(void)
{
	return agk::GetRayCastY();
}
