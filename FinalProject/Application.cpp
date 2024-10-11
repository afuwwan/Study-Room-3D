#include "Application.h"

Application::Application()
{

}

Application::~Application()
{
}

void Application::setupShadow() 
{
	glm::vec3 lightPos = glm::vec3(0, 25, 0);
	glm::mat4 view = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	glm::mat4 lightSpaceMatrix = projection * view;
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);
	shader->setMat4("lightSpaceMatrix", lightSpaceMatrix);

}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(-2.25, 0, 2.5);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);

}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3( 0, 25, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	shader->setVec3("lightColor", lightColor);

}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("texturedCube.vert", "texturedCube.frag");
	shader->Init();

	// Assuming you have the necessary variables declared in your class


	// Create the framebuffer object
	glGenFramebuffers(1, &depthMapFBO);

	// Create the depth texture
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	GLfloat borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

	// Attach the depth texture to the framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// Create cube diffuse texture and specular texture
	cubeDiffTex = new Texture("light_DarkGray.png");
	cubeDiffTex->Init();
	cubeSpecTex = new Texture("light_DarkGray.png");
	cubeSpecTex->Init();
	// Create instance of cube
	cube = new Cube(shader, cubeDiffTex, cubeSpecTex);
	cube->Init();
	cube->SetScale(0.2f, 0.2f, 0.2f);

	// Create cube diffuse texture and specular texture
	cubeDiffTex2 = new Texture("wall.png");
	cubeDiffTex2->Init();
	cubeSpecTex2 = new Texture("wall.png");
	cubeSpecTex2->Init();
	// Create instance of cube
	cube2 = new Cube(shader, cubeDiffTex2, cubeSpecTex2);
	cube2->Init();
	cube2->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex3 = new Texture("");
	cubeDiffTex3->Init();
	cubeSpecTex3 = new Texture("");
	cubeSpecTex3->Init();
	// Create instance of cube
	cube3 = new Cube(shader, cubeDiffTex3, cubeSpecTex3);
	cube3->Init();
	cube3->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex4 = new Texture("kayu_Gelap.png");
	cubeDiffTex4->Init();
	cubeSpecTex4 = new Texture("kayu_Gelap.png");
	cubeSpecTex4->Init();
	// Create instance of cube
	cube4 = new Cube(shader, cubeDiffTex4, cubeSpecTex4);
	cube4->Init();
	cube4->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex5 = new Texture("darkCloth.png");
	cubeDiffTex5->Init();
	cubeSpecTex5 = new Texture("darkCloth.png");
	cubeSpecTex5->Init();
	// Create instance of cube
	cube5 = new Cube(shader, cubeDiffTex5, cubeSpecTex5);
	cube5->Init();
	cube5->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex6 = new Texture("laptopBottom.png");
	cubeDiffTex6->Init();
	cubeSpecTex6 = new Texture("laptopBottom.png");
	cubeSpecTex6->Init();
	// Create instance of cube
	cube6 = new Cube(shader, cubeDiffTex6, cubeSpecTex6);
	cube6->Init();
	cube6->SetScale(1.5f, 0.1f, 2.0f);
	
	cubeDiffTex7 = new Texture("laptopTop.png");
	cubeDiffTex7->Init();
	cubeSpecTex7 = new Texture("laptopTop.png");
	cubeSpecTex7->Init();
	// Create instance of cube
	cube7 = new Cube(shader, cubeDiffTex7, cubeSpecTex7);
	cube7->Init();
	cube7->SetScale(0.05f, 1.5f, 2.0f);

	cubeDiffTex8 = new Texture("wall.png");
	cubeDiffTex8->Init();
	cubeSpecTex8 = new Texture("wall.png");
	cubeSpecTex8->Init();
	// Create instance of cube
	cube8 = new Cube(shader, cubeDiffTex8, cubeSpecTex8);
	cube8->Init();
	cube8->SetScale(0.2f, 0.2f, 0.2f);

	cubeDiffTex9 = new Texture("foto1.png");
	cubeDiffTex9->Init();
	cubeSpecTex9 = new Texture("foto1.png");
	cubeSpecTex9->Init();
	// Create instance of cube
	cube9 = new Cube(shader, cubeDiffTex9, cubeSpecTex9);
	cube9->Init();
	cube9->SetScale(0.15f, 3.5f, 6.0f);

	cubeDiffTex10 = new Texture("foto2.png");
	cubeDiffTex10->Init();
	cubeSpecTex10 = new Texture("foto2.png");
	cubeSpecTex10->Init();
	// Create instance of cube
	cube10 = new Cube(shader, cubeDiffTex10, cubeSpecTex10);
	cube10->Init();
	cube10->SetScale(0.15f, 3.0f, 3.0f);

	cubeDiffTex11 = new Texture("foto3.png");
	cubeDiffTex11->Init();
	cubeSpecTex11 = new Texture("foto3.png");
	cubeSpecTex11->Init();
	// Create instance of cube
	cube11 = new Cube(shader, cubeDiffTex11, cubeSpecTex11);
	cube11->Init();
	cube11->SetScale(0.15f, 3.0f, 3.0f);

	cubeDiffTex12 = new Texture("darkGray.png");
	cubeDiffTex12->Init();
	cubeSpecTex12 = new Texture("darkGray.png");
	cubeSpecTex12->Init();
	// Create instance of cube
	cube12 = new Cube(shader, cubeDiffTex12, cubeSpecTex12);
	cube12->Init();
	cube12->SetScale(0.15f, 3.5f, 3.5f);

	cubeDiffTex13 = new Texture("darkGray.png");
	cubeDiffTex13->Init();
	cubeSpecTex13 = new Texture("darkGray.png");
	cubeSpecTex13->Init();
	// Create instance of cube
	cube13 = new Cube(shader, cubeDiffTex13, cubeSpecTex13);
	cube13->Init();
	cube13->SetScale(0.15f, 3.5f, 3.5f);

	cubeDiffTex14 = new Texture("buku1.png");
	cubeDiffTex14->Init();
	cubeSpecTex14 = new Texture("buku1.png");
	cubeSpecTex14->Init();
	// Create instance of cube
	cube14 = new Cube(shader, cubeDiffTex14, cubeSpecTex14);
	cube14->Init();
	cube14->SetScale(1.0f, 1.15f, 0.15f);

	cubeDiffTex15 = new Texture("kayu_Gelap.png");
	cubeDiffTex15->Init();
	cubeSpecTex15 = new Texture("kayu_Gelap.png");
	cubeSpecTex15->Init();
	// Create instance of cube
	cube15 = new Cube(shader, cubeDiffTex15, cubeSpecTex15);
	cube15->Init();
	cube15->SetScale(0.35f, 0.5f, 0.075f);

	cubeDiffTex16 = new Texture("kayu_Gelap.png");
	cubeDiffTex16->Init();
	cubeSpecTex16 = new Texture("kayu_Gelap.png");
	cubeSpecTex16->Init();
	// Create instance of cube
	cube16 = new Cube(shader, cubeDiffTex16, cubeSpecTex16);
	cube16->Init();
	cube16->SetScale(0.075f, 0.5f, 0.35f);

	cubeDiffTex17 = new Texture("pensil.png");
	cubeDiffTex17->Init();
	cubeSpecTex17 = new Texture("pensil.png");
	cubeSpecTex17->Init();
	// Create instance of cube
	cube17 = new Cube(shader, cubeDiffTex17, cubeSpecTex17);
	cube17->Init();
	cube17->SetScale(0.0875f, 0.5f, 0.075f);

	cubeDiffTex18 = new Texture("buku2.png");
	cubeDiffTex18->Init();
	cubeSpecTex18 = new Texture("buku2.png");
	cubeSpecTex18->Init();
	// Create instance of cube
	cube18 = new Cube(shader, cubeDiffTex18, cubeSpecTex18);
	cube18->Init();
	cube18->SetScale(1.0f, 1.15f, 0.15f);

	cubeDiffTex19 = new Texture("buku3.png");
	cubeDiffTex19->Init();
	cubeSpecTex19 = new Texture("buku3.png");
	cubeSpecTex19->Init();
	// Create instance of cube
	cube19 = new Cube(shader, cubeDiffTex19, cubeSpecTex19);
	cube19->Init();
	cube19->SetScale(1.0f, 1.15f, 0.15f);

	cubeDiffTex20 = new Texture("penggaris.png");
	cubeDiffTex20->Init();
	cubeSpecTex20 = new Texture("penggaris.png");
	cubeSpecTex20->Init();
	// Create instance of cube
	cube20 = new Cube(shader, cubeDiffTex20, cubeSpecTex20);
	cube20->Init();
	cube20->SetScale(0.0075f, 0.7f, 0.15f);

	cubeDiffTex21 = new Texture("");
	cubeDiffTex21->Init();
	cubeSpecTex21 = new Texture("");
	cubeSpecTex21->Init();
	// Create instance of cube
	cube21 = new Cube(shader, cubeDiffTex21, cubeSpecTex21);
	cube21->Init();
	cube21->SetScale(0.5f, 0.09f, 0.5f);

	cubeDiffTex22 = new Texture("wall.png");
	cubeDiffTex22->Init();
	cubeSpecTex22 = new Texture("wall.png");
	cubeSpecTex22->Init();
	// Create instance of cube
	cube22 = new Cube(shader, cubeDiffTex22, cubeSpecTex22);
	cube22->Init();
	cube22->SetScale(0.1f, 0.5f, 0.1f);

	cubeDiffTex23 = new Texture("wall.png");
	cubeDiffTex23->Init();
	cubeSpecTex23 = new Texture("wall.png");
	cubeSpecTex23->Init();
	// Create instance of cube
	cube23 = new Cube(shader, cubeDiffTex23, cubeSpecTex23);
	cube23->Init();
	cube23->SetScale(0.4f, 0.4f, 0.4f);


	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();

	setupShadow();
}

