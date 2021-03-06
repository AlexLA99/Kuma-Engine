#pragma once

#include <string>
#include <vector>

class Component;
enum  ComponentType;
class ComponentTransform;
class ComponentMesh;
class ComponentTexture;

class GameObject
{
public:
	GameObject(char* name);
	GameObject(GameObject* parent, char* name);
	~GameObject();

	void Update();

	Component* AddComponent(Component* component);

	void Enable();
	void Disable();

	bool IsActive();
	const char* GetName();
	std::vector<Component*> GetComponents()const;

	void DeleteComponentType(ComponentType type);

	bool HasComponentType(ComponentType type);

private:
	bool active;
	std::string name;
	std::vector<Component*> components;


public:
	ComponentTransform* transform = nullptr;
	ComponentTexture* texture = nullptr;
	std::vector<GameObject*> children;
	GameObject* parent;
};
