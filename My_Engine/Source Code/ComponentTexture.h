#pragma once
class Component;
class TextureInfo;

class ComponentTexture : public Component
{
public:
	ComponentTexture(GameObject* owner);
	ComponentTexture(GameObject* owner, char* path, TextureInfo* mesh);
	~ComponentTexture();

	void Update() override;
	void DrawInspector() override;

	char* GetPath()const;
	TextureInfo* GetTexture() const;

	bool IsEnabled();
	void SwitchEnabledTexture();
private:

	TextureInfo* texture = nullptr;
	char* path;

};
