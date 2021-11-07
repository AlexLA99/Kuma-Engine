#pragma once


class Component;
struct MeshEntry;

class ComponentMesh : public Component
{
public:
	ComponentMesh(GameObject* owner);
	ComponentMesh(GameObject* owner, char* path, MeshEntry* mesh);
	~ComponentMesh();

	void Update() override;
	void DrawInspector() override;

	void DrawMesh();
	char* GetPath()const;
private:

	MeshEntry* mesh;
	char* path;

};
