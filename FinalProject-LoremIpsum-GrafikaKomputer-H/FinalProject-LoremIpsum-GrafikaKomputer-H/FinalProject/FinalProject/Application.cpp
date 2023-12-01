#include "Application.h"

Application::Application()
{
	angle = 0;
}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 1000.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(5, 1, 5);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3(4, 4, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("cube.vert", "cube.frag");
	shader->Init();
	// Create instance of cube
	cube = new Cube(shader);
	cube->Init();
	cube->SetRotation(0, 0, 1, 0);

	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	lastLightToggled += deltaTime;
	angle += (float)((deltaTime * 0.5f) / 1000);
	ProcessInput(this->window);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetBackgroundColor(94, 232, 247);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	// Seat
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(0.0f, -0.3f, 0.0f);
	cube->SetScale(1.0f, 0.1f, 1.0f);
	cube->Draw();

	// Backrest
	//cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(0.0f, 0.4f, 0.45f);
	cube->SetScale(1.0f, 0.5f, 0.1f);
	cube->Draw();

	// Front Right Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(0.45f, -0.4f, 0.45f);
	cube->SetScale(0.1f, 1.2f, 0.1f);
	cube->Draw();

	// Front Left Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(-0.45f, -0.4f, 0.45f);
	cube->SetScale(0.1f, 1.2f, 0.1f);
	cube->Draw();

	// Back Right Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(0.45f, -0.7f, -0.45f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Back Left Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(-0.45f, -0.7f, -0.45f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Seat
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(1.5f, -0.3f, 0.0f);
	cube->SetScale(1.0f, 0.1f, 1.0f);
	cube->Draw();

	// Backrest
	//cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(1.5f, 0.4f, 0.45f);
	cube->SetScale(1.0f, 0.5f, 0.1f);
	cube->Draw();

	// Front Right Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(1.05f, -0.4f, 0.45f);
	cube->SetScale(0.1f, 1.2f, 0.1f);
	cube->Draw();

	// Front Left Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(1.95f, -0.4f, 0.45f);
	cube->SetScale(0.1f, 1.2f, 0.1f);
	cube->Draw();

	// Back Right Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(1.05f, -0.7f, -0.45f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Back Left Leg
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(1.95f, -0.7f, -0.45f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Seat
	//cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(0.70f, 0.1f, -1.3f);
	cube->SetScale(3.35f, 0.2f, 1.1f);
	cube->Draw();

	// Front Left Leg
	cube->SetColor(92.0f, 51.0f, 23.0f);
	//cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(2.19f, -0.41f, -1.75f);
	cube->SetScale(0.2f, 1.2f, 0.15f);
	cube->Draw();

	// Back Left Leg
	cube->SetColor(92.0f, 51.0f, 23.0f); 
	//cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(2.19f, -0.41f, -0.90f);
	cube->SetScale(0.2f, 1.2f, 0.15f);
	cube->Draw();

	// Back Right Leg
	cube->SetColor(92.0f, 51.0f, 23.0f); 
	//cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(-0.80f, -0.41f, -0.90f);
	cube->SetScale(0.2f, 1.2f, 0.15f);
	cube->Draw();

	// Front Right Leg
	cube->SetColor(92.0f, 51.0f, 23.0f); 
	//cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(-0.80f, -0.41f, -1.75f);
	cube->SetScale(0.2f, 1.2f, 0.15f);
	cube->Draw();

	//WhiteBoard
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(1.25f, 1.40f, -5.75f);
	cube->SetScale(7.2f, 3.1f, 0.1f);
	cube->Draw();

	//Right
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(4.90f, 1.40f, -5.75f);
	cube->SetScale(0.1f, 3.3f, 0.2f);
	cube->Draw();

	//Left
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(-2.37f, 1.40f, -5.75f);
	cube->SetScale(0.1f, 3.3f, 0.2f);
	cube->Draw();

	//Top
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(1.30f, 3.00f, -5.75f);
	cube->SetScale(7.27f, 0.1f, 0.2f);
	cube->Draw();

	//Top
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(1.30f, -0.20f, -5.75f);
	cube->SetScale(7.27f, 0.1f, 0.2f);
	cube->Draw();

	// Wall
	cube->SetColor(99.0f, 99.0f, 99.0f);
	cube->SetPosition(0.0f, 2.0f, 6.50f);
	cube->SetScale(25.0f, 10.0f, 25.0f);
	cube->Draw();

	// Floor
	cube->SetColor(199.0f, 199.0f, 199.0f);
	cube->SetPosition(0.0f, -1.7f, 6.50f);
	cube->SetScale(25.0f, 1.0f, 25.0f);
	cube->Draw();

	// Roof
	cube->SetColor(217.0f, 217.0f, 217.0f);
	cube->SetPosition(0.0f, 7.4f, 6.50f);
	cube->SetScale(25.0f, 1.0f, 25.0f);
	cube->Draw();


	//glass
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(12.5f, 3.4f, 0.0f);
	cube->SetScale(0.05f, 2.5f, 3.0f);
	cube->Draw();

	//glass
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(12.5f, 3.4f, 10.0f);
	cube->SetScale(0.05f, 2.5f, 3.0f);
	cube->Draw();

	//wardobe
	cube->SetColor(204.0f, 153.0f, 102.0f);
	cube->SetPosition(10.94f, 1.35f, 18.45f);
	cube->SetScale(3.05f, 5.0f, 1.0f);
	cube->Draw();

	//bar
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(11.0f, 1.35f, 17.94f);
	cube->SetScale(0.05f, 5.0f, 0.05f);
	cube->Draw();

	//knob
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(10.7f, 1.25f, 17.90f);
	cube->SetScale(0.15f, 0.15f, 0.15f);
	cube->Draw();

	//knob
	cube->SetColor(92.0f, 51.0f, 23.0f);
	cube->SetPosition(11.30f, 1.25f, 17.90f);
	cube->SetScale(0.15f, 0.15f, 0.15f);
	cube->Draw();

	//LCD
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(-7.0f, 4.7f, -5.75f);
	cube->SetScale(4.4f, 0.2f, 0.4f);
	cube->Draw();

	//LCD
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(-7.0f, 3.1f, -5.75f);
	cube->SetScale(4.0f, 3.0f, 0.1f);
	cube->Draw();

	//Pluto Projector
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(-7.0f, 5.7f, 1.75f);
	cube->SetScale(0.15f, 3.0f, 0.15f);
	cube->Draw();

	//Pluto Projector
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(-7.05f, 4.0f, 1.75f);
	cube->SetScale(1.6f, 0.5f, 1.5f);
	cube->Draw();

	//Pluto Projector
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(-7.45f, 4.2f, 1.17f);
	cube->SetScale(0.4f, 0.4f, 0.4f);
	cube->Draw();





	glDisable(GL_DEPTH_TEST);

}

void Application::UpdateCameraDirection(double xpos, double ypos)
{
	// Update yaw dan pitch berdasarkan input mouse
	yaw += xpos;
	pitch += ypos;

	// Batasi pitch agar tidak melebihi batas atas dan bawah
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	// Hitung vektor arah kamera berdasarkan yaw dan pitch
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	// Normalisasi vektor arah kamera
	viewDir = glm::normalize(front);

	// Perbarui matriks pandangan (view matrix)
	glm::mat4 view = glm::lookAt(viewPos, viewPos + viewDir, glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}


void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	// Faktor sensitivitas mouse
	float sensitivity = 0.5f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	// Update orientasi kamera berdasarkan input mouse
	UpdateCameraDirection(xoffset, yoffset);

	// Fixed camera movement speed
	float fixedMovementSpeed = 0.05f;

	// Update camera position based on keyboard input
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		viewPos += fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		viewPos -= fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		viewPos -= glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		viewPos += glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;


	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && lastLightToggled > 200) {
		lampOn = !lampOn;
		lastLightToggled = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && lastLightToggled > 200) {
		skyOn = !skyOn;
		lastLightToggled = 0;
	}
}



int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Cube Example",
		1366, 768,
		false,
		false);
}