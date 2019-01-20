#include <Game.h>

static bool flip;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube VBO")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		render();
	}

}

typedef struct
{
	float coordinate[3];
	float color[3];
} Vertex;

Vertex vertex[36];
Vertex finalVert[36];
GLubyte triangles[36];
MyVector3 translation = { 0,0,1 };

/* Variable to hold the VBO identifier */                                              
GLuint vbo[1];
GLuint index;

void Game::initialize()
{
	isRunning = true;

	glewInit();

	/* Vertices counter-clockwise winding */

	vertex[0].coordinate[0] = 0.5f;
	vertex[0].coordinate[1] = 0.5f;
	vertex[0].coordinate[2] =- 0.0f;

	vertex[1].coordinate[0] = -0.5f;
	vertex[1].coordinate[1] = 0.5f;
	vertex[1].coordinate[2] = -0.0f;

	vertex[2].coordinate[0] = -0.5f;
	vertex[2].coordinate[1] = -0.5f;
	vertex[2].coordinate[2] = -0.0f;

	vertex[3].coordinate[0] = -0.5f; 
	vertex[3].coordinate[1] = -0.5f;  
	vertex[3].coordinate[2] = -0.0f;

	vertex[4].coordinate[0] = 0.5f; 
	vertex[4].coordinate[1] = -0.5f;  
	vertex[4].coordinate[2] = -0.0f;

	vertex[5].coordinate[0] = 0.5f; 
	vertex[5].coordinate[1] = 0.5f;  
	vertex[5].coordinate[2] = -0.0f;

	vertex[6].coordinate[0] = 0.5f;
	vertex[6].coordinate[1] = 0.5f;
	vertex[6].coordinate[2] = -0.0f;

	vertex[7].coordinate[0] = 0.5f;
	vertex[7].coordinate[1] = 0.5f;
	vertex[7].coordinate[2] = 0.0f;

	vertex[8].coordinate[0] = 0.5f;
	vertex[8].coordinate[1] = -0.5f;
	vertex[8].coordinate[2] = 0.0f;

	vertex[9].coordinate[0] = 0.5f;
	vertex[9].coordinate[1] = -0.5f;
	vertex[9].coordinate[2] = 0.0f;

	vertex[10].coordinate[0] = 0.5f;
	vertex[10].coordinate[1] = -0.5f;
	vertex[10].coordinate[2] =- 0.0f;

	vertex[11].coordinate[0] = 0.5f;
	vertex[11].coordinate[1] = 0.5f;
	vertex[11].coordinate[2] = -0.0f;

	vertex[12].coordinate[0] = -0.5f;
	vertex[12].coordinate[1] = 0.5f;
	vertex[12].coordinate[2] = -0.0f;

	vertex[13].coordinate[0] = -0.5f;
	vertex[13].coordinate[1] = 0.5f;
	vertex[13].coordinate[2] = 0.0f;

	vertex[14].coordinate[0] = -0.5f;
	vertex[14].coordinate[1] = -0.5f;
	vertex[14].coordinate[2] = 0.0f;

	vertex[15].coordinate[0] = -0.5f;
	vertex[15].coordinate[1] = -0.5f;
	vertex[15].coordinate[2] = 0.0f;

	vertex[16].coordinate[0] = -0.5f;
	vertex[16].coordinate[1] = -0.5f;
	vertex[16].coordinate[2] = -0.0f;

	vertex[17].coordinate[0] = -0.5f;
	vertex[17].coordinate[1] = 0.5f;
	vertex[17].coordinate[2] = -0.0f;

	vertex[18].coordinate[0] = -0.5f;
	vertex[18].coordinate[1] = 0.5f;
	vertex[18].coordinate[2] = 0.0f;

	vertex[19].coordinate[0] = 0.5f;
	vertex[19].coordinate[1] = 0.5f;
	vertex[19].coordinate[2] = 0.0f;

	vertex[20].coordinate[0] = -0.5f;
	vertex[20].coordinate[1] = -0.5f;
	vertex[20].coordinate[2] = 0.0f;

	vertex[21].coordinate[0] = -0.5f;
	vertex[21].coordinate[1] = -0.5f;
	vertex[21].coordinate[2] = 0.0f;

	vertex[22].coordinate[0] = 0.5f;
	vertex[22].coordinate[1] = -0.5f;
	vertex[22].coordinate[2] = 0.0f;

	vertex[23].coordinate[0] = 0.5f;
	vertex[23].coordinate[1] = 0.5f;
	vertex[23].coordinate[2] = 0.0f;

	vertex[24].coordinate[0] = -0.5f;
	vertex[24].coordinate[1] = -0.5f;
	vertex[24].coordinate[2] = -0.0f;

	vertex[25].coordinate[0] = 0.5f;
	vertex[25].coordinate[1] = -0.5f;
	vertex[25].coordinate[2] = -0.0f;

	vertex[26].coordinate[0] = 0.5f;
	vertex[26].coordinate[1] = -0.5f;
	vertex[26].coordinate[2] = 0.0f;

	vertex[27].coordinate[0] = 0.5f;
	vertex[27].coordinate[1] = -0.5f;
	vertex[27].coordinate[2] = 0.0f;

	vertex[28].coordinate[0] = -0.5f;
	vertex[28].coordinate[1] = -0.5f;
	vertex[28].coordinate[2] = 0.0f;

	vertex[29].coordinate[0] = -0.5f;
	vertex[29].coordinate[1] = -0.5f;
	vertex[29].coordinate[2] = -0.0f;

	vertex[30].coordinate[0] = -0.5f;
	vertex[30].coordinate[1] = 0.5f;
	vertex[30].coordinate[2] = -0.0f;

	vertex[31].coordinate[0] = 0.5f;
	vertex[31].coordinate[1] = 0.5f;
	vertex[31].coordinate[2] = -0.0f;

	vertex[32].coordinate[0] = 0.5f;
	vertex[32].coordinate[1] = 0.5f;
	vertex[32].coordinate[2] = 0.0f;

	vertex[33].coordinate[0] = 0.5f;
	vertex[33].coordinate[1] = 0.5f;
	vertex[33].coordinate[2] = 0.0f;

	vertex[34].coordinate[0] = -0.5f;
	vertex[34].coordinate[1] = 0.5f;
	vertex[34].coordinate[2] = 0.0f;

	vertex[35].coordinate[0] = -0.5f;
	vertex[35].coordinate[1] = 0.5f;
	vertex[35].coordinate[2] = -0.0f;


	for (int i = 0; i < 36; i++)
	{
		vertex[i].color[0] = 0.1f;
		vertex[i].color[1] = 1.0f;
		vertex[i].color[2] = 0.0f;
	}


	for (int i = 0; i < 36; i++)
	{
		triangles[i] = i;
	}

	for (int i = 0; i < 36; i++)
	{
		finalVert[i] = vertex[i];
		finalVert[i].coordinate[0] += translation.x;
		finalVert[i].coordinate[1] += translation.y;
	}

	/*vertex[0].color[0] = 0.1f;
	vertex[0].color[1] = 1.0f;
	vertex[0].color[2] = 0.0f;

	vertex[1].color[0] = 0.2f;
	vertex[1].color[1] = 1.0f;
	vertex[1].color[2] = 0.0f;

	vertex[2].color[0] = 0.3f;
	vertex[2].color[1] = 1.0f;
	vertex[2].color[2] = 0.0f;

	vertex[3].color[0] = 0.4f;
	vertex[3].color[1] = 1.0f;
	vertex[3].color[2] = 0.0f;

	vertex[4].color[0] = 0.5f;
	vertex[4].color[1] = 1.0f;
	vertex[4].color[2] = 0.0f;

	vertex[5].color[0] = 0.6f;
	vertex[5].color[1] = 1.0f;
	vertex[5].color[2] = 0.0f;


	triangles[0] = 0;   triangles[1] = 1;   triangles[2] = 2;
	triangles[3] = 3;   triangles[4] = 4;   triangles[5] = 5;*/

	/* Create a new VBO using VBO id */
	glGenBuffers(1, vbo);

	/* Bind the VBO */
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

	/* Upload vertex data to GPU */
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glGenBuffers(1, &index);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLubyte) * 6, triangles, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}

	keyInputs();

	//Change vertex data
	//vertex[0].coordinate[0] += -0.0001f;
	//vertex[0].coordinate[1] += -0.0001f;
	//vertex[0].coordinate[2] += -0.0001f;

	cout << "Update up" << endl;
}

