#include "Editor.h"

// Constructor & Destructor

gmd::Editor::Editor()
	: m_Window(Vector2(1280, 720))
{
	this->Init();
}

// Private

void gmd::Editor::Init() 
{
	// Init here
}

void gmd::Editor::RenderGUI()
{
	ImGui::Begin("Triangle Example");
	ImGui::Text("Hello, this is a triangle!");
	ImGui::End();
}

void gmd::Editor::Render()
{
	// OpenGL Rendering
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();
}

// Public

void gmd::Editor::Update()
{
	this->m_Window.NewFrame();

	this->RenderGUI();
	this->Render();

	this->m_Window.EndFrame();
}
