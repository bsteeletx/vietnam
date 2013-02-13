#pragma once
class Quaternion
{
public:
	Quaternion(void);
	~Quaternion(void);
	Quaternion(float w, float x, float y, float z);

	float getW(void);
	float getX(void);
	float getY(void);
	float getZ(void);

	void resetAllTo(float w, float x, float y, float z);
	
	void setW(float value);
	void setX(float value);
	void setY(float value);
	void setZ(float value);

private:
	float wRot, xRot, yRot, zRot;
};