void Application::DeInit()
{
	delete cube;
	delete cube2;
	delete cube3;
	delete cube4;
	delete cube5;
	delete cube6;
	delete cube7;
	delete cube8;
	delete cube9;
	delete cube10;
	delete cube11;
	delete cube12;
	delete cube13;
	delete cube14;
	delete cube15;
	delete cube16;
	delete cube17;
	delete cube18;
	delete cube19;
	delete cube20;
	delete cube21;
	delete cube22;
	delete cube23;
	
}

void Application::Update(double deltaTime)
{
	//angle += (float)((deltaTime * 1.5f) / 10);

	cube->SetRotation(angle2, 0, 0.1, 0);
	cube2->SetRotation(angle2, 0, 0.1, 0);
	cube3->SetRotation(angle2, 0, 0.1, 0);
	cube4->SetRotation(angle2, 0, 0.1, 0);
	cube5->SetRotation(angle2, 0, 0.1, 0);
	//cube6->SetRotation(83.25, 0, 1.0, 0);
	//cube6->SetRotation(166.5, 0, 1.0, 0);
	cube6->SetRotation(-83.25, 0, 1.0, 0);
	cube7->SetRotation(-83.25, 0, 1.0, 0);
	cube8->SetRotation(angle2, 0, 0.1, 0);
	cube9->SetRotation(angle2, 0, 0.1, 0);
	cube10->SetRotation(97.39, 1, 0, 0);
	cube11->SetRotation(97.39, 1, 0, 0);
	cube12->SetRotation(0, 1, 0, 0);
	cube13->SetRotation(0, 1, 0, 0);
	cube14->SetRotation(0, 1, 0, 0);
	cube15->SetRotation(0, 1, 0, 0);
	cube16->SetRotation(0, 1, 0, 0);
	cube17->SetRotation(0, 1, 0, 0);
	cube18->SetRotation(0, 1, 0, 0);
	cube19->SetRotation(0, 1, 0, 0);
	cube20->SetRotation(0, 1, 0, 0);
	cube21->SetRotation(0, 1, 0, 0);
	cube22->SetRotation(0, 1, 0, 0);
	cube23->SetRotation(0, 1, 0, 0);
	
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(58.0f / 255.0f, 45.0f / 255.0f, 92.0f / 255.0f, 1.0f);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	glm::vec3 lightPos = glm::vec3(0, 25, 0);
	glm::mat4 view = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	glm::mat4 lightSpaceMatrix = projection * view;
	shader->setMat4("lightSpaceMatrix", lightSpaceMatrix);
	shader->setInt("shadowMap", 0);


/*===================================================== Box ==================================================*/

	//Alas 
	for (int i = 0; i < 70; i++) {
		//cube->SetPosition(25 + i * -1.0, -5.0, -25.0);
		//cube->Draw();

		for (int j = 0; j < 75; j++) {
			cube4->SetPosition(25 + i * -1.0, -5.0, -25 + j * 1.0);
			cube4->Draw();
		} 
	} 

	//Dinding ngadep kursi
	for (int i = 0; i < 55; i++) { 

		// Titik Acuan 
		//cube->SetPosition(0, -5 + i + 1.0, 0);
		//cube->Draw();

		for (int j = 0; j < 75; j++) { 
			cube->SetPosition(25.0, -6 + i + 1.0, -25 + j * 1.0); 
			cube->Draw(); 
		} 

		cube->SetPosition(25.0, -6 + i + 1.0, -25.0);
		cube->Draw();
	}

	//dinding belakang pintu
	/*for (int i = 0; i < 55; i++) {

		// Titik Acuan 
		//cube->SetPosition(0, -5 + i + 1.0, 0);
		//cube->Draw();

		for (int j = 0; j < 75; j++) {
			cube->SetPosition(-45.0, -6 + i + 1.0, -25 + j * 1.0);
			cube->Draw();
		}

		cube->SetPosition(-45.0, -6 + i + 1.0, -25.0);
		cube->Draw();
	}*/

	//Dinding Sebelah kanan meja kursi
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 70; j++) {
			cube->SetPosition(25 + j * -1.0, -5 + i * 1.0, 49.0);
			cube->Draw();
		}

	}

	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 70; j++) {
			cube->SetPosition(25 + j * -1.0, 32 + i * 1.0, 49.0);
			cube->Draw();
		}

	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 23; j++) {
			cube->SetPosition(25 + j * -1.0, 13 + i * 1.0, 49.0);
			cube->Draw();
		}

	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 20; j++) {
			cube->SetPosition(-25 + j * -1.0, 13 + i * 1.0, 49.0);
			cube->Draw();
		}

	}
	// z = 25
	// y = -5
	// x = 24
	/*for (int i = 0; i < 1; i++) {
		cube->SetPosition(1.0, 1.0, 1.0); 
		cube->SetRotation(angle, 0.5, 0, 0);
		cube->Draw();

		cube->SetPosition(1.0, 1.0, 1.0);
		cube->SetRotation(angle, 0.5, 0, 0);
		cube->Draw();
	}*/
