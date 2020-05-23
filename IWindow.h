#pragma once
class IWindow
{
private:

public:

	virtual void configurate(int width, int height, char *name) = 0;

	virtual ~IWindow() {};
};