void Game::render()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);

	/*	As the data positions will be updated by the this program on the
		CPU bind the updated data to the GPU for drawing	*/
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 6, vertex, GL_STATIC_DRAW);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);


	glColorPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 12);

	/*	Draw Triangle from VBO	(set where to start from as VBO can contain 
		model compoents that are and are not to be drawn )	*/
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), (char*)NULL + 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_BYTE, (char*)NULL + 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;

	glDeleteBuffers(1, vbo);
}

void Game::keyInputs()
{


	//rotation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 36; i++)
		{

			MyVector3 vec = { vertex[i].coordinate[0] , vertex[i].coordinate[1]	, vertex[i].coordinate[2] }
			vec = (MyMatrix3::rotationX(0.01) * vec);
			vertex[i].coordinate[0] = vec.x;
			vertex[i].coordinate[1] = vec.y;
			vertex[i].coordinate[2] = vec.z;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 36; i++)
		{
			MyVector3 vec = { vertex[i].coordinate[0] , vertex[i].coordinate[1]	, vertex[i].coordinate[2] }
			vec = (MyMatrix3::rotationX(-0.01) * vec);
			vertex[i].coordinate[0] = vec.x;
			vertex[i].coordinate[1] = vec.y;
			vertex[i].coordinate[2] = vec.z;
		}
	}
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	
		for (int i = 0; i < 36; i++)
		{
			MyVector3 vec = { vertex[i].coordinate[0] , vertex[i].coordinate[1]	, vertex[i].coordinate[2] }
			vec = (MyMatrix3::rotationZ(0.01) * vec);
			vertex[i].coordinate[0] = vec.x;
			vertex[i].coordinate[1] = vec.y;
			vertex[i].coordinate[2] = vec.z;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 36; i++)
		{
			MyVector3 vec = { vertex[i].coordinate[0] , vertex[i].coordinate[1]	, vertex[i].coordinate[2] }
			vec = (MyMatrix3::rotationZ(-0.01) * vec);
			vertex[i].coordinate[0] = vec.x;
			vertex[i].coordinate[1] = vec.y;
			vertex[i].coordinate[2] = vec.z;
		}
	}
	/// <summary>
	/// translation
	/// </summary>
	/// 
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 36; i++)
		{
			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,0.01, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,-0.01, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation down
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 36; i++)
		{

			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0, -0.01, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0,0.01, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation left
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 36; i++)
		{

			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ -0.01, 0, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0.01, 0, 0 }) * translationArray[i]);
			}
		}
	}
	/// <summary>
	/// key presses for the translation Right
	/// </summary>
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 36; i++)
		{
			if (translationArray[i].z >= 0)
			{

				translationArray[i] = (MyMatrix3::translation(MyVector3{ 0.01, 0, 0 }) * translationArray[i]);
			}
			else
			{
				translationArray[i] = (MyMatrix3::translation(MyVector3{ -0.01, 0, 0 }) * translationArray[i]);
			}
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 36; i++)
		{
			MyVector3 vec = { vertex[i].coordinate[0] , vertex[i].coordinate[1]	, vertex[i].coordinate[2] }
			vec = (MyMatrix3::scale(1.01) * vec);
			vertex[i].coordinate[0] = vec.x;
			vertex[i].coordinate[1] = vec.y;
			vertex[i].coordinate[2] = vec.z;
		}


	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 36; i++)
		{
			MyVector3 vec = { vertex[i].coordinate[0] , vertex[i].coordinate[1]	, vertex[i].coordinate[2] }
			vec = (MyMatrix3::scale(0.99) * vec);
			vertex[i].coordinate[0] = vec.x;
			vertex[i].coordinate[1] = vec.y;
			vertex[i].coordinate[2] = vec.z;
		}

	}
	for (int i = 0; i < 36; i++)
	{
		finalVert[i] = vertex[i];
		finalVert[i].coordinate[0] += translation.x;
		finalVert[i].coordinate[1] += translation.y;
	}

}