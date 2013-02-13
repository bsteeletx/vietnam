#include "Shader.h"
#include "agk.h"

Shader::Shader(Text VertexFilename, Text PixelFilename)
{
	shaderID = agk::LoadShader(VertexFilename.getCString(), PixelFilename.getCString());
}

Shader::~Shader(void)
{
}

unsigned int Shader::getID(void)
{
	return shaderID;
}

void Shader::setConstantByName(Text Name, float value1, float value2, float value3, float value4)
{
	agk::SetShaderConstantByName(shaderID, Name.getCString(), value1, value2, value3, value4);
}