/*=============================================================================================================*/



/*==================================================== Kursi ==================================================*/ 
	
	//Chair legs
	for (int i = 0; i < 8; i++) {
		//Kanan Bawah
		cube3->SetPosition(2.0, -4 + i * 1.0, -4.0);
		cube3->Draw();

		//Kanan Depan
		cube3->SetPosition(10.0, -4 + i * 1.0, -4.0);
		cube3->Draw();

		//Kiri Belakang
		cube3->SetPosition(2.0, -4 + i * 1.0, -11.0);
		cube3->Draw();
		
		//Kiri Depan
		cube3->SetPosition(10.0, -4 + i * 1.0, -11.0);
		cube3->Draw();
	}
	//Chair Seat
	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {
			cube2->SetPosition(2 + i * 1.0, 4.0, -12 + j * 1.0);
			cube2->Draw();
		}

		cube2->SetPosition(1.0, 4.0, -3 + i * -1.0);
		cube2->Draw();

		cube2->SetPosition(11.0, 4.0, -3 + i * -1.0);
		cube2->Draw();
	}

	//Chair Lay thing
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 12; j++) {
			cube2->SetPosition(1.0, 5 + j * 1.0, -3 + i * -1.0);
			cube2->Draw();

			// maksud dari (5 + j * 1.0) itu angka 5 untuk mengatur posisi dan 1.0 itu klw diubah ke 5.0 maka jarak antar objek adalah 5.0
			// j sendiri jumlah perulangan pada titik tersebut
		}
	}

	for (int i = 0; i < 8; i++) {
		cube2->SetPosition(1.0, 17.0, -4 + i * -1.0);
		cube2->Draw();
	}

