#pragma once

#include "Point.h"
#include "RGBA.h"
#include "Image.h"
#include <string>

class Image;
class Point;

class Text
{
public:
	Text();
	~Text();
	Text(const char* textString, bool isVisible = false);
	//Text(unsigned int assignedTextNumber, const char* textString, bool isVisible = false);
	Text(std::string textString, bool isVisible = false);
	
	//Text& operator= (const Text& newText);
	Text& operator+= (Text addText);
	bool operator== (Text otherText);
	bool operator!= (const Text otherText);

	unsigned int countTokens(char delimeter);

	void deleteAll(void);
	
	void fixToScreen(bool toScreen);
	int foundNeedle(const char needle);

	char getChar(unsigned int index);
	float getCharAngle(unsigned int index);
	float getCharAngleInRad(unsigned int index);
	unsigned short getCharColorAlpha(unsigned int index);
	unsigned short getCharColorBlue(unsigned int index);
	unsigned short getCharColorGreen(unsigned int index);
	unsigned short getCharColorRed(unsigned int index);
	float getCharX(unsigned int index);
	float getCharY(unsigned int index);
	unsigned short getColorAlpha(void);
	unsigned short getColorBlue(void);
	unsigned short getColorGreen(void);
	unsigned short getColorRed(void);
	const char *getCString(void);
	unsigned int getDepth(void);
	short getDelimiterIndex(char separator);
	bool getExists(void);
	bool getHitTest(Point Location);
	unsigned int getID(void);
	unsigned int getLength(void);
	float getLineSpacing(void);
	unsigned int getNextID(void);
	float getSize(void);
	float getSpacing(void);
	std::string getString(void);
	Text getToken(char delimeter, unsigned int token);
	float getTotalHeight(void);
	float getTotalWidth(void);
	bool getVisible(void);
	float getX();
	float getY();

	Text left(unsigned int count);
	unsigned int len(void);
	Text lower(void);

	Text mid(unsigned int position, int length);

	void print(bool newLineAtEnd = true);

	Text right(unsigned int count);
	
	void setAlignment(unsigned short mode);
	void setCharAngle(unsigned int index, float angle);
	void setCharAngleInRad(unsigned int index, float angle);
	void setCharColor(unsigned int index, RGBA Value);
	void setCharColorAlpha(unsigned int index, unsigned short alpha);
	void setCharColorBlue(unsigned int index, unsigned short blue);
	void setCharColorGreen(unsigned int index, unsigned short green);
	void setCharColorRed(unsigned int index, unsigned short red);
	void setCharPosition(unsigned int index, Point Location);
	void setCharX(unsigned int index, float x);
	void setCharY(unsigned int index, float y);
	void setColor(RGBA value);
	void setColorAlpha(unsigned short alpha);
	void setColorBlue(unsigned short blue);
	void setColorGreen(unsigned short green);
	void setColorRed(unsigned short red);
	void setDefaultExtendedFontImage(Image Object);
	void setDefaultMagFilter(bool linear);
	void setDefaultMinFilter(bool linear);
	void setDepth(unsigned int depth);
	void setExtendedFontImage(Image Object);
	void setFontImage(Image Object);
	void setLineSpacing(float spacing);
	void setMaxWidth(float width);
	void setPosition(Point Location);
	void setPrintColor(RGBA Value);
	void setPrintSize(float size);
	void setPrintSpacing(float space);
	void setScissor(Point TopLeft, Point BottomRight);
	void setSize(float size);
	void setSpacing(float spacing);
	void setString(const char* string);
	void setString(std::string string);
	void setVisible(bool visible);
	void setX(float x);
	void setY(float y);
	bool splitAtDelimeter(Text *Part1, Text *Part2, char delimeter);

	Text upper(void);

	enum Alignment
	{
		LEFT,
		CENTER,
		RIGHT
	};

protected:
	bool canBeSeen;
	unsigned int textNumber;
	std::string storedString;
	
	bool _Alignment(unsigned short mode);
	bool _Color(unsigned short value);
	bool _Depth(unsigned int value);
	bool _Index(unsigned int value);
	bool _NotNegativeFloat(float value);
};