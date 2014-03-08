#ifndef _PARTICLES_H_
#define _PARTICLES_H_
#include "Point.h"
#include "Image.h"
#include "Color.h"
class Particles
{
public:
	Particles();
	~Particles();
	Particles(float x, float y);
	Particles(unsigned int assignedNumber, float x, float y);

	Particles& operator= (const Particles& newParticles);

	void AddColorKeyFrame(float time, Color Values);
	void AddForce(float startTime, float endTime, float xAcc, float yAcc);
	
	void ClearColors(void);
	void ClearForces(void);

	void Delete();

	void FixToScreen(bool toScreen);

	bool GetActive(void);
	float GetAngle(void);
	float GetAngleInRad(void);
	unsigned short GetDepth(void);
	float GetDirectionX(void);
	float GetDirectionY(void);
	bool GetExists(void);
	float GetFrequency(void);
	float GetLife(void);
	bool GetMaxReached(void);
	float GetSize(void);
	bool GetVisible(void);
	float GetX(void);
	float GetY(void);

	void ResetCount(void);

	void SetActive(bool active);
	void SetAngle(float angle);
	void SetAngleInRad(float angleInRad);
	void SetColorInterpolation(bool smooth);
	void SetDepth(unsigned short depth);
	void SetDirection(float xVelocity, float yVelocity);
	void SetFrequency(float freq);
	void SetImage(Image Object);
	void SetLife(float lifespan);
	void SetMax(unsigned int maxParticles);
	void SetPosition(Point Location);
	void SetSize(float size);
	void SetStartZone(Point TopLeft, Point BottomRight);
	void SetVelocityRange(float minVelocity, float maxVelocity);
	void SetVisible(bool visible);

	void Update(float updateSpeed);

private:
	unsigned int _particleNumber;
};

#endif