/*=============================================================================================================*/



/*==================================================== Meja ===================================================*/
	
	//Table legs
	for (int i = 0; i < 12; i++) {
		//Kanan Belakang
		cube3->SetPosition(12.0, -4 + i * 1.0, 6.0);
		cube3->Draw();

		//Kanan Depan
		cube3->SetPosition(22.0, -4 + i * 1.0, 6.0);
		cube3->Draw();

		//Kiri Belakang
		cube3->SetPosition(12.0, -4 + i * 1.0, -23.0);
		cube3->Draw();

		//Kiri Depan
		cube3->SetPosition(22.0, -4 + i * 1.0, -23.0);
		cube3->Draw();
	}
	//Table Plate
	for (int i = 0; i < 15; i++) {
		
		for (int j = 0; j < 34; j++) {
			cube2->SetPosition(10 + i * 1.0, 8.0, 8 + j * -1.0);
			cube2->Draw();
		}

	}

/*=============================================================================================================*/



/*==================================================== Laptop =================================================*/

	for (int i = 0; i < 8; i++) {
		//Alas Laptop
		for (int j = 0; j < 5; j++) {

			//cube3->SetPosition(14 + j * 1.0, 8.5, -4 + i * -1.0);
			//cube3->Draw();

		}

		//Penutup Laptop
		for (int j = 0; j < 5; j++) {
			//cube3->SetPosition(18.0, 9.5 + j * 1.0, -4 + i * -1.0);
			//cube3->Draw();
		}
	}


	for (int i = 0; i < 8; i++) {
		cube6->SetPosition(2.0, 17.0, -0.65);
		cube6->Draw();

		cube7->SetPosition(75.0, 1.56, -0.65);
		cube7->Draw();
	}
	
