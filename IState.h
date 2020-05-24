#pragma once
class IState
{
private:

public:

	virtual ~IState() {};

	virtual void Init() = 0;
	//virtual void HandleInput() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	//virtual void Render(float dt) = 0;

	//virtual void Pause() {}
	//virtual void Resume() {}
};

