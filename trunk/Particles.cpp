#include "Particles.h"
#include "agk.h"

Particles::Particles(void)
{
	_particleNumber = 0;
}

Particles::~Particles(void)
{
	//if (GetExists())
		//agk::DeleteParticles(_particleNumber);
}

Particles::Particles(float x, float y)
{
	_particleNumber = agk::CreateParticles(x, y);
}

Particles& Particles::operator= (const Particles& newParticle)
{	
	if (this != &newParticle)
	{
		_particleNumber = newParticle._particleNumber;
	}

	return *this;
}

Particles::Particles(unsigned int assignedNumber, float x, float y)
{
	if (assignedNumber != 0)
	{
		agk::CreateParticles(assignedNumber, x, y);
		_particleNumber = assignedNumber;
	}
}

void Particles::AddColorKeyFrame(float time, Color Values)
{
	if (time > 0.0f)
		agk::AddParticlesColorKeyFrame(_particleNumber, time, Values.GetRed(), Values.GetGreen(), Values.GetBlue(), Values.GetAlpha());
}

void Particles::AddForce(float startTime, float endTime, float xAcc, float yAcc)
{
	if (startTime < endTime)
	{
		if (startTime >= 0.0f)
			agk::AddParticlesForce(_particleNumber, startTime, endTime, xAcc, yAcc);
	}
}

void Particles::ClearColors(void)
{
	agk::ClearParticlesColors(_particleNumber);
}

void Particles::ClearForces(void)
{
	agk::ClearParticlesForces(_particleNumber);
}

void Particles::Delete()
{
	agk::DeleteParticles(_particleNumber);
}

void Particles::FixToScreen(bool toScreen)
{
	if (toScreen)
		agk::FixParticlesToScreen(_particleNumber, 1);
	else
		agk::FixParticlesToScreen(_particleNumber, 0);
}

bool Particles::GetActive(void)
{
	if (agk::GetParticlesActive(_particleNumber) == 1)
		return true;
	
	return false;
}

float Particles::GetAngle(void)
{
	return agk::GetParticlesAngle(_particleNumber);
}

float Particles::GetAngleInRad(void)
{
	return agk::GetParticlesAngleRad(_particleNumber);
}

unsigned short Particles::GetDepth(void)
{
	return (unsigned short) agk::GetParticlesDepth(_particleNumber);
}

float Particles::GetDirectionX(void)
{
	return agk::GetParticlesDirectionX(_particleNumber);
}

float Particles::GetDirectionY(void)
{
	return agk::GetParticlesDirectionY(_particleNumber);
}

bool Particles::GetExists(void)
{
	if (agk::GetParticlesExists(_particleNumber) == 1)
		return true;

	return false;
}

float Particles::GetFrequency(void)
{
	return agk::GetParticlesFrequency(_particleNumber);
}

float Particles::GetLife(void)
{
	return agk::GetParticlesLife(_particleNumber);
}

bool Particles::GetMaxReached(void)
{
	if (agk::GetParticlesMaxReached(_particleNumber) == 1)
		return true;
	
	return false;
}

float Particles::GetSize(void)
{
	return agk::GetParticlesSize(_particleNumber);
}

bool Particles::GetVisible(void)
{
	if (agk::GetParticlesVisible(_particleNumber) == 1)
		return true;

	return false;
}

float Particles::GetX(void)
{
	return agk::GetParticlesX(_particleNumber);
}

float Particles::GetY(void)
{
	return agk::GetParticlesY(_particleNumber);
}

void Particles::ResetCount(void)
{
	agk::ResetParticleCount(_particleNumber);
}

void Particles::SetActive(bool active)
{
	if (active)
		agk::SetParticlesActive(_particleNumber, 1);
	else
		agk::SetParticlesActive(_particleNumber, 0);
}

void Particles::SetAngle(float angle)
{
	agk::SetParticlesAngle(_particleNumber, angle);
}

void Particles::SetAngleInRad(float angleInRad)
{
	agk::SetParticlesAngleRad(_particleNumber, angleInRad);
}

void Particles::SetColorInterpolation(bool smooth)
{
	if (smooth)
		agk::SetParticlesColorInterpolation(_particleNumber, 1);
	else
		agk::SetParticlesColorInterpolation(_particleNumber, 0);
}

void Particles::SetDepth(unsigned short depth)
{
	agk::SetParticlesDepth(_particleNumber, depth);
}

void Particles::SetDirection(float xVelocity, float yVelocity)
{
	agk::SetParticlesDirection(_particleNumber, xVelocity, yVelocity);
}

void Particles::SetFrequency(float freq)
{
	if (freq > 0.0f)
		agk::SetParticlesFrequency(_particleNumber, freq);
}

void Particles::SetImage(Image Object)
{
	agk::SetParticlesImage(_particleNumber, Object.GetID());
}

void Particles::SetLife(float lifespan)
{
	if (lifespan > 0.0f)
		agk::SetParticlesLife(_particleNumber, lifespan);
}

void Particles::SetMax(unsigned int maxParticles)
{
	agk::SetParticlesMax(_particleNumber, maxParticles);
}

void Particles::SetPosition(Point Location)
{
	agk::SetParticlesPosition(_particleNumber, Location.GetX(), Location.GetY());
}

void Particles::SetSize(float size)
{
	if(size > 0.0f)
		agk::SetParticlesSize(_particleNumber, size);
}

void Particles::SetStartZone(Point TopLeft, Point BottomRight)
{
	agk::SetParticlesStartZone(_particleNumber, TopLeft.GetX(), TopLeft.GetY(), BottomRight.GetX(), BottomRight.GetY());
}

void Particles::SetVelocityRange(float minVelocity, float maxVelocity)
{
	agk::SetParticlesVelocityRange(_particleNumber, minVelocity, maxVelocity);
}

void Particles::SetVisible(bool visible)
{
	if (visible)
		agk::SetParticlesVisible(_particleNumber, 1);
	else
		agk::SetParticlesVisible(_particleNumber, 0);
}

void Particles::Update(float updateSpeed)
{
	if (updateSpeed > 0.0f)
		agk::UpdateParticles(_particleNumber, updateSpeed);
}