/*=============================================================================================================*/

/*==================================================== Rak Buku ===============================================*/

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 34; j++) {
			
			for (int k = 0; k < 5; k++) {
				cube8->SetPosition(20 + i * 1.0, -4 + k * 7.0, 15 + j * 1.0);
				cube8->Draw();
			}
		}

	}

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 4; j++) {

			for (int k = 0; k < 29; k++) {
				cube8->SetPosition(20 + i * 1.0, -4 + k * 1.0, 15 + j * 11.0);
				cube8->Draw();
			}
		}

	}

/*=============================================================================================================*/

/*===================================================== Karpet ================================================*/

	for (int i = 0; i < 70; i++) {

		for (int j = 0; j < 36; j++) {
			cube5->SetPosition(25 + i * -1.0, -4.75, 13 + j * 1.0);
			cube5->Draw();

			
		}

	}

/*=============================================================================================================*/

/*===================================================== Pintu =================================================*/

	//Frame atas
	for (int i = 0; i < 20; i++) {
		cube->SetPosition(-25 + i * -1.0, 30.0, -25.0);
		cube->Draw();
	}

	//Frame Kiri Kanan
	for (int i = 0; i < 2; i++) {

		for (int j = 0; j < 34; j++) {
			cube->SetPosition(-25 + i * -19.0, -4 + j * 1.0,  -25.0);
			cube->Draw();
		}
	}

	//Pintu
	for (int i = 0; i < 19; i++) {

		for (int j = 0; j < 34; j++) {
			cube2->SetPosition(-43.0, -4 + j * 1.0, -24 + i * 1.0);
			cube2->Draw();
		}
	}

	//Gagang Pintu
	for (int i = 0; i < 3; i++) {
		cube3->SetPosition(-43.5, 12.0, -10 + i * 1.0);
		cube3->Draw();

		cube3->SetPosition(-42.5, 12.0, -10 + i * 1.0);
		cube3->Draw();
	}

/*=============================================================================================================*/

/*===================================================== Foto ==================================================*/
	
	//Foto 1
	cube9->SetPosition(32.0, 1.5, -0.265);
	cube9->Draw();
	
	//Foto 2s
	cube10->SetPosition(-58.9, 1.5, 2.0);
	cube10->Draw();
	//Frame
	cube12->SetPosition(-59.5, 1.3, 1.725);
	cube12->Draw();

	//Foto 3
	cube11->SetPosition(-58.9, 1.5, 0.5);
	cube11->Draw();
	//Frame
	cube13->SetPosition(-59.5, 1.3, 0.43);
	cube13->Draw();

/*=============================================================================================================*/

/*===================================================== Jendela ===============================================*/

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 1; j++) {
			cube2->SetPosition(2 + j * -1.0, 13 + i * 1.0, 49.0);
			cube2->Draw();

			cube2->SetPosition(-24 + j * -1.0, 13 + i * 1.0, 49.0);
			cube2->Draw();

			cube2->SetPosition(-11.0 + j * -1.0, 13 + i * 1.0, 49.0);
			cube2->Draw();
		}
		
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 26; j++) {
			cube2->SetPosition(1 + j * -1.0, 13 + i * 1.0, 49.0);
			cube2->Draw();

			//cube2->SetPosition(1 + j * -1.0, 22.0 + i * 1.0, 49.0);
			//cube2->Draw();

			cube2->SetPosition(1 + j * -1.0, 31 + i * 1.0, 49.0);
			cube2->Draw();
		}

	}

