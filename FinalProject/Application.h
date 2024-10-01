#pragma once

#include "RenderEngine.h"
#include "Cube.h"
#include "Camera.h"
#include "Shader.h"
#include "Texture.h"

class Application :
    public RenderEngine
{
public:
    Application();
    ~Application();

private:
	Shader *shader;
	Texture *cubeDiffTex, *cubeSpecTex;
	Texture *cubeDiffTex2, *cubeSpecTex2;
	Texture* cubeDiffTex3, * cubeSpecTex3;
	Texture* cubeDiffTex4, * cubeSpecTex4;
	Texture* cubeDiffTex5, * cubeSpecTex5;
	Texture* cubeDiffTex6, * cubeSpecTex6;
	Texture* cubeDiffTex7, * cubeSpecTex7;
	Texture* cubeDiffTex8, * cubeSpecTex8;
	Texture* cubeDiffTex9, * cubeSpecTex9;
	Texture* cubeDiffTex10, * cubeSpecTex10;
	Texture* cubeDiffTex11, * cubeSpecTex11;
	Texture* cubeDiffTex12, * cubeSpecTex12;
	Texture* cubeDiffTex13, * cubeSpecTex13;
	Texture* cubeDiffTex14, * cubeSpecTex14;
	Texture* cubeDiffTex15, * cubeSpecTex15;
	Texture* cubeDiffTex16, * cubeSpecTex16;
	Texture* cubeDiffTex17, * cubeSpecTex17;
	Texture* cubeDiffTex18, * cubeSpecTex18;
	Texture* cubeDiffTex19, * cubeSpecTex19;
	Texture* cubeDiffTex20, * cubeSpecTex20;
	Texture* cubeDiffTex21, * cubeSpecTex21;
	Texture* cubeDiffTex22, * cubeSpecTex22;
	Texture* cubeDiffTex23, * cubeSpecTex23;


	Cube* cube5;
	Cube *cube4;
	Cube *cube3;
	Cube *cube2;
	Cube *cube;
	Cube* cube6;
	Cube* cube7;
	Cube* cube8;
	Cube* cube9;
	Cube* cube10;
	Cube* cube11;
	Cube* cube12;
	Cube* cube13;
	Cube* cube14;
	Cube* cube15;
	Cube* cube16;
	Cube* cube17;
	Cube* cube18;
	Cube* cube19;
	Cube* cube20;
	Cube* cube21;
	Cube* cube22;
	Cube* cube23;
	
	GLuint depthMapFBO;
	GLuint depthMap;
	const GLuint SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;

	Camera *camera;

	float angle = 0;
	float angle2 = 0;
	glm::vec3 viewPos;



	float cameraSpeed = 0.5f;


	void setupPerspective();
	void setupCamera();
	void setupLighting(); 
	void setupShadow();

	virtual void Init();
	virtual void DeInit(); 
	virtual void Update(double deltaTime);
	virtual void Render();
	virtual void ProcessInput(GLFWwindow* window);

};

