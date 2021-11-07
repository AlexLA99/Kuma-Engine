#include "Application.h"
#include "ModuleRenderer3D.h"
#include "GameObject.h"
#include "Component.h"
#include "ComponentMesh.h"
#include "ComponentTransform.h"
#include "ComponentTexture.h"
#include "TextureImporter.h"
#include "MeshImporter.h"
#include "ImGui.h"

ComponentMesh::ComponentMesh(GameObject* owner) : Component(ComponentType::MESH, owner)
{

}

ComponentMesh::ComponentMesh(GameObject* owner, char* path, MeshEntry* mesh = nullptr) : Component(ComponentType::MESH, owner), mesh(mesh), path(path)
{
}

ComponentMesh::~ComponentMesh()
{

}

void ComponentMesh::Update()
{
	DrawMesh();
}

void  ComponentMesh::DrawInspector()
{
	if (ImGui::CollapsingHeader("Mesh"))
	{
		ImGui::Text("Path: %s", path);
		ImGui::Text("Vertices: %d", mesh->num_vertices);


	}
}

void ComponentMesh::DrawMesh()
{
	if (active)
	{
		if (owner->texture != nullptr)
		{
			if (owner->texture->IsEnabled())
			{
				App->renderer3D->DrawMesh(mesh);
				return;
			}
		}
	}

	App->renderer3D->DrawMesh(mesh);
}

char* ComponentMesh::GetPath()const
{
	return path;
}