/*=============================================================================================================*/


/*===================================================== Buku ==================================================*/

	//Row 1
	for (int i = 0; i < 10; i++) {
		cube14->SetPosition(4.4, 3.541, 21.9 + i * 1.3);
		cube14->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube19->SetPosition(4.4, 3.541, 35.9 + i * 1.3);
		cube19->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube14->SetPosition(4.4, 3.541, 50.9 + i * 1.3);
		cube14->Draw();
	}

	//Row 2
	for (int i = 0; i < 10; i++) {
		cube18->SetPosition(4.4, 2.341, 21.9 + i * 1.3);
		cube18->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube19->SetPosition(4.4, 2.341, 35.9 + i * 1.3);
		cube19->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube14->SetPosition(4.4, 2.341, 50.9 + i * 1.3);
		cube14->Draw();
	}

	//Row 3
	for (int i = 0; i < 10; i++) {
		cube14->SetPosition(4.4, 1.141, 21.9 + i * 1.3);
		cube14->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube14->SetPosition(4.4, 1.141, 35.9 + i * 1.3);
		cube14->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube18->SetPosition(4.4, 1.141, 50.9 + i * 1.3);
		cube18->Draw();
	}

	//Row 4
	for (int i = 0; i < 10; i++) {
		cube18->SetPosition(4.4, -0.141, 21.9 + i * 1.3);
		cube18->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube14->SetPosition(4.4, -0.141, 35.9 + i * 1.3);
		cube14->Draw();
	}

	for (int i = 0; i < 10; i++) {
		cube19->SetPosition(4.4, -0.141, 50.9 + i * 1.3);
		cube19->Draw();
	}

/*=============================================================================================================*/



/*=================================================== Alat Tulis ==============================================*/

	for (int i = 0; i < 2; i++) {
		cube15->SetPosition(12.0, 3.7, 2 + i * 4.0);
		cube15->Draw();

		cube16->SetPosition(54.15 + i * 3.7, 3.7, 0.90);
		cube16->Draw();
	}

	for (int i = 0; i < 3; i++) {
		cube17->SetPosition(49.0, 4.0, 2.75 + i * 1.5);
		cube17->Draw();
	}
	cube20->SetPosition(545.0, 2.8, 2.5);
	cube20->Draw();


/*=============================================================================================================*/

/*================================================= Lampu Belajar =============================================*/

	cube21->SetPosition(8.0, 20.0, -7.0);
	cube21->Draw();

	cube22->SetPosition(40.0, 4.0, -35.0);
	cube22->Draw();

	cube23->SetPosition(10.025, 6.0, -8.7);
	cube23->Draw();

/*=============================================================================================================*/


	shader->setInt("shadowMap", -1);

	glDisable(GL_DEPTH_TEST);

}

glm::vec3 cameraFront /*= glm::vec3(0.0f, 0.0f, -1.0f)*/;

// Add yaw and pitch for camera rotation
float yaw = -90.0f;
float pitch = 0.0f;
float sensitivity = 10.0f; // Adjust for mouse movement sensitivity


void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	// Handle camera movement
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		viewPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		viewPos -= cameraSpeed * cameraFront;
	
	/*if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		viewPos -= glm::normalize(glm::cross(cameraFront, glm::vec3(0.0f, 1.0f, 0.0f))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		viewPos += glm::normalize(glm::cross(cameraFront, glm::vec3(0.0f, 1.0f, 0.0f))) * cameraSpeed;*/


	// Rotate camera on A/D key press (yaw)
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		yaw -= sensitivity;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		yaw += sensitivity;

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		viewPos.y += cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		viewPos.y -= cameraSpeed;


	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(front);

	// Update the view matrix with the new viewPos and cameraFront
	glm::mat4 view = glm::lookAt(viewPos, viewPos + cameraFront, glm::vec3(0.0f, 1.0f, 0.0f));
	shader->setMat4("view", view);


}

int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Bismillah", 
		1200, 900, 
		false, 
		false);
}


