#include "Application.h"
#include "ModuleRenderer3D.h"
#include "GameObject.h"
#include "Component.h"
#include "ComponentTransform.h"
#include "TextureImporter.h"
#include "ComponentTexture.h"
#include "ImGui.h"

ComponentTexture::ComponentTexture(GameObject* owner) : Component(ComponentType::TEXTURE, owner)
{

}

ComponentTexture::ComponentTexture(GameObject* owner, char* path, Texture* texture = nullptr) : Component(ComponentType::TEXTURE, owner), texture(texture), path(path)
{

}

ComponentTexture::~ComponentTexture()
{

}

void ComponentTexture::Update()
{

}

void  ComponentTexture::DrawInspector()
{
	if (ImGui::CollapsingHeader("Texture"))
	{
		ImGui::Text("Path: %s", path);
		if (ImGui::Checkbox("Active", &this->active)) {}
	}
}

char* ComponentTexture::GetPath()const
{
	return path;
}

Texture* ComponentTexture::GetTexture() const
{
	return texture;
}

bool ComponentTexture::IsEnabled()
{
	return active;
}

void ComponentTexture::SwitchEnabledTexture()
{
	active = !active;
}